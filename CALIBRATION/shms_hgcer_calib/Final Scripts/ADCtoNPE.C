void ADCtoNPE(Int_t RunNumber=487)
{
  /*
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
  */
  TFile *F = new TFile("../root_files/shms_calibration_487.root");
  Double_t hgc_adc2npe[4] = {1.0/550.0, 1.0/450.0, 1.0/390.0, 1.0/450.0};

  TH1F *hgc_spectra[4];
  TH1F *hgc_spectra_conv[4];
  TH2F *hgc_mirrorplane[4];
  int nbins;


  for (int i=0;i<4;i++)
    {
      hgc_spectra[i] = (TH1F*)F->Get(Form("phgc_adcPulseInt%d",i+1));
      nbins = hgc_spectra[i]->GetXaxis()->GetNbins();
      hgc_spectra_conv[i] = new TH1F(Form("hgc_spectra_conv%d",i+1),"title",nbins,0,12);
      cout <<  nbins << endl;
      for (int k=0;k<=nbins;k++)
	{	  
	  Double_t y = hgc_spectra[i]->GetBinContent(k);
	  Double_t x = hgc_spectra[i]->GetXaxis()->GetBinCenter(k);
	  Double_t xnew = hgc_adc2npe[i]*x;
	  hgc_spectra_conv[i]->Fill(xnew,y);
	}
      hgc_mirrorplane[i] = (TH2F*)F->Get(Form("ptrk_h2_hgc%d_PulseInt",i+1));
    }
  



  TCanvas *c0 = new TCanvas();
  hgc_spectra_conv[0]->Draw();


}
