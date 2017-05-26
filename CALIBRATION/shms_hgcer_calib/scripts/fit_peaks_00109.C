#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TStyle.h>
#include <TChain.h>
#include <TPostScript.h>
#include <TLatex.h>
#include <TMath.h>
#include <TPaveLabel.h>
#include <TGraphErrors.h>

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

Double_t multiple_gauss(Double_t *x, Double_t *par)
{
  Double_t result1 = par[0]*exp((-0.5)*((x[0] - par[1])/(par[2]))*((x[0] - par[1])/(par[2])));
  Double_t result2 = par[3]*exp((-0.5)*((x[0] - par[4])/(pow(2, 0.5)*par[2]))*((x[0] - par[4])/(pow(2, 0.5)*par[2])));
  Double_t result3 = par[5]*exp((-0.5)*((x[0] - par[6])/(pow(3, 0.5)*par[2]))*((x[0] - par[6])/(pow(3, 0.5)*par[2])));
  Double_t result4 = par[7]*exp((-0.5)*((x[0] - par[8])/(pow(4, 0.5)*par[2]))*((x[0] - par[8])/(pow(4, 0.5)*par[2])));
  Double_t result5 = par[9]*exp((-0.5)*((x[0] - par[10])/(pow(5, 0.5)*par[2]))*((x[0] - par[10])/(pow(5, 0.5)*par[2])));
  Double_t result6 = par[11]*exp((-0.5)*((x[0] - par[12])/(pow(6, 0.5)*par[2]))*((x[0] - par[12])/(pow(6, 0.5)*par[2])));
  return result1 + result2 + result3 + result4;
}

double linear_function(Double_t *x, Double_t *par)
{
  double result3 = par[1]*x[0] + par[0];
  return result3;   
} 

