// Macro to perform time-walk fits and extract the calibration parameters
// Author: Eric Pooser, pooser@jlab.org

// Declare ROOT files
TFile *histoFile, *outFile;

// Declare constants
static const UInt_t nPlanes    = 4;
static const UInt_t nSides     = 2;
static const UInt_t nBarsMax   = 21;
static const UInt_t nTwFitPars = 3;

static const Double_t tdcThresh      = 120.0;  // 30 mV in units of FADC channels
static const Double_t twFitRangeLow  = 20.0;
static const Double_t twFitRangeHigh = 300.0;
static const Double_t c0twParInit    = -35.0;
static const Double_t c1twParInit    = 5.0;
static const Double_t c2twParInit    = 0.25;

static const Double_t fontSize       = 0.05;
static const Double_t yTitleOffset   = 0.75;
static const Double_t errorLineWidth = 1.0;
static const Double_t markerSize     = 1.75;

static const UInt_t lineWidth = 4;
static const UInt_t lineStyle = 7;

static const UInt_t  nbars[nPlanes]      = {13, 13, 14, 21};
static const TString planeNames[nPlanes] = {"1x", "1y", "2x", "2y"};
static const TString sideNames[nSides]   = {"pos", "neg"};
static const TString twFitParNames[nTwFitPars]  = {"c_{0}", "c_{1}", "c_{2}"};

// Declare directories
TDirectory *dataDir, *planeDir[nPlanes], *sideDir[nPlanes][nSides];
TDirectory *twDir[nPlanes][nSides];
// Declare fits
TF1 *twFit[nPlanes][nSides][nBarsMax], *avgParFit[nPlanes][nSides][nTwFitPars];
// Declare arrays
Double_t paddleIndex[nPlanes][nSides][nBarsMax];
Double_t twFitPar[nPlanes][nSides][nTwFitPars][nBarsMax];
Double_t avgPar[nPlanes][nSides][nTwFitPars];
// Declare canvases
TCanvas *twFitCan[nPlanes][nSides], *twFitParCan[nTwFitPars];
// Declare histos
// 2D histos
TH2F *h2_adcTdcTimeDiffWalk[nPlanes][nSides][nBarsMax];
// Declare graphs
//TGraphErrors *twFitParGraph[nPlanes][nSides][nTwFitPars];
TGraph *twFitParGraph[nPlanes][nSides][nTwFitPars];
// Declare multi-graphs
TMultiGraph *twFitParMultiGraph[nPlanes][nTwFitPars];
// Declare legends
TLegend *twFitParLegend[nPlanes][nTwFitPars], *avgParLegend[nPlanes][nTwFitPars];
// Declare stats
TPaveStats *twFitStats[nPlanes][nSides][nBarsMax];

// Functions to extract calibration parameters
//=:=:=:=:=:=:
//=: Level 1
//=:=:=:=:=:=:

// Add color to fit lines
void addColorToFitLine(UInt_t style, UInt_t width, UInt_t color, TF1 *fit1D) {
  fit1D->SetLineStyle(lineStyle);
  fit1D->SetLineWidth(lineWidth);
  fit1D->SetLineColor(kRed);
} // addColorToFitLine()

void addColorToGraph(UInt_t style, UInt_t size, UInt_t color, TGraph *graph) {
  graph->SetMarkerStyle(style);
  graph->SetMarkerSize(size);
  graph->SetMarkerColor(color);
} // addColorToFitGraph()

// Make the time-walk fit parameter canvases
void makeTwFitParCan() {
  for (UInt_t ipar = 0; ipar < nTwFitPars; ipar++) {
    twFitParCan[ipar] = new TCanvas(twFitParNames[ipar]+"FitParCan", "Parameter "+twFitParNames[ipar]+" Canvas", 1600, 800);
    twFitParCan[ipar]->Divide(2, 2);
  } // Parameter loop
} // makeTwFitParCan()

// Make the time-walk fit parameter canvases
TCanvas *makeCan(UInt_t numColumns, UInt_t numRows, UInt_t winWidth, UInt_t winHeight, TCanvas *can, TString name, TString title) {
  can = new TCanvas(name, title, winWidth, winHeight);
  can->Divide(numColumns, numRows);
  return can;
} // makeTwFitParCan()

