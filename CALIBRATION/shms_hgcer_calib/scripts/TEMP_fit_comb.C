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

//Accessories For Method 1
/*
int iparB[num_pars] = {0, 1, 2, 3, 4};
int iparSB[num_pars] = {5, 1, 2, 6, 4};

struct GlobalChi2 {
  GlobalChi2(  ROOT::Math::IMultiGenFunction & f1,
	       ROOT::Math::IMultiGenFunction & f2) :
    fChi2_1(&f1), fChi2_2(&f2) {}

  // parameter vector is first background (in common 1 and 2)
  // and then is signal (only in 2)
  double operator() (const double *par) const {
    double p1[2];
    for (int i = 0; i < 2; ++i) p1[i] = par[iparB[i] ];

    double p2[5];
    for (int i = 0; i < 5; ++i) p2[i] = par[iparSB[i] ];

    return (*fChi2_1)(p1) + (*fChi2_2)(p2);
  }

  const  ROOT::Math::IMultiGenFunction * fChi2_1;
  const  ROOT::Math::IMultiGenFunction * fChi2_2;
};
*/


Double_t multiple_gauss(Double_t *x, Double_t *par)
{
  Double_t result1 = par[0]*exp((-0.5)*((x[0] - par[1])/(par[2]))*((x[0] - par[1])/(par[2])));
  Double_t result2 = par[3]*exp((-0.5)*((x[0] - par[4])/(pow(2, 0.5)*par[2]))*((x[0] - par[4])/(pow(2, 0.5)*par[2])));
  Double_t result3 = par[5]*exp((-0.5)*((x[0] - par[6])/(pow(3, 0.5)*par[2]))*((x[0] - par[6])/(pow(3, 0.5)*par[2])));
  Double_t result4 = par[7]*exp((-0.5)*((x[0] - par[8])/(pow(4, 0.5)*par[2]))*((x[0] - par[8])/(pow(4, 0.5)*par[2])));
  Double_t result5 = par[9]*exp((-0.5)*((x[0] - par[10])/(pow(5, 0.5)*par[2]))*((x[0] - par[10])/(pow(5, 0.5)*par[2])));
  Double_t result6 = par[11]*exp((-0.5)*((x[0] - par[12])/(pow(6, 0.5)*par[2]))*((x[0] - par[12])/(pow(6, 0.5)*par[2])));
  return result1 + result2 + result3 +result4 + result5 + result6;
}


Double_t multiple_gauss_test(Double_t *x, Double_t *par)
{
  Double_t result1 = par[0]*exp((-0.5)*(pow((x[0] - par[1]),2)/pow((par[2]),2)));
  Double_t result2 = par[3]*exp((-0.5)*(pow((x[0] - par[4]),2)/pow((par[5]),2)));
  Double_t result3 = par[6]*exp((-0.5)*(pow((x[0] - par[7]),2)/pow((par[8]),2)));
  Double_t result4 = par[9]*exp((-0.5)*(pow((x[0] - par[10]),2)/pow((par[11]),2)));
  return result1 + result2 + result3 + result4;
}


double linear_function(Double_t *x, Double_t *par)
{
  double linresult = par[1]*x[0] + par[0];
  return linresult;   
} 


