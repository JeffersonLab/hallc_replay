#include <iostream>

//Define the conversion from ADC channel to mean number of electrons

//const float convert = (1/157)/(TMath::Power(1.6021766*10,-7));

void single_pad_fit(TPad*);



void gain_matching_position()
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


  /*
  TH1F *p1m1 = (TH1F*)f->Get("pmt1_mir1");
  TH1F *p1m2 = (TH1F*)f->Get("pmt1_mir2");
  TH1F *p1m3 = (TH1F*)f->Get("pmt1_mir3");
  TH1F *p1m4 = (TH1F*)f->Get("pmt1_mir4");

  TH1F *p2m1 = (TH1F*)f->Get("pmt2_mir1");
  TH1F *p2m2 = (TH1F*)f->Get("pmt2_mir2");
  TH1F *p2m3 = (TH1F*)f->Get("pmt2_mir3");
  TH1F *p2m4 = (TH1F*)f->Get("pmt2_mir4");

  TH1F *p3m1 = (TH1F*)f->Get("pmt3_mir1");
  TH1F *p3m2 = (TH1F*)f->Get("pmt3_mir2");
  TH1F *p3m3 = (TH1F*)f->Get("pmt3_mir3");
  TH1F *p3m4 = (TH1F*)f->Get("pmt3_mir4");

  TH1F *p4m1 = (TH1F*)f->Get("pmt4_mir1");
  TH1F *p4m2 = (TH1F*)f->Get("pmt4_mir2");
  TH1F *p4m3 = (TH1F*)f->Get("pmt4_mir3");
  TH1F *p4m4 = (TH1F*)f->Get("pmt4_mir4");
  */


  //Define Photoelectron Parameters
  int npe = 0;
  int lower = 0;
  int upper = 0;


  //Create file for fit results
  ofstream fout;
  fout.open("fit_results.txt");


  
  //Gaussian Fitting Functions
  /*
  TF1 *gauss2 = new TF1("gauss2","[0]*exp(-((x-[1])**2)/([2])) + [3]*exp(-((x-[4])**2)/([5])) + [6]",0,900);

  gauss2->SetParameters(830,10,3802,315,580,2162,203);
  gauss2->SetParNames("1st Coeff","1st Mean","1st Offset","2nd Coeff","2nd Mean","2nd Offset","Ver Offset");

  TF1 *gauss3 = new TF1("gauss3","[0]*exp(-((x-[1])**2)/([2])) + [3]*exp(-((x-[4])**2)/([5])) + [6]*exp(-((x-[7])**2)/([8])) + [9]",0,1400);

  gauss3->SetParameters(1000,10,3802,315,580,2162,300,1245,200000,200);
  gauss3->SetParNames("1st Coeff","1st Mean","1st Offset","2nd Coeff","2nd Mean","2nd Offset","3rd Coeff","3rd Mean","3rd Offset","Ver Offset");
  */  


  //Presenting Data in a nice way
  TCanvas *c1 = new TCanvas("c1","c1",1200,600);
  gStyle->SetLabelSize(0.12,"xy");
  c1->Divide(4,4);

  TCanvas *c2 = new TCanvas("c2","c2",1200,600);
  c2->Divide(4,4);
  
  for (int i = 0;i<16;i++)
    {
      TF1 *gauss2 = new TF1("gauss2","[0]*exp(-((x-[1])**2)/([2])) + [3]*exp(-((x-[4])**2)/([5])) + [6]",0,900);
      gauss2->SetParameters(830,10,3802,315,580,2162,203);
      gauss2->SetParNames("1st Coeff","1st Mean","1st Offset","2nd Coeff","2nd Mean","2nd Offset","Ver Offset");

      TF1 *gauss3 = new TF1("gauss3","[0]*exp(-((x-[1])**2)/([2])) + [3]*exp(-((x-[4])**2)/([5])) + [6]*exp(-((x-[7])**2)/([8])) + [9]",0,1400);
      gauss3->SetParameters(1000,10,3802,315,580,2162,300,1245,200000,200);
      gauss3->SetParNames("1st Coeff","1st Mean","1st Offset","2nd Coeff","2nd Mean","2nd Offset","3rd Coeff","3rd Mean","3rd Offset","Ver Offset");
      
      TPad *p1 = (TPad*)c1->GetPad(i+1);
      p1->SetLogy();
      TString pmt_name;
      pmt_name.Form("pmt%i_mir%i",i/4+1,i%4+1);
      cout << "??????????" << "        " << pmt_name << endl;
      TH1F *test = (TH1F*)f->Get(pmt_name);
      c2->cd(i+1);
      test->Fit("gauss3","r");
      //single_pad_fit(p1); 
    }
  c2->Update();
  
  
  //Examining PMT 1
  /*
  TPad *p1 = (TPad*)(c1->cd(1));
  p1->SetLogy();
  p1m1->Fit("gauss3","r");
  //p1m1->Fit("gauss2","r");
  //fout << gauss2->GetParameter(1) << endl << gauss2->GetParameter(4) << endl;
  */
  
  /*
  TPad *p1 = (TPad*)(c1->cd(1));
  p1->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT1/Mir1: ";
  cin >> npe;
  fout << "PMT1" << endl;  
  TGraph *gr1 = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;     
      p1m1->Fit("gaus","+","",lower,upper);
      gr1->SetPoint(i,i+1,p1m1->GetFunction("gaus")->GetParameter(1));
      fout << p1m1->GetFunction("gaus")->GetParameter(1) << endl;
      gPad->Update();     
    }
	      
  TPad *p2 = (TPad*)(c1->cd(2));
  p2->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT1/Mir2: ";
  cin >> npe;
  TGraph *gr2 = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;     
      p1m2->Fit("gaus","+","",lower,upper);
      gr2->SetPoint(i,i+1,p1m2->GetFunction("gaus")->GetParameter(1));
      fout << p1m2->GetFunction("gaus")->GetParameter(1) << endl;
      gPad->Update();     
    }

  TPad *p3 = (TPad*)(c1->cd(3));
  p3->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT1/Mir3: ";
  cin >> npe;
  TGraph *gr3 = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;     
      p1m3->Fit("gaus","+","",lower,upper);
      gr3->SetPoint(i,i+1,p1m3->GetFunction("gaus")->GetParameter(1));
      fout << p1m3->GetFunction("gaus")->GetParameter(1) << endl;
      gPad->Update();     
    }

  TPad *p4 = (TPad*)(c1->cd(4));
  p4->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT1/Mir4: ";
  cin >> npe;
  TGraph *gr4 = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;     
      p1m4->Fit("gaus","+","",lower,upper);
      gr4->SetPoint(i,i+1,p1m4->GetFunction("gaus")->GetParameter(1));
      fout << p1m4->GetFunction("gaus")->GetParameter(1) << endl;
      gPad->Update();     
    }


  //Examining PMT 2
 
  TPad *p5 = (TPad*)(c1->cd(5));
  p5->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT2/Mir1: ";
  cin >> npe;
  fout << endl << endl << "PMT2" << endl; 
  TGraph *gr5 = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;     
      p2m1->Fit("gaus","+","",lower,upper);
      gr5->SetPoint(i,i+1,p2m1->GetFunction("gaus")->GetParameter(1));
      fout << p2m1->GetFunction("gaus")->GetParameter(1) << endl;
      gPad->Update();     
    }
  
  TPad *p6 = (TPad*)(c1->cd(6));
  p6->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT2/Mir2: ";
  cin >> npe;
  TGraph *gr6 = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;    
      p2m2->Fit("gaus","+","",lower,upper);
      gr6->SetPoint(i,i+1,p2m2->GetFunction("gaus")->GetParameter(1));
      fout << p2m2->GetFunction("gaus")->GetParameter(1) << endl;
      gPad->Update();
    }

  
  TPad *p7 = (TPad*)(c1->cd(7));
  p7->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT2/Mir3: ";
  cin >> npe;
  TGraph *gr7 = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;     
      p2m3->Fit("gaus","+","",lower,upper);
      gr7->SetPoint(i,i+1,p2m3->GetFunction("gaus")->GetParameter(1));
      fout << p2m3->GetFunction("gaus")->GetParameter(1) << endl;
      gPad->Update();     
    }

  TPad *p8 = (TPad*)(c1->cd(8));
  p8->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT2/Mir4: ";
  cin >> npe;
  TGraph *gr8 = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;     
      p2m4->Fit("gaus","+","",lower,upper);
      gr8->SetPoint(i,i+1,p2m4->GetFunction("gaus")->GetParameter(1));
      fout << p2m4->GetFunction("gaus")->GetParameter(1) << endl;
      gPad->Update();     
    }

  //Examining PMT 3
  
  TPad *p9 = (TPad*)(c1->cd(9));
  p9->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT3/Mir1: ";
  cin >> npe;
  fout << endl << endl << "PMT3" << endl;
  TGraph *gr9 = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;     
      p3m1->Fit("gaus","+","",lower,upper);
      gr9->SetPoint(i,i+1,p3m1->GetFunction("gaus")->GetParameter(1));
      fout << p3m1->GetFunction("gaus")->GetParameter(1) << endl;
      gPad->Update();     
    }
  
  TPad *p10 = (TPad*)(c1->cd(10));
  p10->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT3/Mir2: ";
  cin >> npe;
  TGraph *gr10 = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;    
      p3m2->Fit("gaus","+","",lower,upper);
      gr10->SetPoint(i,i+1,p3m2->GetFunction("gaus")->GetParameter(1));
      fout << p3m2->GetFunction("gaus")->GetParameter(1) << endl;
      gPad->Update();
    }
  
  TPad *p11 = (TPad*)(c1->cd(11));
  p11->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT3/Mir3: ";
  cin >> npe;
  TGraph *gr11 = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;      
      p3m3->Fit("gaus","+","",lower,upper);
      gr11->SetPoint(i,i+1,p3m3->GetFunction("gaus")->GetParameter(1));
      fout << p3m3->GetFunction("gaus")->GetParameter(1) << endl;
      gPad->Update();      
    }

  
  TPad *p12 = (TPad*)(c1->cd(12));
  p12->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT3/Mir4: ";
  cin >> npe;
  TGraph *gr12 = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;     
      p3m4->Fit("gaus","+","",lower,upper);
      gr12->SetPoint(i,i+1,p3m4->GetFunction("gaus")->GetParameter(1));
      fout << p3m4->GetFunction("gaus")->GetParameter(1) << endl;
      gPad->Update();     
    }

  //Examining PMT 4

  
  TPad *p13 = (TPad*)(c1->cd(13));
  p13->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT4/Mir1: ";
  cin >> npe;
  fout << endl << endl << "PMT4" << endl; 
  TGraph *gr13 = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;     
      p4m1->Fit("gaus","+","",lower,upper);
      gr13->SetPoint(i,i+1,p4m1->GetFunction("gaus")->GetParameter(1));
      fout << p4m1->GetFunction("gaus")->GetParameter(1) << endl;
      gPad->Update();     
    }
  
  TPad *p14 = (TPad*)(c1->cd(14));
  p14->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT4/Mir2: ";
  cin >> npe;
  TGraph *gr14 = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;    
      p4m2->Fit("gaus","+","",lower,upper);
      gr14->SetPoint(i,i+1,p4m2->GetFunction("gaus")->GetParameter(1));
      fout << p4m2->GetFunction("gaus")->GetParameter(1) << endl;
      gPad->Update();
    }
  
  TPad *p15 = (TPad*)(c1->cd(15));
  p15->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT4/Mir3: ";
  cin >> npe;
  TGraph *gr15 = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;      
      p4m3->Fit("gaus","+","",lower,upper);
      gr15->SetPoint(i,i+1,p4m3->GetFunction("gaus")->GetParameter(1));
      fout << p4m3->GetFunction("gaus")->GetParameter(1) << endl;
      gPad->Update();      
    }
  
  TPad *p16 = (TPad*)(c1->cd(16));
  p16->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT4: ";
  cin >> npe;
  TGraph *gr16 = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;      
      p4m4->Fit("gaus","+","",lower,upper);
      gr16->SetPoint(i,i+1,p4m4->GetFunction("gaus")->GetParameter(1));
      fout << p4m4->GetFunction("gaus")->GetParameter(1) << endl;
      gPad->Update();      
    }
				 
  fout.close();
  //Draw number of photoelectrons vs ADC channel
  
  TCanvas *npe_adc = new TCanvas("npe_adc","NPE vs Mean ADC Channel",1200,600);
  gStyle->SetMarkerStyle(20);
  gStyle->SetMarkerSize(5.0);
  npe_adc->Divide(4,4);

  TPad *q1 = (TPad*)(npe_adc->cd(1));
  gr1->Draw();
  gr1->Fit("pol1","+");
  gPad->Update();

  TPad *q2 = (TPad*)(npe_adc->cd(2));
  gr2->Draw();
  gr2->Fit("pol1","+");
  gPad->Update();

  TPad *q3 = (TPad*)(npe_adc->cd(3));
  gr3->Draw();
  gr3->Fit("pol1","+");
  gPad->Update();

  TPad *q4 = (TPad*)(npe_adc->cd(4));
  gr4->Draw();
  gr4->Fit("pol1","+");
  gPad->Update();

  
  TPad *q5 = (TPad*)(npe_adc->cd(5));
  gr5->Draw();
  gr5->Fit("pol1","+");
  gPad->Update();

  TPad *q6 = (TPad*)(npe_adc->cd(6));
  gr6->Draw();
  gr6->Fit("pol1","+");
  gPad->Update();

  TPad *q7 = (TPad*)(npe_adc->cd(7));
  gr7->Draw();
  gr7->Fit("pol1","+");
  gPad->Update();

  TPad *q8 = (TPad*)(npe_adc->cd(8));
  gr8->Draw();
  gr8->Fit("pol1","+");
  gPad->Update();

  
  TPad *q9 = (TPad*)(npe_adc->cd(9));
  gr9->Draw();
  gr9->Fit("pol1","+");
  gPad->Update();

  TPad *q10 = (TPad*)(npe_adc->cd(10));
  gr10->Draw();
  gr10->Fit("pol1","+");
  gPad->Update();

  TPad *q11 = (TPad*)(npe_adc->cd(11));
  gr11->Draw();
  gr11->Fit("pol1","+");
  gPad->Update();

  TPad *q12 = (TPad*)(npe_adc->cd(12));
  gr12->Draw();
  gr12->Fit("pol1","+");
  gPad->Update();

  
  TPad *q13 = (TPad*)(npe_adc->cd(13));
  gr13->Draw();
  gr13->Fit("pol1","+");
  gPad->Update();

  TPad *q14 = (TPad*)(npe_adc->cd(14));
  gr14->Draw();
  gr14->Fit("pol1","+");
  gPad->Update();

  TPad *q15 = (TPad*)(npe_adc->cd(15));
  gr15->Draw();
  gr15->Fit("pol1","+");
  gPad->Update();

  TPad *q16 = (TPad*)(npe_adc->cd(16));
  gr16->Draw();
  gr16->Fit("pol1","+");
  gPad->Update();

  
  //Output ADC Spectra with conversion to NPE
  
  TCanvas *npe_spec = new TCanvas("npe_spec","NPE Spectrum for each PMT",1200,600);
  npe_spec->Divide(2,2);

  TPad *np_1 = (TPad*)(npe_spec->cd(1));
  TH1F *nh1 = new TH1F("nh1","NPE spectrum",num_bins,adc_low,adc_high);
  np_1->SetLogy();
  f->Draw("raw_pmt1>>nh1");
  */
};

void single_pad_fit(TPad* temp)
{
  temp->Draw();
}
