SHMS Drift Chambers Calibration
============================================
This is directory contains the code for calibrating the 
pair of SHMS drift chambers.



Directory structure
----------------------
* run_Cal.C   : steering script that executes all scripts in the
  	      	'scripts' directory
* scripts  : all scripts necessary to do calibration
* root_files : all root files produced by the calibration are here
* data_files : all data files produced by the calibration are here




Running code
---------------
* First set the parameter 'p_using_tzero_per_wire = 0' in the 
  parameter file located at: hallc_replay/PARAM/SHMS/DC/pdc.param

* Replay the data to produce the uncalibrated root file to be used as input in the calibration
  * From the hallc_replay execute: ./hcana SCRIPTS/SHMS/replay_shms.C

* From this directory execute: root -l run_Cal.C

* From the calibration results, two parameter files will be produced in:
  * hallc_replay/PARAM/SHMS/DC/pdc_tzero_per_wire_run%d_NEW.param. %d=run_number
  * hallc_replay/PARAM/SHMS/DC/pdriftmap_new.param

* Rename the new parameter files as follows:
  * cp pdc_tzero_per_wire_run%d_NEW.param pdc_tzero_per_wire.param
  * cp pdriftmap_new.param pdriftmap.param

* Before replaying the data again, set the parameter 'p_using_tzero_per_wire = 1' to 
  allow the source code (hcana) to read the parameter values during the replay.

* Replay the data with the updated parameters to produce the new calibrated root files
  with the corrected drift times and drift distances.


Brief decription of code
------------------------
* The code determines the tzero offsets on a wire-by-wire basis. 
* Uses paddle 10 positive PMT on plane 1 as the reference PMT ( offset fixed at 0)
* To get data file name. Reads-in the input file: tofcal.inp 
* Opens data file
    * "0" line separates events
    * Should have pair of neg and pos PMTs for each paddle
    * Format is : iside  ipl ipad tdcval_uncorr pathl zcor tdcval_corr adcval
        * iside = 1,2 for pos and neg PMT
        * ipl = plane number
        * tdcval_uncorr = raw time in ns. The program uses this in optimization.
        * pathl = distance for focal plane to the paddle using the track
        * zcor = time (ns) for the particle to go from focal plane to paddle. Correction subtracted from tdcval_uncrr
        * tdcval_corr = the corrected time in ns. Not used by program. Just gives the initial chi2.
        * adcval = ADC value used in fit
* Loops through data determines the number of hits in each PMT. Will only include PMT if the number of hits > 100.
* Again loops through the data filling array with time difference between all pairs PMTs, pathl and adcval.
* Use the CERNLIB routine deqn to invert the matrix and determine the fit parameters.
