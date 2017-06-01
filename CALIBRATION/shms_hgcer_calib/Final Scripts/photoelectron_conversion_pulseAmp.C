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



Double_t multiple_gauss_test(Double_t *x, Double_t *par)
{
  Double_t result1 = par[0]*exp((-0.5)*(pow((x[0] - par[1]),2)/pow((par[2]),2)));
  Double_t result2 = par[3]*exp((-0.5)*(pow((x[0] - par[4]),2)/pow((par[5]),2)));
  Double_t result3 = par[6]*exp((-0.5)*(pow((x[0] - par[7]),2)/pow((par[8]),2)));
  Double_t result4 = par[9]*exp((-0.5)*(pow((x[0] - par[10]),2)/pow((par[11]),2)));
  Double_t result5 = par[12]*exp((-0.5)*(pow((x[0] - par[13]),2)/pow((par[14]),2)));
  return result1 + result2 + result3 + result4 + result5;
}

Double_t pedistal(Double_t *x, Double_t *par)
{
  Double_t ped_result =  par[0]*exp((-0.5)*(pow((x[0] - par[1]),2)/pow((par[2]),2)));
  return ped_result;
}


double linear_function(Double_t *x, Double_t *par)
{
  double linresult = par[1]*x[0] + par[0];
  return linresult;   
} 


void photoelectron_conversion_pulseAmp(Int_t RunNumber=0)
{

  if (RunNumber == 0)
    {
      cout << "Enter a Run Number (-1 to exit): ";
      cin >> RunNumber;
      if (RunNumber == -2) 
	{
	  TFile *F = new TFile("../root_files/old_hcana/shms_calibration_several.root");
	}
      else if (RunNumber <= 0) return;
      else TFile *F = new TFile(Form("../root_files/shms_calibration_%d.root", RunNumber));
    }
  
  TH1F *hgc_sum[4];
  TH1F *hgc_cuts[4];
  TH1F *hgc_off[4][4]; //[pmt][quadrant]
  TList *list = new TList;
  list->Clear("");
  for (int i=0;i<4;i++)
    {
      hgc_sum[i] = (TH1F*)F->Get(Form("phgc_adcPulseAmp%d",i+1));
      hgc_cuts[i] = (TH1F*)F->Get(Form("phgc_quad%d_pulseAmp_sum%d",i+1,i+1));
      for (int j=0;j<4;j++)
	{
	  hgc_off[i][j] = (TH1F*)F->Get(Form("phgc_quad%d_pulseAmp_sum%d",j+1,i+1));
	}
    }
 
  list->Add(hgc_off[0][1]);
  list->Add(hgc_off[0][2]);
  list->Add(hgc_off[0][3]);

  TH1F *all = (TH1F*)hgc_off[0][1]->Clone("all");
  all->Reset();
  all->Merge(list);

  TF1 *fped = new TF1("fped",pedistal,3,60,3);
  fped->SetParNames("Amplitude", "Mean", "Std. Dev.");
  fped->SetParameters(10000.,150.,44.);
  fped->SetParLimits(0, 0., 1000000.);
  fped->SetParLimits(1, 0., 50.);
  fped->SetParLimits(2, 0., 100.);
  
  TF1 *fgaus = new TF1("fgaus", multiple_gauss_test,50,3500,9);
  fgaus->SetParNames("Amplitude 1", "Mean 1", "Std. Dev. 1","Amplitude 2","Mean 2","Std. Dev. 2","Amplitude 3","Mean 3","Std. Dev. 3");
  fgaus->SetParameters(1244., 141., 31., 847., 270., 612., 500., 400., 1000.);
  fgaus->SetParLimits(0, 0., 100000.);
  fgaus->SetParLimits(1, 80., 170.);
  fgaus->SetParLimits(2, 30., 100.);
  fgaus->SetParLimits(3, 0., 100000.);
  fgaus->SetParLimits(4, 200., 1000.);
  fgaus->SetParLimits(5, 30., 1000.);
  fgaus->SetParLimits(6, 0., 100000.);
  fgaus->SetParLimits(7, 350., 4000.);
  fgaus->SetParLimits(8, 30., 2000.);

  TCanvas *c2 = new TCanvas("c2", "Another");
  c2->SetLogy();
  all->Draw("same");
  all->Fit("fped","REM+same");
  all->Fit("fgaus","REM+same");
  all->SetAxisRange(0., 4000., "X");
  gPad->Update();
  
  TCanvas *c1 = new TCanvas("c1", "Que?");
  c1->Divide(2,2);
  for (int i=0;i<4;i++)
    {
      c1->cd(i+1)->SetLogy();
      hgc_cuts[i]->Fit("fped","REM+same");
      hgc_cuts[i]->Fit("fgaus","REM+same");
      hgc_cuts[i]->SetAxisRange(0., 4000., "X");
      gPad->Update();
    }
  
  TCanvas *c0 = new TCanvas("c0","Whatever");
  c0->Divide(2,2);
  for (int i=0; i<4; i++)
    {
      c0->cd(i+1)->SetLogy();
      hgc_sum[i]->Draw("same");
      hgc_sum[i]->Fit("fped","REM+same");
      hgc_sum[i]->Fit("fgaus","REM+same");
      hgc_sum[i]->SetAxisRange(0., 4000., "X");
      gPad->Update();
    }

}
