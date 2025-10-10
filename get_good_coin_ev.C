/*
  Script to calculate randoms subtracted real coincidence events and then to predict the number of 
  coincidence triggers required to get a desired number of good coincidence events.
  ----
  [terminal]$ root -l
  root [0] .x get_good_coin_ev.C(<run_number>,<nevents_replayed>)
  ----
  P. Datta <pdbforce@jlab.org> Created 03 Mar 2025
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <regex>

#include "TChain.h"
#include "TCanvas.h"
#include "TStopwatch.h"

// ****
// To-do
// 1. Add RF plot (which branch to use?)

/* ------ ########### ------
   ###### USER INPUTS ######
   ------ ########### ------ */
// --- Basic ---
// ---
// 1. list of analysis cuts to apply
std::string anacuts = "(P.gtr.p<=2.9||P.hgcer.npeSum>1)&&P.aero.npeSum>2&&H.cer.npeSum>2&&H.cal.etottracknorm>0.7&&P.cal.etottracknorm<0.8&&abs(P.gtr.dp-5.)<15.&&abs(H.gtr.dp)<8.";
// 2. histo ranges - Convention: {nbin,hmin,hmax}
std::vector<double> hcoin_range{200,10,90};
std::vector<double> hQ2_range{200,0.1,10},hx_range{200,0.01,1.2},hW_range{200,0.1,5},hz_range{200,0.01,1.2},hMMpi_range{200,-0.5,8};
// ---
// --- Advanced (for experts) ---
// ---
// 1. ROOT tree branch to get coin time
std::string coinTbranch = "CTime.ePiCoinTime_ROC2"; 
// 2. ns, Distance of the center of the block to choose randoms from the mean of the main coin peak
double rndmscutdist = 18.;                  
// 3. Ratio of randoms cut region width to good coin cut region width
double rndmscutfactor = 6.;
// 4. Beam bunch structure (should be either 2 or 4 ns)
double beambunchstruct = 4.;
// --- **** ---
// --- **** ---

// Utility functions
TF1* FitCoinPeak(TH1F *h);
void CustomizeHist(TH1F *h);
void PlotPtAccHisto(TH2* h2);
void DetermineCoinCutRegion(TH1F* hcoin, double *fitparams, int verbosity, std::vector<double> &cutregion);
void PlotCutRegion(double xmin, double xmax, EColor fcolor, double alpha);
void ExtractCoinEvCounts(TH1F *hcoin, std::vector<double> const &cutregion, int verbosity, std::vector<double> &counts);
double ExtractValueFromReportFile(const std::string& filename, const std::string& key, const char delimiter, int skipCount);
void PredictNoOfTriggersNeeded(std::string const &inrepfile, std::vector<double> const &counts, double descoinev, int verbosity, std::vector<double> &outputs);
void CalcNormYield(std::string const &inrepfile, double Nrealcoinev, double Nrealcoinev_err, int verbosity, std::vector<double> &NormYield);
std::vector<std::string> SplitString(char const delim, std::string const myStr);
TPaveText* CreateSummaryPaveText(int rnum, ULong64_t totevintree, const std::string& anacuts, const std::vector<double>& counts, double normyield, double descoinev, const std::vector<double>& predtrig, TStopwatch* sw);
TPaveText* CreateSummaryPaveText_new(int rnum, const std::string& anacuts, const std::vector<double>& counts, double normyield, double descoinev, const std::vector<double>& predtrig, TStopwatch* sw);
void PrintCSVLine(std::ofstream &out, int runnum, std::vector<double> const counts, std::vector<double> const normyield, double * coinfitparams);

// global variables
bool is_50k = false;

