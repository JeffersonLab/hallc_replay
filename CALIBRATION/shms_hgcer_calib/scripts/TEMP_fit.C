Double_t multiple_gauss(Double_t *x, Double_t *par)
{
  Double_t result1 = par[0]*exp((-0.5)*((x[0] - par[1])/(par[2]))*((x[0] - par[1])/(par[2])));
  Double_t result2 = par[3]*exp((-0.5)*((x[0] - par[4])/(pow(2, 0.5)*par[2]))*((x[0] - par[4])/(pow(2, 0.5)*par[2])));
  Double_t result3 = par[5]*exp((-0.5)*((x[0] - par[6])/(pow(3, 0.5)*par[2]))*((x[0] - par[6])/(pow(3, 0.5)*par[2])));
  Double_t result4 = par[7]*exp((-0.5)*((x[0] - par[8])/(pow(4, 0.5)*par[2]))*((x[0] - par[8])/(pow(4, 0.5)*par[2])));
  Double_t result5 = par[9]*exp((-0.5)*((x[0] - par[10])/(pow(5, 0.5)*par[2]))*((x[0] - par[10])/(pow(5, 0.5)*par[2])));
  Double_t result6 = par[11]*exp((-0.5)*((x[0] - par[12])/(pow(6, 0.5)*par[2]))*((x[0] - par[12])/(pow(6, 0.5)*par[2])));
  return result1 + result2;
}

double linear_function(Double_t *x, Double_t *par)
{
  double linresult = par[1]*x[0] + par[0];
  return linresult;   
} 

