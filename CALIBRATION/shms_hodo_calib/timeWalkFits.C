// Macro to perform time-walk fits and extract the calibration parameters
// Author: Eric Pooser, pooser@jlab.org

// Declare ROOT files
TFile *histoFile, *outFile;

// Declare constants
static const UInt_t NPLANES   = 4;
static const UInt_t NSIDES    = 2;
static const UInt_t MAXNBARS  = 21;

static const Double_t tdcThresh = 120.0;  // 30 mV in units of FADC channels

static const UInt_t  nbars[NPLANES]      = {13, 13, 14, 21};
static const TString planeNames[NPLANES] = {"1x", "1y", "2x", "2y"};
static const TString sideNames[NSIDES]   = {"pos", "neg"};

// Flag to draw canvas'
static const Bool_t drawCan = 0; 

// Declare directories
TDirectory *dataDir, *planeDir[NPLANES], *sideDir[NPLANES][NSIDES];
TDirectory *timeWalkDir[NPLANES][NSIDES];

// Declare fits
TF1 *timeWalkFit[NPLANES][NSIDES][MAXNBARS];

// Declare parameter arrays
Double_t c0[NPLANES][NSIDES][MAXNBARS], c1[NPLANES][NSIDES][MAXNBARS], c2[NPLANES][NSIDES][MAXNBARS];
Double_t c0Err[NPLANES][NSIDES][MAXNBARS], c1Err[NPLANES][NSIDES][MAXNBARS], c2Err[NPLANES][NSIDES][MAXNBARS];

// Declare canvas'
TCanvas *fitCan[NPLANES][NSIDES], *parCan;

// Declare histos
// 2D histos
TH2F *h2_adcTdcTimeDiffWalk[NPLANES][NSIDES][MAXNBARS];

// Define the time-walk fit function
Double_t timeWalkFunc(Double_t *a, Double_t *c) {
  Double_t timeWalkVal = c[0] + c[1]/(TMath::Power((a[0]/tdcThresh), c[2]));
  return timeWalkVal;
}

void timeWalkFits() {

  // Read the ROOT file containing the time-walk histos
  histoFile = new TFile("timeWalkHistos.root", "READ");
  // Obtain the top level directory
  dataDir = dynamic_cast <TDirectory*> (histoFile->FindObjectAny("hodoUncalib"));
  // Loop over the planes
  for(UInt_t iplane = 0; iplane < NPLANES; iplane++) {
    // Obtain the plane directory
    planeDir[iplane] = dynamic_cast <TDirectory*> (dataDir->FindObjectAny(planeNames[iplane]));
    // Loop over the sides
    for(UInt_t iside = 0; iside < NSIDES; iside++) {
      // Obtain the side and time walk directories
      sideDir[iplane][iside]     = dynamic_cast <TDirectory*> (planeDir[iplane]->FindObjectAny(sideNames[iside]));
      timeWalkDir[iplane][iside] = dynamic_cast <TDirectory*> (sideDir[iplane][iside]->FindObjectAny("adcTdcTimeDiffWalk"));
      
      // Declare canvas to plot histos and fits for diagnostics
      if (drawCan) {
	fitCan[iplane][iside] = new TCanvas(planeNames[iplane]+"_"+sideNames[iside]+"_timeWalkFitCan", planeNames[iplane]+"_"+sideNames[iside]+"_timeWalkFitCan", 1600, 800);
	if (iplane != 3) fitCan[iplane][iside]->Divide(5, 3);
      }
            
      // Loop over the paddles
      for(UInt_t ipaddle = 0; ipaddle < nbars[iplane]; ipaddle++) {
	// Obtain the time-walk histos
	h2_adcTdcTimeDiffWalk[iplane][iside][ipaddle] = dynamic_cast <TH2F*> (timeWalkDir[iplane][iside]->FindObjectAny(Form("h2_adcTdcTimeDiffWalk_paddle_%d", ipaddle+1)));
	// Declare and initialize the fits
	timeWalkFit[iplane][iside][ipaddle] = new TF1("timeWalkFit", timeWalkFunc, 0.0, 4000.0, 3);
	timeWalkFit[iplane][iside][ipaddle]->SetParameters(-35.0, 10.0, 0.25);
	
	if (iplane == 3) continue;
	if (drawCan) {
	  // Draw fits on canvas
	  fitCan[iplane][iside]->cd(ipaddle+1);
	  gPad->SetLogz();
	  h2_adcTdcTimeDiffWalk[iplane][iside][ipaddle]->Draw("COLZ");
	}
	// Perform the fits
	h2_adcTdcTimeDiffWalk[iplane][iside][ipaddle]->Fit("timeWalkFit", "REQM");
	// Obtain the fit parameters and associated errors
	c0[iplane][iside][ipaddle]    = timeWalkFit[iplane][iside][ipaddle]->GetParameter(0);
	c0Err[iplane][iside][ipaddle] = timeWalkFit[iplane][iside][ipaddle]->GetParError(0);
	c1[iplane][iside][ipaddle]    = timeWalkFit[iplane][iside][ipaddle]->GetParameter(1);
	c1Err[iplane][iside][ipaddle] = timeWalkFit[iplane][iside][ipaddle]->GetParError(1);
	c2[iplane][iside][ipaddle]    = timeWalkFit[iplane][iside][ipaddle]->GetParameter(2);
	c2Err[iplane][iside][ipaddle] = timeWalkFit[iplane][iside][ipaddle]->GetParError(2);
	
      } // Paddle loop
    } // Side loop
  } // Plane loop
  

} // timeWalkFunc