// Main function
int get_good_coin_ev(int rnum,                 // Run number to analyze
		     int nevent=-1,            // # of events replayed
		     double descoinev=100000., // desired number of real coin events
		     std::string indirroot="ROOTfiles", // Path to directory containing input ROOT file
		     std::string indirreport="REPORT_OUTPUT/COIN/PRODUCTION", // Path to directory containing input report file
		     std::string outdirplot="HISTOGRAMS/COIN/PDF", // Path to directory to save output plots
		     std::string outfilebase="output_get_good_coin_ev") // output filename prefix
{
  gErrorIgnoreLevel = kError; // Ignores all ROOT warnings

  if (nevent==50000) is_50k = true;
  
  // Define a clock to keep track of macro processing time
  TStopwatch *sw = new TStopwatch();
  sw->Start();
  
  // Reading input ROOT files
  std::string inrfile = Form("%s/coin_replay_production_%d_%d.root",indirroot.c_str(),rnum,nevent); // input ROOT file name with directory path
  ROOT::EnableImplicitMT();
  ROOT::RDataFrame data_rdf("T",inrfile.c_str());
  // Defining new columns
  std::string Epi = "sqrt(pow(P.gtr.p,2) + 0.139*0.139)";
  std::string z = Epi + "/H.kin.primary.nu";
  std::string pt2 = "pow(P.gtr.p,2)*(1.-pow(cos(P.kin.secondary.th_xq),2))";
  std::string pt = "sqrt(pow(P.gtr.p,2)*(1.-pow(cos(P.kin.secondary.th_xq),2)))";  
  std::string ptxacc = pt + "*cos(P.kin.secondary.ph_xq)";
  std::string ptyacc = pt + "*sin(P.kin.secondary.ph_xq)";
  // MMpi^2 = Q2 * ((1-x)/x) * (1-z) + Mp^2 - pt^2/z;
  std::string mmpi = "sqrt(H.kin.primary.Q2*((1.-H.kin.primary.x_bj)/H.kin.primary.x_bj)*(1.-"+z+")" + "+0.938*0.938-" + pt2+"/"+z+")";
  //std::string mmpi = "pow(0.938+H.kin.primary.nu-"+Epi+",2.) - H.kin.primary.q3m*(H.kin.primary.q3m-2.*"+pt+")-pow(P.gtr.p,2)"; 
  auto data_rdf_raw = data_rdf.Define("z",z.c_str())
    .Define("mmpi",mmpi.c_str())
    .Define("ptxacc",ptxacc.c_str())
    .Define("ptyacc",ptyacc.c_str());

  // defining output ROOT file
  //Form("%s/%s_%d_%d.root",indirroot.c_str(),outfilebase.c_str(),rnum,nevent);
  TString outfile = inrfile; // Let's save the output files in the input root file
  TFile *fout = new TFile(outfile.Data(),"UPDATE");

  // Defining histos
  // coin 
  TH1F *hcoin = (TH1F*)data_rdf_raw.Filter(anacuts)
    .Histo1D({"hcoin","",int(hcoin_range[0]),hcoin_range[1],hcoin_range[2]},coinTbranch.c_str())->Clone();
  hcoin->GetXaxis()->SetTitle("e-#pi Coincidence Time (ns)"); CustomizeHist(hcoin); 
  // kine
  TH1F *hx = (TH1F*)data_rdf_raw.Filter(anacuts+"&&abs(H.kin.primary.x_bj)<3")
    .Histo1D({"hx","",int(hx_range[0]),hx_range[1],hx_range[2]},"H.kin.primary.x_bj")->Clone();
  hx->GetXaxis()->SetTitle("x_{bj}"); CustomizeHist(hx);
  TH1F *hQ2 = (TH1F*)data_rdf_raw.Filter(anacuts+"&&abs(H.kin.primary.Q2)<10")
    .Histo1D({"hQ2","",int(hQ2_range[0]),hQ2_range[1],hQ2_range[2]},"H.kin.primary.Q2")->Clone();
  hQ2->GetXaxis()->SetTitle("Q^{2} (GeV/c)^{2}"); CustomizeHist(hQ2); 
  TH1F *hz = (TH1F*)data_rdf_raw.Filter(anacuts+"&&abs(P.gtr.p)<10")
    .Histo1D({"hz","",int(hz_range[0]),hz_range[1],hz_range[2]},"z")->Clone();
  hz->GetXaxis()->SetTitle("z"); CustomizeHist(hz);
  TH1F *hW = (TH1F*)data_rdf_raw.Filter(anacuts+"&&abs(H.kin.primary.W)<10")
    .Histo1D({"hW","",int(hW_range[0]),hW_range[1],hW_range[2]},"H.kin.primary.W")->Clone();
  hW->GetXaxis()->SetTitle("W (GeV)"); CustomizeHist(hW);
  TH1F *hMMpi = (TH1F*)data_rdf_raw.Filter(anacuts+"&&abs(P.kin.secondary.MMpi)<10")
    .Histo1D({"hMMpi","",int(hMMpi_range[0]),hMMpi_range[1],hMMpi_range[2]},"P.kin.secondary.MMpi")->Clone();
  TH1F *hMMpi_pd = (TH1F*)data_rdf_raw.Filter(anacuts+"&&abs(P.gtr.p)<10")
    .Histo1D({"hMMpi_pd","",int(hMMpi_range[0]),hMMpi_range[1],hMMpi_range[2]},"mmpi")->Clone();  
  hMMpi->GetXaxis()->SetTitle("Missing Mass (GeV)"); CustomizeHist(hMMpi);     
  TH2F *h2ptaccp = (TH2F*)data_rdf_raw.Filter(anacuts+"&&abs(P.gtr.p)<10")
    .Histo2D({"h2ptaccp","",100,-1,1.,100,-1.,1.},"ptxacc","ptyacc")->Clone();
  // beta
  TH2F *h2hbetaVScoin = (TH2F*)data_rdf_raw.Filter(anacuts+"&&H.gtr.beta>0")
    .Histo2D({"h2hbetaVScoin","",int(hcoin_range[0]),hcoin_range[1],hcoin_range[2],100,0.2,1.4},coinTbranch.c_str(),"H.gtr.beta")->Clone();
  h2hbetaVScoin->SetStats(0);
  h2hbetaVScoin->GetYaxis()->SetTitle("HMS #beta"); h2hbetaVScoin->GetYaxis()->CenterTitle();  
  h2hbetaVScoin->GetXaxis()->SetTitle("e-#pi Coincidence Time (ns)"); h2hbetaVScoin->GetXaxis()->CenterTitle();  
  TH2F *h2pbetaVScoin = (TH2F*)data_rdf_raw.Filter(anacuts+"&&P.gtr.beta>0")
    .Histo2D({"h2pbetaVScoin","",int(hcoin_range[0]),hcoin_range[1],hcoin_range[2],100,0.2,1.4},coinTbranch.c_str(),"P.gtr.beta")->Clone();    
  h2pbetaVScoin->SetStats(0);
  h2pbetaVScoin->GetYaxis()->SetTitle("SHMS #beta"); h2pbetaVScoin->GetYaxis()->CenterTitle();  
  h2pbetaVScoin->GetXaxis()->SetTitle("e-#pi Coincidence Time (ns)"); h2pbetaVScoin->GetXaxis()->CenterTitle();  

  // Plotting and fitting the coin time histo
  TCanvas *ccoin = new TCanvas("ccoin","ccoin",1500,600);
  ccoin->Divide(2,1);  
  ccoin->cd(1);
  gStyle->SetOptStat("e");
  gStyle->SetOptFit(1);
  // fitting the coin histo
  TF1 *fcoin = FitCoinPeak(hcoin);
  double fitparams[3];
  fcoin->GetParameters(&fitparams[0]);
  hcoin->Write("",TObject::kOverwrite);

  // determining and plotting the coin time cut regions
  std::vector<double> coincutregion;
  DetermineCoinCutRegion(hcoin,fitparams,0,coincutregion);
  PlotCutRegion(coincutregion[0],coincutregion[1],kGreen,0.3); // main coin peak
  PlotCutRegion(coincutregion[2],coincutregion[3],kRed,0.3);   // randoms to the left of main peak

  // Extracting the desired counts
  std::vector<double> counts;
  ExtractCoinEvCounts(hcoin,coincutregion,1,counts);
  
  // Predicting the # triggers needed to get 100K good coin events
  std::string inrepfile = Form("%s/replay_coin_production_%d_%d.report",indirreport.c_str(),rnum,nevent); // input report file name with directory path
  std::vector<double> predtrig;
  PredictNoOfTriggersNeeded(inrepfile,counts,descoinev,0,predtrig);

  // Calculate charge normalized and efficiency ccorrected yield
  std::vector<double> normyield{0.,0.};
  CalcNormYield(inrepfile,counts[2],counts[5],1,normyield);

  // Write important stuff to a summary canvas
  ccoin->cd(2);
  ULong64_t nEntries = *data_rdf.Count();
  //std::cout << nEntries << "\n";
  TPaveText* pvtxt = CreateSummaryPaveText(rnum, nEntries, anacuts, counts, normyield[0], descoinev, predtrig, sw);
  pvtxt->Draw();
  ccoin->Update();
  ccoin->Write("",TObject::kOverwrite);

  // Ploting several physics histograms
  TCanvas *cphys = new TCanvas("cphys","cphys",1500,800);
  cphys->Divide(3,2);  
  gStyle->SetOptStat(1111);
  //
  cphys->cd(1);
  hx->Draw();
  hx->Write("",TObject::kOverwrite);
  //
  cphys->cd(2);
  hQ2->Draw();
  hQ2->Write("",TObject::kOverwrite);
  //
  cphys->cd(3);
  hz->Draw();
  hz->Write("",TObject::kOverwrite);
  //
  cphys->cd(4);
  hW->Draw();
  hW->Write("",TObject::kOverwrite);
  //
  cphys->cd(5);
  hMMpi->Draw();
  hMMpi->Write("",TObject::kOverwrite);
  hMMpi_pd->Write("",TObject::kOverwrite);    
  //
  cphys->cd(6);
  PlotPtAccHisto(h2ptaccp);
  h2ptaccp->Write("",TObject::kOverwrite);
  cphys->Update();
  cphys->Write("",TObject::kOverwrite);

  // Plotting beta vs coin time
  TCanvas *cbeta = new TCanvas("cbeta","cbeta",1500,600);
  cbeta->Divide(2,1);
  cbeta->cd(1);
  gPad->SetGridy();
  h2hbetaVScoin->Draw("colz");
  h2hbetaVScoin->Write("",TObject::kOverwrite);
  cbeta->cd(2);
  gPad->SetGridy();  
  h2pbetaVScoin->Draw("colz");
  h2pbetaVScoin->Write("",TObject::kOverwrite);
  cbeta->Write("",TObject::kOverwrite);
  
  // Writing out the canvas
  TString outplot = Form("%s/%s_%d_%d.pdf",outdirplot.c_str(),outfilebase.c_str(),rnum,nevent);
  ccoin->SaveAs(Form("%s[",outplot.Data()));
  ccoin->SaveAs(Form("%s",outplot.Data())); 
  cphys->SaveAs(Form("%s",outplot.Data()));
  cbeta->SaveAs(Form("%s",outplot.Data()));  
  cbeta->SaveAs(Form("%s]",outplot.Data()));

  // Writing out some useful stuff
  std::string outcsv = Form("%s/%s_%d_%d.csv",indirreport.c_str(),outfilebase.c_str(),rnum,nevent);
  std::ofstream outcsv_data(outcsv.c_str());
  PrintCSVLine(outcsv_data,rnum,counts,normyield,fitparams);  

  std::cout << "------" << std::endl;
  std::cout << " Output CSV file  : " << outcsv << std::endl;  
  std::cout << " Output PDF file  : " << outplot << std::endl;
  std::cout << " Output ROOT file  : " << outfile << std::endl;  
  std::cout << "------" << std::endl << std::endl;
  
  // Reporting macro processing time and resources
  std::cout << "\nCPU time = " << sw->CpuTime() << "s. Real time = " << sw->RealTime() << "s.\n";

  return 0;
}