void TEMP_fit_comb(Int_t RunNumber=0)
{
  int num_pars = 6;
  int fit_max = 2500;
  int fit_min = 200;

  ofstream fout;
  fout.open("../fit_param.txt");

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
  
  TH1F *hgc_e[4][4]; //[quadrant][PMT]
  TH1F *hgc_pi[4][4];
  TH1F *hgc_sum[4][4];
  
  for (int i=0;i<4;i++) 
    {
      for (int j=0;j<4;j++)
	{
	  hgc_e[i][j] = (TH1F*)F->Get(Form("phgc_quad%d_e%d", i+1, j+1));
	  hgc_pi[i][j] = (TH1F*)F->Get(Form("phgc_quad%d_pi%d", i+1, j+1));
	  hgc_sum[i][j] = (TH1F*)F->Get(Form("phgc_quad%d_sum%d", i+1, j+1));
	}
    }

  //Another Method...Just Add them Up
  gStyle->SetOptFit(111);

  TList *list = new TList;
  list->Add(hgc_e[1][0]);
  list->Add(hgc_e[2][0]);
  list->Add(hgc_e[3][0]);
  TH1F *all = (TH1F*)hgc_sum[1][0]->Clone("all");
  all->Reset();
  all->Merge(list);

  TF1 *f1 = new TF1("f1",multiple_gauss_test,fit_min,fit_max,12);
  f1->SetParameters(500.,500.,200.,198.272,1000.,200.,198.272,1500.,200.);
  f1->SetParameter(9, 198.272);
  f1->SetParameter(10, 2000.);
  f1->SetParameter(11, 200.);
  f1->SetParNames("Amplitude 1","Mean 1","Std. Dev. 1","Amplitude 2","Mean 2","Std. Dev. 2","Amplitude 3","Mean 3","Std. Dev. 3");
  f1->SetParName(9, "Amplitude 4");
  f1->SetParName(10, "Mean 4");
  f1->SetParName(11, "Std. Dev. 4");
  f1->SetParLimits(0, 100., 5000.);
  f1->SetParLimits(3, 100., 5000.);
  f1->SetParLimits(6, 100., 5000.);
  f1->SetParLimits(9, 100., 5000.);


  TCanvas *c0 = new TCanvas("c0","c0");
  all->Fit("f1","REMB");
  gPad->Update();
  //cout << f1->GetChisquare()/f1->GetNDF() << endl;
  if (f1->GetChisquare()/f1->GetNDF() > 2.5 || f1->GetChisquare()/f1->GetNDF() < 0.7)
    {
      cout << "Error: Check fitting limits or number of peaks" << endl;
      break;
    }

  f1->SetParLimits(1, f1->GetParameter(1)- 50, f1->GetParameter(1)+50);
  f1->SetParLimits(4, f1->GetParameter(4)- 50, f1->GetParameter(4)+50);
  f1->SetParLimits(7, f1->GetParameter(7)- 50, f1->GetParameter(7)+50);
  f1->SetParLimits(10, f1->GetParameter(10)- 50, f1->GetParameter(10)+50);

  TF1 *Gauss4 = new TF1("Gauss4",multiple_gauss_test,300,2500,12);
  Gauss4->SetParameters(f1->GetParameter(0),f1->GetParameter(1),f1->GetParameter(2),f1->GetParameter(3),f1->GetParameter(4),f1->GetParameter(5),f1->GetParameter(6),f1->GetParameter(7),f1->GetParameter(8),f1->GetParameter(9));
  Gauss4->SetParameter(10, f1->GetParameter(10));
  Gauss4->SetParameter(11, f1->GetParameter(11));
  Gauss4->SetParLimits(1, f1->GetParameter(1)- 50, f1->GetParameter(1)+50);
  Gauss4->SetParLimits(4, f1->GetParameter(4)- 50, f1->GetParameter(4)+50);
  Gauss4->SetParLimits(7, f1->GetParameter(7)- 50, f1->GetParameter(7)+50);
  Gauss4->SetParLimits(10, f1->GetParameter(10)- 50, f1->GetParameter(10)+50);
  Gauss4->SetParLimits(0, 5., 5000.);
  Gauss4->SetParLimits(3, 5., 5000.);
  Gauss4->SetParLimits(6, 5., 5000.);
  Gauss4->SetParLimits(9, 5., 5000.);
  Gauss4->SetParLimits(2, 0., 1000.);
  Gauss4->SetParLimits(5, 0., 1000.);
  Gauss4->SetParLimits(8, 0., 1000.);
  Gauss4->SetParLimits(11, 0., 1000.);
  Gauss4->SetParNames("Amplitude 1","Mean 1","Std. Dev. 1","Amplitude 2","Mean 2","Std. Dev. 2","Amplitude 3","Mean 3","Std. Dev. 3");
  Gauss4->SetParName(9, "Amplitude 4");
  Gauss4->SetParName(10, "Mean 4");
  Gauss4->SetParName(11, "Std. Dev. 4");

  TF1 *Gauss3 = new TF1("Gauss3",multiple_gauss_test,300,2000,9);
  Gauss3->SetParameters(f1->GetParameter(0),f1->GetParameter(1),f1->GetParameter(2),f1->GetParameter(3),f1->GetParameter(4),f1->GetParameter(5),f1->GetParameter(6),f1->GetParameter(7),f1->GetParameter(8));
  Gauss3->SetParLimits(1, f1->GetParameter(1)- 50, f1->GetParameter(1)+50);
  Gauss3->SetParLimits(4, f1->GetParameter(4)- 50, f1->GetParameter(4)+50);
  Gauss3->SetParLimits(7, f1->GetParameter(7)- 50, f1->GetParameter(7)+50);
  Gauss3->SetParLimits(0, 5., 5000.);
  Gauss3->SetParLimits(3, 5., 5000.);
  Gauss3->SetParLimits(6, 5., 5000.);
  Gauss3->SetParLimits(2, 0., 1000.);
  Gauss3->SetParLimits(5, 0., 1000.);
  Gauss3->SetParLimits(8, 0., 1000.);
  Gauss3->SetParNames("Amplitude 1","Mean 1","Std. Dev. 1","Amplitude 2","Mean 2","Std. Dev. 2","Amplitude 3","Mean 3","Std. Dev. 3");

  TF1 *Gauss2 = new TF1("Gauss2",multiple_gauss_test,300,1350,6);
  Gauss2->SetParameters(f1->GetParameter(0),f1->GetParameter(1),f1->GetParameter(2),f1->GetParameter(3),f1->GetParameter(4),f1->GetParameter(5));
  Gauss2->SetParLimits(1, f1->GetParameter(1)- 50, f1->GetParameter(1)+50);
  Gauss2->SetParLimits(4, f1->GetParameter(4)- 50, f1->GetParameter(4)+50);
  Gauss2->SetParLimits(0, 5., 5000.);
  Gauss2->SetParLimits(3, 5., 5000.);
  Gauss2->SetParLimits(2, 0., 1000.);
  Gauss2->SetParLimits(5, 0., 1000.);
  Gauss2->SetParNames("Amplitude 1","Mean 1","Std. Dev. 1","Amplitude 2","Mean 2","Std. Dev. 2");

  TF1 *Gauss1 = new TF1("Gauss1",multiple_gauss_test,300,700,3);
  Gauss1->SetParameters(f1->GetParameter(0),f1->GetParameter(1),f1->GetParameter(2));
  Gauss1->SetParLimits(1, f1->GetParameter(1)- 50, f1->GetParameter(1)+50);
  Gauss1->SetParLimits(0, 5., 5000.);
  Gauss1->SetParLimits(2, 0., 1000.);
  Gauss1->SetParNames("Amplitude 1","Mean 1","Std. Dev. 1");

  TCanvas *c1 = new TCanvas("c1","c1");
  c1->Divide(2,1);
  c1->cd(1);
  for (int i=1;i<4;i++)
    {
      hgc_e[i][0]->Fit("Gauss4","REMBQ");
      if (Gauss4->GetChisquare()/Gauss4->GetNDF() > 1.5 || Gauss4->GetChisquare()/Gauss4->GetNDF() < 0.85)
	{
	  cout << "Decreasing Peak Numbers for hgc_e[" << i << "][0]" << endl;
	  hgc_e[i][0]->Fit("Gauss3","REMBQ");
	  if (Gauss3->GetChisquare()/Gauss3->GetNDF() > 1.5 || Gauss3->GetChisquare()/Gauss3->GetNDF() < 0.85)
	    {
	      cout << "Decreasing Peak Numbers for hgc_e[" << i << "][0]" << endl;
	      hgc_e[i][0]->Fit("Gauss2","REMBQ");
	      if (Gauss2->GetChisquare()/Gauss2->GetNDF() > 1.5 || Gauss2->GetChisquare()/Gauss2->GetNDF() < 0.85)
		{
		  cout << "Decreasing Peak Numbers for hgc_e[" << i << "][0]" << endl;
		  hgc_e[i][0]->Fit("Gauss1","REMBQ");
		}
	    }	
	}
    }
  hgc_e[1][0]->Draw();
  hgc_e[2][0]->Draw("same");
  hgc_e[3][0]->Draw("same");
  gPad->Update();
  
  c1->cd(2);
  for (int i=1;i<4;i++)
    {
      hgc_pi[i][0]->Fit("Gauss4","REMBQ");
      if (Gauss4->GetChisquare()/Gauss4->GetNDF() > 1.5 || Gauss4->GetChisquare()/Gauss4->GetNDF() < 0.85)
	{
	  cout << "Decreasing Peak Numbers for hgc_pi[" << i << "][0]" << endl;
	  hgc_pi[i][0]->Fit("Gauss3","REMBQ");
	  if (Gauss3->GetChisquare()/Gauss3->GetNDF() > 1.5 || Gauss3->GetChisquare()/Gauss3->GetNDF() < 0.85)
	    {
	      cout << "Decreasing Peak Numbers for hgc_pi[" << i << "][0]" << endl;
	      hgc_pi[i][0]->Fit("Gauss2","REMBQ");
	      if (Gauss2->GetChisquare()/Gauss2->GetNDF() > 1.5 || Gauss2->GetChisquare()/Gauss2->GetNDF() < 0.85)
		{
		  cout << "Decreasing Peak Numbers for hgc_pi[" << i << "][0]" << endl;
		  hgc_pi[i][0]->Fit("Gauss1","REMBQ");
		}
	    }	
	}
    }
  hgc_pi[1][0]->Draw();
  hgc_pi[2][0]->Draw("same");
  hgc_pi[3][0]->Draw("same");
  gPad->Update();



  //Start Of Method 1...........................................
  /********
  TF1 *fB = new TF1("fB",multiple_gauss,fit_min,fit_max,num_pars);
  fB->SetParameters(500.,500.,200.,198.272,1000.);

  TF1 *fS = new TF1("fS",multiple_gauss,fit_min,fit_max,num_pars);
  fS->SetParameters(500.,500.,200.,198.272,1000.);

  // perform now global fit

  //TF1 *fSB = new TF1("fSB","fB + fS",0,100);

  ROOT::Math::WrappedMultiTF1 wfB(*fB,1);
  ROOT::Math::WrappedMultiTF1 wfSB(*fS,1);

  ROOT::Fit::DataOptions opt;
  ROOT::Fit::DataRange rangeB;
  // set the data range
  rangeB.SetRange(0,2000);
  ROOT::Fit::BinData dataB(opt,rangeB);
  ROOT::Fit::FillData(dataB, hgc_sum[1][0]);

  ROOT::Fit::DataRange rangeSB;
  rangeSB.SetRange(0,2000);
  ROOT::Fit::BinData dataSB(opt,rangeSB);
  ROOT::Fit::FillData(dataSB, hgc_sum[2][0]);

  ROOT::Fit::Chi2Function chi2_B(dataB, wfB);
  ROOT::Fit::Chi2Function chi2_SB(dataSB, wfSB);

  GlobalChi2 globalChi2(chi2_B, chi2_SB);

  ROOT::Fit::Fitter fitter;

  const int Npar = 5;
  double par0[Npar] = {};

  // create before the parameter settings in order to fix or set range on them
  //fitter.Config().SetParamsSettings(6,par0);
  // fix parameters
  //fitter.Config().ParSettings(1).Fix();
  //fitter.Config().ParSettings(2).Fix();
  //fitter.Config().ParSettings(4).Fix();
  // set limits on parameters
  //fitter.Config().ParSettings(0).SetLimits(0,2000);
  //fitter.Config().ParSettings(3).SetLimits(0,500);
  //fitter.Config().ParSettings(3).SetStepSize(5);

  fitter.Config().MinimizerOptions().SetPrintLevel(0);
  fitter.Config().SetMinimizer("Minuit","Migrad");

  // fit FCN function directly
  // (specify optionally data size and flag to indicate that is a chi2 fit)
  fitter.FitFCN(5,globalChi2,0,dataB.Size()+dataSB.Size(),true);
  ROOT::Fit::FitResult result = fitter.Result();
  result.Print(std::cout);

  TCanvas * c1 = new TCanvas("Simfit","Simultaneous fit of two histograms",
                             10,10,700,700);
  c1->Divide(1,2);
  c1->cd(1);
  gStyle->SetOptFit(1111);

  fB->SetFitResult( result, iparB);
  fB->SetLineColor(kBlue);
  hgc_sum[2][0]->GetListOfFunctions()->Add(fB);
  hgc_sum[2][0]->Draw();

  c1->cd(2);
  fS->SetFitResult( result, iparSB);
  fS->SetLineColor(kRed);
  hgc_sum[1][0]->GetListOfFunctions()->Add(fS);
  hgc_sum[1][0]->Draw();

 
  */
  //Start Of Method 2........................................
  /*
  TF1 *f1 = new TF1("f1",multiple_gauss,fit_min,fit_max,num_pars);
  f1->SetParameters(500.,500.,200.,198.272,1000.);
  f1->SetParLimits(2,0.,500.);
  f1->SetParNames("Amplitude 1","Mean 1","Std. Dev.","Amplitude 2","Mean 2","Amplitude 3","Mean 3","Amplitude 4","Mean 4","Amplitude 5","Mean 5");
  f1->SetParName(11,"Amplitude 6");
  f1->SetParName(12,"Mean 6");

  TCanvas *c0 = new TCanvas("c0","c0");
  hgc_e[1][0]->Fit("f1","REM");
  gPad->Update();
  

  ROOT::Fit::BinData data;
  ROOT::Fit::FillData(data, hgc_e[1][0]);
  
  for (int i=1;i<4;i++)
    {
      if (hgc_e[i][0]->GetEntries()<5000)
	{
	  cout << "hgc_e[" << i << "][0]" << "has been omitted..." << endl;
	  continue;
	}
      else
	{
	  ROOT::Fit::FillData(data, hgc_e[i][0]);
	}

      if (hgc_pi[i][0]->GetEntries()<5000)
	{
	  cout << "hgc_pi[" << i << "][0]" << "has been omitted..." << endl;
	  continue;
	}
      else
	{
	  ROOT::Fit::FillData(data, hgc_pi[i][0]);
	}
    }
  
  cout << "data size is " << data.Size() << endl;
 
  Double_t p[] = {500.,500.,200.,198.272,1000.};
  ROOT::Math::WrappedMultiTF1 wf(*f1);
  wf.SetParameters(p);

  ROOT::Fit::Fitter fitter;
  fitter.SetFunction(wf);

  fitter.Fit(data);
  ROOT::Fit::FitResult result = fitter.Result();
  result.Print(std::cout);

  f1->FixParameter(1, result.Parameter(1));
  f1->FixParameter(2, result.Parameter(2));
  f1->FixParameter(4, result.Parameter(4));
  f1->FixParameter(6, result.Parameter(6));
  f1->FixParameter(8, result.Parameter(8));
  f1->FixParameter(10, result.Parameter(10));
  f1->FixParameter(12, result.Parameter(12));

  cout << hgc_e[1][0]->GetListOfFunctions() << endl;

  TCanvas *c2 = new TCanvas("c2","c2");
  c2->cd(1);
  //hgc_e[1][0]->Draw("hist");
  //hgc_e[1][0]->Fit("f1","REM+");
  hgc_e[3][0]->Fit("f1","REM","same");
  hgc_pi[1][0]->Fit("f1","REM","same");
  hgc_e[2][0]->Fit("f1","REM","same");
  hgc_pi[2][0]->Fit("f1","REM","same");
  hgc_pi[3][0]->Fit("f1","REM","same");
  
  
  TCanvas *c1 = new TCanvas("c1","Fit Results");
  c1->Divide(3,1);
  c1->cd(1);
  hgc_e[1][0]->Fit("f1", "RE");
  hgc_pi[1][0]->Fit("f1","RE");
  hgc_e[1][0]->Draw();
  hgc_pi[1][0]->Draw("same");
  c1->cd(2);
  hgc_e[2][0]->Fit("f1","RE");
  hgc_pi[2][0]->Fit("f1","RE");
  hgc_e[2][0]->Draw();
  hgc_pi[2][0]->Draw("same");
  c1->cd(3);
  hgc_e[3][0]->Fit("f1","RE");
  hgc_pi[3][0]->Fit("f1","RE");
  hgc_e[3][0]->Draw();
  hgc_pi[3][0]->Draw("same");
  */
}
