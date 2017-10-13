// Macro to perform time-walk calibrations for the hodoscopes
// Author: Eric Pooser, pooser@jlab.org

#include <time.h>

// Declare replay data file and output file
TFile *replayFile, *outFile;

// Declare data tree
TTree *rawDataTree;

// Declare constants
static const UInt_t NPLANES     = 4;
static const UInt_t NSIDES      = 2;
static const UInt_t NADCSIGNALS = 3;
static const UInt_t NTDCSIGNALS = 1;
static const UInt_t NSIGNALS    = NADCSIGNALS + NTDCSIGNALS;
static const UInt_t MAXTDCHITS  = 128;
static const UInt_t MAXADCHITS  = 4;
static const UInt_t MAXNBARS    = 21;

static const TString spec  = "P";
static const TString detec = "hod";
static const TString trig  = "T";
static const TString shms  = "shms";

static const UInt_t  nbars[NPLANES]        = {13, 13, 14, 21};
static const TString planeNames[NPLANES]   = {"1x", "1y", "2x", "2y"};
static const TString sideNames[NSIDES]     = {"pos", "neg"};
static const TString signalNames[NSIGNALS] = {"Adc", "Tdc"};
static const TString adcData[NADCSIGNALS]  = {"ErrorFlag", "PulseTimeRaw", "PulseAmp"};
static const TString tdcData[NTDCSIGNALS]  = {"TimeRaw"};

static const Double_t adcChanToTime = 0.0625;
static const Double_t tdcChanToTime = 0.100;

// Declare variables to obtain from data tree
// Number of ADC & TDC hits
Int_t    adcHits[NPLANES][NSIDES][NSIGNALS], tdcHits[NPLANES][NSIDES][NSIGNALS];
// Paddle number which fired
Double_t adcPaddle[NPLANES][NSIDES][NSIGNALS][MAXNBARS*MAXADCHITS];
Double_t tdcPaddle[NPLANES][NSIDES][NSIGNALS][MAXNBARS*MAXTDCHITS];
// FADC data
Double_t hodoAdcPulseTimeRaw[NPLANES][NSIDES][NSIGNALS][MAXNBARS*MAXADCHITS];
Double_t hodoAdcPulseAmp[NPLANES][NSIDES][NSIGNALS][MAXNBARS*MAXADCHITS];
Double_t hodoAdcErrorFlag[NPLANES][NSIDES][NSIGNALS][MAXNBARS*MAXADCHITS];
// TDC Data
Double_t hodoTdcTimeRaw[NPLANES][NSIDES][NSIGNALS][MAXNBARS*MAXTDCHITS];
// Trigger apparatus data
Double_t refAdcPulseTimeRaw, refAdcPulseAmpRaw, refAdcMultiplicity;
Double_t refT1TdcTimeRaw, refT2TdcTimeRaw, refT3TdcTimeRaw;
// Declare variables to steer data to arrays
TString *adcBaseName, *adcNdataName, *adcPaddleName;
TString *adcErrorFlagName, *adcPulseTimeRawName, *adcPulseAmpName;
TString *tdcBaseName, *tdcNdataName, *tdcPaddleName;
TString *tdcTimeRawName;
// Declare directories for output ROOT file
TDirectory *trigRawDir, *hodoRawDir, *hodoUncalibDir;
TDirectory *planeRawDir[NPLANES], *sideRawDir[NPLANES][NSIDES], *planeUncalibDir[NPLANES], *sideUncalibDir[NPLANES][NSIDES];
TDirectory *adcTimeWalkDir[NPLANES][NSIDES], *tdcTimeWalkDir[NPLANES][NSIDES], *adcTdcTimeDiffWalkDir[NPLANES][NSIDES];
// Declare histos
// 1D histos
TH1F *h1_refAdcPulseTimeRaw, *h1_refAdcPulseAmpRaw, *h1_refAdcMultiplicity;
TH1F *h1_refT1TdcTimeRaw, *h1_refT2TdcTimeRaw, *h1_refT3TdcTimeRaw;
// 2D histos
TH2F *h2_adcErrorFlag[NPLANES][NSIDES];
TH2F *h2_adcPulseTimeRaw[NPLANES][NSIDES];
TH2F *h2_adcPulseAmp[NPLANES][NSIDES];
TH2F *h2_tdcTimeRaw[NPLANES][NSIDES];