// Make the time-walk fit parameter multi-graphs
void makeTwFitParMultiGraphs(UInt_t iplane) {
  for (UInt_t ipar = 0; ipar < nTwFitPars; ipar++) 
    twFitParMultiGraph[iplane][ipar] = new TMultiGraph(planeNames[iplane]+"_"+twFitParNames[ipar]+"_Multigraph", "Plane "+planeNames[iplane]+" Parameter "+twFitParNames[ipar]);
} // makeTwFitParMultiGraphs()

// Make the time-walk fit histogram and fit canvases
void makeTwFitCans(UInt_t iplane, UInt_t iside) {
  twFitCan[iplane][iside] = new TCanvas(planeNames[iplane]+"_"+sideNames[iside]+"_twFitCan", planeNames[iplane]+"_"+sideNames[iside]+"_twFitCan", 1600, 800);
  if (iplane != 3) twFitCan[iplane][iside]->Divide(5, 3);
  if (iplane == 3) twFitCan[iplane][iside]->Divide(6, 4);
} // makeTwFitCans()

// Define the time-walk fit function
Double_t twFunc(Double_t *a, Double_t *c) {
  Double_t twVal = c[0] + c[1]/(TMath::Power((a[0]/tdcThresh), c[2]));
  return twVal;
} // twFunc()

//=:=:=:=:=:=:
//=: Level 2
//=:=:=:=:=:=:

// Draw the time-walk fit parameter legend
void drawFitParLegend(UInt_t iplane, UInt_t ipar) {
  twFitParLegend[iplane][ipar] = new TLegend(0.1, 0.7, 0.3, 0.9);
  for(UInt_t iside = 0; iside < nSides; iside++) {
    if (iside == 0) twFitParLegend[iplane][ipar]->AddEntry(twFitParGraph[iplane][iside][ipar], "Positive Side", "ep");
    if (iside == 1) twFitParLegend[iplane][ipar]->AddEntry(twFitParGraph[iplane][iside][ipar], "Negative Side", "ep");
  } // Side loop
  twFitParLegend[iplane][ipar]->Draw();
} // drawFitParLegend()

// Draw the parameter evereage legend
void drawAvgParLegend(UInt_t iplane, UInt_t ipar) {
  avgParLegend[iplane][ipar] = new TLegend(0.6, 0.7, 0.9, 0.9);
  for(UInt_t iside = 0; iside < nSides; iside++)
    avgParLegend[iplane][ipar]->AddEntry(avgParFit[iplane][iside][ipar], "#bar{"+twFitParNames[ipar]+"}"+Form(" = %.2f", avgPar[iplane][iside][ipar]),"l");
  avgParLegend[iplane][ipar]->Draw();
} // drawAvgParLegend()

// Make the time-walk fit parameter graphs
void makeTwFitParGraphs(UInt_t iplane, UInt_t iside) {
  for (UInt_t ipar = 0; ipar < nTwFitPars; ipar++) {
    // Populate graphs and multi-graphs
    twFitParGraph[iplane][iside][ipar] = new TGraph(nbars[iplane], paddleIndex[iplane][iside], twFitPar[iplane][iside][ipar]);
    if (iside == 0) addColorToGraph(22, markerSize, kRed,  twFitParGraph[iplane][iside][ipar]);
    if (iside == 1) addColorToGraph(23, markerSize, kBlue, twFitParGraph[iplane][iside][ipar]);
    // Add graphs to multi graph
    twFitParMultiGraph[iplane][ipar]->Add(twFitParGraph[iplane][iside][ipar]);
  } // Parameter loop
} // makeTwFitParGraphs()