//----------------------------------------------------------
void CustomizeHist(TH1F *h) {
  // Customizes coin histo
  
  h->SetLineColor(kBlack);
  //h->SetLineWidth(2);
  h->GetXaxis()->CenterTitle();
}
//----------------------------------------------------------
TF1* FitCoinPeak(TH1F *h) {
  // function to fit hcoin histogram to find the corresponding mean and sigma.
  // it fits the good coin peak twice for better precision. The evaluated mean
  // and sigma will be used for randoms subtraction.

  // first fit
  double xmax = h->GetXaxis()->GetBinCenter(h->GetMaximumBin()); // x position of the bin with the highest content (i.e. the center of the good coin peak)
  double minfitR = xmax - 1.5; //min fit range
  double maxfitR = xmax + 1.5; //max fit range  
  // defining fit function
  TF1 *fitg1 = new TF1("fit","gaus",hcoin_range[1],hcoin_range[2]);
  fitg1->SetRange(minfitR,maxfitR);
  h->Fit(fitg1,"NO+RQ");
  // get fit parameters from the first fit
  double param[3];
  fitg1->GetParameters(param);

  // second fit
  minfitR = param[1] - 2.*param[2];
  maxfitR = param[1] + 2.*param[2];   
  TF1 *fitg2 = new TF1("fit","gaus",minfitR,maxfitR);
  fitg1->SetRange(minfitR,maxfitR);
  fitg1->SetParameters(&param[0]);
  h->Fit(fitg2,"RQ");

  return fitg2;
}
//----------------------------------------------------------
double FindMinAfterPeak(TH1F* hist) 
/* Finds the bin-center of the first minima after the main coin peak. */
{
  // Number of bins in the histogram
  int nBins = hist->GetNbinsX();
  // Step 1: Find the bin with the largest content (the main peak)
  int peakBin = -1;
  double peakValue = -1;

  // Find the bin with the largest content
  for (int i = 1; i <= nBins; ++i) {
    double content = hist->GetBinContent(i);
    if (content > peakValue) {
      peakValue = content;
      peakBin = i;
    }
  }
  // Step 2: Search for the first local minimum after the main peak
  int minBinAfterPeak = -1;
  double minValue = std::numeric_limits<double>::infinity(); // start with a large value
  // Now search from peakBin + 1 to find the first local minimum
  bool foundMin = false;
  for (int i = peakBin + 1; i <= nBins - 1; ++i) {
    double left = hist->GetBinContent(i - 1);
    double middle = hist->GetBinContent(i);
    double right = hist->GetBinContent(i + 1);   
    // Check if the current bin is smaller than both its neighbors (local minimum)
    if (middle < left && middle < right) {
      minBinAfterPeak = i;
      minValue = middle;
      foundMin = true;
      break;  // First local minimum after peak
    }
  }
  // Return the x-position of the bin center of the minimum after the peak
  if (foundMin) {
    return hist->GetBinCenter(minBinAfterPeak);
  } else {
    std::cerr << "No minimum found after the peak!" << std::endl;
    return -1;
  }
}
//----------------------------------------------------------
void DetermineCoinCutRegion(TH1F* hcoin, double * fitparams, int verbosity, std::vector<double> &cutregion)
/* Determines the coin cut regions
*/
{
  // determining the cut width for the good coin time peak
  /*
   There are three ways to determine the cut width of the good coin time peak -
   1. One half of the beam bunch structure (either 1 or 2 ns). This is the simplest approach
      and Dave likes it.
   2. Fit the good coin time peak using a Gaussian. Then define one standard deviation of the 
      distribution as the cut width. 1.5 or 2 standard deviations are viable options as well.
   3. Use an algorithm to find the minima immediately next to the good coin peak. Then use
      the distance between that and the mean of the good coin time peak as the cut width.
   Using the first approach is preferred. 
  */
  double cutwidth = 0.; // half-width of the good coin time cut
  // -- 1st approach
  cutwidth = beambunchstruct/2.;
  // -- 2nd approach
  // cutwidth = ccutsigma*fitparams[2]; 
  // -- 3rd approach    
  // double firstminima = FindMinAfterPeak(hcoin); // minima immediately after the main peak
  // cutwidth = firstminima - fitparams[1]; 
  double xlowgood = fitparams[1] - cutwidth;
  double xhigood = fitparams[1] + cutwidth;
  // ---
  // determining the cut widths for randoms
  // ---
  // Distance of the center of the block to choose randoms from the mean of the good coin time peak  
  double dist = rndmscutdist; 
  double xlowrndm = fitparams[1] - dist - rndmscutfactor*cutwidth;
  double xhirndm = fitparams[1] - dist + rndmscutfactor*cutwidth;

  cutregion = {xlowgood,xhigood,xlowrndm,xhirndm};

  if (verbosity>0) {
    std::cout << "\n------\n";
    std::cout << "x low of main coin peak cut      : " << xlowgood << "\n";
    std::cout << "x hi of main coin peak cut       : " << xhigood << "\n";    
    std::cout << "x low of random peak cut (left)  : " << xlowrndm << "\n";
    std::cout << "x hi of random peak cut  (left)  : " << xhirndm << "\n"; 
    std::cout << "------\n";    
  }
}
//----------------------------------------------------------
double UnfoldyNDC(double yNDC) 
/* Returns y value for a given y coordinate in NDC */
{
  gPad->Update();
  return yNDC*(gPad->GetY2()-gPad->GetY1()) + gPad->GetY1();
}
//----------------------------------------------------------
void PlotCutRegion(double xmin, double xmax, EColor fillcolor, double alpha)
/* Plots cut region for given x range */
{
  TBox *cutRegion = new TBox(xmin,UnfoldyNDC(0.1),xmax,UnfoldyNDC(0.9));
  cutRegion->SetFillColorAlpha(fillcolor, 0.3);
  cutRegion->Draw();
}
//----------------------------------------------------------
void ExtractCoinEvCounts(TH1F *hcoin, std::vector<double> const &cutregion, int verbosity, std::vector<double> &counts)
{
  // total events under the main coin peak
  double totalcoin = hcoin->Integral(hcoin->FindBin(cutregion[0]),hcoin->FindBin(cutregion[1]));
  double totalcoin_err = sqrt(totalcoin);
  // total random coincidence events in the selected region away from the main coin peak
  double rndmcoin = hcoin->Integral(hcoin->FindBin(cutregion[2]),hcoin->FindBin(cutregion[3]));
  double rndmcoin_err = sqrt(rndmcoin);
  // calculated scaled coin
  double scaledrndmcoin = rndmcoin/rndmscutfactor;
  double scaledrndmcoin_err = rndmcoin_err/rndmscutfactor;    
  // + hcoin->Integral(hcoin->FindBin(cutregion[4]),hcoin->FindBin(cutregion[5]));  // (not used)
  // radoms-subtrated good coin events    
  double goodcoin = totalcoin - scaledrndmcoin;
  double goodcoin_err = sqrt(pow(totalcoin_err,2) + pow(scaledrndmcoin_err,2));  

  counts = {totalcoin,scaledrndmcoin,goodcoin,totalcoin_err,scaledrndmcoin_err,goodcoin_err};
  //counts = {totalcoin,rndmcoin,goodcoin}; //,totalcoin_err,rndmcoin_err,goodcoin_err};  

  if (verbosity>0) {
    std::cout << "\n--------\n";
    std::cout << "Total events under the main coin time peak : " << (int)totalcoin << " +/- " << (int)totalcoin_err << "\n";
    std::cout << "Scaled random coin events selected         : " << (int)scaledrndmcoin << " +/- " << (int)scaledrndmcoin_err << "\n";
    std::cout << "Randoms subtracted real coin events        : " << (int)goodcoin << " +/- " << (int)goodcoin_err << "\n";
    std::cout << "--------\n";    
  }
}
//----------------------------------------------------------
std::string trim(const std::string& str) {
  // Function to trim leading and trailing spaces
  size_t first = str.find_first_not_of(" \t");
  if (first == std::string::npos) return ""; // Empty or only spaces
  size_t last = str.find_last_not_of(" \t");
  return str.substr(first, (last - first + 1));
}
//----------------------------------------------------------
std::string normalizeSpaces(const std::string& str) {
  // Function to normalize spaces (convert multiple spaces to a single space)
  return std::regex_replace(str, std::regex("\\s+"), " ");
}
//----------------------------------------------------------
double ExtractValueFromReportFile(const std::string& filename, const std::string& key, const char delimiter, int skipCount = 0)
/*
  Reads the hcana report file and extracts the number (int or double) associated with
  a given string and delimiter (: or =), skipping `skipCount` number of valid matches
  before returning the number.
*/
{
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file " << filename << std::endl;
    return -1;  // Indicate failure
  }

  std::string line;
  std::string normalizedKey = normalizeSpaces(trim(key));  // Normalize the key once
  int matchCount = 0;

  while (std::getline(file, line)) {
    std::string normalizedLine = normalizeSpaces(trim(line));  // Normalize spaces and trim

    size_t pos = normalizedLine.find(normalizedKey);
    
    // Ensure the match is exact (not a substring of another key)
    if (pos != std::string::npos) {
      bool validMatch = false;

      if (pos == 0 || std::isspace(normalizedLine[pos - 1])) {
        size_t searchPos = pos + normalizedKey.length();
        while (searchPos < normalizedLine.length() && std::isspace(normalizedLine[searchPos])) {
          searchPos++;
        }
        if (searchPos < normalizedLine.length() && normalizedLine[searchPos] == delimiter) {
          validMatch = true;
        }
      }

      if (validMatch) {
        if (matchCount < skipCount) {
          matchCount++;
          continue;  // Skip this occurrence
        }

        std::istringstream iss(normalizedLine.substr(normalizedLine.find(delimiter) + 1));
        double number;
        if (iss >> number) {
          return number;
        }
      }
    }
  }

  std::cerr << "Error: Key '" << key << "' not found after skipping " << skipCount << " occurrences." << std::endl;
  return -1;  // Indicate failure
}
//----------------------------------------------------------
void PredictNoOfTriggersNeeded(std::string const &inrepfile,      // Input report file name with path
			       std::vector<double> const &counts, // Coin event counts (output of ExtractCoinEvCounts)
			       double descoinev,                  // Desired number of coin events
			       int verbosity,
			       std::vector<double> &outputs)      // Output: Desired number of triggers
