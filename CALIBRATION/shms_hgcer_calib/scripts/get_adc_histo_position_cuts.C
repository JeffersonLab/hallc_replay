#include <iostream>

#define NPMT 4

void get_adc_histo_position_cuts()
{
  gROOT->Reset();

  //Specify Histogram Parameters 
  int num_bins = 500;
  int adc_low = -500;
  int adc_high = 15000;
  int hgc_position = 230;

  //Reading Proper ROOT file
  int run_NUM = 0;
  char line[20];

  cout << endl << endl << endl << "Beginning ADC spectrum display " << endl; 

  FILE *run = fopen("scripts/input_RUN.txt","r");

  while (fgets(&line[0],19,run))
    {
      sscanf(&line[0],"%i",&run_NUM);
    }

  fclose(run);

  cout << "Processing run: " << run_NUM << endl;

  TFile *f = new TFile(Form("../../ROOTfiles/replay_all_%d.root", run_NUM), "READ");
  
  TFile *g = new TFile(Form("root_files/run%d/shms_hgcer_adc_position_%d.root", run_NUM, run_NUM), "RECREATE");

  TTree *tree = (TTree*)f->Get("T");



  
  //Presenting Data



  
  //Visualizing the Raw ADC information
  TCanvas *adc_0 = new TCanvas("adc_0","Raw ADC Plots",1200,600);
  adc_0->Divide(2,2);

  //Raw PMT1
  TPad *p1_0 = (TPad*)(adc_0->cd(1));
  TH1F *raw_pmt1 = new TH1F("raw_pmt1","Raw ADC Spectrum for PMT 1",num_bins,adc_low,adc_high);
  p1_0->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>raw_pmt1","P.hgcer.adcCounter == 1");
  gPad->Update();
  
  //Raw PMT2
  TPad *p2_0 = (TPad*)(adc_0->cd(2));
  TH1F *raw_pmt2 = new TH1F("raw_pmt2","Raw ADC Spectrum for PMT 2",num_bins,adc_low,adc_high);
  p2_0->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>raw_pmt2","P.hgcer.adcCounter == 2");
  gPad->Update();
  
  //Raw PMT3
  TPad *p3_0 = (TPad*)(adc_0->cd(3));
  TH1F *raw_pmt3 = new TH1F("raw_pmt3","Raw ADC Spectrum for PMT 3",num_bins,adc_low,adc_high);
  p3_0->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>raw_pmt3","P.hgcer.adcCounter == 3");
  gPad->Update();

  //Raw PMT4
  TPad *p4_0 = (TPad*)(adc_0->cd(4));
  TH1F *raw_pmt4 = new TH1F("raw_pmt4","Raw ADC Spectrum for PMT 4",num_bins,adc_low,adc_high);
  p4_0->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>raw_pmt4","P.hgcer.adcCounter == 4");
  gPad->Update();



  //Display Position of events in HGC mirror plane
  TCanvas *projec = new TCanvas("projec","Particle Projection",1200,600);
  TH2F *hgc_pos = new TH2F("hgc_pos","Particle Projected Position in HGC",10000,-200,200,10000,-200,200);
  hgc_pos->GetXaxis()->SetTitle("Y dimension");
  hgc_pos->GetYaxis()->SetTitle("X dimension");
  tree->Draw("P.tr.x[0] + P.tr.th[0] * 230:P.tr.y[0] + P.tr.ph[0] * 230>>hgc_pos","","colz");
  gPad->Update();


  
  //Display ADC Spectrum after cutting to various mirrors
  TCanvas *pos_cut = new TCanvas("pos_cut","ADC Spectrum with Position Cuts",1200,600);
  pos_cut->Divide(4,4);

  //PMT1
  TPad *p1m1 = (TPad*)(pos_cut->cd(1));
  TH1F *pmt1_mir1 = new TH1F("pmt1_mir1","PMT 1 looking at Mirror 1",num_bins,adc_low,adc_high);
  p1m1->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>pmt1_mir1","P.hgcer.adcCounter == 1 && P.tr.y[0] + P.tr.ph[0] * 230 > 0  && P.tr.x[0] + P.tr.th[0] * 230 > 0");
  gPad->Update();
  
  TPad *p1m2 = (TPad*)(pos_cut->cd(2));
  TH1F *pmt1_mir2 = new TH1F("pmt1_mir2","PMT 1 looking at Mirror 2",num_bins,adc_low,adc_high);
  p1m2->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>pmt1_mir2","P.hgcer.adcCounter == 1 && P.tr.y[0] + P.tr.ph[0] * 230 < 0  && P.tr.x[0] + P.tr.th[0] * 230 > 0" );
  gPad->Update();
  
  TPad *p1m3 = (TPad*)(pos_cut->cd(3));
  TH1F *pmt1_mir3 = new TH1F("pmt1_mir3","PMT 1 looking at Mirror 3",num_bins,adc_low,adc_high);
  p1m3->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>pmt1_mir3","P.hgcer.adcCounter == 1 && P.tr.y[0] + P.tr.ph[0] * 230 > 0  && P.tr.x[0] + P.tr.th[0] * 230 < 0");
  gPad->Update();
  
  TPad *p1m4 = (TPad*)(pos_cut->cd(4));
  TH1F *pmt1_mir4 = new TH1F("pmt1_mir4","PMT 1 looking at Mirror 4",num_bins,adc_low,adc_high);
  p1m4->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>pmt1_mir4","P.hgcer.adcCounter == 1 && P.tr.y[0] + P.tr.ph[0] * 230 < 0  && P.tr.x[0] + P.tr.th[0] * 230 < 0");
  gPad->Update();
  
  
  //PMT2
  TPad *p2m1 = (TPad*)(pos_cut->cd(5));
  TH1F *pmt2_mir1 = new TH1F("pmt2_mir1","PMT 2 looking at Mirror 1",num_bins,adc_low,adc_high);
  p2m1->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>pmt2_mir1","P.hgcer.adcCounter == 2 && P.tr.y[0] + P.tr.ph[0] * 230 > 0  && P.tr.x[0] + P.tr.th[0] * 230 > 0");
  gPad->Update();
  
  TPad *p2m2 = (TPad*)(pos_cut->cd(6));
  TH1F *pmt2_mir2 = new TH1F("pmt2_mir2","PMT 2 looking at Mirror 2",num_bins,adc_low,adc_high);
  p2m2->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>pmt2_mir2","P.hgcer.adcCounter == 2 && P.tr.y[0] + P.tr.ph[0] * 230 < 0  && P.tr.x[0] + P.tr.th[0] * 230 > 0");
  gPad->Update();
  
  TPad *p2m3 = (TPad*)(pos_cut->cd(7));
  TH1F *pmt2_mir3 = new TH1F("pmt2_mir3","PMT 2 looking at Mirror 3",num_bins,adc_low,adc_high);
  p2m3->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>pmt2_mir3","P.hgcer.adcCounter == 2 && P.tr.y[0] + P.tr.ph[0] * 230 > 0  && P.tr.x[0] + P.tr.th[0] * 230 < 0");
  gPad->Update();
  
  TPad *p2m4 = (TPad*)(pos_cut->cd(8));
  TH1F *pmt2_mir4 = new TH1F("pmt2_mir4","PMT 2 looking at Mirror 4",num_bins,adc_low,adc_high);
  p2m4->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>pmt2_mir4","P.hgcer.adcCounter == 2 && P.tr.y[0] + P.tr.ph[0] * 230 < 0  && P.tr.x[0] + P.tr.th[0] * 230 < 0");
  gPad->Update();
  
  
  //PMT3
  TPad *p3m1 = (TPad*)(pos_cut->cd(9));
  TH1F *pmt3_mir1 = new TH1F("pmt3_mir1","PMT 3 looking at Mirror 1",num_bins,adc_low,adc_high);
  p3m1->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>pmt3_mir1","P.hgcer.adcCounter == 3 && P.tr.y[0] + P.tr.ph[0] * 230 > 0  && P.tr.x[0] + P.tr.th[0] * 230 > 0");
  gPad->Update();
  
  TPad *p3m2 = (TPad*)(pos_cut->cd(10));
  TH1F *pmt3_mir2 = new TH1F("pmt3_mir2","PMT 3 looking at Mirror 2",num_bins,adc_low,adc_high);
  p3m2->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>pmt3_mir2","P.hgcer.adcCounter == 3 && P.tr.y[0] + P.tr.ph[0] * 230 < 0  && P.tr.x[0] + P.tr.th[0] * 230 > 0");
  gPad->Update();
  
  TPad *p3m3 = (TPad*)(pos_cut->cd(11));
  TH1F *pmt3_mir3 = new TH1F("pmt3_mir3","PMT 3 looking at Mirror 3",num_bins,adc_low,adc_high);
  p3m3->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>pmt3_mir3","P.hgcer.adcCounter == 3 && P.tr.y[0] + P.tr.ph[0] * 230 > 0  && P.tr.x[0] + P.tr.th[0] * 230 < 0");
  gPad->Update();
  
  TPad *p3m4 = (TPad*)(pos_cut->cd(12));
  TH1F *pmt3_mir4 = new TH1F("pmt3_mir4","PMT 3 looking at Mirror 4",num_bins,adc_low,adc_high);
  p3m4->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>pmt3_mir4","P.hgcer.adcCounter == 3 && P.tr.y[0] + P.tr.ph[0] * 230 < 0  && P.tr.x[0] + P.tr.th[0] * 230 < 0");
  gPad->Update();
  
  
  //PMT4
  TPad *p4m1 = (TPad*)(pos_cut->cd(13));
  TH1F *pmt4_mir1 = new TH1F("pmt4_mir1","PMT 4 looking at Mirror 1",num_bins,adc_low,adc_high);
  p4m1->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>pmt4_mir1","P.hgcer.adcCounter == 4 && P.tr.y[0] + P.tr.ph[0] * 230 > 0  && P.tr.x[0] + P.tr.th[0] * 230 > 0");
  gPad->Update();
  
  TPad *p4m2 = (TPad*)(pos_cut->cd(14));
  TH1F *pmt4_mir2 = new TH1F("pmt4_mir2","PMT 4 looking at Mirror 2",num_bins,adc_low,adc_high);
  p4m2->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>pmt4_mir2","P.hgcer.adcCounter == 4 && P.tr.y[0] + P.tr.ph[0] * 230 < 0  && P.tr.x[0] + P.tr.th[0] * 230 > 0");
  gPad->Update();
  
  TPad *p4m3 = (TPad*)(pos_cut->cd(15));
  TH1F *pmt4_mir3 = new TH1F("pmt4_mir3","PMT 4 looking at Mirror 3",num_bins,adc_low,adc_high);
  p4m3->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>pmt4_mir3","P.hgcer.adcCounter == 4 && P.tr.y[0] + P.tr.ph[0] * 230 > 0  && P.tr.x[0] + P.tr.th[0] * 230 < 0");
  gPad->Update();
  
  TPad *p4m4 = (TPad*)(pos_cut->cd(16));
  TH1F *pmt4_mir4 = new TH1F("pmt4_mir4","PMT 4 looking at Mirror 4",num_bins,adc_low,adc_high);
  p4m4->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>pmt4_mir4","P.hgcer.adcCounter == 4 && P.tr.y[0] + P.tr.ph[0] * 230 < 0  && P.tr.x[0] + P.tr.th[0] * 230 < 0"); 
  gPad->Update();
  

  
  //Search for single photoelectron peaks
  TCanvas *npe = new TCanvas("npe","Single Photoelectron Peaks",1200,600);
  npe->Divide(2,2);

  TPad *p1 = (TPad*)(npe->cd(1));
  TH1F *npe1 = new TH1F("npe1","Single Photoelectron Peaks for PMT 1",num_bins,adc_low,adc_high);
  p1->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>npe1","P.hgcer.adcCounter == 1 && P.tr.x[0] + P.tr.th[0] * 230 < 10 && P.tr.y[0] + P.tr.ph[0] * 230 < 10");
  gPad->Update();
  
  TPad *p2 = (TPad*)(npe->cd(2));
  TH1F *npe2 = new TH1F("npe2","Single Photoelectron Peaks for PMT 2",num_bins,adc_low,adc_high);
  p2->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>npe2","P.hgcer.adcCounter == 2 && P.tr.y[0] + P.tr.ph[0] * 230 > 10 && abs(P.tr.x[0] + P.tr.th[0] * 230) > 0 ");
  gPad->Update();
  
  TPad *p3 = (TPad*)(npe->cd(3));
  TH1F *npe3 = new TH1F("npe3","Single Photoelectron Peaks for PMT 3",num_bins,adc_low,adc_high);
  p3->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>npe3","P.hgcer.adcCounter == 3 && P.tr.x[0] + P.tr.th[0] * 230 > 10 && abs(P.tr.y[0] + P.tr.ph[0] * 230) < 60");
  gPad->Update();
  
  TPad *p4 = (TPad*)(npe->cd(4));
  TH1F *npe4 = new TH1F("npe4","Single Photoelectron Peaks for PMT 4",num_bins,adc_low,adc_high);
  p4->SetLogy();
  tree->Draw("P.hgcer.adcPulseInt>>npe4","P.hgcer.adcCounter == 4 && P.tr.x[0] + P.tr.th[0] * 230 > 20 && abs(P.tr.y[0] + P.tr.ph[0] * 230) < 60");
  gPad->Update();

  g->Write();
}
