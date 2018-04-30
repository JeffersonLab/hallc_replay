#!/usr/bin/env python3
import os
import sys
import copy
import json
import getpass
import argparse
import datetime
import warnings

#------------------------------------------------------------------------------
# Define environment

# Where do you want your job output (json files, stdout, stderr)?
out_dir = os.path.join('/volatile/hallc/comm2017/', getpass.getuser() , 'hcswif/output')
if not os.path.isdir(out_dir):
     raise FileNotFoundError('out_dir: ' + out_dir + ' does not exist')

# Where is your raw data?
raw_dir = '/mss/hallc/spring17/raw'
if not os.path.isdir(raw_dir):
    raise FileNotFoundError('raw_dir: ' + raw_dir + ' does not exist')

# Where is hcswif?
hcswif_dir = os.path.dirname(os.path.realpath(__file__))

# hcswif_prefix is used as prefix for workflow, job names, filenames, etc.
now = datetime.datetime.now()
datestr = now.strftime("%Y%m%d%H%M")
hcswif_prefix = 'hcswif' + datestr 

#------------------------------------------------------------------------------
def main():
    parsed_args = parseArgs()
    workflow, outfile = getWorkflow(parsed_args) 
    writeWorkflow(workflow, outfile)

#------------------------------------------------------------------------------
def parseArgs():
    usage_str = ('\n\n'
                 'For mode=replay, you must specify a spectrometer and run number' 
                 'For mode=batch, you must specify a shell script/command' 
                 '\n\n'  
                 'python hcswif.py' 
                 ' --mode (replay|shell)'
                 ' --spectrometer (HMS|SHMS|COIN|HMS_COIN|SHMS_COIN)' 
                 ' --run <a space-separated list of runs>' 
                 ' --events <number of events>' 
                 ' --replay <hcana replay script>' 
                 ' --command <shell command or script to run>'
                 ' --filelist <file containing list of input files to jget>'
                 ' --name <workflow name>' 
                 ' --project <project>')
    parser = argparse.ArgumentParser(usage=usage_str)

    # Check if any args specified
    if len(sys.argv) < 2:
        raise RuntimeError(parser.print_help())

    # Add arguments
    parser.add_argument('--mode', nargs=1, dest='mode',
                        help='type of workflow (replay or shell)')
    parser.add_argument('--spectrometer', nargs=1, dest='spectrometer',
                        help='spectrometer to analyze (HMS, SHMS, COIN, HMS_COIN, SHMS_COIN)')
    parser.add_argument('--run', nargs='+', dest='run', 
                        help='a space-separated list of run number(s)')
    parser.add_argument('--events', nargs=1, dest='events',
                        help='number of events to analyze (default=all)')
    parser.add_argument('--name', nargs=1, dest='name', 
                        help='workflow name')
    parser.add_argument('--replay', nargs=1, dest='replay', 
                        help='hcana replay script')
    parser.add_argument('--command', nargs=1, dest='command', 
                        help='shell command or script to run')
    parser.add_argument('--filelist', nargs=1, dest='filelist', 
                        help='file contaning list of input files to jget')
    parser.add_argument('--project', nargs=1, dest='project', 
                        help='name of project')

    # Return parsed arguments
    return parser.parse_args()

#------------------------------------------------------------------------------
def getWorkflow(parsed_args):
    # Initialize
    workflow = initializeWorkflow(parsed_args)
    outfile = os.path.join(out_dir, workflow['name'] + '.json')

    # Get jobs
    if parsed_args.mode==None:
        raise RuntimeError('Must specify a mode (replay or shell)')
    mode = parsed_args.mode[0].lower()
    if mode == 'replay':
        workflow['jobs'] = getReplayJobs(parsed_args, workflow['name'])
    elif mode == 'shell':
        workflow['jobs'] = getShellJobs(parsed_args, workflow['name'])
    else:
        raise ValueError('Mode must be replay or shell')

    # Add project to jobs
    workflow = addCommonJobInfo(workflow, parsed_args)

    return workflow, outfile

#------------------------------------------------------------------------------
def initializeWorkflow(parsed_args):
    workflow = {}
    if parsed_args.name==None:
        workflow['name'] = hcswif_prefix
    else:
        workflow['name'] = parsed_args.name[0]

    return workflow

