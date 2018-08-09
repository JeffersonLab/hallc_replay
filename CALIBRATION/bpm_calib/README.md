# Hall C BPM Calibration Scripts

## Instructions
1. Install the repository parallel to your ~/hallc_replay and ~/hcana installations.

2. Source the setup.sh or setup.csh as appropriate for your shell.

3. It is expected that the ROOT files are already in the ~/hallc_replay/ROOTfiles directory.

4. It is expected that the HARP/BPM data for the appropriate runs are in a text file called harp_info.txt, although a different filename can be specified as an argument to the ROOT macro.

5.  Within ROOT, execute the bpm calibration macro as:

.x bpm_calibration.C("harp_info.txt")