// Draw the time-walk fit parameter multi-graph
void drawTwFitParMultiGraph(UInt_t iplane) {
  // ROOT settings
  // gStyle->SetTitleFontSize(fontSize);
  // gStyle->SetLabelSize(fontSize, "XY");
  // gStyle->SetTitleSize(fontSize, "XY");
  // gStyle->SetTitleOffset(yTitleOffset, "Y");
  // Populate the parameter canvases
  for (UInt_t ipar = 0; ipar < nTwFitPars; ipar++) {
    twFitParCan[ipar]->cd(iplane+1);
    // gPad->SetGrid();
    twFitParMultiGraph[iplane][ipar]->Draw("AP");
    // X-axis aesthetics
    twFitParMultiGraph[iplane][ipar]->GetXaxis()->SetTitle("Paddle Number");
    twFitParMultiGraph[iplane][ipar]->GetXaxis()->CenterTitle();
    twFitParMultiGraph[iplane][ipar]->GetXaxis()->SetNdivisions(21);
    // Y-axis aesthetics
    twFitParMultiGraph[iplane][ipar]->GetYaxis()->SetTitle("Fit Parameter "+twFitParNames[ipar]);
    twFitParMultiGraph[iplane][ipar]->GetYaxis()->CenterTitle();
    if (ipar == 2) {
      twFitParMultiGraph[iplane][ipar]->GetYaxis()->SetRangeUser(0.0, 1.0);
      twFitParMultiGraph[iplane][ipar]->GetYaxis()->SetNdivisions(10);
    }
    twFitParMultiGraph[iplane][ipar]->Draw("AP");
    // Draw legends
    drawFitParLegend(iplane, ipar);
    drawAvgParLegend(iplane, ipar);
  } // Parameter loop
} // drawTwFitParMultiGraph()

//=:=:=:=:=:=:
//=: Level 3
//=:=:=:=:=:=:

// Perform the timw-walk fits
void doTwFits(UInt_t iplane, UInt_t iside, UInt_t ipaddle) {
  // ROOT settings
  //gStyle->SetStatFormat(".2f");
  //gStyle->SetOptStat(0011);
  // gStyle->SetStatH(0.075);
  // gStyle->SetStatW(0.250);
  // gStyle->SetStatX(0.90);
  // gStyle->SetStatY(0.90);
  gStyle->SetOptFit();

  // Draw fits on canvas
  twFitCan[iplane][iside]->cd(ipaddle+1);
  gPad->SetLogz();
  h2_adcTdcTimeDiffWalk[iplane][iside][ipaddle]->Draw("COLZ");
  gPad->Modified(); gPad->Update();
  // Obtain the stats box object and manipulate it 
  twFitStats[iplane][iside][ipaddle] = dynamic_cast <TPaveStats*> (h2_adcTdcTimeDiffWalk[iplane][iside][ipaddle]->FindObject("stats"));
  if (twFitStats[iplane][iside][ipaddle]) {
    twFitStats[iplane][iside][ipaddle]->SetName("twFitStats");
    twFitStats[iplane][iside][ipaddle]->SetOptStat(11);
    //twFitStats[iplane][iside][ipaddle]->SetOptFit(111);
    twFitStats[iplane][iside][ipaddle]->SetOptFit(111);
    twFitStats[iplane][iside][ipaddle]->SetStatFormat(".2f");
    twFitStats[iplane][iside][ipaddle]->SetFitFormat(".2f");
  }
  gPad->Modified(); gPad->Update();

  // Declare and initialize the fits
  twFit[iplane][iside][ipaddle] = new TF1("twFit", twFunc, twFitRangeLow, twFitRangeHigh, nTwFitPars);
  for (UInt_t ipar = 0; ipar < nTwFitPars; ipar++)
    twFit[iplane][iside][ipaddle]->SetParName(ipar, twFitParNames[ipar]);
  twFit[iplane][iside][ipaddle]->SetParameters(c0twParInit, c1twParInit, c2twParInit);
  
  // Perform the fits and scream if it failed
  Int_t twFitStatus = h2_adcTdcTimeDiffWalk[iplane][iside][ipaddle]->Fit("twFit", "REQ");	
  if (twFitStatus != 0) 
    cout << "ERROR: Time Walk Fit Failed!!! " << "Status = " << twFitStatus << " For Plane: " <<  planeNames[iplane] << " Side: " << sideNames[iside] << " Paddle: " << ipaddle+1 << endl;
  gPad->Modified(); gPad->Update();
		
  // Obtain the fit parameters and associated errors
  for (UInt_t ipar = 0; ipar < nTwFitPars; ipar++) 
    twFitPar[iplane][iside][ipar][ipaddle]  = twFit[iplane][iside][ipaddle]->GetParameter(ipar);
} // doTwFits()

