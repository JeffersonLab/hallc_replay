#include <iostream>

//Define the conversion from ADC channel to mean number of electrons

const float convert = (1/157)/(TMath::Power(1.6021766*10,-7));


void Plotter()
{
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
  TFile *f = new TFile(Form("root_files/run%d/shms_hgcer_adc_time_%d.root",run_NUM,run_NUM), "READ");
  TH1F *PMT1_lower = (TH1F*)f->Get("h1_lower");
  TH1F *PMT1_upper = (TH1F*)f->Get("h1_upper");
  TH1F *PMT2_lower = (TH1F*)f->Get("h2_lower");
  TH1F *PMT2_upper = (TH1F*)f->Get("h2_upper");
  TH1F *PMT3_lower = (TH1F*)f->Get("h3_lower");
  TH1F *PMT3_upper = (TH1F*)f->Get("h3_upper");
  TH1F *PMT4_lower = (TH1F*)f->Get("h4_lower");
  TH1F *PMT4_upper = (TH1F*)f->Get("h4_upper");  
 

  //Define Photoelectron Parameters
  int npe = 0;
  int lower = 0;
  int upper = 0;

  
  //Presenting Data in a nice way
  TCanvas *c1 = new TCanvas("c1","Single Photoelectron Peaks",1200,600);
  gStyle->SetLabelSize(0.12,"xy");
  c1->Divide(2,4);

  //Examining PMT 1 lower cut
  TPad *p1 = (TPad*)(c1->cd(1));
  p1->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT1 lower cut: ";
  cin >> npe;
  TGraph *p1_lower = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;     
      PMT1_lower->Fit("gaus","+","",lower,upper);
      p1_lower->SetPoint(i,i+1,convert * PMT1_lower->GetFunction("gaus")->GetParameter(1));
      gPad->Update();     
    }

  //Examining PMT 1 upper cut
  TPad *p2 = (TPad*)(c1->cd(2));
  p2->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT1 upper cut: ";
  cin >> npe;
  TGraph *p1_upper = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;
      PMT1_upper->Fit("gaus","+","",lower,upper);
      p1_upper->SetPoint(i,i+1,convert * PMT1_upper->GetFunction("gaus")->GetParameter(1));
      gPad->Update();
    }


  //Examining PMT 2 lower cut
  TPad *p3 = (TPad*)(c1->cd(3));
  p3->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT2 lower cut: ";
  cin >> npe;
  TGraph *p2_lower = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;    
      PMT2_lower->Fit("gaus","+","",lower,upper);
      p2_lower->SetPoint(i,i+1,convert * PMT2_lower->GetFunction("gaus")->GetParameter(1));
      gPad->Update();
    }

  //Examining PMT 2 upper cut
  TPad *p4 = (TPad*)(c1->cd(4));
  p4->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT2 upper cut: ";
  cin >> npe;
  TGraph *p2_upper = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;     
      PMT2_upper->Fit("gaus","+","",lower,upper);
      p2_upper->SetPoint(i,i+1,convert * PMT2_upper->GetFunction("gaus")->GetParameter(1));
      gPad->Update();      
    }

  //Examining PMT 3 lower cut
  TPad *p5 = (TPad*)(c1->cd(5));
  p5->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT3 lower cut: ";
  cin >> npe;
  TGraph *p3_lower = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;      
      PMT3_lower->Fit("gaus","+","",lower,upper);
      p3_lower->SetPoint(i,i+1,convert * PMT3_lower->GetFunction("gaus")->GetParameter(1));
      gPad->Update();      
    }

  //Examining PMT 3 upper cut
  TPad *p6 = (TPad*)(c1->cd(6));
  p6->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT3 upper cut: ";
  cin >> npe;
  TGraph *p3_upper = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;      
      PMT3_upper->Fit("gaus","+","",lower,upper);
      p3_upper->SetPoint(i,i+1,convert * PMT3_upper->GetFunction("gaus")->GetParameter(1));
      gPad->Update();      
    }

  //Examining PMT 4 lower cut
  TPad *p7 = (TPad*)(c1->cd(7));
  p7->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT4 lower cut: ";
  cin >> npe;
  TGraph *p4_lower = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;      
      PMT4_lower->Fit("gaus","+","",lower,upper);
      p4_lower->SetPoint(i,i+1,convert * PMT4_lower->GetFunction("gaus")->GetParameter(1));
      gPad->Update();      
    }

  //Examining PMT 4 upper cut
  TPad *p8 = (TPad*)(c1->cd(8));
  p8->SetLogy();
  npe = 0;
  cout << "Number of photoelectrons on PMT4 upper cut: ";
  cin >> npe;
  TGraph *p4_upper = new TGraph();
  for (int i=0;i<npe;i++)
    {
      lower = 0;
      upper = 0;
      
      cout << endl << "Lower boundary for p.e. " << i+1 << ": ";
      cin >> lower;
      cout << endl << "Upper boundary for p.e. " << i+1 << ": ";
      cin >> upper;
      PMT4_upper->Fit("gaus","+","",lower,upper);
      p4_upper->SetPoint(i,i+1,convert * PMT4_upper->GetFunction("gaus")->GetParameter(1));
      gPad->Update();      
    }

  c->Close();


  //Draw number of photoelectrons vs ADC channel

  cout << "!!!!!!!!!!" << "Conversion taken as 1/512 pC/ADC channel" << "!!!!!!!!!!";
  
  TCanvas *npe_adc = new TCanvas("npe_adc","NPE vs Mean ADC Channel",1200,600);
  gStyle->SetMarkerSize(1.0);
  npe_adc->Divide(2,4);

  //Examining PMT 1
  TPad *q1 = (TPad*)(npe_adc->cd(1));
  p1_lower->Draw();
  p1_lower->Fit("pol1","+");
  gPad->Update();

  TPad *q2 = (TPad*)(npe_adc->cd(2));
  p1_upper->Draw();
  p1_upper->Fit("pol1","+");
  gPad->Update();

  TPad *q3 = (TPad*)(npe_adc->cd(3));
  p2_lower->Draw();
  p2_lower->Fit("pol1","+");
  gPad->Update();

  TPad *q4 = (TPad*)(npe_adc->cd(4));
  p2_upper->Draw();
  p2_upper->Fit("pol1","+");
  gPad->Update();

  TPad *q5 = (TPad*)(npe_adc->cd(5));
  p3_lower->Draw();
  p3_lower->Fit("pol1","+");
  gPad->Update();

  TPad *q6 = (TPad*)(npe_adc->cd(6));
  p3_upper->Draw();
  p3_upper->Fit("pol1","+");
  gPad->Update();

  TPad *q7 = (TPad*)(npe_adc->cd(7));
  p4_lower->Draw();
  p4_lower->Fit("pol1","+");
  gPad->Update();

  TPad *q8 = (TPad*)(npe_adc->cd(8));
  p4_upper->Draw();
  p4_upper->Fit("pol1","+");
  gPad->Update();

};

void gain_matching_time()
{

  Plotter();
  
};