TH2F *h2_adcPulseTime[NPLANES][NSIDES];
TH2F *h2_tdcTime[NPLANES][NSIDES];
TH2F *h2_adcTdcTimeDiff[NPLANES][NSIDES];
TH2F *h2_adcTimeWalk[NPLANES][NSIDES][MAXNBARS];
TH2F *h2_tdcTimeWalk[NPLANES][NSIDES][MAXNBARS];
TH2F *h2_adcTdcTimeDiffWalk[NPLANES][NSIDES][MAXNBARS];

// Declare event data objects
UInt_t nentries, ievent, adcPaddleNum, tdcPaddleNum;

Int_t numAdcHits, numTdcHits;

Double_t adcErrorFlag, adcPulseTimeRaw, adcPulseTime, adcPulseAmp;
Double_t tdcTimeRaw, tdcTime, adcTdcTimeDiff;

Bool_t adcRefMultiplicityCut, adcRefPulseAmpRawCut, adcRefPulseTimeRawCut;
Bool_t edtmCut, adcErrorFlagCut, adcAndTdcHitCut;

void generatePlots(UInt_t iplane, UInt_t iside, UInt_t ipaddle) {

  // Create trigger aparatus directory
  trigRawDir = dynamic_cast <TDirectory*> (outFile->Get("trigAppRaw"));
  if (!trigRawDir) {trigRawDir = outFile->mkdir("trigAppRaw"); trigRawDir->cd();}
  else outFile->cd("trigAppRaw");
  // FADC reference
  if (!h1_refAdcPulseTimeRaw) h1_refAdcPulseTimeRaw = new TH1F("h1_refAdcPulseTimeRaw", "ROC2 Raw FADC Reference Pulse Time; Raw FADC Pulse Time (ns); Number of Entries / 100 ps", 4000, 0, 400);
  if (!h1_refAdcPulseAmpRaw)  h1_refAdcPulseAmpRaw  = new TH1F("h1_refAdcPulseAmpRaw", "ROC2 Raw FADC Reference Pulse Amplitude; Raw FADC Pulse Amplitude (channels); Number of Entries / 1 channel", 4100, 0, 4100);
  if (!h1_refAdcMultiplicity) h1_refAdcMultiplicity = new TH1F("h1_refAdcMultiplicity", "ROC2 Raw FADC Reference Multiplicity; Raw FADC Multiplicity; Number of Entries", 5, -0.5, 4.5);
  // TDC reference
  if (!h1_refT1TdcTimeRaw) h1_refT1TdcTimeRaw = new TH1F("h1_refT1TdcTimeRaw", "ROC2 T1 Raw TDC Reference TDC Time (Slot 20, Channel 15); Raw TDC Time (ns); Number of Entries / 100 ps", 4000, 0, 400);
  if (!h1_refT2TdcTimeRaw) h1_refT2TdcTimeRaw = new TH1F("h1_refT2TdcTimeRaw", "ROC2 T2 Raw TDC Reference TDC Time (Slot 19, Channel 31); Raw TDC Time (ns); Number of Entries / 100 ps", 4000, 0, 400);
  if (!h1_refT3TdcTimeRaw) h1_refT3TdcTimeRaw = new TH1F("h1_refT3TdcTimeRaw", "ROC2 T3 Raw TDC Reference TDC Time (Slot 19, Channel 38); Raw TDC Time (ns); Number of Entries / 100 ps", 4000, 0, 400);
  
  // Create plane directory for raw hodoscope quantities
  hodoRawDir = dynamic_cast <TDirectory*> (outFile->Get("hodoRaw"));
  if (!hodoRawDir) {hodoRawDir = outFile->mkdir("hodoRaw"); hodoRawDir->cd();}
  else outFile->cd("hodoRaw");
  planeRawDir[iplane] = dynamic_cast <TDirectory*> (hodoRawDir->Get(planeNames[iplane]));
  if (!planeRawDir[iplane]) {planeRawDir[iplane] = hodoRawDir->mkdir(planeNames[iplane]); planeRawDir[iplane]->cd();}
  else hodoRawDir->cd(planeNames[iplane]);
  // Create side directory
  sideRawDir[iplane][iside] = dynamic_cast <TDirectory*> (planeRawDir[iplane]->Get(sideNames[iside]));
  if (!sideRawDir[iplane][iside]) {sideRawDir[iplane][iside] = planeRawDir[iplane]->mkdir(sideNames[iside]); sideRawDir[iplane][iside]->cd();}
  else outFile->cd("hodoRaw/"+planeNames[iplane]+"/"+sideNames[iside]);
  // Book histos
  if (!h2_adcErrorFlag[iplane][iside])    h2_adcErrorFlag[iplane][iside]    = new TH2F("h2_adcErrorFlag", "FADC Error Flag Plane "+planeNames[iplane]+" Side "+sideNames[iside]+"; PMT Number; FADC Error Flag", 13, 0.5, 13.5, 2, -0.5, 1.5);
  if (!h2_adcPulseTimeRaw[iplane][iside]) h2_adcPulseTimeRaw[iplane][iside] = new TH2F("h2_adcPulseTimeRaw", "Raw FADC Pulse Time Plane "+planeNames[iplane]+" Side "+sideNames[iside]+"; PMT Number; Raw FADC Pulse Time (ns) / 100 ps", 13, 0.5, 13.5, 4000, 0, 400);
  if (!h2_adcPulseAmp[iplane][iside])     h2_adcPulseAmp[iplane][iside]     = new TH2F("h2_adcPulseAmp", "FADC Pulse Amplitude Plane "+planeNames[iplane]+" Side "+sideNames[iside]+"; PMT Number; FADC Pulse Amplitude (channels) / 1 Channel", 13, 0.5, 13.5, 4000, 0, 4000);
  if (!h2_tdcTimeRaw[iplane][iside])      h2_tdcTimeRaw[iplane][iside]      = new TH2F("h2_tdcTimeRaw", "Raw TDC Time Plane "+planeNames[iplane]+" Side "+sideNames[iside]+"; PMT Number; Raw TDC Time (ns) / 100 ps", 13, 0.5, 13.5, 4000, 0, 400);
  
  // Create plane directory for uncalibrated hodoscope quantities
  hodoUncalibDir = dynamic_cast <TDirectory*> (outFile->Get("hodoUncalib"));
  if (!hodoUncalibDir) {hodoUncalibDir = outFile->mkdir("hodoUncalib"); hodoUncalibDir->cd();}
  else outFile->cd("hodoUncalib");
  planeUncalibDir[iplane] = dynamic_cast <TDirectory*> (hodoUncalibDir->Get(planeNames[iplane]));
  if (!planeUncalibDir[iplane]) {planeUncalibDir[iplane] = hodoUncalibDir->mkdir(planeNames[iplane]); planeUncalibDir[iplane]->cd();}
  else hodoUncalibDir->cd(planeNames[iplane]);
  // Create side directory
  sideUncalibDir[iplane][iside] = dynamic_cast <TDirectory*> (planeUncalibDir[iplane]->Get(sideNames[iside]));
  if (!sideUncalibDir[iplane][iside]) {sideUncalibDir[iplane][iside] = planeUncalibDir[iplane]->mkdir(sideNames[iside]); sideUncalibDir[iplane][iside]->cd();}
  else outFile->cd("hodoUncalib/"+planeNames[iplane]+"/"+sideNames[iside]);
  // Book histos
  if (!h2_adcPulseTime[iplane][iside])   h2_adcPulseTime[iplane][iside]   = new TH2F("h2_adcPulseTime", "FADC Pulse Time Plane "+planeNames[iplane]+" Side "+sideNames[iside]+"; PMT Number;  FADC Pulse Time (ns) / 100 ps", 13, 0.5, 13.5, 8000, -400, 400);
  if (!h2_tdcTime[iplane][iside])        h2_tdcTime[iplane][iside]        = new TH2F("h2_tdcTime", "TDC Time Plane "+planeNames[iplane]+" Side "+sideNames[iside]+"; PMT Number;  TDC Time (ns) / 100 ps", 13, 0.5, 13.5, 8000, -400, 400);
  if (!h2_adcTdcTimeDiff[iplane][iside]) h2_adcTdcTimeDiff[iplane][iside] = new TH2F("h2_adcTdcTimeDiff", "TDC-ADC Time Plane "+planeNames[iplane]+" Side "+sideNames[iside]+"; PMT Number;  TDC - ADC Time (ns) / 100 ps", 13, 0.5, 13.5, 16000, -800, 800);
  // Create ADC time-walk directory
  adcTimeWalkDir[iplane][iside] = dynamic_cast <TDirectory*> (sideUncalibDir[iplane][iside]->Get("adcTimeWalk"));
  if (!adcTimeWalkDir[iplane][iside]) {adcTimeWalkDir[iplane][iside] = sideUncalibDir[iplane][iside]->mkdir("adcTimeWalk"); adcTimeWalkDir[iplane][iside]->cd();}
  else (outFile->cd("hodoUncalib/"+planeNames[iplane]+"/"+sideNames[iside]+"/adcTimeWalk"));
  // Book histos
  if (!h2_adcTimeWalk[iplane][iside][ipaddle]) h2_adcTimeWalk[iplane][iside][ipaddle] = new TH2F(Form("h2_adcTimeWalk_paddle_%d", ipaddle+1), "ADC Time vs. Pulse Amplitude Plane "+planeNames[iplane]+" Side "+sideNames[iside]+" Paddle "+"; Pulse Amplitude / 10 Channels;  ADC Time (ns) / 100 ps", 400, 0, 4000, 4000, -200, 200);
  // Create TDC time-walk directory
  tdcTimeWalkDir[iplane][iside] = dynamic_cast <TDirectory*> (sideUncalibDir[iplane][iside]->Get("tdcTimeWalk"));
  if (!tdcTimeWalkDir[iplane][iside]) {tdcTimeWalkDir[iplane][iside] = sideUncalibDir[iplane][iside]->mkdir("tdcTimeWalk"); tdcTimeWalkDir[iplane][iside]->cd();}
  else (outFile->cd("hodoUncalib/"+planeNames[iplane]+"/"+sideNames[iside]+"/tdcTimeWalk"));
  // Book histos
  if (!h2_tdcTimeWalk[iplane][iside][ipaddle]) h2_tdcTimeWalk[iplane][iside][ipaddle] = new TH2F(Form("h2_tdcTimeWalk_paddle_%d", ipaddle+1), "TDC Time vs. Pulse Amplitude Plane "+planeNames[iplane]+" Side "+sideNames[iside]+" Paddle "+"; Pulse Amplitude / 10 Channels;  TDC Time (ns) / 100 ps", 400, 0, 4000, 4000, -300, 100);
  // Create TDC-ADC time-walk directory
  adcTdcTimeDiffWalkDir[iplane][iside] = dynamic_cast <TDirectory*> (sideUncalibDir[iplane][iside]->Get("adcTdcTimeDiffWalk"));
  if (!adcTdcTimeDiffWalkDir[iplane][iside]) {adcTdcTimeDiffWalkDir[iplane][iside] = sideUncalibDir[iplane][iside]->mkdir("adcTdcTimeDiffWalk"); adcTdcTimeDiffWalkDir[iplane][iside]->cd();}
  else (outFile->cd("hodoUncalib/"+planeNames[iplane]+"/"+sideNames[iside]+"/adcTdcTimeDiffWalk"));
  // Book histos
  if (!h2_adcTdcTimeDiffWalk[iplane][iside][ipaddle]) h2_adcTdcTimeDiffWalk[iplane][iside][ipaddle] = new TH2F(Form("h2_adcTdcTimeDiffWalk_paddle_%d", ipaddle+1), "TDC - ADC Time vs. Pulse Amplitude Plane "+planeNames[iplane]+" Side "+sideNames[iside]+" Paddle "+"; Pulse Amplitude / 10 Channels;  TDC- ADC Time (ns) / 100 ps", 400, 0, 4000, 4000, -200, 200);
  
} // generatePlots()

