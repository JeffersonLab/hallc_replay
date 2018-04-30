# hcswif
hcswif is a python script for generating JSON files that describe a swif workflow to be run on JLab's ifarm

The json output is one long string, but the following command will display it in a pretty format:
```
python -m json.tool myswifjob.json
```

Visit these links for more details on swif

https://hallcweb.jlab.org/DocDB/0008/000871/001/SWIF%20Intro.pdf

https://scicomp.jlab.org/docs/swif

# Initial setup
You'll need to modify a few files so that hcswif points to the correct hcana, raw data, etc.

The following is a list of files and variables that you may need to modify:
```
1) hcswif.py
    - out_dir
    - raw_dir
2) setup.sh
    - hcana_dir
    - hallc_replay_dir
    - Version of /site/12gev_physics/production.sh
```

# Usage
Note that hcswif must be run with python 3, not python 2

```
./hcswif.py --mode (replay|shell) --spectrometer (HMS|SHMS|COIN|HMS_COIN|SHMS_COIN) --run <a space-separated list of runs> --events <number of events> --replay <hcana replay script> --command <shell script or command> --filelist <necessary files to jget for shell mode> --name <workflow name> --project <project>
```
Some parameters are optional, and some are only relevant for one mode. Optional parameters are assigned default values. Parameters may be specified in any order on the command line.

Parameter    | replay?  | shell?   | Description
------------ | -------- | -------- | ------------------------------------------------
mode         | -        | -        | Are we replaying runs or running a shell script?
spectrometer | required | -        | Which spectrometer? This specifies a replay script and what raw .dat is used
run          | required | -        | A space-separated list of runs
events       | optional | -        | Number of events to use. Default is all events (i.e. -1)
replay       | optional | -        | Replay script to be used; path is relative to your hallc_replay directory. Defaults exist for each spectrometer.
command      | -        | required | Full path location of the shell script to be run
filelist     | -        | optional | List of files needed for your shell script
name         | optional | optional | Name of workflow. Default is hcswifXXXXXXXX, with a timestamp suffix
project      | optional | optional | Project to which the time should be accounted. Default is c-comm2017, but I might remove that to prevent accidental use of that account.


# Examples
## Replay runs using default hcana scripts
This will replay 50k SHMS events for COIN runs 2296 and 2297 using the default script SCRIPTS/SHMS/PRODUCTION/replay_production_shms_coin.C
```
$ ./hcswif.py --mode replay --spectrometer SHMS_COIN --run 2296 2297 --events 50000 --name myswifjob --project c-comm2017
Wrote: /some/directory/myswifjob.json
$ swif import -file myswifjob.json
$ swif run myswifjob
```

## Run a shell script or command, which may or may not be hcana-related
This example will submit a job that runs myscript.sh, which presumably does something more complicated than "regular" replay. It uses a filelist text file called "myfiles" that contains one full path file location per line. These files will be added to the 'input' list of the shell script's job.
```
$ ./hcswif.py --mode shell --command /some/directory/myscript.sh --name myswifjob --project c-comm2017 --filelist myfiles
Wrote: /some/directory/myswifjob.json
$ swif import -file myswifjob.json
$ swif run myswifjob
```

Note that instead of specifying a filelist, you may explicitly put appropriate `jget`s in your shell script to read your raw data from tape.

## Warnings
If some parameters aren't specified (e.g. project, events, filelist) you will be warned and possibly asked if you want to use the default value.
```
$ ./hcswif.py --mode shell --command /some/directory/myscript.sh --name myswifjob
./hcswif.py:160: UserWarning: No project specified.
  warnings.warn('No project specified.')
Should I use project=c-comm2017? (y/n): y
Wrote: /some/directory/myswifjob.json
```