/* Returns desired number of triggers needed to reach "descoinev" of real coincidence events */
{
  double accALLtrigger = ExtractValueFromReportFile(inrepfile, "All Triggers", ':'); // total accepted triggers    
  double accCointrigger = ExtractValueFromReportFile(inrepfile, "Coincidence Triggers", ':'); // total accepted coin triggers  
  double accHMStrigger = ExtractValueFromReportFile(inrepfile, "Accepted HMS Triggers", ':'); // total accepted HMS triggers
  double accSHMStrigger = ExtractValueFromReportFile(inrepfile, "Accepted SHMS Triggers", ':'); // total accepted SHMS triggers
  // predicting trigger needed to reach 100000 good coin events
  double predALLtrigger = (accALLtrigger / counts[2]) * descoinev;    
  double predCointrigger = (accCointrigger / counts[2]) * descoinev;  
  double predHMStrigger = (accHMStrigger / counts[2]) * descoinev;
  double predSHMStrigger = (accSHMStrigger / counts[2]) * descoinev;

  outputs = {predALLtrigger,predCointrigger,predHMStrigger,predSHMStrigger};

  if (verbosity>0) {
    std::cout << "\n--- Trigger Predictions ---\n";
    std::cout << "No. of triggers needed to get " << (int)descoinev << " real coin events  : " << (int)predALLtrigger << "\n";        
    std::cout << "Coin triggers needed to get " << (int)descoinev << " real coin events  : " << (int)predCointrigger << "\n";    
    std::cout << "HMS triggers needed to get " << (int)descoinev << " real coin events  : " << (int)predHMStrigger << "\n";
    std::cout << "SHMS triggers needed to get " << (int)descoinev << " real coin events : " << (int)predSHMStrigger << "\n";
    std::cout << "-------\n";
  }
}
//----------------------------------------------------------
void CalcNormYield(std::string const &inrepfile, // Input report file name with path
		   double Nrealcoinev,          // No. of real coin (randoms subtracted) events
		   double Nrealcoinev_err,       // Statistical error for randoms subtracted coin event
		   int verbosity,
		   std::vector<double> &NormYield)
