#include "Fit/Fitter.h"
#include "Fit/BinData.h"
#include "Fit/Chi2FCN.h"
#include "TH1.h"
#include "TList.h"
#include "Math/WrappedMultiTF1.h"
#include "HFitInterface.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TFile.h"
/*
par[0] = scale
par[1] = std. dev
par[2] = mean
par[3] = v_1
par[4] = alpha_2
par[5] = v2/v1
par[6] = alpha3/(1-alpha2)
par[7] = v3/v1
par[8] = epsilon
 */

Double_t Degtiarenko_function(Double_t *x, Double_t *par)
{
  Double_t Degtiarenko;
  Double_t Gaussian;
  Double_t Poisson;
  
  for (Int_t i=0; i<1; i++)
    {

      Gaussian = (par[0]/(pow(2*TMath::Pi(),0.5)*par[1]))*exp(-0.5*(pow(x[0]-par[2],2))/(pow(par[1],2)));

      //Gaussian = 1/(pow(2*TMath::Pi(),0.5)*pow((par[1]/par[0])**2+i/(pow(par[3]*(1+par[5]*(par[4]/(1-par[4]))+par[6]*(par[7]-1)),2)*par[8]),0.5)) * exp(-pow(x[0] - i/(par[3]*(1+par[5]*(par[4]/(1-par[4]))+par[6]*(par[7]-1))),2)/(2*pow((par[1]/par[0])**2+i/(pow(par[3]*(1+par[5]*(par[4]/(1-par[4]))+par[6]*(par[7]-1)),2)*par[8]),1)));

      Poisson = exp(-par[2])*pow(par[3]*(1+par[5]*(par[4]/(1-par[4]))+par[6]*(par[7]-1)),i)*exp(-par[3]*(1+par[5]*(par[4]/(1-par[4])) + par[6]*(par[7]-1)))/TMath::Factorial(i);

      for (Int_t j=0; j<20; j++)
	{
	Poisson +=  (pow(par[2],j)*exp(-par[2]))/TMath::Factorial(j) * (pow(j*par[3]*(1+par[5]*(par[4]/(1-par[4]))+par[6]*(par[7]-1)),i)*exp(-j*par[3]*(1+par[5]*(par[4]/(1-par[4]))+par[6]*(par[7]-1))))/TMath::Factorial(i);
	}
      Degtiarenko += Gaussian * Poisson;
    }
  return Gaussian;
}



void Degtiarenko_fit(Int_t RunNumber=0)
{
  int num_pars = 9;
  int fit_max = 60;
  int fit_min = 10;

  if (RunNumber == 0)
    {
      cout << "Enter a Run Number (-1 to exit): ";
      cin >> RunNumber;  
      if (RunNumber <= 0) return;
      else TFile *F = new TFile(Form("../root_files/shms_calibration_%d.root", RunNumber));
    }

  TH1F *hgc_sum[4]; //[PMT]
  
  for (int i=0;i<4;i++) 
    {
      hgc_sum[i] = (TH1F*)F->Get(Form("phgc_adcPulseAmp%d", i+1));
    }

  TF1 *f1 = new TF1("f1", Degtiarenko_function, fit_min, fit_max, 9);
  f1->SetParNames("scale","std. dev","mean","v_1","alpha_2","v2/v1","alpha3/(1-alpha2)","v3/v1","epsilon");
  f1->SetParameters(0.2*10**7, 10, 30, 1, 0.95, 0.95, 0.95, 0.95, 100);
  f1->SetParLimits(0, 0., 9999999999999.);
  f1->SetParLimits(1, 0., 9999999999999.);
  f1->SetParLimits(2, 0., 9999999999999.);
  f1->SetParLimits(3, 0., 9999999999999.);
  f1->SetParLimits(4, 0., 1.);
  f1->SetParLimits(5, 0., 1.);
  f1->SetParLimits(6, 0., 1.);
  f1->SetParLimits(7, 0., 1.);
  f1->SetParLimits(8, 1., 9999999999999.);


  TCanvas *c0 = new TCanvas("c0", "TEST");
  //f1->Draw();
  //hgc_sum[0]->Draw("same");
  hgc_sum[0]->Fit("f1","RM");
  gPad->Update();


}
