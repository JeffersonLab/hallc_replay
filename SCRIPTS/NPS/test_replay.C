void test_replay(Int_t RunNumber=10398, Int_t MaxEvent=1000)
{

  R__LOAD_LIBRARY(libSpectrum.so);
  R__LOAD_LIBRARY(src/libNPSApp.so);
  
  //Cretae FileName Patterns
  const char* RunFileNamePattern="shms_all_%05d.dat";
  const char* ROOTFileNamePattern = "NPS_%d.root";
  vector<TString> pathList;
  pathList.push_back("./raw");
  pathList.push_back("./cache"); 
  
  // Add variables to global list.
  gHcParms->Define("gen_run_number", "Run Number", RunNumber);  //this variable is called in template file to get the run number
  gHcParms->AddString("g_ctp_database_filename", "DBASE/standard.database");
  gHcParms->Load(gHcParms->GetString("g_ctp_database_filename"), RunNumber);
  gHcParms->Load(gHcParms->GetString("g_ctp_parm_filename"));
  gHcParms->Load(gHcParms->GetString("g_ctp_kinematics_filename"), RunNumber);

  //Load param file to include (or not) raw fADC data in ROOTfile 
  gHcParms->Load("PARAM/NPS/GEN/nps_fadc_debug.param");
   
  // Load the Hall C style detector map 
  gHcDetectorMap = new THcDetectorMap();
  //gHcDetectorMap->Load("MAPS/DETEC/shms_stack.map");

  //standard map for shms cal tests (should also be loaded if usgin nps_cal_replicate>0 option in nps_geom.param)
  gHcDetectorMap->Load("MAPS/DETEC/pcal_nps_standard.map");

  //Load either translation/projection maps if nps_cal_replicate=0, as a 2nd
  //method to duplicate events in other "fake" nps quadrants
  //gHcDetectorMap->Load("MAPS/DETEC/pcal_nps_translation.map");
  //gHcDetectorMap->Load("MAPS/DETEC/pcal_nps_projection.map");

  
  //Add NPS spectrometer apparatus
  THaApparatus* NPS = new THcNPSApparatus("NPS","NPS");
  gHaApps->Add(NPS);

  //Add NPS Calorimeter to NPS apparatus
  THcNPSCalorimeter* cal = new THcNPSCalorimeter("cal", "Calorimeter");
  NPS->AddDetector(cal);
  
  // Add handler for prestart event 125.
  THcConfigEvtHandler* ev125 = new THcConfigEvtHandler("HC", "Config Event type 125");
  gHaEvtHandlers->Add(ev125);
  
  THcNPSAnalyzer* analyzer = new THcNPSAnalyzer;  
  THaEvent* event = new THaEvent;

  //Define the run(s) that we want to analyze.
  THcRun* run = new THcRun( pathList, Form(RunFileNamePattern, RunNumber) );

  // Set to read in Hall C run database parameters
  run->SetRunParamClass("THcRunParameters");
  run->SetEventRange(1, MaxEvent);    
  run->SetNscan(1);
  run->SetDataRequired(0x7);
  run->Print();

  
  // Define the analysis parameters
  TString ROOTFileName = Form(ROOTFileNamePattern, RunNumber);

  //Default count mode 
  //analyzer->SetCountMode(2);    // 0 = counter is # of physics triggers
                                // 1 = counter is # of all decode reads
                                // 2 = counter is event number



  
  // Define the analysis parameters
  analyzer->SetEvent( event );
  
  analyzer->SetOutFile(ROOTFileName.Data());
  analyzer->SetCrateMapFileName("MAPS/db_cratemap.dat");
  analyzer->SetOdefFile("DEF-files/NPS.def");       // optional
  analyzer->SetCutFile("DEF-files/NPS_cuts.def");   // optional
  //analyzer->SetCountMode(2);                        // Counter event number same as gen_event_ID_number


  //Required for NPS testing with event merging
  analyzer->SetNevMerge(1);
  analyzer->SetCountMode(0);
  
  
  analyzer->Process(run);     // start the actual analysis

  
}
