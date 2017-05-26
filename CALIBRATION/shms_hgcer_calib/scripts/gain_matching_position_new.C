#include <iostream>

//Define the conversion from ADC channel to mean number of electrons

//const float convert = (1/157)/(TMath::Power(1.6021766*10,-7));

void single_pad_fit(TPad*);



void gain_matching_position_new()
{
  //User Defined Parameters for histograms
  int num_bins = 250;
  int adc_low = 0;
  int adc_high = 5000;
  
  //Read Run Number from txt file
  int run_NUM = 0;
  char line[20];

  FILE *run = fopen("scripts/input_RUN.txt", "r");
  while(fgets(&line[0],19,run))
    {
      sscanf(&line[0],"%i",&run_NUM);
    }

  fclose(run);

  //Get Data to fit
  TFile *f = new TFile(Form("root_files/run%d/shms_hgcer_adc_position_%d.root",run_NUM,run_NUM), "READ");

  //Create file for fit results
  ofstream fout;
  fout.open("fit_results.txt");


  //Presenting Data in a nice way

  TCanvas *c2 = new TCanvas("c2","c2",1200,600);
  c2->Divide(4,4);

  
  TCanvas *c3 = new TCanvas("c3","c3",1200,600);
  c3->Divide(4,4);
  
  
  for (int i = 0;i<16;i++)
    {
      c2->cd(i+1);
      c2->GetPad(i+1)->SetLogy();
      
      TString pmt_name;
      pmt_name.Form("pmt%i_mir%i",i/4+1,i%4+1);
      TH1F *hist = (TH1F*)f->Get(pmt_name);
      hist->GetXaxis()->SetRangeUser(-300,5000);
      
      TSpectrum *s = new TSpectrum(2);
      s->Search(hist,2.0,"nobackground",0.001);
      fout << s->GetPositionX()[0] << " " << s->GetPositionX()[1] << endl; 
      
      if (s->GetNPeaks() == 2)
	{
	  TF1 *gauss2 = new TF1("gauss2","[0]*exp(-((x-[1])**2)/(2*[2]**2)) + [3]*exp(-((x-[4])**2)/(2*[2]**2))",-300,850);
	  gauss2->SetParameters(10,0,50,10,0);
	  if (s->GetPositionX()[0] > s->GetPositionX()[1])
	    {
	      gauss2->FixParameter(1,s->GetPositionX()[1]);
	      gauss2->FixParameter(4,s->GetPositionX()[0]);
	    }
	  else
	    {
	      gauss2->FixParameter(1,s->GetPositionX()[0]);
	      gauss2->FixParameter(4,s->GetPositionX()[1]);
	    }
	  gauss2->SetParNames("1st Coeff","1st Mean","1st Offset","2nd Coeff","2nd Mean","2nd Offset","Ver Offset");
	  hist->Fit("gauss2","NR");

	  TF1 *gp1 = new TF1("gp1","[0]*exp(-((x-[1])**2)/(2*[2]**2))",gauss2->GetParameter(1)-2000,gauss2->GetParameter(1)+2000);
	  gp1->SetParameter(0,gauss2->GetParameter(0));
	  gp1->SetParameter(1,gauss2->GetParameter(1));
	  gp1->SetParameter(2,gauss2->GetParameter(2));

	  TF1 *gp2 = new TF1("gp2","[0]*exp(-((x-[1])**2)/(2*[2]**2))",gauss2->GetParameter(4)-2000,gauss2->GetParameter(4)+2000);
	  gp2->SetParameter(0,gauss2->GetParameter(3));
	  gp2->SetParameter(1,gauss2->GetParameter(4));
	  gp2->SetParameter(2,gauss2->GetParameter(2));

	  gp1->Draw("same");
	  gp2->Draw("same");
	  /*
	  c3->cd(i+1);
	  
	  TGraphErrors *g1 = new TGraphErrors();
	  g1->SetPoint(0,1,gp1->GetParameter(1));
	  g1->SetPointError(0,0,gp1->GetParameter(2));
	  g1->SetPoint(1,2,gp2->GetParameter(1));
	  g1->SetPointError(1,0,gp2->GetParameter(2));

	  g1->Draw("AP");
	  g1->Fit("pol0","R");
	  */
	}

      if (s->GetNPeaks() == 3)
	{
	  TF1 *gauss3 = new TF1("gauss3","[0]*exp(-((x-[1])**2)/([2])) + [3]*exp(-((x-[4])**2)/([5])) + [6]*exp(-((x-[7])**2)/([8]))",-100,2000);
	  gauss3->SetParameters(1000,0,1000,1000,0,1000,1000,0,1000);
	  gauss3->FixParameter(1,s->GetPositionX()[0]);
	  gauss3->FixParameter(4,s->GetPositionX()[1]);
	  gauss3->FixParameter(7,s->GetPositionX()[2]);
	  gauss3->SetParNames("1st Coeff","1st Mean","1st Offset","2nd Coeff","2nd Mean","2nd Offset","3rd Coeff","3rd Mean","3rd Offset","Ver Offset");
	  hist->Fit("gauss3","R");

	  TF1 *gp1 = new TF1("gp1","[0]*exp(-((x-[1])**2)/([2]))",s->GetPositionX()[0]-100,s->GetPositionX()[0]+100);
	  gp1->SetParameter(0,gauss3->GetParameter(0));
	  gp1->SetParameter(1,gauss3->GetParameter(1));
	  gp1->SetParameter(2,gauss3->GetParameter(2));

	  TF1 *gp2 = new TF1("gp2","[0]*exp(-((x-[1])**2)/([2]))",s->GetPositionX()[1]-200,s->GetPositionX()[1]+200);
	  gp2->SetParameter(0,gauss3->GetParameter(3));
	  gp2->SetParameter(1,gauss3->GetParameter(4));
	  gp2->SetParameter(2,gauss3->GetParameter(5));

	  TF1 *gp3 = new TF1("gp3","[0]*exp(-((x-[1])**2)/([2]))",s->GetPositionX()[2]-100,s->GetPositionX()[2]+100);
	  gp3->SetParameter(0,gauss3->GetParameter(6));
	  gp3->SetParameter(1,gauss3->GetParameter(7));
	  gp3->SetParameter(2,gauss3->GetParameter(8));

	  
	  gp1->Draw("same");
	  gp2->Draw("same");
	  gp3->Draw("same");

	  //c3->cd(i+1);
	  
	  TGraphErrors *g1 = new TGraphErrors();
	  g1->SetPoint(0,1,gp1->GetParameter(1));
	  g1->SetPointError(0,0,gp1->GetParameter(2));
	  g1->SetPoint(1,2,gp2->GetParameter(1));
	  g1->SetPointError(1,0,gp2->GetParameter(2));
	  g1->SetPoint(2,3,gp3->GetParameter(1));
	  g1->SetPointError(2,0,gp3->GetParameter(2));

	  //g1->Draw();
	}
      
      //single_pad_fit(p1); 
    }
  c2->Update();
  //c3->Update();
  
};

void single_pad_fit(TPad* temp)
{
  temp->Draw();
}
