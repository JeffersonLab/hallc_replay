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


void photoelectrons(Int_t RunNumber=0)
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


  gStyle->SetOptFit(111);

  TF1 *f1 = new TF1("f1",multiple_gauss_test,fit_min,fit_max,12);
  f1->SetParNames("Amplitude 1","Mean 1","Std. Dev. 1","Amplitude 2","Mean 2","Std. Dev. 2","Amplitude 3","Mean 3","Std. Dev. 3");
  f1->SetParName(9, "Amplitude 4");
  f1->SetParName(10, "Mean 4");
  f1->SetParName(11, "Std. Dev. 4");
  

  TF1 *Gauss4 = new TF1("Gauss4",multiple_gauss_test,300,2500,12);
  Gauss4->SetParNames("Amplitude 1","Mean 1","Std. Dev. 1","Amplitude 2","Mean 2","Std. Dev. 2","Amplitude 3","Mean 3","Std. Dev. 3");
  Gauss4->SetParName(9, "Amplitude 4");
  Gauss4->SetParName(10, "Mean 4");
  Gauss4->SetParName(11, "Std. Dev. 4");

  TF1 *Gauss3 = new TF1("Gauss3",multiple_gauss_test,300,2000,9);
  Gauss3->SetParNames("Amplitude 1","Mean 1","Std. Dev. 1","Amplitude 2","Mean 2","Std. Dev. 2","Amplitude 3","Mean 3","Std. Dev. 3");

  TF1 *Gauss2 = new TF1("Gauss2",multiple_gauss_test,300,1350,6);
  Gauss2->SetParNames("Amplitude 1","Mean 1","Std. Dev. 1","Amplitude 2","Mean 2","Std. Dev. 2");

  TF1 *Gauss1 = new TF1("Gauss1",multiple_gauss_test,300,700,3);
  Gauss1->SetParNames("Amplitude 1","Mean 1","Std. Dev. 1");

  //Start for PMT 1
  TList *list = new TList;
  list->Add(hgc_e[1][0]);
  list->Add(hgc_e[2][0]);
  list->Add(hgc_e[3][0]);

  TH1F *all = (TH1F*)hgc_sum[1][0]->Clone("all");
  all->Reset();
  all->Merge(list);

  Double_t x_sum[100], y_sum[100], y_serr[100];
  Double_t x_e[100], y_e[100], y_eerr[100];
  Double_t x_pi[100], y_pi[100], y_pierr[100];

  Double_t x_err[100] = NULL;

  float root_chi;

  f1->SetParameters(500.,500.,200.,198.272,1000.,200.,198.272,1500.,200.);
  f1->SetParameter(9, 198.272);
  f1->SetParameter(10, 2000.);
  f1->SetParameter(11, 200.);
  f1->SetParLimits(0, 100., 5000.);
  f1->SetParLimits(3, 100., 5000.);
  f1->SetParLimits(6, 100., 5000.);
  f1->SetParLimits(9, 100., 5000.);

  TCanvas *c0 = new TCanvas("c0","c0");
  all->Fit("f1","REMB");
  gPad->Update();
  if (f1->GetChisquare()/f1->GetNDF() > 2.5 || f1->GetChisquare()/f1->GetNDF() < 0.7)
    {
      cout << "Error: Check fitting limits or number of peaks" << endl;
      break;
    }
  
  root_chi = pow(f1->GetChisquare()/f1->GetNDF(), 0.5);
  x_sum[0] = 1, y_sum[0] = f1->GetParameter(1), y_serr[0] = f1->GetParError(1)*root_chi;
  x_sum[1] = 2, y_sum[1] = f1->GetParameter(4), y_serr[1] = f1->GetParError(4)*root_chi;
  x_sum[2] = 3, y_sum[2] = f1->GetParameter(7), y_serr[2] = f1->GetParError(7)*root_chi;
  x_sum[3] = 4, y_sum[3] = f1->GetParameter(10), y_serr[3] = f1->GetParError(10)*root_chi;

  gr_sum =  new TGraphErrors(4, x_sum, y_sum, x_err, y_serr);
  

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

  Gauss2->SetParameters(f1->GetParameter(0),f1->GetParameter(1),f1->GetParameter(2),f1->GetParameter(3),f1->GetParameter(4),f1->GetParameter(5));
  Gauss2->SetParLimits(1, f1->GetParameter(1)- 50, f1->GetParameter(1)+50);
  Gauss2->SetParLimits(4, f1->GetParameter(4)- 50, f1->GetParameter(4)+50);
  Gauss2->SetParLimits(0, 5., 5000.);
  Gauss2->SetParLimits(3, 5., 5000.);
  Gauss2->SetParLimits(2, 0., 1000.);
  Gauss2->SetParLimits(5, 0., 1000.);
  
  Gauss1->SetParameters(f1->GetParameter(0),f1->GetParameter(1),f1->GetParameter(2));
  Gauss1->SetParLimits(1, f1->GetParameter(1)- 50, f1->GetParameter(1)+50);
  Gauss1->SetParLimits(0, 5., 5000.);
  Gauss1->SetParLimits(2, 0., 1000.);

  TCanvas *c1 = new TCanvas("c1","c1");
  c1->Divide(2,1);
  c1->cd(1);
  j = 0;
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
		  root_chi = pow(Gauss1->GetChisquare()/Gauss1->GetNDF(), 0.5);
		  x_e[j] = 1, y_e[j] = Gauss1->GetParameter(1), y_eerr[j] = Gauss1->GetParError(1)*root_chi;
		  j = j+1;
		  continue;
		}
	      root_chi = pow(Gauss2->GetChisquare()/Gauss2->GetNDF(), 0.5);
	      x_e[j] = 1, y_e[j] = Gauss2->GetParameter(1), y_eerr[j] = Gauss2->GetParError(1)*root_chi;
	      x_e[j+1] = 2, y_e[j+1] = Gauss2->GetParameter(4), y_eerr[j+1] = Gauss2->GetParError(4)*root_chi;  
	      j = j+2;
	      continue;
	    }
	  root_chi = pow(Gauss3->GetChisquare()/Gauss3->GetNDF(), 0.5);
	  x_e[j] = 1, y_e[j] = Gauss3->GetParameter(1), y_eerr[j] = Gauss3->GetParError(1)*root_chi;
	  x_e[j+1] = 2, y_e[j+1] = Gauss3->GetParameter(4), y_eerr[j+1] = Gauss3->GetParError(4)*root_chi;  
	  x_e[j+2] = 3, y_e[j+2] = Gauss3->GetParameter(7), y_eerr[j+2] = Gauss3->GetParError(7)*root_chi; 
	  j = j+3;
	  continue;
	}
      root_chi = pow(Gauss4->GetChisquare()/Gauss4->GetNDF(), 0.5);
      x_e[j] = 1, y_e[j] = Gauss4->GetParameter(1), y_eerr[j] = Gauss4->GetParError(1)*root_chi;
      x_e[j+1] = 2, y_e[j+1] = Gauss4->GetParameter(4), y_eerr[j+1] = Gauss4->GetParError(4)*root_chi;  
      x_e[j+2] = 3, y_e[j+2] = Gauss4->GetParameter(7), y_eerr[j+2] = Gauss4->GetParError(7)*root_chi;
      x_e[j+3] = 4, y_e[j+3] = Gauss4->GetParameter(10), y_eerr[j+3] = Gauss4->GetParError(10)*root_chi; 
      j = j+4;
      continue;
    }

  hgc_e[1][0]->Draw();
  hgc_e[2][0]->Draw("same");
  hgc_e[3][0]->Draw("same");
  gPad->Update();
  
  gr_e =  new TGraphErrors(j+1, x_e, y_e, x_err, y_eerr);

  c1->cd(2);
  j = 0;
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
		  root_chi = pow(Gauss1->GetChisquare()/Gauss1->GetNDF(), 0.5);
		  x_pi[j] = 1, y_pi[j] = Gauss1->GetParameter(1), y_pierr[j] = Gauss1->GetParError(1)*root_chi;
		  j = j+1;
		  continue;
		}
	      root_chi = pow(Gauss2->GetChisquare()/Gauss2->GetNDF(), 0.5);
	      x_pi[j] = 1, y_pi[j] = Gauss2->GetParameter(1), y_pierr[j] = Gauss2->GetParError(1)*root_chi;
	      x_pi[j+1] = 2, y_pi[j+1] = Gauss2->GetParameter(4), y_pierr[j+1] = Gauss2->GetParError(4)*root_chi;  
	      j = j+2;
	      continue;
	    }	
	  root_chi = pow(Gauss3->GetChisquare()/Gauss3->GetNDF(), 0.5);
	  x_pi[j] = 1, y_pi[j] = Gauss3->GetParameter(1), y_pierr[j] = Gauss3->GetParError(1)*root_chi;
	  x_pi[j+1] = 2, y_pi[j+1] = Gauss3->GetParameter(4), y_pierr[j+1] = Gauss3->GetParError(4)*root_chi;  
	  x_pi[j+2] = 3, y_pi[j+2] = Gauss3->GetParameter(7), y_pierr[j+2] = Gauss3->GetParError(7)*root_chi; 
	  j = j+3;
	  continue;
	}
      root_chi = pow(Gauss4->GetChisquare()/Gauss4->GetNDF(), 0.5);
      x_pi[j] = 1, y_pi[j] = Gauss4->GetParameter(1), y_pierr[j] = Gauss4->GetParError(1)*root_chi;
      x_pi[j+1] = 2, y_pi[j+1] = Gauss4->GetParameter(4), y_pierr[j+1] = Gauss4->GetParError(4)*root_chi;  
      x_pi[j+2] = 3, y_pi[j+2] = Gauss4->GetParameter(7), y_pierr[j+2] = Gauss4->GetParError(7)*root_chi;
      x_pi[j+3] = 4, y_pi[j+3] = Gauss4->GetParameter(10), y_pierr[j+3] = Gauss4->GetParError(10)*root_chi; 
      j = j+4;
      continue;
    }
  hgc_pi[1][0]->Draw();
  hgc_pi[2][0]->Draw("same");
  hgc_pi[3][0]->Draw("same");
  gPad->Update();

  gr_pi =  new TGraphErrors(j+1, x_pi, y_pi, x_err, y_pierr);

  TCanvas *p1 = new TCanvas("p1", "PMT 1, Photoelectrons vs ADC");
  p1->Divide(3,1);
  p1->cd(1);
  gr_sum->Fit("pol1");
  gr_sum->Draw("A*");
  p1->cd(2);
  gr_e->Fit("pol1");
  gr_e->Draw("A*");
  p1->cd(3);
  gr_pi->Fit("pol1");
  gr_pi->Draw("A*");
  gPad->Update();


}
