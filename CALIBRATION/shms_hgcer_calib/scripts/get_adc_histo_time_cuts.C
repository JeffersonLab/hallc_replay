//Script to add adc histograms from original root file to new root file

#include <iostream>

#define NPMT 4

void get_adc_histo_time_cuts()
{

  gROOT->Reset();

  //User Histogram Parameters
  int num_bins = 250;
  int adc_low = 0;
  int adc_high = 5000;
  
  //Read Run Number from txt file
  int run_NUM = 0;
  char line[20];

  cout << endl << endl << endl << "Beginning ADC spectrum display " << endl;
  FILE *run = fopen("scripts/input_RUN.txt", "r");
  
  while (fgets(&line[0],19,run))
    {
      sscanf(&line[0],"%i",&run_NUM);
    }
  
  fclose(run);
  
  cout << "Processing run: " << run_NUM << endl;
  
  //open file
  TFile *f = new TFile(Form("../../ROOTfiles/replay_all_%d.root", run_NUM), "READ");

  //create new file
  TFile *g = new TFile(Form("root_files/run%d/shms_hgcer_adc_time_%d.root", run_NUM, run_NUM), "RECREATE");

  //Get the tree and import information
  TTree *tree = (TTree*)f->Get("T");
  
  
  //Presenting Data in a nice way
  TCanvas *adc = new TCanvas("adc","ADC Calibration Data",1200,600);
  gStyle->SetLabelSize(0.125,"x");
  gStyle->SetLabelSize(0.1,"y");
  adc->Divide(2,4);

  
  //Examining PMT 1  
  TPad *p1 = (TPad*)(adc->cd(1));
  TH1F *h1 = new TH1F("h1","Raw PMT 1",num_bins,adc_low,adc_high);
  p1->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>h1","P.hgcer.adcCounter == 1");

  TPad *p2 = (TPad*)(adc->cd(2));
  TH1F *h2 = new TH1F("h2","PMT 1 Timing",250,1000,2000);
  tree->Draw("P.hgcer.adcPulseTimeRaw>>h2","P.hgcer.adcCounter == 1"); 


  //Examining PMT 2 
  TPad *p3 = (TPad*)(adc->cd(3));
  TH1F *h3 = new TH1F("h3","Raw PMT 2",num_bins,adc_low,adc_high);
  p3->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>h3","P.hgcer.adcCounter == 2");

  TPad *p4 = (TPad*)(adc->cd(4));
  TH1F *h4 = new TH1F("h4","PMT 2 Timing",250,1000,2000);
  tree->Draw("P.hgcer.adcPulseTimeRaw>>h4","P.hgcer.adcCounter == 2"); 


  //Examining PMT 3 
  TPad *p5 = (TPad*)(adc->cd(5));
  TH1F *h5 = new TH1F("h5","Raw PMT 3",num_bins,adc_low,adc_high);
  p5->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>h5","P.hgcer.adcCounter == 3");
  
  TPad *p6 = (TPad*)(adc->cd(6));
  TH1F *h6 = new TH1F("h6","PMT 3 Timing",250,1000,2000);
  tree->Draw("P.hgcer.adcPulseTimeRaw>>h6","P.hgcer.adcCounter == 3");

  
  //Examining PMT 4
  TPad *p7 = (TPad*)(adc->cd(7));
  TH1F *h7 = new TH1F("h7","Raw PMT 4",num_bins,adc_low,adc_high);
  p7->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>h7","P.hgcer.adcCounter == 4");
  
  TPad *p8 = (TPad*)(adc->cd(8));
  TH1F *h8 = new TH1F("h8","PMT 4 Timing",250,1000,2000);
  tree->Draw("P.hgcer.adcPulseTimeRaw>>h8","P.hgcer.adcCounter == 4");
  gPad->Update();


  //User defined cuts for each PMT

  Int_t PMT1_lower;
  Int_t PMT1_upper;
  Int_t PMT1_mid;

  Int_t PMT2_lower;
  Int_t PMT2_upper;
  Int_t PMT2_mid;

  Int_t PMT3_lower;
  Int_t PMT3_upper;
  Int_t PMT3_mid;

  Int_t PMT4_lower;
  Int_t PMT4_upper;
  Int_t PMT4_mid;

  cout << "Input Lower Range for PMT 1: ";
  cin >> PMT1_lower;
  cout << endl << "Input Upper Range for PMT 1: ";
  cin >> PMT1_upper;
  cout << endl << "Input Division Point: ";
  cin >> PMT1_mid;

  cout << endl << "Input Lower Range for PMT 2: ";
  cin >> PMT2_lower;
  cout << endl << "Input Upper Range for PMT 2: ";
  cin >> PMT2_upper;
  cout << endl << "Input Division Point: ";
  cin >> PMT2_mid;

  cout << endl << "Input Lower Range for PMT 3: ";
  cin >> PMT3_lower;
  cout << endl << "Input Upper Range for PMT 3: ";
  cin >> PMT3_upper;
  cout << endl << "Input Division Point: ";
  cin >> PMT3_mid;

  cout << endl << "Input Lower Range for PMT 4: ";
  cin >> PMT4_lower;
  cout << endl << "Input Upper Range for PMT 4: ";
  cin >> PMT4_upper;
  cout << endl << "Input Division Point: ";
  cin >> PMT4_mid;

  cout << endl << endl;
  
  //Present Cut Results
  TCanvas *c = new TCanvas("c","Time Cut Spectrum",1200,600);
  c->Divide(2,4);

  //Examining PMT 1
  TPad *q1 = (TPad*)(c->cd(1));
  TH1F *h1_lower = new TH1F ("h1_lower","PMT 1 Lower Time Cut",num_bins,adc_low,adc_high);
  q1->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>h1_lower",Form("P.hgcer.adcCounter == 1 && abs(P.hgcer.adcPulseTimeRaw - ((%d + %d)/2)) < (%d - ((%d + %d)/2))",PMT1_mid,PMT1_lower,PMT1_mid,PMT1_mid,PMT1_lower));

  TPad *q2 = (TPad*)(c->cd(2));
  TH1F *h1_upper = new TH1F ("h1_upper","PMT 1 Upper Time Cut",num_bins,adc_low,adc_high);
  q2->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>h1_upper",Form("P.hgcer.adcCounter == 1 && abs(P.hgcer.adcPulseTimeRaw - ((%d + %d)/2)) < (%d - ((%d + %d)/2))",PMT1_upper,PMT1_mid,PMT1_upper,PMT1_upper,PMT1_mid));
  gPad->Update();

  
  //Examining PMT 2
  TPad *q3 = (TPad*)(c->cd(3));
  TH1F *h2_lower = new TH1F ("h2_lower","PMT 2 Lower Time Cut",num_bins,adc_low,adc_high);
  q3->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>h2_lower",Form("P.hgcer.adcCounter == 2 && abs(P.hgcer.adcPulseTimeRaw - ((%d + %d)/2)) < (%d - ((%d + %d)/2))",PMT2_mid,PMT2_lower,PMT2_mid,PMT2_mid,PMT2_lower));

  TPad *q4 = (TPad*)(c->cd(4));
  TH1F *h2_upper = new TH1F ("h2_upper","PMT 2 Upper Time Cut",num_bins,adc_low,adc_high);
  q4->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>h2_upper",Form("P.hgcer.adcCounter == 2 && abs(P.hgcer.adcPulseTimeRaw - ((%d + %d)/2)) < (%d - ((%d + %d)/2))",PMT2_upper,PMT2_mid,PMT2_upper,PMT2_upper,PMT2_mid));
  gPad->Update();

  
  //Examining PMT 3
  TPad *q5 = (TPad*)(c->cd(5));
  TH1F *h3_lower = new TH1F ("h3_lower","PMT 3 Lower Time Cut",num_bins,adc_low,adc_high);
  q5->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>h3_lower",Form("P.hgcer.adcCounter == 3 && abs(P.hgcer.adcPulseTimeRaw - ((%d + %d)/2)) < (%d - ((%d + %d)/2))",PMT3_mid,PMT3_lower,PMT3_mid,PMT3_mid,PMT3_lower));

  TPad *q6 = (TPad*)(c->cd(6));
  TH1F *h3_upper = new TH1F ("h3_upper","PMT 3 Upper Time Cut",num_bins,adc_low,adc_high);
  q6->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>h3_upper",Form("P.hgcer.adcCounter == 3 && abs(P.hgcer.adcPulseTimeRaw - ((%d + %d)/2)) < (%d - ((%d + %d)/2))",PMT3_upper,PMT3_mid,PMT3_upper,PMT3_upper,PMT3_mid));
  gPad->Update();


  //Examining PMT 4
  TPad *q7 = (TPad*)(c->cd(7));
  TH1F *h4_lower = new TH1F ("h4_lower","PMT 4 Lower Time Cut",num_bins,adc_low,adc_high);
  q7->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>h4_lower",Form("P.hgcer.adcCounter == 4 && abs(P.hgcer.adcPulseTimeRaw - ((%d + %d)/2)) < (%d - ((%d + %d)/2))",PMT4_mid,PMT4_lower,PMT4_mid,PMT4_mid,PMT4_lower));
  
  TPad *q8 = (TPad*)(c->cd(8));
  TH1F *h4_upper = new TH1F ("h4_upper","PMT 4 Upper Time Cut",num_bins,adc_low,adc_high);
  q8->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>h4_upper",Form("P.hgcer.adcCounter == 4 && abs(P.hgcer.adcPulseTimeRaw - ((%d + %d)/2)) < (%d - ((%d + %d)/2))",PMT4_upper,PMT4_mid,PMT4_upper,PMT4_upper,PMT4_mid));
  gPad->Update();

  g->Write();

}