void fit_peaks_00109()
{
  string run_number = "488";
  string voltage = "2200";
  string spectrum_name = "PMT " + voltage + "V";
  const int num_pars = 9;
  const int fit_max = 6000;
  const int fit_min = 200;

  string graph_title = "Gain (ch. per electron) of " + spectrum_name;

  string postscript_filename = "run" + run_number + "_peak_fits.ps";
  string gain_filename = "run" + run_number + "_gain.ps";
  string vec_filename = "run" + run_number + ".vec";

  TFile *F = new TFile("../root_files/shms_calibration.root");
  TH1F *ADC0 = (TH1F*)F->Get("hgc_quad1_e1");
  ADC0->GetXaxis()->SetTitle("ADC channels");
  ADC0->GetYaxis()->SetTitle("Counts");
  ADC0->GetYaxis()->SetTitleOffset(1.4);
  ADC0->GetYaxis()->SetNdivisions(408,kTRUE);
  ADC0->SetLineColor(4);
  ADC0->SetFillStyle(1001);
  ADC0->SetFillColor(kBlue-7);
  

//************************************************************************************

//Canvas Definition  
  TCanvas *c1 = new TCanvas("c1", " c1",12,29,699,599);
  c1->SetBorderMode(0);
  gStyle->SetOptFit(100);
  gStyle->SetOptStat(0);
  gStyle-> SetStatFontSize(0.004);
  gStyle-> SetStatW(0.15);
  gStyle-> SetStatX(0.9);
  gStyle-> SetStatY(0.9);


///////////////////////////////////////////////////////////////////////////////////////////
//Postscript Drawing
TPostScript ps(postscript_filename.c_str(),-113);
  c1->Update();  
  ps.NewPage();

  c1->cd(1);
   gPad->SetGridy();
   gPad->SetGridx();
   gPad->SetFillColor(0);

  TF1 *fit_function = new TF1("fit_function",multiple_gauss,fit_min,fit_max,num_pars);
   fit_function->SetNpx(200000);

   fit_function->SetParName(0,"Amplitude 1");
   fit_function->SetParName(1,"Mean 1");
   fit_function->SetParName(2,"Std. Dev.");
   fit_function->SetParName(3,"Amplitude 2");
   fit_function->SetParName(4,"Mean 2");
   fit_function->SetParName(5,"Amplitude 3");
   fit_function->SetParName(6,"Mean 3");
   fit_function->SetParName(7,"Amplitude 4");
   fit_function->SetParName(8,"Mean 4");

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// set initial values for parameters
   fit_function->SetParameter(0,369.258);
   fit_function->SetParameter(1,443.711);
   fit_function->SetParameter(2,107.568);

   fit_function->SetParameter(3,198.272);
   fit_function->SetParameter(4,868.061);
   
   fit_function->SetParameter(5,500.);
   fit_function->SetParameter(6,1300.);
   
   fit_function->SetParameter(7,100.);
   fit_function->SetParameter(8,1700.);
   
   fit_function->SetLineColor(2);
   fit_function->SetLineWidth(2.);

   ADC0->Fit("fit_function", "MRE");
   float root_chi = pow(fit_function->GetChisquare(), 0.5);
   float x[] = {1,2,3};
   float y[] = {static_cast<float>(fit_function->GetParameter(1)),static_cast<float>(fit_function->GetParameter(4)),static_cast<float>(fit_function->GetParameter(6))};
   float yerr[] = {static_cast<float>(fit_function->GetParError(1)*root_chi), static_cast<float>(fit_function->GetParError(4)*root_chi), static_cast<float>(fit_function->GetParError(6)*root_chi)};
   float *xerr = NULL;  
   cout << "Chi^2/NDF: " << fit_function->GetChisquare()/fit_function->GetNDF() << endl;
   ADC0->Draw();

  ps.Close();   






///////////////////////////////////////////////////////////////////////////////////////////
//compute gain in ch/electron


  TCanvas *c2 = new TCanvas("c2","c2",12,29,899,599);
  c2->SetBorderMode(0);
  gStyle->SetOptStat(0);
  gStyle-> SetStatY(0.5);

//Postscript Drawing
  TPostScript ps2(gain_filename.c_str(),-113);
  c2->Update();  
  ps2.NewPage();

  c2->cd(1);  
  gPad->SetGridy();
  gPad->SetGridx();
  gPad->SetFillColor(0);
   
  TGraphErrors *gain_graph = new TGraphErrors(3.,x,y,xerr,yerr);
  gain_graph->SetTitle(graph_title.c_str());
  gain_graph->GetXaxis()->SetTitle("Photoelectrons");
  gain_graph->GetXaxis()->SetLimits(0.,4.);
  gain_graph->SetMinimum(0.);
  gain_graph->SetMaximum(1.2*y[2]);
  gain_graph->GetYaxis()->SetTitle("Mean ADC channel");
  gain_graph->SetMarkerColor(4);
  gain_graph->SetLineColor(4);
  gain_graph->SetMarkerStyle(20);
  gain_graph->SetMarkerSize(0.5);

  TF1 *linear_fit = new TF1("linear_fit",linear_function,0,4,2);
  linear_fit->SetParName(0, "Y-intercept");
  linear_fit->SetParName(1, "Slope");
  linear_fit->SetLineColor(2);
  linear_fit->SetNpx(100000);

  gStyle->SetOptFit(110);
  gStyle->SetOptStat(1110);
  gain_graph->Fit("linear_fit","MRE");

  cout << "Chi^2/NDF: " << linear_fit->GetChisquare()/linear_fit->GetNDF() << endl;
  gain_graph->Draw("AP");	

  ofstream outfile;
  outfile.open(vec_filename.c_str());
  outfile << "run" << run_number << " " << voltage << " " << "Gain: " << linear_fit->GetParameter(1) << " +/- " 
          << linear_fit->GetParError(1) << " Chi^2/NDF: " << linear_fit->GetChisquare()/linear_fit->GetNDF() << endl;

	ps2.Close();   

}
