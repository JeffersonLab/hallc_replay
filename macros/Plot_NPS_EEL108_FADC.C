void Plot_NPS_EEL108_FADC( Int_t nrun=47 ) {

  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);

  gStyle->SetCanvasColor(0);
  gStyle->SetFrameFillColor(0);

  gStyle->SetPadTopMargin(.05);
  gStyle->SetPadLeftMargin(.15);
  gStyle->SetPadRightMargin(.05);
  gStyle->SetPadBottomMargin(.15);

  gStyle->SetTitleOffset(1.1, "X");
  gStyle->SetTitleOffset(1.1, "Y");
  gStyle->SetTitleFont(42,"X");
  gStyle->SetTitleFont(42,"Y");
  gStyle->SetTitleSize(0.055,"X");
  gStyle->SetTitleSize(0.055,"Y");

  gStyle->SetLabelOffset(0.03, "X");
  gStyle->SetLabelOffset(0.03, "Y");
  gStyle->SetLabelFont(42,"X");
  gStyle->SetLabelFont(42,"Y");
  gStyle->SetLabelSize(0.12,"X");
  gStyle->SetLabelSize(0.12,"Y");

  gStyle->SetNdivisions(404,"X");
  gStyle->SetNdivisions(303,"Y");

  gStyle->SetStripDecimals(kFALSE);

  // --------------------------------------------------------------------------------

  //const int maxSamp = 28;
  const int maxSamp = 1+1+100; // 100 samples for run 23+
  const int nrows = 16;
  const int ncols = 16;
  int nblocks = nrows*ncols;

  int slot, col;
  cout << "assumed run = "<<nrun<<endl;

  cout << "Choose FADC module id (1-16)" << endl;
  cin>> col;
  slot = col;
  if( slot > nrows ) {
    cout << slot << " is not a valid FADC module id" << endl;
    exit;
  }
  else if( slot <= 8 )
    slot += 2;
  else
    slot += 4;

  // --------------------------------------------------------------------------------

  TFile *f = new TFile(Form("ROOTfiles/nps_eel108_%d.root", nrun)); 
  TTree *t = (TTree*) f->Get("T");

  Int_t NSampWaveForm;
  t->SetBranchAddress("Ndata.NPS.cal.fly.adcSampWaveform",&NSampWaveForm) ;
  Double_t SampWaveForm[10000];
  t->SetBranchAddress("NPS.cal.fly.adcSampWaveform",&SampWaveForm) ;

  TH1F *h_SampWaveForm[nblocks];

  for (Int_t n=0;n<nblocks;n++) {
    h_SampWaveForm[n] = new TH1F(Form("h_SampWaveForm_%d",n),"",maxSamp,0,maxSamp*4);
    h_SampWaveForm[n]->SetLineWidth(2);
    h_SampWaveForm[n]->SetLineColor(2);
    h_SampWaveForm[n]->GetYaxis()->SetRangeUser(-1,1);
  }

  Int_t SampPMT;
  Int_t NSamp;
  Double_t SampADC;
  
  Long64_t nentries = t->GetEntries();
  TCanvas *CanSamp= new TCanvas("canSamp", "NPS Calorimeter FADC Sample (EEL108) ", 600,1000);

 
  // --------------------------------------------------------------------------------

  int inp;

  for (int i = 0; i < nentries; i++) {

    t->GetEntry(i);
    
    if (i%10000==0) cout << " Entry = " << i << endl;
    
    for (Int_t n=0;n<nblocks;n++) {
      for (Int_t nn=0;nn<maxSamp;nn++) {
	h_SampWaveForm[n]->SetBinContent(nn,0);
      }
    }
    
    Int_t ns = 0;

    while (ns < NSampWaveForm) {
      SampPMT=SampWaveForm[ns++];

      NSamp=SampWaveForm[ns++];

      for (Int_t n=0;n<NSamp;n++) {
	SampADC=SampWaveForm[ns++];
	h_SampWaveForm[SampPMT]->SetBinContent(n,SampADC);
      }
    }	

    CanSamp->Clear();
    CanSamp->Update();

    CanSamp->Divide(2,9);
    
    CanSamp->cd(1);
    TLatex* tex = new TLatex(0.25,0.6,"EEL108");
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.4);
    tex->Draw();

    tex = new TLatex(0.25,0.2,"NPS Crate 2");
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.4);
    tex->Draw();

    CanSamp->cd(2);
    tex = new TLatex(0.35,0.8,Form("FADC Slot %d",slot));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(2);
    tex->SetTextSize(0.2);
    tex->Draw();

    tex = new TLatex(0.35,0.6,Form("Event %d",i+1));
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(2);
    tex->SetTextSize(0.2);
    tex->Draw();

    tex = new TLatex(0.35,0.4,"Amplitude (mV)");
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.2);
    tex->Draw();

    tex = new TLatex(0.35,0.2,"Time (ns)");
    tex->SetNDC(1);
    tex->SetTextFont(42);
    tex->SetTextColor(1);
    tex->SetTextSize(0.2);
    tex->Draw();

    for (Int_t n=(col-1)*16; n<(col-1)*16+nrows; n++) {
      CanSamp->cd(n+3-(col-1)*16);
      h_SampWaveForm[n]->Draw();
    }
    
    CanSamp->Update();

    cout << " Enter 1 for next event, event number, or 0 to quit" << endl;
    cin>> inp;
    if (inp !=1) i=inp;
    if (inp ==0) i=nentries;

  }
}