// Calculate the averege of the time-walk fit parameters
void calcParAvg(UInt_t iplane, UInt_t iside) {
  // gStyle->SetOptFit(0);
  for (UInt_t ipar = 0; ipar < nTwFitPars; ipar++) {
    // Calculate the weighted average while ignoring fit errors provided by Minuit
    avgParFit[iplane][iside][ipar] = new TF1("avgParFit", "pol0", 1, nbars[iplane]);
    avgParFit[iplane][iside][ipar]->SetParName(0, "#bar{"+twFitParNames[ipar]+"}");
    // Add color to fit lines
    if (iside == 0) addColorToFitLine(lineStyle, lineWidth, kRed,  avgParFit[iplane][iside][ipar]);
    if (iside == 1) addColorToFitLine(lineStyle, lineWidth, kBlue, avgParFit[iplane][iside][ipar]);
    // Initialize the parameters
    if (ipar == 0) avgParFit[iplane][iside][ipar]->SetParameter(0, c0twParInit);
    if (ipar == 1) avgParFit[iplane][iside][ipar]->SetParameter(0, c1twParInit);
    if (ipar == 2) avgParFit[iplane][iside][ipar]->SetParameter(0, c2twParInit);
    // Perform the least squares fit 
    Int_t avgParFitStatus = twFitParGraph[iplane][iside][ipar]->Fit("avgParFit", "REQ");
    if (avgParFitStatus != 0) 
      cout << "ERROR: Parameter Fit Failed!!! " << "Status = " << avgParFitStatus << " For Plane: " <<  planeNames[iplane] << " Side: " << sideNames[iside] << endl;
    // Store the fit parameters
    avgPar[iplane][iside][ipar] = avgParFit[iplane][iside][ipar]->GetParameter(0);
  } // Parameter loop
} // calcParAvg()

//=:=:=:=:=
//=: Main
//=:=:=:=:=

void timeWalkCalib() {
  // Read the ROOT file containing the time-walk histos
  histoFile = new TFile("timeWalkHistos.root", "READ");
  // Obtain the top level directory
  dataDir = dynamic_cast <TDirectory*> (histoFile->FindObjectAny("hodoUncalib"));


  // Create the parameter canvases
  //makeTwFitParCan();

  for (UInt_t ipar = 0; ipar < nTwFitPars; ipar++) {
    makeCan(2, 2, 1600, 800, twFitParCan[ipar], twFitParNames[ipar]+"FitParCan", "Parameter "+twFitParNames[ipar]+" Canvas");
    cout << twFitParCan[ipar] << endl;
  }


  // Loop over the planes
  //for(UInt_t iplane = 0; iplane < nPlanes; iplane++) {
  for(UInt_t iplane = 0; iplane < 1; iplane++) {
    // Obtain the plane directory
    planeDir[iplane] = dynamic_cast <TDirectory*> (dataDir->FindObjectAny(planeNames[iplane]));
    // Create multigraphs
    makeTwFitParMultiGraphs(iplane);
    // Loop over the sides
    for(UInt_t iside = 0; iside < nSides; iside++) {
      // Obtain the side and time walk directories
      sideDir[iplane][iside] = dynamic_cast <TDirectory*> (planeDir[iplane]->FindObjectAny(sideNames[iside]));
      twDir[iplane][iside]   = dynamic_cast <TDirectory*> (sideDir[iplane][iside]->FindObjectAny("adcTdcTimeDiffWalk"));
      // Create the time-walk histo and fit canvases
      makeTwFitCans(iplane, iside);            
      // Loop over the paddles
      for(UInt_t ipaddle = 0; ipaddle < nbars[iplane]; ipaddle++) {
	// Populate the paddle index arrays
	paddleIndex[iplane][iside][ipaddle]    = Double_t (ipaddle + 1);
	// Obtain the time-walk histos
	h2_adcTdcTimeDiffWalk[iplane][iside][ipaddle] = dynamic_cast <TH2F*> (twDir[iplane][iside]->FindObjectAny(Form("h2_adcTdcTimeDiffWalk_paddle_%d", ipaddle+1)));
	// Perform the time-walk fits while ignoring the S2Y plane (for now)
	if (iplane == 3) continue;
	doTwFits(iplane, iside, ipaddle);
      } // Paddle loop

      // Produce the time-walk fit parameter graphs
      makeTwFitParGraphs(iplane, iside);
      // Calculate the average of the time-walk fit parameters
      calcParAvg(iplane, iside);
    } // Side loop
    // Draw the time-walk parameter graphs
    drawTwFitParMultiGraph(iplane);

  } // Plane loop 

} // timeWalkFits()







