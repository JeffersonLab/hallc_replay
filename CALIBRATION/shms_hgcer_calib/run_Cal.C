//Script to run over all SHMS HGCER calibration scripts at once and update the necessary parameter files

void run_Cal()
{

  //User Input Run
  int run_NUM;
  cout << "Enter Run Number: ";
  cin >> run_NUM;

  //Create input file with run number
  ofstream fout;
  fout.open("scripts/input_RUN.txt");
  fout << run_NUM << endl;
  fout.close();

  //Create root and data file directories if they don't exist
  gROOT->ProcessLine(".! mkdir root_files");
  gROOT->ProcessLine(".! mkdir data_files");

  //Create run directories if they don't exist
  gROOT->ProcessLine(Form(".! mkdir root_files/run%d", run_NUM));
  gROOT->ProcessLine(Form(".! mkdir data_files/run%d", run_NUM));

  //User Input Cut Condition
  TString cut;
  cout << "Enter Cut Parameter (time or position): ";
  cin >> cut;
  
  //Execute Visualization scripts
  
  if (cut == "time" || cut == 't')
    {
      gROOT->ProcessLine(".x scripts/get_adc_histo_time_cuts.C");
    }

  if (cut =="position" || cut == 'p')
    {
      gROOT->ProcessLine(".x scripts/get_adc_histo_position_cuts.C");
    }
  
  //Input for Gain Matching


  if (cut == "time" || cut == 't')
    {
      gROOT->ProcessLine(".x scripts/gain_matching_time.C"); 
    }

  if (cut == "position" || cut == 'p')
    {
      gROOT->ProcessLine(".x scripts/gain_matching_position_new.C");
    }
  
}