void time_walk_calib() {

  // Initialize the analysis clock
  clock_t t;
  t = clock();

  // Obtain the replay data file and create new output ROOT file
  replayFile = new TFile("phodo_replay_1248.root", "READ");
  outFile    = new TFile("time_walk_calib.root", "RECREATE");
  // Obtain the tree
  rawDataTree = dynamic_cast <TTree*> (replayFile->Get("T"));
  // Acquire the trigger apparatus data
  rawDataTree->SetBranchAddress("T.shms.pFADC_TREF_ROC2_adcPulseTimeRaw", &refAdcPulseTimeRaw);
  rawDataTree->SetBranchAddress("T.shms.pFADC_TREF_ROC2_adcPulseAmpRaw",  &refAdcPulseAmpRaw);
  rawDataTree->SetBranchAddress("T.shms.pFADC_TREF_ROC2_adcMultiplicity", &refAdcMultiplicity);
  rawDataTree->SetBranchAddress("T.shms.pT1_tdcTimeRaw", &refT1TdcTimeRaw);
  rawDataTree->SetBranchAddress("T.shms.pT2_tdcTimeRaw", &refT2TdcTimeRaw);
  rawDataTree->SetBranchAddress("T.shms.pT3_tdcTimeRaw", &refT3TdcTimeRaw);
  // Loop over the planes, sides, signals, leafs, and fill data arrays
  for(UInt_t iplane = 0; iplane < NPLANES; iplane++) {
    for(UInt_t iside = 0; iside < NSIDES; iside++) {
      // Generate directory structure and histograms
      for(UInt_t ipaddle = 0; ipaddle < nbars[iplane]; ipaddle++)
	generatePlots(iplane, iside, ipaddle);	
      for(UInt_t isignal = 0; isignal < NSIGNALS; isignal++) {

	// Acquire the hodoscope ADC data objects
	if(signalNames[isignal] == "Adc") {
	  // Define the leaf strings of interest
	  adcBaseName   = new TString(spec+"."+detec+"."+planeNames[iplane]+"."+
				      sideNames[iside]+signalNames[isignal]);
	  adcNdataName  = new TString("Ndata."+*adcBaseName+"Counter");
	  adcPaddleName = new TString(*adcBaseName+"Counter");
	  // Fill the leafs
	  rawDataTree->SetBranchAddress(*adcNdataName, &adcHits[iplane][iside][isignal]);
	  rawDataTree->SetBranchAddress(*adcPaddleName, &adcPaddle[iplane][iside][isignal]);
	  // Loop over the adc data objects
	  for(UInt_t iadcdata = 0; iadcdata < NADCSIGNALS; iadcdata++) {
	    if (adcData[iadcdata] == "ErrorFlag") {
	      adcErrorFlagName = new TString(*adcBaseName+"ErrorFlag");
	      rawDataTree->SetBranchAddress(*adcErrorFlagName, &hodoAdcErrorFlag[iplane][iside][isignal]);
	    } // Error flag leaf
	    if (adcData[iadcdata] == "PulseTimeRaw") {
	      adcPulseTimeRawName = new TString(*adcBaseName+"PulseTimeRaw");
	      rawDataTree->SetBranchAddress(*adcPulseTimeRawName, &hodoAdcPulseTimeRaw[iplane][iside][isignal]);
	    } // Raw pulse time leaf
	    if (adcData[iadcdata] == "PulseAmp") {
	      adcPulseAmpName = new TString(*adcBaseName+"PulseAmp");
	      rawDataTree->SetBranchAddress(*adcPulseAmpName, &hodoAdcPulseAmp[iplane][iside][isignal]);
	    } // Pedestal subtracted pulse amplitude leaf
	  } // ADC signal data loop
	} // ADC signal

	  // Acquire the hodoscope TDC data objects
	if(signalNames[isignal] == "Tdc") {
	  // Define the leaf strings of interest
	  tdcBaseName   = new TString(spec+"."+detec+"."+planeNames[iplane]+"."+
				      sideNames[iside]+signalNames[isignal]);
	  tdcNdataName  = new TString("Ndata."+*tdcBaseName+"Counter");
	  tdcPaddleName = new TString(*tdcBaseName+"Counter");
	  // Fill the leafs
	  rawDataTree->SetBranchAddress(*tdcNdataName,  &tdcHits[iplane][iside][isignal]);
	  rawDataTree->SetBranchAddress(*tdcPaddleName, &tdcPaddle[iplane][iside][isignal]);
	  // Loop over the TDC data objects
	  for(UInt_t itdcdata = 0; itdcdata < NTDCSIGNALS; itdcdata++) {
	    if (tdcData[itdcdata] == "TimeRaw") {
	      tdcTimeRawName = new TString(*tdcBaseName+"TimeRaw");
	      rawDataTree->SetBranchAddress(*tdcTimeRawName, &hodoTdcTimeRaw[iplane][iside][isignal]);
	    } // Raw TDC time leaf
	  } // TDC signal data loop
	} // TDC signal	
	
      } // Signal loop
    } // Side loop
  } // Plane loop

    // Loop over the events and fill histograms
  nentries = rawDataTree->GetEntries();
  //nentries = 1000;
  cout << "\n******************************************"    << endl;
  cout << nentries << " Events Will Be Processed"           << endl;
  cout << "******************************************\n"    << endl;
  for (ievent = 0; ievent < nentries; ievent++) {
    // Acquire the event from the data tree
    rawDataTree->GetEntry(ievent);
    // Fill trigger apparatus histos
    h1_refAdcPulseTimeRaw->Fill(refAdcPulseTimeRaw*adcChanToTime);
    h1_refAdcPulseAmpRaw->Fill(refAdcPulseAmpRaw);
    h1_refAdcMultiplicity->Fill(refAdcMultiplicity);
    h1_refT1TdcTimeRaw->Fill(refT1TdcTimeRaw*tdcChanToTime);
    h1_refT2TdcTimeRaw->Fill(refT2TdcTimeRaw*tdcChanToTime);
    h1_refT3TdcTimeRaw->Fill(refT3TdcTimeRaw*tdcChanToTime);
    // Loop over the planes, sides, signals, data arrays, and fill hodoscope histograms
    for(UInt_t iplane = 0; iplane < NPLANES; iplane++) {
      for(UInt_t iside = 0; iside < NSIDES; iside++) {
	for(UInt_t isignal = 0; isignal < NSIGNALS; isignal++) {

	  // Acquire the hodoscope ADC data objects
	  if(signalNames[isignal] == "Adc") { 
	    // Loop over the ADC data objects
	    for(UInt_t iadcdata = 0; iadcdata < NADCSIGNALS; iadcdata++) {
	      numAdcHits = adcHits[iplane][iside][isignal];
	      for (Int_t iadchit = 0; iadchit < numAdcHits; iadchit++) {
		// Obtain variables
		adcPaddleNum    = adcPaddle[iplane][iside][isignal][iadchit];
		adcErrorFlag    = hodoAdcErrorFlag[iplane][iside][isignal][iadchit];
		adcPulseTimeRaw = hodoAdcPulseTimeRaw[iplane][iside][isignal][iadchit]*adcChanToTime;
		adcPulseTime    = adcPulseTimeRaw - refAdcPulseTimeRaw*adcChanToTime;
		adcPulseAmp     = hodoAdcPulseAmp[iplane][iside][isignal][iadchit];
		// Fill histos
		if (adcData[iadcdata] == "ErrorFlag") 
		  h2_adcErrorFlag[iplane][iside]->Fill(adcPaddleNum, adcErrorFlag);
		if (adcData[iadcdata] == "PulseTimeRaw") {
		  h2_adcPulseTimeRaw[iplane][iside]->Fill(adcPaddleNum, adcPulseTimeRaw);
		  h2_adcPulseTime[iplane][iside]->Fill(adcPaddleNum, adcPulseTime);	  
		}
		if (adcData[iadcdata] == "PulseAmp") 
		  h2_adcPulseAmp[iplane][iside]->Fill(adcPaddleNum, adcPulseAmp);
	      } // ADC hit loop
	    } // ADC signal data loop
	  } // ADC signal

	    // Acquire the hodoscope TDC data objects
	  if(signalNames[isignal] == "Tdc") { 
	    // Loop over the TDC data objects
	    for(UInt_t itdcdata = 0; itdcdata < NTDCSIGNALS; itdcdata++) {
	      numTdcHits = tdcHits[iplane][iside][isignal];
	      // Define cuts
	      edtmCut = (numTdcHits == nbars[0] || numTdcHits == nbars[2] || numTdcHits == nbars[3]);
	      // Implement cuts
	      if (edtmCut) continue;
	      for (Int_t itdchit = 0; itdchit < numTdcHits; itdchit++) {
		// Obtain variables
		tdcPaddleNum = tdcPaddle[iplane][iside][isignal][itdchit];
		tdcTimeRaw   = hodoTdcTimeRaw[iplane][iside][isignal][itdchit]*tdcChanToTime;
		tdcTime      = tdcTimeRaw - refT1TdcTimeRaw*tdcChanToTime;
		if (tdcData[itdcdata] == "TimeRaw") {
		  h2_tdcTimeRaw[iplane][iside]->Fill(tdcPaddleNum, tdcTimeRaw);
		  h2_tdcTime[iplane][iside]->Fill(tdcPaddleNum, tdcTime);
		} // RDC raw time signal
	      } // TDC hit loop
	    } // TDC signal data loop
	  } // TDC signal

	    // Define cuts
	  adcRefMultiplicityCut = (refAdcMultiplicity != 1.0);
	  adcRefPulseAmpRawCut  = (TMath::Abs(refAdcPulseAmpRaw - 698.0) > 12.0);
	  adcRefPulseTimeRawCut = (TMath::Abs(refAdcPulseTimeRaw*adcChanToTime - 239.0) > 6.0);
	  // Implement cuts
	  if (adcRefMultiplicityCut || adcRefPulseAmpRawCut || adcRefPulseTimeRawCut) continue;	  
	  //if (adcRefMultiplicityCut || adcRefPulseAmpRawCut) continue;
	  // Acquire the hodoscope ADC data objects
	  if(signalNames[isignal] == "Adc") { 
	    // Loop over the signals again
	    for(UInt_t jsignal = 0; jsignal < NSIGNALS; jsignal++) {
	      // Acquire othe hodoscope TDC data objects
	      if(signalNames[jsignal] == "Tdc") { 
		// Loop over the ADC data objects
		for(UInt_t iadcdata = 0; iadcdata < NADCSIGNALS; iadcdata++) {
		  if (adcData[iadcdata] != "PulseTimeRaw") continue;
		  // Acquire the number of ADC hits
		  numAdcHits = adcHits[iplane][iside][isignal];
		  for (Int_t iadchit = 0; iadchit < numAdcHits; iadchit++) {
		    // Obtain variables
		    adcPaddleNum    = UInt_t (adcPaddle[iplane][iside][isignal][iadchit]);
		    adcErrorFlag    = hodoAdcErrorFlag[iplane][iside][isignal][iadchit];
		    adcPulseTimeRaw = hodoAdcPulseTimeRaw[iplane][iside][isignal][iadchit]*adcChanToTime;
		    adcPulseTime    = adcPulseTimeRaw - refAdcPulseTimeRaw*adcChanToTime;
		    adcPulseAmp     = hodoAdcPulseAmp[iplane][iside][isignal][iadchit];
		    // Define cuts
		    adcErrorFlagCut = (adcErrorFlag != 0);
		    // Implement cuts
		    if (adcErrorFlagCut) continue; 
		    // Loop over the TDC data objects
		    for(UInt_t itdcdata = 0; itdcdata < NTDCSIGNALS; itdcdata++) {
		      if (tdcData[itdcdata] != "TimeRaw") continue;
		      // Acquire the number of TDC hits
		      numTdcHits = tdcHits[iplane][iside][jsignal];
		      // Define cuts
		      edtmCut = (numTdcHits == nbars[0] || numTdcHits == nbars[2] || numTdcHits == nbars[3]);
		      // Implement cuts
		      if (edtmCut) continue;
		      for (Int_t itdchit = 0; itdchit < numTdcHits; itdchit++) {
			// Obtain variables
			tdcPaddleNum   = UInt_t (tdcPaddle[iplane][iside][jsignal][itdchit]);
			tdcTimeRaw     = hodoTdcTimeRaw[iplane][iside][jsignal][itdchit]*tdcChanToTime;
			tdcTime        = tdcTimeRaw - refT1TdcTimeRaw*tdcChanToTime;
			adcTdcTimeDiff = tdcTime - adcPulseTime;
			// Define cuts
			adcAndTdcHitCut = (adcPaddleNum != tdcPaddleNum);
			// Implement cuts
			if (adcAndTdcHitCut) continue;
			h2_adcTdcTimeDiff[iplane][iside]->Fill(tdcPaddleNum, adcTdcTimeDiff);
			h2_adcTimeWalk[iplane][iside][tdcPaddleNum-1]->Fill(adcPulseAmp, adcPulseTime);
			h2_tdcTimeWalk[iplane][iside][tdcPaddleNum-1]->Fill(adcPulseAmp, tdcTime);
			h2_adcTdcTimeDiffWalk[iplane][iside][tdcPaddleNum-1]->Fill(adcPulseAmp, adcTdcTimeDiff);
		      } // TDC hit loop
		    } // TDC signal loop
		  } // ADC hit loop
		} // ADC signal loop
	      } // TDC signal
	    } // Nested signal loop
	  } // ADC signal

	} // Signal loop
      } // Side loop
    } // Plane loop

    if (ievent % 100000 == 0 && ievent != 0)
      cout << ievent << " Events Have Been Processed..." << endl;

  } // rawDataTree event loop  

  cout << "\n***************************************" << endl;
  cout << ievent << " Events Were Processed"          << endl;
  cout << "***************************************\n" << endl;

  // Calculate the analysis rate
  t = clock() - t;
  printf ("The Analysis Took %.1f seconds \n", ((float) t) / CLOCKS_PER_SEC);
  printf ("The Analysis Event Rate Was %.3f kHz \n", (ievent + 1) / (((float) t) / CLOCKS_PER_SEC*1000.));

  outFile->Write();
  outFile->Close();

  return 0;

} // time_walk_calib()