void TEMP_fit(Int_t RunNumber=0)
{
  ofstream fout;
  fout.open("../fit_param.txt");

  const int num_pars = 5;
  const int fit_max = 1300;
  const int fit_min = 200;

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

  
  //TFile *F = new TFile("../root_files/shms_calibration_several.root");
  
  TH1F *hgc_quad1_e[4];
  TH1F *hgc_quad1_pi[4];
  TH1F *hgc_quad1_sum[4];

  TH1F *hgc_quad2_e[4];
  TH1F *hgc_quad2_pi[4];
  TH1F *hgc_quad2_sum[4];

  TH1F *hgc_quad3_e[4];
  TH1F *hgc_quad3_pi[4];
  TH1F *hgc_quad3_sum[4];

  TH1F *hgc_quad4_e[4];
  TH1F *hgc_quad4_pi[4];
  TH1F *hgc_quad4_sum[4];

  
  hgc_quad1_e[0] = (TH1F*)F->Get("phgc_quad1_e1");
  hgc_quad1_e[1] = (TH1F*)F->Get("phgc_quad1_e2");
  hgc_quad1_e[2] = (TH1F*)F->Get("phgc_quad1_e3");
  hgc_quad1_e[3] = (TH1F*)F->Get("phgc_quad1_e4");
  hgc_quad1_pi[0] = (TH1F*)F->Get("phgc_quad1_pi1");
  hgc_quad1_pi[1] = (TH1F*)F->Get("phgc_quad1_pi2");
  hgc_quad1_pi[2] = (TH1F*)F->Get("phgc_quad1_pi3");
  hgc_quad1_pi[3] = (TH1F*)F->Get("phgc_quad1_pi4");
  hgc_quad1_sum[0] = (TH1F*)F->Get("phgc_quad1_sum1");
  hgc_quad1_sum[1] = (TH1F*)F->Get("phgc_quad1_sum2");
  hgc_quad1_sum[2] = (TH1F*)F->Get("phgc_quad1_sum3");
  hgc_quad1_sum[3] = (TH1F*)F->Get("phgc_quad1_sum4");

  hgc_quad2_e[0] = (TH1F*)F->Get("phgc_quad2_e1");
  hgc_quad2_e[1] = (TH1F*)F->Get("phgc_quad2_e2");
  hgc_quad2_e[2] = (TH1F*)F->Get("phgc_quad2_e3");
  hgc_quad2_e[3] = (TH1F*)F->Get("phgc_quad2_e4");
  hgc_quad2_pi[0] = (TH1F*)F->Get("phgc_quad2_pi1");
  hgc_quad2_pi[1] = (TH1F*)F->Get("phgc_quad2_pi2");
  hgc_quad2_pi[2] = (TH1F*)F->Get("phgc_quad2_pi3");
  hgc_quad2_pi[3] = (TH1F*)F->Get("phgc_quad2_pi4");
  hgc_quad2_sum[0] = (TH1F*)F->Get("phgc_quad2_sum1");
  hgc_quad2_sum[1] = (TH1F*)F->Get("phgc_quad2_sum2");
  hgc_quad2_sum[2] = (TH1F*)F->Get("phgc_quad2_sum3");
  hgc_quad2_sum[3] = (TH1F*)F->Get("phgc_quad2_sum4");

  hgc_quad3_e[0] = (TH1F*)F->Get("phgc_quad3_e1");
  hgc_quad3_e[1] = (TH1F*)F->Get("phgc_quad3_e2");
  hgc_quad3_e[2] = (TH1F*)F->Get("phgc_quad3_e3");
  hgc_quad3_e[3] = (TH1F*)F->Get("phgc_quad3_e4");
  hgc_quad3_pi[0] = (TH1F*)F->Get("phgc_quad3_pi1");
  hgc_quad3_pi[1] = (TH1F*)F->Get("phgc_quad3_pi2");
  hgc_quad3_pi[2] = (TH1F*)F->Get("phgc_quad3_pi3");
  hgc_quad3_pi[3] = (TH1F*)F->Get("phgc_quad3_pi4");
  hgc_quad3_sum[0] = (TH1F*)F->Get("phgc_quad3_sum1");
  hgc_quad3_sum[1] = (TH1F*)F->Get("phgc_quad3_sum2");
  hgc_quad3_sum[2] = (TH1F*)F->Get("phgc_quad3_sum3");
  hgc_quad3_sum[3] = (TH1F*)F->Get("phgc_quad3_sum4");

  hgc_quad4_e[0] = (TH1F*)F->Get("phgc_quad4_e1");
  hgc_quad4_e[1] = (TH1F*)F->Get("phgc_quad4_e2");
  hgc_quad4_e[2] = (TH1F*)F->Get("phgc_quad4_e3");
  hgc_quad4_e[3] = (TH1F*)F->Get("phgc_quad4_e4");
  hgc_quad4_pi[0] = (TH1F*)F->Get("phgc_quad4_pi1");
  hgc_quad4_pi[1] = (TH1F*)F->Get("phgc_quad4_pi2");
  hgc_quad4_pi[2] = (TH1F*)F->Get("phgc_quad4_pi3");
  hgc_quad4_pi[3] = (TH1F*)F->Get("phgc_quad4_pi4");
  hgc_quad4_sum[0] = (TH1F*)F->Get("phgc_quad4_sum1");
  hgc_quad4_sum[1] = (TH1F*)F->Get("phgc_quad4_sum2");
  hgc_quad4_sum[2] = (TH1F*)F->Get("phgc_quad4_sum3");
  hgc_quad4_sum[3] = (TH1F*)F->Get("phgc_quad4_sum4");


  //Rebin the data to be more coarse
  /*
  hgc_quad2_e[0]->Rebin(2);
  hgc_quad2_pi[0]->Rebin(2);
  hgc_quad3_e[0]->Rebin(2);
  hgc_quad3_pi[0]->Rebin(2);
  hgc_quad4_e[0]->Rebin(2);
  hgc_quad4_pi[0]->Rebin(2);

  hgc_quad2_e[1]->Rebin(2);
  hgc_quad2_pi[1]->Rebin(2);
  hgc_quad3_e[1]->Rebin(2);
  hgc_quad3_pi[1]->Rebin(2);
  hgc_quad4_e[1]->Rebin(2);
  hgc_quad4_pi[1]->Rebin(2);

  hgc_quad2_e[2]->Rebin(2);
  hgc_quad2_pi[2]->Rebin(2);
  hgc_quad3_e[2]->Rebin(2);
  hgc_quad3_pi[2]->Rebin(2);
  hgc_quad4_e[2]->Rebin(2);
  hgc_quad4_pi[2]->Rebin(2);

  hgc_quad2_e[3]->Rebin(2);
  hgc_quad2_pi[3]->Rebin(2);
  hgc_quad3_e[3]->Rebin(2);
  hgc_quad3_pi[3]->Rebin(2);
  hgc_quad4_e[3]->Rebin(2);
  hgc_quad4_pi[3]->Rebin(2);
  */

  //Fitting Function
  TF1 *fit_function_e = new TF1("fit_function_e",multiple_gauss,fit_min,fit_max,num_pars);
   fit_function_e->SetNpx(200000);

   fit_function_e->SetParName(0,"Amplitude 1");
   fit_function_e->SetParName(1,"Mean 1");
   fit_function_e->SetParName(2,"Std. Dev.");
   fit_function_e->SetParName(3,"Amplitude 2");
   fit_function_e->SetParName(4,"Mean 2");
   fit_function_e->SetParName(5,"Amplitude 3");
   fit_function_e->SetParName(6,"Mean 3");
   fit_function_e->SetParName(7,"Amplitude 4");
   fit_function_e->SetParName(8,"Mean 4");

// set initial values for parameters
   fit_function_e->SetParameter(0,500.);
   fit_function_e->SetParameter(1,500.);
   fit_function_e->SetParLimits(1,fit_min,fit_max);
   fit_function_e->SetParameter(2,200.);

   fit_function_e->SetParameter(3,198.272);
   fit_function_e->SetParameter(4,1000.);
   fit_function_e->SetParLimits(4,fit_min,fit_max);
   
   fit_function_e->SetParameter(5,500.);
   fit_function_e->SetParameter(6,1500.);
   fit_function_e->SetParLimits(6,fit_min,fit_max);
   
   fit_function_e->SetParameter(7,100.);
   fit_function_e->SetParameter(8,2000.);
   fit_function_e->SetParLimits(8,fit_min,fit_max);
   
   fit_function_e->SetLineColor(2);
   fit_function_e->SetLineWidth(2.);

   TF1 *fit_function_pi = new TF1("fit_function_pi",multiple_gauss,fit_min,fit_max,num_pars);
   fit_function_pi->SetNpx(200000);

   fit_function_pi->SetParName(0,"Amplitude 1");
   fit_function_pi->SetParName(1,"Mean 1");
   fit_function_pi->SetParName(2,"Std. Dev.");
   fit_function_pi->SetParName(3,"Amplitude 2");
   fit_function_pi->SetParName(4,"Mean 2");
   fit_function_pi->SetParName(5,"Amplitude 3");
   fit_function_pi->SetParName(6,"Mean 3");
   fit_function_pi->SetParName(7,"Amplitude 4");
   fit_function_pi->SetParName(8,"Mean 4");

// set initial values for parameters
   fit_function_pi->SetParameter(0,200.);
   fit_function_pi->SetParameter(1,500.);
   fit_function_pi->SetParLimits(1,fit_min,fit_max);
   fit_function_pi->SetParameter(2,200.);

   fit_function_pi->SetParameter(3,198.272);
   fit_function_pi->SetParameter(4,1000.);
   fit_function_pi->SetParLimits(4,fit_min,fit_max);
   
   fit_function_pi->SetParameter(5,500.);
   fit_function_pi->SetParameter(6,1500.);
   fit_function_pi->SetParLimits(6,fit_min,fit_max);
   
   fit_function_pi->SetParameter(7,100.);
   fit_function_pi->SetParameter(8,2000.);
   fit_function_pi->SetParLimits(8,fit_min,fit_max);
   
   fit_function_pi->SetLineColor(2);
   fit_function_pi->SetLineWidth(2.);

   //Linear Gain Matching graph
   Double_t x_1[100], y_1[100], y_1err[100];
   Double_t x_2[100], y_2[100], y_2err[100];
   Double_t x_3[100], y_3[100], y_3err[100];
   Double_t x_4[100], y_4[100], y_4err[100];

   Double_t x_err[100] = NULL;

   Int_t n = 18;
   
   float root_chi_e, root_chi_pi;

   TSpectrum *s = new TSpectrum(2);

   TCanvas *PMT1_off = new TCanvas("PMT1_off", "Fit of off-diagonal for PMT1", 1200, 600);
   PMT1_off->Divide(3,1);
  
   PMT1_off->cd(1);
   hgc_quad2_e[0]->SetLineColor(4);
   hgc_quad2_e[0]->GetXaxis()->SetRangeUser(0,6000);
   hgc_quad2_pi[0]->SetLineColor(8);
   hgc_quad2_pi[0]->GetXaxis()->SetRangeUser(0,6000);
   s->Search(hgc_quad2_e[0],2.5,"",0.10);
   s->Search(hgc_quad2_pi[0],2.5,"",0.10);
   hgc_quad2_e[0]->Fit("fit_function_e", "RE");
   hgc_quad2_pi[0]->Fit("fit_function_pi", "RE");
   hgc_quad2_e[0]->Draw();
   hgc_quad2_pi[0]->Draw("same");

   fout << "PMT1, Quad2, e" << endl;
   fout << pow(fit_function_e->GetChisquare(), 0.5) << '  ' << fit_function_e->GetParameter(1) << '  ' << fit_function_e->GetParameter(4) << '  ' << fit_function_e->GetParameter(6) << endl;

   fout << endl << "PMT1, Quad2, pi" << endl;
   fout << pow(fit_function_pi->GetChisquare(), 0.5) << '  ' << fit_function_pi->GetParameter(1) << '  ' << fit_function_pi->GetParameter(4) << '  ' << fit_function_pi->GetParameter(6) << endl;

   root_chi_e = pow(fit_function_e->GetChisquare(), 0.5);
   root_chi_pi = pow(fit_function_pi->GetChisquare(), 0.5);

   x_1[0] = 1, y_1[0] = fit_function_e->GetParameter(1), y_1err[0] = fit_function_e->GetParError(1)*root_chi_e;
   x_1[1] = 1, y_1[1] = fit_function_pi->GetParameter(1), y_1err[1] = fit_function_pi->GetParError(1)*root_chi_pi;
   x_1[2] = 2, y_1[2] = fit_function_e->GetParameter(4), y_1err[2] = fit_function_e->GetParError(4)*root_chi_e;
   x_1[3] = 2, y_1[3] = fit_function_pi->GetParameter(4), y_1err[3] = fit_function_pi->GetParError(4)*root_chi_pi;
   x_1[4] = 3, y_1[4] = fit_function_e->GetParameter(6), y_1err[4] = fit_function_e->GetParError(6)*root_chi_e;
   x_1[5] = 3, y_1[5] = fit_function_pi->GetParameter(6), y_1err[5] = fit_function_pi->GetParError(6)*root_chi_pi;

   PMT1_off->cd(2);
   hgc_quad3_e[0]->SetLineColor(4);
   hgc_quad3_e[0]->GetXaxis()->SetRangeUser(0,6000);
   hgc_quad3_pi[0]->SetLineColor(8);
   hgc_quad3_pi[0]->GetXaxis()->SetRangeUser(0,6000);
   s->Search(hgc_quad3_e[0],2.5,"",0.10);
   s->Search(hgc_quad3_pi[0],2.5,"",0.10);
   hgc_quad3_e[0]->Fit("fit_function_e", "RE");
   hgc_quad3_pi[0]->Fit("fit_function_pi", "RE");
   hgc_quad3_e[0]->Draw();
   hgc_quad3_pi[0]->Draw("same");

   fout << endl << "PMT1, Quad3, e" << endl;
   fout << pow(fit_function_e->GetChisquare(), 0.5) << '  ' << fit_function_e->GetParameter(1) << '  ' << fit_function_e->GetParameter(4) << '  ' << fit_function_e->GetParameter(6) << endl;

   fout << endl << "PMT1, Quad3, pi" << endl;
   fout << pow(fit_function_pi->GetChisquare(), 0.5) << '  ' << fit_function_pi->GetParameter(1) << '  ' << fit_function_pi->GetParameter(4) << '  ' << fit_function_pi->GetParameter(6) << endl;

   root_chi_e = pow(fit_function_e->GetChisquare(), 0.5);
   root_chi_pi = pow(fit_function_pi->GetChisquare(), 0.5);

   x_1[6] = 1, y_1[6] = fit_function_e->GetParameter(1), y_1err[6] = fit_function_e->GetParError(1)*root_chi_e;
   x_1[7] = 1, y_1[7] = fit_function_pi->GetParameter(1), y_1err[7] = fit_function_pi->GetParError(1)*root_chi_pi;
   x_1[8] = 2, y_1[8] = fit_function_e->GetParameter(4), y_1err[8] = fit_function_e->GetParError(4)*root_chi_e;
   x_1[9] = 2, y_1[9] = fit_function_pi->GetParameter(4), y_1err[9] = fit_function_pi->GetParError(4)*root_chi_pi;
   x_1[10] = 3, y_1[10] = fit_function_e->GetParameter(6), y_1err[10] = fit_function_e->GetParError(6)*root_chi_e;
   x_1[11] = 3, y_1[11] = fit_function_pi->GetParameter(6), y_1err[11] = fit_function_pi->GetParError(6)*root_chi_pi;

   PMT1_off->cd(3);
   hgc_quad4_e[0]->SetLineColor(4);
   hgc_quad4_e[0]->GetXaxis()->SetRangeUser(0,6000);
   hgc_quad4_pi[0]->SetLineColor(8);
   hgc_quad4_pi[0]->GetXaxis()->SetRangeUser(0,6000);
   s->Search(hgc_quad4_e[0],2.5,"",0.10);
   s->Search(hgc_quad4_pi[0],2.5,"",0.10);
   hgc_quad4_e[0]->Fit("fit_function_e", "RE");
   hgc_quad4_pi[0]->Fit("fit_function_pi", "RE");
   hgc_quad4_e[0]->Draw();
   hgc_quad4_pi[0]->Draw("same");

   fout << endl << "PMT1, Quad4, e" << endl;
   fout << pow(fit_function_e->GetChisquare(), 0.5) << '  ' << fit_function_e->GetParameter(1) << '  ' << fit_function_e->GetParameter(4) << '  ' << fit_function_e->GetParameter(6) << endl;

   fout << endl << "PMT1, Quad4, pi" << endl;
   fout << pow(fit_function_pi->GetChisquare(), 0.5) << '  ' << fit_function_pi->GetParameter(1) << '  ' << fit_function_pi->GetParameter(4) << '  ' << fit_function_pi->GetParameter(6) << endl;

   root_chi_e = pow(fit_function_e->GetChisquare(), 0.5);
   root_chi_pi = pow(fit_function_pi->GetChisquare(), 0.5);

   x_1[12] = 1, y_1[12] = fit_function_e->GetParameter(1), y_1err[12] = fit_function_e->GetParError(1)*root_chi_e;
   x_1[13] = 1, y_1[13] = fit_function_pi->GetParameter(1), y_1err[13] = fit_function_pi->GetParError(1)*root_chi_pi;
   x_1[14] = 2, y_1[14] = fit_function_e->GetParameter(4), y_1err[14] = fit_function_e->GetParError(4)*root_chi_e;
   x_1[15] = 2, y_1[15] = fit_function_pi->GetParameter(4), y_1err[15] = fit_function_pi->GetParError(4)*root_chi_pi;
   x_1[16] = 3, y_1[16] = fit_function_e->GetParameter(6), y_1err[16] = fit_function_e->GetParError(6)*root_chi_e;
   x_1[17] = 3, y_1[17] = fit_function_pi->GetParameter(6), y_1err[17] = fit_function_pi->GetParError(6)*root_chi_pi;

   gPad->Update();

   
   TCanvas *PMT2_off = new TCanvas("PMT2_off", "Fit of off-diagonal for PMT2", 1200, 600);
   PMT2_off->Divide(3,1);
  
   PMT2_off->cd(1);
   hgc_quad1_e[1]->SetLineColor(4);
   hgc_quad1_e[1]->GetXaxis()->SetRangeUser(0,6000);
   hgc_quad1_pi[1]->SetLineColor(8);
   hgc_quad1_pi[1]->GetXaxis()->SetRangeUser(0,6000);
   s->Search(hgc_quad1_e[1],4,"",0.10);
   s->Search(hgc_quad1_pi[1],4,"",0.10);
   hgc_quad1_e[1]->Fit("fit_function_e", "RE");
   hgc_quad1_pi[1]->Fit("fit_function_pi", "RE");
   hgc_quad1_e[1]->Draw();
   hgc_quad1_pi[1]->Draw("same");

   fout << endl << "PMT2, Quad1, e" << endl;
   fout << pow(fit_function_e->GetChisquare(), 0.5) << '  ' << fit_function_e->GetParameter(1) << '  ' << fit_function_e->GetParameter(4) << '  ' << fit_function_e->GetParameter(6) << endl;

   fout << endl << "PMT2, Quad1, pi" << endl;
   fout << pow(fit_function_pi->GetChisquare(), 0.5) << '  ' << fit_function_pi->GetParameter(1) << '  ' << fit_function_pi->GetParameter(4) << '  ' << fit_function_pi->GetParameter(6) << endl;

   x_2[0] = 1, y_2[0] = fit_function_e->GetParameter(1), y_2err[0] = fit_function_e->GetParError(1)*root_chi_e;
   x_2[1] = 1, y_2[1] = fit_function_pi->GetParameter(1), y_2err[1] = fit_function_pi->GetParError(1)*root_chi_pi;
   x_2[2] = 2, y_2[2] = fit_function_e->GetParameter(4), y_2err[2] = fit_function_e->GetParError(4)*root_chi_e;
   x_2[3] = 2, y_2[3] = fit_function_pi->GetParameter(4), y_2err[3] = fit_function_pi->GetParError(4)*root_chi_pi;
   x_2[4] = 3, y_2[4] = fit_function_e->GetParameter(6), y_2err[4] = fit_function_e->GetParError(6)*root_chi_e;
   x_2[5] = 3, y_2[5] = fit_function_pi->GetParameter(6), y_2err[5] = fit_function_pi->GetParError(6)*root_chi_pi;


   PMT2_off->cd(2);
   hgc_quad3_e[1]->SetLineColor(4);
   hgc_quad3_e[1]->GetXaxis()->SetRangeUser(0,6000);
   hgc_quad3_pi[1]->SetLineColor(8);
   hgc_quad3_pi[1]->GetXaxis()->SetRangeUser(0,6000);
   s->Search(hgc_quad2_e[1],4,"",0.10);
   s->Search(hgc_quad2_pi[1],4,"",0.10);
   hgc_quad3_e[1]->Fit("fit_function_e", "RE");
   hgc_quad3_pi[1]->Fit("fit_function_pi", "RE");
   hgc_quad3_e[1]->Draw();
   hgc_quad3_pi[1]->Draw("same");

   fout << endl <<  "PMT2, Quad3, e" << endl;
   fout << pow(fit_function_e->GetChisquare(), 0.5) << '  ' << fit_function_e->GetParameter(1) << '  ' << fit_function_e->GetParameter(4) << '  ' << fit_function_e->GetParameter(6) << endl;

   fout << endl << "PMT2, Quad3, pi" << endl;
   fout << pow(fit_function_pi->GetChisquare(), 0.5) << '  ' << fit_function_pi->GetParameter(1) << '  ' << fit_function_pi->GetParameter(4) << '  ' << fit_function_pi->GetParameter(6) << endl;

   x_2[6] = 1, y_2[6] = fit_function_e->GetParameter(1), y_2err[6] = fit_function_e->GetParError(1)*root_chi_e;
   x_2[7] = 1, y_2[7] = fit_function_pi->GetParameter(1), y_2err[7] = fit_function_pi->GetParError(1)*root_chi_pi;
   x_2[8] = 2, y_2[8] = fit_function_e->GetParameter(4), y_2err[8] = fit_function_e->GetParError(4)*root_chi_e;
   x_2[9] = 2, y_2[9] = fit_function_pi->GetParameter(4), y_2err[9] = fit_function_pi->GetParError(4)*root_chi_pi;
   x_2[10] = 3, y_2[10] = fit_function_e->GetParameter(6), y_2err[10] = fit_function_e->GetParError(6)*root_chi_e;
   x_2[11] = 3, y_2[11] = fit_function_pi->GetParameter(6), y_2err[11] = fit_function_pi->GetParError(6)*root_chi_pi;

   PMT2_off->cd(3);
   hgc_quad4_e[1]->SetLineColor(4);
   hgc_quad4_e[1]->GetXaxis()->SetRangeUser(0,6000);
   hgc_quad4_pi[1]->SetLineColor(8);
   hgc_quad4_pi[1]->GetXaxis()->SetRangeUser(0,6000);
   s->Search(hgc_quad4_e[1],4,"",0.10);
   s->Search(hgc_quad4_pi[1],4,"",0.10);
   hgc_quad4_e[1]->Fit("fit_function_e", "RE");
   hgc_quad4_pi[1]->Fit("fit_function_pi", "RE");
   hgc_quad4_e[1]->Draw();
   hgc_quad4_pi[1]->Draw("same");

   fout << endl << "PMT2, Quad4, e" << endl;
   fout << pow(fit_function_e->GetChisquare(), 0.5) << '  ' << fit_function_e->GetParameter(1) << '  ' << fit_function_e->GetParameter(4) << '  ' << fit_function_e->GetParameter(6) << endl;

   fout << endl << "PMT2, Quad4, pi" << endl;
   fout << pow(fit_function_pi->GetChisquare(), 0.5) << '  ' << fit_function_pi->GetParameter(1) << '  ' << fit_function_pi->GetParameter(4) << '  ' << fit_function_pi->GetParameter(6) << endl;

   x_2[12] = 1, y_2[12] = fit_function_e->GetParameter(1), y_2err[12] = fit_function_e->GetParError(1)*root_chi_e;
   x_2[13] = 1, y_2[13] = fit_function_pi->GetParameter(1), y_2err[13] = fit_function_pi->GetParError(1)*root_chi_pi;
   x_2[14] = 2, y_2[14] = fit_function_e->GetParameter(4), y_2err[14] = fit_function_e->GetParError(4)*root_chi_e;
   x_2[15] = 2, y_2[15] = fit_function_pi->GetParameter(4), y_2err[15] = fit_function_pi->GetParError(4)*root_chi_pi;
   x_2[16] = 3, y_2[16] = fit_function_e->GetParameter(6), y_2err[16] = fit_function_e->GetParError(6)*root_chi_e;
   x_2[17] = 3, y_2[17] = fit_function_pi->GetParameter(6), y_2err[17] = fit_function_pi->GetParError(6)*root_chi_pi;

   gPad->Update();

   TCanvas *PMT3_off = new TCanvas("PMT3_off", "Fit of off-diagonal for PMT3", 1200, 600);
   PMT3_off->Divide(3,1);
  
   PMT3_off->cd(1);
   hgc_quad1_e[2]->SetLineColor(4);
   hgc_quad1_e[2]->GetXaxis()->SetRangeUser(0,6000);
   hgc_quad1_pi[2]->SetLineColor(8);
   hgc_quad1_pi[2]->GetXaxis()->SetRangeUser(0,6000);
   s->Search(hgc_quad1_e[2],4,"",0.10);
   s->Search(hgc_quad1_pi[2],4,"",0.10);
   hgc_quad1_e[2]->Fit("fit_function_e", "RE");
   hgc_quad1_pi[2]->Fit("fit_function_pi", "RE");
   hgc_quad1_e[2]->Draw();
   hgc_quad1_pi[2]->Draw("same");

   fout << endl << "PMT3, Quad1, e" << endl;
   fout << pow(fit_function_e->GetChisquare(), 0.5) << '  ' << fit_function_e->GetParameter(1) << '  ' << fit_function_e->GetParameter(4) << '  ' << fit_function_e->GetParameter(6) << endl;

   fout << endl << "PMT3, Quad1, pi" << endl;
   fout << pow(fit_function_pi->GetChisquare(), 0.5) << '  ' << fit_function_pi->GetParameter(1) << '  ' << fit_function_pi->GetParameter(4) << '  ' << fit_function_pi->GetParameter(6) << endl;

   x_3[0] = 1, y_3[0] = fit_function_e->GetParameter(1), y_3err[0] = fit_function_e->GetParError(1)*root_chi_e;
   x_3[1] = 1, y_3[1] = fit_function_pi->GetParameter(1), y_3err[1] = fit_function_pi->GetParError(1)*root_chi_pi;
   x_3[2] = 2, y_3[2] = fit_function_e->GetParameter(4), y_3err[2] = fit_function_e->GetParError(4)*root_chi_e;
   x_3[3] = 2, y_3[3] = fit_function_pi->GetParameter(4), y_3err[3] = fit_function_pi->GetParError(4)*root_chi_pi;
   x_3[4] = 3, y_3[4] = fit_function_e->GetParameter(6), y_3err[4] = fit_function_e->GetParError(6)*root_chi_e;
   x_3[5] = 3, y_3[5] = fit_function_pi->GetParameter(6), y_3err[5] = fit_function_pi->GetParError(6)*root_chi_pi;

   PMT3_off->cd(2);
   hgc_quad2_e[2]->SetLineColor(4);
   hgc_quad2_e[2]->GetXaxis()->SetRangeUser(0,6000);
   hgc_quad2_pi[2]->SetLineColor(8);
   hgc_quad2_pi[2]->GetXaxis()->SetRangeUser(0,6000);
   s->Search(hgc_quad2_e[2],4,"",0.10);
   s->Search(hgc_quad2_pi[2],4,"",0.10);
   hgc_quad2_e[2]->Fit("fit_function_e", "RE");
   hgc_quad2_pi[2]->Fit("fit_function_pi", "RE");
   hgc_quad2_e[2]->Draw();
   hgc_quad2_pi[2]->Draw("same");

   fout << endl << "PMT3, Quad2, e" << endl;
   fout << pow(fit_function_e->GetChisquare(), 0.5) << '  ' << fit_function_e->GetParameter(1) << '  ' << fit_function_e->GetParameter(4) << '  ' << fit_function_e->GetParameter(6) << endl;

   fout << endl << "PMT3, Quad2, pi" << endl;
   fout << pow(fit_function_pi->GetChisquare(), 0.5) << '  ' << fit_function_pi->GetParameter(1) << '  ' << fit_function_pi->GetParameter(4) << '  ' << fit_function_pi->GetParameter(6) << endl;

   x_3[6] = 1, y_3[6] = fit_function_e->GetParameter(1), y_3err[6] = fit_function_e->GetParError(1)*root_chi_e;
   x_3[7] = 1, y_3[7] = fit_function_pi->GetParameter(1), y_3err[7] = fit_function_pi->GetParError(1)*root_chi_pi;
   x_3[8] = 2, y_3[8] = fit_function_e->GetParameter(4), y_3err[8] = fit_function_e->GetParError(4)*root_chi_e;
   x_3[9] = 2, y_3[9] = fit_function_pi->GetParameter(4), y_3err[9] = fit_function_pi->GetParError(4)*root_chi_pi;
   x_3[10] = 3, y_3[10] = fit_function_e->GetParameter(6), y_3err[10] = fit_function_e->GetParError(6)*root_chi_e;
   x_3[11] = 3, y_3[11] = fit_function_pi->GetParameter(6), y_3err[11] = fit_function_pi->GetParError(6)*root_chi_pi;

   PMT3_off->cd(3);
   hgc_quad4_e[2]->SetLineColor(4);
   hgc_quad4_e[2]->GetXaxis()->SetRangeUser(0,6000);
   hgc_quad4_pi[2]->SetLineColor(8);
   hgc_quad4_pi[2]->GetXaxis()->SetRangeUser(0,6000);
   s->Search(hgc_quad4_e[2],4,"",0.10);
   s->Search(hgc_quad4_pi[2],4,"",0.10);
   hgc_quad4_e[2]->Fit("fit_function_e", "RE");
   hgc_quad4_pi[2]->Fit("fit_function_pi", "RE");
   hgc_quad4_e[2]->Draw();
   hgc_quad4_pi[2]->Draw("same");

   fout << endl << "PMT3, Quad4, e" << endl;
   fout << pow(fit_function_e->GetChisquare(), 0.5) << '  ' << fit_function_e->GetParameter(1) << '  ' << fit_function_e->GetParameter(4) << '  ' << fit_function_e->GetParameter(6) << endl;

   fout << endl << "PMT3, Quad4, pi" << endl;
   fout << pow(fit_function_pi->GetChisquare(), 0.5) << '  ' << fit_function_pi->GetParameter(1) << '  ' << fit_function_pi->GetParameter(4) << '  ' << fit_function_pi->GetParameter(6) << endl;

   x_3[12] = 1, y_3[12] = fit_function_e->GetParameter(1), y_3err[12] = fit_function_e->GetParError(1)*root_chi_e;
   x_3[13] = 1, y_3[13] = fit_function_pi->GetParameter(1), y_3err[13] = fit_function_pi->GetParError(1)*root_chi_pi;
   x_3[14] = 2, y_3[14] = fit_function_e->GetParameter(4), y_3err[14] = fit_function_e->GetParError(4)*root_chi_e;
   x_3[15] = 2, y_3[15] = fit_function_pi->GetParameter(4), y_3err[15] = fit_function_pi->GetParError(4)*root_chi_pi;
   x_3[16] = 3, y_3[16] = fit_function_e->GetParameter(6), y_3err[16] = fit_function_e->GetParError(6)*root_chi_e;
   x_3[17] = 3, y_3[17] = fit_function_pi->GetParameter(6), y_3err[17] = fit_function_pi->GetParError(6)*root_chi_pi;

   gPad->Update();

   TCanvas *PMT4_off = new TCanvas("PMT4_off", "Fit of off-diagonal for PMT4", 1200, 600);
   PMT4_off->Divide(3,1);
  
   PMT4_off->cd(1);
   hgc_quad1_e[3]->SetLineColor(4);
   hgc_quad1_e[3]->GetXaxis()->SetRangeUser(0,6000);
   hgc_quad1_pi[3]->SetLineColor(8);
   hgc_quad1_pi[3]->GetXaxis()->SetRangeUser(0,6000);
   s->Search(hgc_quad1_e[3],4,"",0.10);
   s->Search(hgc_quad1_pi[3],4,"",0.10);
   hgc_quad1_e[3]->Fit("fit_function_e", "RE");
   hgc_quad1_pi[3]->Fit("fit_function_pi", "RE");
   hgc_quad1_e[3]->Draw();
   hgc_quad1_pi[3]->Draw("same");

   fout << endl << "PMT4, Quad1, e" << endl;
   fout << pow(fit_function_e->GetChisquare(), 0.5) << '  ' << fit_function_e->GetParameter(1) << '  ' << fit_function_e->GetParameter(4) << '  ' << fit_function_e->GetParameter(6) << endl;

   fout << endl << "PMT4, Quad1, pi" << endl;
   fout << pow(fit_function_pi->GetChisquare(), 0.5) << '  ' << fit_function_pi->GetParameter(1) << '  ' << fit_function_pi->GetParameter(4) << '  ' << fit_function_pi->GetParameter(6) << endl;

   x_4[0] = 1, y_4[0] = fit_function_e->GetParameter(1), y_4err[0] = fit_function_e->GetParError(1)*root_chi_e;
   x_4[1] = 1, y_4[1] = fit_function_pi->GetParameter(1), y_4err[1] = fit_function_pi->GetParError(1)*root_chi_pi;
   x_4[2] = 2, y_4[2] = fit_function_e->GetParameter(4), y_4err[2] = fit_function_pi->GetParError(4)*root_chi_pi;
   x_4[3] = 2, y_4[3] = fit_function_pi->GetParameter(4), y_4err[3] = fit_function_e->GetParError(4)*root_chi_e;
   x_4[4] = 3, y_4[4] = fit_function_e->GetParameter(6), y_4err[4] = fit_function_pi->GetParError(6)*root_chi_pi;
   x_4[5] = 3, y_4[5] = fit_function_pi->GetParameter(6), y_4err[5] = fit_function_e->GetParError(6)*root_chi_e;

   PMT4_off->cd(2);
   hgc_quad2_e[3]->SetLineColor(4);
   hgc_quad2_e[3]->GetXaxis()->SetRangeUser(0,6000);
   hgc_quad2_pi[3]->SetLineColor(8);
   hgc_quad2_pi[3]->GetXaxis()->SetRangeUser(0,6000);
   s->Search(hgc_quad2_e[3],4,"",0.10);
   s->Search(hgc_quad2_pi[3],4,"",0.10);
   hgc_quad2_e[3]->Fit("fit_function_e", "RE");
   hgc_quad2_pi[3]->Fit("fit_function_pi", "RE");
   hgc_quad2_e[3]->Draw();
   hgc_quad2_pi[3]->Draw("same");

   fout << endl << "PMT4, Quad2, e" << endl;
   fout << pow(fit_function_e->GetChisquare(), 0.5) << '  ' << fit_function_e->GetParameter(1) << '  ' << fit_function_e->GetParameter(4) << '  ' << fit_function_e->GetParameter(6) << endl;

   fout << endl << "PMT4, Quad2, pi" << endl;
   fout << pow(fit_function_pi->GetChisquare(), 0.5) << '  ' << fit_function_pi->GetParameter(1) << '  ' << fit_function_pi->GetParameter(4) << '  ' << fit_function_pi->GetParameter(6) << endl;

   x_4[6] = 1, y_4[6] = fit_function_e->GetParameter(1), y_4err[6] = fit_function_e->GetParError(1)*root_chi_e;
   x_4[7] = 1, y_4[7] = fit_function_pi->GetParameter(1), y_4err[7] = fit_function_pi->GetParError(1)*root_chi_pi;
   x_4[8] = 2, y_4[8] = fit_function_e->GetParameter(4), y_4err[8] = fit_function_e->GetParError(4)*root_chi_e;
   x_4[9] = 2, y_4[9] = fit_function_pi->GetParameter(4), y_4err[9] = fit_function_pi->GetParError(4)*root_chi_pi;
   x_4[10] = 3, y_4[10] = fit_function_e->GetParameter(6), y_4err[10] = fit_function_e->GetParError(6)*root_chi_e;
   x_4[11] = 3, y_4[11] = fit_function_pi->GetParameter(6), y_4err[11] = fit_function_pi->GetParError(6)*root_chi_pi;

   PMT4_off->cd(3);
   hgc_quad3_e[3]->SetLineColor(4);
   hgc_quad3_e[3]->GetXaxis()->SetRangeUser(0,6000);
   hgc_quad3_pi[3]->SetLineColor(8);
   hgc_quad3_pi[3]->GetXaxis()->SetRangeUser(0,6000);
   s->Search(hgc_quad3_e[3],4,"",0.10);
   s->Search(hgc_quad3_pi[3],4,"",0.10);
   hgc_quad3_e[3]->Fit("fit_function_e", "RE");
   hgc_quad3_pi[3]->Fit("fit_function_pi", "RE");
   hgc_quad3_e[3]->Draw();
   hgc_quad3_pi[3]->Draw("same");

   fout << endl << "PMT4, Quad3, e" << endl;
   fout << pow(fit_function_e->GetChisquare(), 0.5) << '  ' << fit_function_e->GetParameter(1) << '  ' << fit_function_e->GetParameter(4) << '  ' << fit_function_e->GetParameter(6) << endl;

   fout << endl << "PMT4, Quad3, pi" << endl;
   fout << pow(fit_function_pi->GetChisquare(), 0.5) << '  ' << fit_function_pi->GetParameter(1) << '  ' << fit_function_pi->GetParameter(4) << '  ' << fit_function_pi->GetParameter(6) << endl;

   x_4[12] = 1, y_4[12] = fit_function_e->GetParameter(1), y_4err[12] = fit_function_e->GetParError(1)*root_chi_e;
   x_4[13] = 1, y_4[13] = fit_function_pi->GetParameter(1), y_4err[13] = fit_function_pi->GetParError(1)*root_chi_pi;
   x_4[14] = 2, y_4[14] = fit_function_e->GetParameter(4), y_4err[14] = fit_function_e->GetParError(4)*root_chi_e;
   x_4[15] = 2, y_4[15] = fit_function_pi->GetParameter(4), y_4err[15] = fit_function_pi->GetParError(4)*root_chi_pi;
   x_4[16] = 3, y_4[16] = fit_function_e->GetParameter(6), y_4err[16] = fit_function_e->GetParError(6)*root_chi_e;
   x_4[17] = 3, y_4[17] = fit_function_pi->GetParameter(6), y_4err[17] = fit_function_pi->GetParError(6)*root_chi_pi;

   gPad->Update();
   
   /*
     float root_chi = pow(fit_function->GetChisquare(), 0.5);
     float x[] = {1,2,3};
     float y[] = {static_cast<float>(fit_function->GetParameter(1)),static_cast<float>(fit_function->GetParameter(4)),static_cast<float>(fit_function->GetParameter(6))};
     float yerr[] = {static_cast<float>(fit_function->GetParError(1)*root_chi), static_cast<float>(fit_function->GetParError(4)*root_chi), static_cast<float>(fit_function->GetParError(6)*root_chi)};
     float *xerr = NULL;  
     cout << "Chi^2/NDF: " << fit_function->GetChisquare()/fit_function->GetNDF() << endl;
   */

   
   gStyle->SetOptFit(111);

   gr_1 = new TGraphErrors(n,x_1,y_1,x_err,y_1err);
   TCanvas *c1_1 = new TCanvas("c1_1", "ADC to p.e. for PMT1",1200, 600);
   for (int i=0; i<n; i++)
     {
       //cout << gr_1->GetX()[i] << '   ' << gr_1->GetY()[i] << '   ' << gr_1->GetErrorY(i) << endl;
       if (gr_1->GetErrorY(i) > 300)
	 {
	   gr_1->RemovePoint(i);
	   i = i-1;
	 }
       if (gr_1->GetX()[i] > 2) gr_1->RemovePoint(i+1);
       {
	 //gr_1->RemovePoint(i);
	 //i = i-1;
       }
     }
   gr_1->GetXaxis()->SetRangeUser(0,3);
   gr_1->Draw("A*");
   gr_1->Fit("pol1");

   gr_2 = new TGraphErrors(n,x_2,y_2,x_err,y_2err);
   TCanvas *c1_2 = new TCanvas("c1_2", "ADC to p.e. for PMT2",1200, 600);
   for (int i=0; i<n; i++)
     {
       if (gr_2->GetErrorY(i) > 300)
	 {
	   gr_2->RemovePoint(i);
	   i = i-1;
	 }
       //if (gr_2->GetX()[i] == 3) gr_2->RemovePoint(i);
     }
   gr_2->GetXaxis()->SetRangeUser(0,3);
   gr_2->Draw("A*");
   gr_2->Fit("pol1");

   gr_3 = new TGraphErrors(n,x_3,y_3,x_err,y_3err);
   TCanvas *c1_3 = new TCanvas("c1_3", "ADC to p.e. for PMT3",1200, 600);
   for (int i=0; i<n; i++)
     {
       if (gr_3->GetErrorY(i) > 300)
	 {
	   gr_3->RemovePoint(i);
	   i = i-1;
	 }
       //if (gr_3->GetX()[i] == 3) gr_3->RemovePoint(i);
     }
   gr_3->GetXaxis()->SetRangeUser(0,3);
   gr_3->Draw("A*");
   gr_3->Fit("pol1");

   gr_4 = new TGraphErrors(n,x_4,y_4,x_err,y_4err);
   TCanvas *c1_4 = new TCanvas("c1_4", "ADC to p.e. for PMT4",1200, 600);
   for (int i=0; i<n; i++)
     {
       if (gr_4->GetErrorY(i) > 300)
	 {
	   gr_4->RemovePoint(i);
	   i = i-1;
	 }
       //if (gr_4->GetX()[i] == 3) gr_4->RemovePoint(i);
     }
   gr_4->GetXaxis()->SetRangeUser(0,3);
   gr_4->Draw("A*");
   gr_4->Fit("pol1");
   

   fout.close();
}