/* Calculates charge normalized and efficiency corrected yeild from random subtracted coin events */
{
  //double charge = ExtractValueFromReportFile(inrepfile, "HMS BCM4A Beam Cut Charge", ':'); //mC
  double charge = ExtractValueFromReportFile(inrepfile, "SHMS BCM4B Beam Cut Charge", ':', 0); //mC  
  double compdeadtime = ExtractValueFromReportFile(inrepfile, "HMS Computer Dead Time", ':', 0)/100.0;
  double treffiHMS = ExtractValueFromReportFile(inrepfile, "E SING FID TRACK EFFIC", ':', 1);  
  double treffiSHMS = ExtractValueFromReportFile(inrepfile, "HADRON SING FID TRACK EFFIC", ':', 0);
  double trigeffi = 1.0; // assuming 100% efficiency for the moment

  //double normyield = Nrealcoinev / (charge * compdeadtime * treffiHMS * treffiSHMS * trigeffi);
  
  double normfac = 1. / (charge * compdeadtime * treffiHMS * treffiSHMS * trigeffi);
  
  double normyield = Nrealcoinev * normfac ; // 1/mC
  double normyield_err = Nrealcoinev_err * normfac; 
  
  if (verbosity>0) {
    std::cout << "\n--- Normalized Yield ---\n";
    std::cout << "Real Coin Ev            : " << (int)Nrealcoinev << "\n";    
    std::cout << "Charge (mC)             : " << charge << "\n";
    std::cout << "Computer dead time      : " << compdeadtime << "\n";
    std::cout << "Tracking Effi. HMS      : " << treffiHMS << "\n";
    std::cout << "Tracking Effi. SHMS     : " << treffiSHMS << "\n";        
    std::cout << "Trigger Effi.           : " << trigeffi << "\n";
    std::cout << "Normalized Yield (1/mC) : " << normyield << " +/- " << normyield_err << "\n";
    std::cout << "-------\n";
  }

  NormYield = {normyield,normyield_err};
}
//----------------------------------------------------------
std::vector<std::string> SplitString(char const delim, std::string const myStr)
/* Splits a string by a delimiter (doesn't include empty sub-strings) */
{
  std::stringstream ss(myStr);
  std::vector<std::string> out;
  while (ss.good()) {
    std::string substr;
    std::getline(ss, substr, delim);
    if (!substr.empty()) out.push_back(substr);
  }
  if (out.empty()) std::cerr << "WARNING! No substrings found!\n";
  return out;
}
//----------------------------------------------------------
void PlotPtAccHisto(TH2* h2) {
  /* Special function to plot P_T acceptance histo */
  h2->SetStats(0);
  h2->GetXaxis()->SetRangeUser(-1, 1);
  h2->GetYaxis()->SetRangeUser(-1, 1);
  h2->GetXaxis()->SetLabelSize(0);  // hide default tick labels
  h2->GetYaxis()->SetLabelSize(0);
  h2->Draw("COL");
  
  // Draw vertical and horizontal lines
  TLine *lx = new TLine(-1, 0, 1, 0);
  TLine *ly = new TLine(0, -1, 0, 1);
  lx->SetLineColor(kGray+2); ly->SetLineColor(kGray+2);
  lx->Draw(); ly->Draw();

  // Draw circular guides and labels
  TLatex* label = new TLatex();
  label->SetTextSize(0.025);  // small, unobtrusive
  label->SetTextColor(kRed);
  label->SetTextAlign(12);    // left-bottom alignment

  for (double r : {0.2, 0.4, 0.6, 0.8}) {
    TEllipse *circle = new TEllipse(0, 0, r);
    circle->SetFillStyle(0);
    circle->SetLineStyle(2);
    circle->SetLineColor(kGray+2);
    circle->Draw();

    // Label each circle near the top-right quadrant
    double x = r / sqrt(2), y = r / sqrt(2);
    label->DrawLatex(x + 0.02, y + 0.02, Form("p_{T} = %.1f", r));
  }

  // Draw angular labels
  TLatex* t = new TLatex();
  t->SetTextAlign(22);
  t->SetTextSize(0.035);
  t->DrawLatex(1.1, 0, "#phi_{h}=0#circ");
  t->DrawLatex(0, 1.08, "#phi_{h}=90#circ");
  t->DrawLatex(-1.12, 0, "#phi_{h}=180#circ");
  t->DrawLatex(0, -1.08, "#phi_{h}=270#circ");
}
//----------------------------------------------------------
TPaveText* CreateSummaryPaveText_old(int rnum, const std::string& anacuts,
                                  const std::vector<double>& counts,
                                  double normyield,
                                  double descoinev,
                                  const std::vector<double>& predtrig,
                                  TStopwatch* sw)