#------------------------------------------------------------------------------
def getReplayJobs(parsed_args, wf_name):
    # Spectrometer
    spectrometer = parsed_args.spectrometer[0]
    if spectrometer.upper() not in ['HMS','SHMS','COIN', 'HMS_COIN', 'SHMS_COIN']:
        raise ValueError('Spectrometer must be HMS, SHMS, COIN, HMS_COIN, or SHMS_COIN')

    # Run(s)
    if parsed_args.run==None:
        raise RuntimeError('Must specify run(s) to process')
    else:
        runs = parsed_args.run

    # Replay script to use
    if parsed_args.replay==None:
        # User has not specified a script, so we provide them with default options

        # COIN has two options: hElec_pProt or pElec_hProt depending on 
        # the spectrometer configuration
        if spectrometer.upper() == 'COIN':
            print('COIN replay script depends on spectrometer configuration.')
            print('1) HMS=e, SHMS=p (SCRIPTS/COIN/PRODUCTION/replay_production_coin_hElec_pProt.C)')
            print('2) HMS=p, SHMS=e (SCRIPTS/COIN/PRODUCTION/replay_production_coin_pElec_hProt.C)')
            replay_script = input("Enter 1 or 2: ")
            
            script_dict = { '1' : 'SCRIPTS/COIN/PRODUCTION/replay_production_coin_hElec_pProt.C', 
                            '2' : 'SCRIPTS/COIN/PRODUCTION/replay_production_coin_pElec_hProt.C' }
            replay_script = script_dict[replay_script]

        # We have 4 options for singles replay; "real" singles or "coin" singles
        else:
            script_dict = { 'HMS' : 'SCRIPTS/HMS/PRODUCTION/replay_production_all_hms.C',
                            'SHMS' : 'SCRIPTS/SHMS/PRODUCTION/replay_production_all_shms.C',
                            'HMS_COIN' : 'SCRIPTS/HMS/PRODUCTION/replay_production_hms_coin.C',
                            'SHMS_COIN' : 'SCRIPTS/SHMS/PRODUCTION/replay_production_shms_coin.C' }
            replay_script = script_dict[spectrometer.upper()]

        # User specified a script so we use that one
    else:
        replay_script = parsed_args.replay[0]

    # Number of events; default is -1 (i.e. all)
    if parsed_args.events==None:
        warnings.warn('No events specified. Analyzing all events.')
        evts = -1 
    else:
        evts = parsed_args.events[0]

    # command for job is `/hcswifdir/hcswif.sh REPLAY RUN NUMEVENTS`
    batch = os.path.join(hcswif_dir, 'hcswif.sh')

    # Create list of jobs for workflow
    jobs = []
    for run in runs:
        job = {}

        # Assume coda stem looks like shms_all_XXXXX, hms_all_XXXXX, or coin_all_XXXXX
        if 'coin' in spectrometer.lower():
            # shms_coin and hms_coin use same coda files as coin
            coda_stem = 'coin_all_' + str(run).zfill(5)
        else:
            # otherwise hms_all_XXXXX or shms_all_XXXXX
            coda_stem = spectrometer.lower() + '_all_' + str(run).zfill(5)

        coda = os.path.join(raw_dir, coda_stem + '.dat')

        # Check if raw data file exist
        if not os.path.isfile(coda):
            raise FileNotFoundError('RAW DATA: ' + coda + ' does not exist')

        job['name'] =  wf_name + '_' + coda_stem
        job['input'] = [{}]
        job['input'][0]['local'] = os.path.basename(coda)
        job['input'][0]['remote'] = coda

        job['command'] = " ".join([batch, replay_script, str(run), str(evts)])

        jobs.append(copy.deepcopy(job))

    return jobs

#------------------------------------------------------------------------------
def getShellJobs(parsed_args, wf_name):
    jobs = []
    job = {}
    job['name'] = wf_name + '_job'

    # command for job should be specified by user
    if parsed_args.command==None:
        raise RuntimeError('Must specify command for batch job')
    command = parsed_args.command[0]
    job['command'] = command

    # Add any necessary input files
    if parsed_args.filelist==None:
        warnings.warn('No file list specified! Assuming your shell script has any necessary jgets') 
    else:
        filelist = parsed_args.filelist[0]
        f = open(filelist,'r') 
        lines = f.readlines()

        # We assume user has been smart enough to only specify valid files
        # or, at worst, lines only containing a \n
        job['input'] = []
        for line in lines:
            filename = line.strip('\n')
            if len(filename)>0:
                if not os.path.isfile(filename):
                    raise FileNotFoundError('RAW DATA: ' + filename + ' does not exist')
                inp={}
                inp['local'] = os.path.basename(filename)
                inp['remote'] = filename
                job['input'].append(inp)

    jobs.append(copy.deepcopy(job))
    
    return jobs

#------------------------------------------------------------------------------
def addCommonJobInfo(workflow, parsed_args):
    # Project
    if parsed_args.project==None:
        warnings.warn('No project specified.')

        project_prompt = 'x'
        while project_prompt.lower() not in ['y', 'n', 'yes', 'no']:
            project_prompt = input('Should I use project=c-comm2017? (y/n): ')

        if project_prompt.lower() in ['y', 'yes']:
            project = 'c-comm2017'
        else:
            raise RuntimeError('Please specify project as argument')
    else:
        project = parsed_args.project[0]

    for n in range(0, len(workflow['jobs'])):
        job = copy.deepcopy(workflow['jobs'][n])

        job['project'] = project

        job['stdout'] = os.path.join(out_dir, job['name'] + '.out')
        job['stderr'] = os.path.join(out_dir, job['name'] + '.err')

        # TODO: Allow user to specify these parameters
        job['track'] = 'analysis'
        job['shell'] = '/usr/bin/bash'
        job['os'] = 'centos7'
        job['diskBytes'] = 10000000000
        job['ramBytes'] = 8000000000
        job['cpuCores'] = 8
        job['timeSecs'] = 14400

        workflow['jobs'][n] = copy.deepcopy(job)
        job.clear()

    return workflow

#------------------------------------------------------------------------------
def writeWorkflow(workflow, outfile):
    with open(outfile, 'w') as f:
        json.dump(workflow, f)

    print('Wrote: ' + outfile)
    return

#------------------------------------------------------------------------------
if __name__ == "__main__":
    main()