/* Function to create a summary canvas (old) */
{  
  TPaveText* pvtxt = new TPaveText(.05, .1, .95, .8);
  pvtxt->SetTextFont(42);
  pvtxt->SetTextSize(0.03);

  pvtxt->AddText(Form("Run Number : %d", rnum));
  pvtxt->AddText("Analysis cuts:");
  std::vector<std::string> aCutList = SplitString('&', anacuts.c_str());
  std::string tmpstr = "";
  int ccount = 0;
  for (std::size_t i = 0; i < aCutList.size(); ++i) {
    if (i > 0 && i % 3 == 0) {
      pvtxt->AddText(Form(" %s", tmpstr.c_str()));
      tmpstr = "";
    }
    ccount++;
    tmpstr += aCutList[i];
    if (ccount != aCutList.size()) tmpstr += ", ";

    if ((aCutList.size() - i) < 3 && ccount == aCutList.size()) {
      pvtxt->AddText(Form(" %s", tmpstr.c_str()));
      tmpstr = "";
    }
  }
  pvtxt->AddText("Counts:");
  pvtxt->AddText(Form("Number of Real (Randoms Subtracted) Coin Events : %.0f", counts[2]));
  pvtxt->AddText(Form("Charge Normalized and Efficiency Corrected Yield : %.1f (1/mC)", normyield));
  pvtxt->AddText("Trigger Predictions");
  pvtxt->AddText(Form("No. of Triggers Needed to Get %.0f Good Coin Events : %.0f", descoinev, predtrig[0]));
  sw->Stop();
  pvtxt->AddText(Form("Macro processing time: CPU %.1fs | Real %.1fs", sw->CpuTime(), sw->RealTime()));

  // Highlight key lines
  if (TText* t1 = pvtxt->GetLineWith("Run")) t1->SetTextColor(kGreen + 3);
  if (TText* t2 = pvtxt->GetLineWith("Analysis")) t2->SetTextColor(kBlue);
  if (TText* t3 = pvtxt->GetLineWith("Counts")) t3->SetTextColor(kBlue);
  if (TText* t4 = pvtxt->GetLineWith("Trigger")) t4->SetTextColor(kBlue);
  if (TText* t5 = pvtxt->GetLineWith("No. of Trigger")) t5->SetTextColor(kRed);
  if (TText* t6 = pvtxt->GetLineWith("Macro")) t6->SetTextColor(kGreen+3);

  return pvtxt;
}
//----------------------------------------------------------
TPaveText* CreateSummaryPaveText(int rnum,
				 ULong64_t totevintree,
				 const std::string& anacuts,
				 const std::vector<double>& counts,
				 double normyield,
				 double descoinev,
				 const std::vector<double>& predtrig,
				 TStopwatch* sw)
/* Function to create a summary canvas */
{  
  TPaveText* pvtxt = new TPaveText(.05, .1, .95, .8);
  pvtxt->SetTextFont(42);
  pvtxt->SetTextSize(0.03);

  pvtxt->AddText(Form("Run Number : %d", rnum));
  pvtxt->AddText("Analysis cuts:");
  std::vector<std::string> aCutList = SplitString('&', anacuts.c_str());
  std::string tmpstr = "";
  int ccount = 0;
  for (std::size_t i = 0; i < aCutList.size(); ++i) {
    if (i > 0 && i % 3 == 0) {
      pvtxt->AddText(Form(" %s", tmpstr.c_str()));
      tmpstr = "";
    }
    ccount++;
    tmpstr += aCutList[i];
    if (ccount != aCutList.size()) tmpstr += ", ";

    if ((aCutList.size() - i) < 3 && ccount == aCutList.size()) {
      pvtxt->AddText(Form(" %s", tmpstr.c_str()));
      tmpstr = "";
    }
  }
  pvtxt->AddText("Counts:");
  pvtxt->AddText(Form("Number of Real (Randoms Subtracted) Coin Events : %.0f", counts[2]));
  pvtxt->AddText(Form("Charge Normalized and Efficiency Corrected Yield : %.1f (1/mC)", normyield));
  pvtxt->AddText(Form("Rate of Good Coin Events : %.4f per CODA event", (double)counts[2]/(double)totevintree));
  sw->Stop();
  if (is_50k) {
    pvtxt->AddText("Predictions");
    pvtxt->AddText("To get \"Extrapolated # good events (this run)\" for the run sheet:");
    pvtxt->AddText(Form("Multiply the rate of good coin events w/ total CODA events, once the run is complete."));
  }
  else {
    pvtxt->AddText(Form("Macro processing time: CPU %.1fs | Real %.1fs", sw->CpuTime(), sw->RealTime()));
  }
    
  // Highlight key lines
  if (TText* t1 = pvtxt->GetLineWith("Run")) t1->SetTextColor(kGreen + 3);
  if (TText* t2 = pvtxt->GetLineWith("Analysis")) t2->SetTextColor(kBlue);
  if (TText* t3 = pvtxt->GetLineWith("Counts")) t3->SetTextColor(kBlue);
  if (TText* t4 = pvtxt->GetLineWith("Predictions")) t4->SetTextColor(kBlue);
  if (TText* t5 = pvtxt->GetLineWith("Rate of Good")) t5->SetTextColor(kRed);
  if (TText* t6 = pvtxt->GetLineWith("To get")) {
    t6->SetTextColor(kGreen + 3);
    t6->SetTextFont(62);
  }
  if (TText* t7 = pvtxt->GetLineWith("Multiply")) t7->SetTextColor(kRed);
  if (TText* t8 = pvtxt->GetLineWith("Macro")) t8->SetTextColor(kGreen+3);
  return pvtxt;
}
//----------------------------------------------------------
void PrintCSVLine(std::ofstream &out, int runnum, std::vector<double> const counts, std::vector<double> const normyield, double * ctfitparams) {
  
  std::ostringstream oss;
  oss << "runnum,coin,randoms,ransubcoin,ransubcoin_err,normyield,normyield_err,";
  oss << "ctmean,ctsigma\n";
  oss << runnum << ","
      << counts[0] << ","
      << counts[1] << ","
      << counts[2] << ","
      << counts[5] << ","        
      << normyield[0] << ","
      << normyield[1] << ","
      << ctfitparams[1] << ","
      << ctfitparams[2];

  out << oss.str() << std::endl;
}

/* extra stuff 


// 1. Path to directory containing input ROOT file
std::string indirroot = "/net/cdaq/cdaql2data/cdaq/hallc-online-rsidis2025/pdbforce/ROOTfiles"; 
// 2. ROOT file name prefix (Convention: <rfprefix>_<runnum>_<nevent>.root)
std::string rfprefix = "coin_replay_production";
// 3. Path to directory containing input report file
std::string indirreport = "/net/cdaq/cdaql2data/cdaq/hallc-online-rsidis2025/pdbforce/REPORT_OUTPUT/COIN/PRODUCTION"; 
// 4. Report file name prefix (Convention: <repfprefix>_<runnum>_<nevent>.report)
std::string repfprefix = "replay_coin_production";  

*/

