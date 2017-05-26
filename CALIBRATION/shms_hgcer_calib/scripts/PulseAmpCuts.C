void PulseAmpCuts()
{
  TFile *F = new TFile("../root_files/shms_calibration_488.root");

  TH1F *hgc_PulseAmp_cut10[4];
  TH1F *hgc_PulseAmp_cut20[4];
  TH1F *hgc_PulseAmp_cut30[4];
  TH1F *hgc_PulseAmp_cut40[4];
  TH1F *hgc_PulseAmp_cut50[4];
  TH1F *hgc_PulseAmp_cut60[4];
  TH1F *hgc_PulseAmp_cut70[4];

  hgc_PulseAmp_cut10[0] = (TH1F*)F->Get("phgc_pulseAmp_101");
  hgc_PulseAmp_cut10[1] = (TH1F*)F->Get("phgc_pulseAmp_102");
  hgc_PulseAmp_cut10[2] = (TH1F*)F->Get("phgc_pulseAmp_103");
  hgc_PulseAmp_cut10[3] = (TH1F*)F->Get("phgc_pulseAmp_104");

  hgc_PulseAmp_cut20[0] = (TH1F*)F->Get("phgc_pulseAmp_201");
  hgc_PulseAmp_cut20[1] = (TH1F*)F->Get("phgc_pulseAmp_202");
  hgc_PulseAmp_cut20[2] = (TH1F*)F->Get("phgc_pulseAmp_203");
  hgc_PulseAmp_cut20[3] = (TH1F*)F->Get("phgc_pulseAmp_204");

  hgc_PulseAmp_cut30[0] = (TH1F*)F->Get("phgc_pulseAmp_301");
  hgc_PulseAmp_cut30[1] = (TH1F*)F->Get("phgc_pulseAmp_302");
  hgc_PulseAmp_cut30[2] = (TH1F*)F->Get("phgc_pulseAmp_303");
  hgc_PulseAmp_cut30[3] = (TH1F*)F->Get("phgc_pulseAmp_304");

  hgc_PulseAmp_cut40[0] = (TH1F*)F->Get("phgc_pulseAmp_401");
  hgc_PulseAmp_cut40[1] = (TH1F*)F->Get("phgc_pulseAmp_402");
  hgc_PulseAmp_cut40[2] = (TH1F*)F->Get("phgc_pulseAmp_403");
  hgc_PulseAmp_cut40[3] = (TH1F*)F->Get("phgc_pulseAmp_404");

  hgc_PulseAmp_cut50[0] = (TH1F*)F->Get("phgc_pulseAmp_501");
  hgc_PulseAmp_cut50[1] = (TH1F*)F->Get("phgc_pulseAmp_502");
  hgc_PulseAmp_cut50[2] = (TH1F*)F->Get("phgc_pulseAmp_503");
  hgc_PulseAmp_cut50[3] = (TH1F*)F->Get("phgc_pulseAmp_504");

  hgc_PulseAmp_cut60[0] = (TH1F*)F->Get("phgc_pulseAmp_601");
  hgc_PulseAmp_cut60[1] = (TH1F*)F->Get("phgc_pulseAmp_602");
  hgc_PulseAmp_cut60[2] = (TH1F*)F->Get("phgc_pulseAmp_603");
  hgc_PulseAmp_cut60[3] = (TH1F*)F->Get("phgc_pulseAmp_604");

  hgc_PulseAmp_cut70[0] = (TH1F*)F->Get("phgc_pulseAmp_701");
  hgc_PulseAmp_cut70[1] = (TH1F*)F->Get("phgc_pulseAmp_702");
  hgc_PulseAmp_cut70[2] = (TH1F*)F->Get("phgc_pulseAmp_703");
  hgc_PulseAmp_cut70[3] = (TH1F*)F->Get("phgc_pulseAmp_704");

  TCanvas *c1 = new TCanvas("c1", "PulseAmp cuts for each PMT", 1200, 600);
  c1->Divide(2,2);

  c1->cd(1);
  c1->cd(1)->SetLogy();
  hgc_PulseAmp_cut10[0]->SetLineColor(2);
  hgc_PulseAmp_cut10[0]->SetLineWidth(2);
  hgc_PulseAmp_cut20[0]->SetLineColor(46);
  hgc_PulseAmp_cut20[0]->SetLineWidth(2);
  hgc_PulseAmp_cut30[0]->SetLineColor(45);
  hgc_PulseAmp_cut30[0]->SetLineWidth(2);
  hgc_PulseAmp_cut40[0]->SetLineColor(44);
  hgc_PulseAmp_cut40[0]->SetLineWidth(2);
  hgc_PulseAmp_cut50[0]->SetLineColor(43);
  hgc_PulseAmp_cut50[0]->SetLineWidth(2);
  hgc_PulseAmp_cut60[0]->SetLineColor(42);
  hgc_PulseAmp_cut60[0]->SetLineWidth(2);
  hgc_PulseAmp_cut70[0]->SetLineColor(41);
  hgc_PulseAmp_cut70[0]->SetLineWidth(2);
  
  hgc_PulseAmp_cut70[0]->SetTitle("Points Removed with PulseAmp from 10 - 70 (mV) PMT1");
  hgc_PulseAmp_cut70[0]->GetXaxis()->SetRangeUser(0,2000);
  hgc_PulseAmp_cut70[0]->Draw();
  hgc_PulseAmp_cut10[0]->Draw("same");
  hgc_PulseAmp_cut20[0]->Draw("same");
  hgc_PulseAmp_cut30[0]->Draw("same");
  hgc_PulseAmp_cut40[0]->Draw("same");
  hgc_PulseAmp_cut50[0]->Draw("same");
  hgc_PulseAmp_cut60[0]->Draw("same");
 

  c1->cd(2);
  c1->cd(2)->SetLogy();
  hgc_PulseAmp_cut10[1]->SetLineColor(2);
  hgc_PulseAmp_cut10[1]->SetLineWidth(2);
  hgc_PulseAmp_cut20[1]->SetLineColor(46);
  hgc_PulseAmp_cut20[1]->SetLineWidth(2);
  hgc_PulseAmp_cut30[1]->SetLineColor(45);
  hgc_PulseAmp_cut30[1]->SetLineWidth(2);
  hgc_PulseAmp_cut40[1]->SetLineColor(44);
  hgc_PulseAmp_cut40[1]->SetLineWidth(2);
  hgc_PulseAmp_cut50[1]->SetLineColor(43);
  hgc_PulseAmp_cut50[1]->SetLineWidth(2);
  hgc_PulseAmp_cut60[1]->SetLineColor(42);
  hgc_PulseAmp_cut60[1]->SetLineWidth(2);
  hgc_PulseAmp_cut70[1]->SetLineColor(41);
  hgc_PulseAmp_cut70[1]->SetLineWidth(2);

  hgc_PulseAmp_cut70[1]->SetTitle("Points Removed with PulseAmp from 10 - 70 (mV) PMT2");
  hgc_PulseAmp_cut70[1]->GetXaxis()->SetRangeUser(0,2000);
  hgc_PulseAmp_cut70[1]->Draw();
  hgc_PulseAmp_cut10[1]->Draw("same");
  hgc_PulseAmp_cut20[1]->Draw("same");
  hgc_PulseAmp_cut30[1]->Draw("same");
  hgc_PulseAmp_cut40[1]->Draw("same");
  hgc_PulseAmp_cut50[1]->Draw("same");
  hgc_PulseAmp_cut60[1]->Draw("same");

  c1->cd(3);
  c1->cd(3)->SetLogy();
  hgc_PulseAmp_cut10[2]->SetLineColor(2);
  hgc_PulseAmp_cut10[2]->SetLineWidth(2);
  hgc_PulseAmp_cut20[2]->SetLineColor(46);
  hgc_PulseAmp_cut20[2]->SetLineWidth(2);
  hgc_PulseAmp_cut30[2]->SetLineColor(45);
  hgc_PulseAmp_cut30[2]->SetLineWidth(2);
  hgc_PulseAmp_cut40[2]->SetLineColor(44);
  hgc_PulseAmp_cut40[2]->SetLineWidth(2);
  hgc_PulseAmp_cut50[2]->SetLineColor(43);
  hgc_PulseAmp_cut50[2]->SetLineWidth(2);
  hgc_PulseAmp_cut60[2]->SetLineColor(42);
  hgc_PulseAmp_cut60[2]->SetLineWidth(2);
  hgc_PulseAmp_cut70[2]->SetLineColor(41);
  hgc_PulseAmp_cut70[2]->SetLineWidth(2);

  hgc_PulseAmp_cut70[2]->SetTitle("Points Removed with PulseAmp from 10 - 70 (mV) PMT3");
  hgc_PulseAmp_cut70[2]->GetXaxis()->SetRangeUser(0,2000);
  hgc_PulseAmp_cut70[2]->Draw();
  hgc_PulseAmp_cut20[2]->Draw("same");
  hgc_PulseAmp_cut30[2]->Draw("same");
  hgc_PulseAmp_cut40[2]->Draw("same");
  hgc_PulseAmp_cut50[2]->Draw("same");
  hgc_PulseAmp_cut60[2]->Draw("same");
  hgc_PulseAmp_cut10[2]->Draw("same");

  c1->cd(4);
  c1->cd(4)->SetLogy();
  hgc_PulseAmp_cut10[3]->SetLineColor(2);
  hgc_PulseAmp_cut10[3]->SetLineWidth(2);
  hgc_PulseAmp_cut20[3]->SetLineColor(46);
  hgc_PulseAmp_cut20[3]->SetLineWidth(2);
  hgc_PulseAmp_cut30[3]->SetLineColor(45);
  hgc_PulseAmp_cut30[3]->SetLineWidth(2);
  hgc_PulseAmp_cut40[3]->SetLineColor(44);
  hgc_PulseAmp_cut40[3]->SetLineWidth(2);
  hgc_PulseAmp_cut50[3]->SetLineColor(43);
  hgc_PulseAmp_cut50[3]->SetLineWidth(2);
  hgc_PulseAmp_cut60[3]->SetLineColor(42);
  hgc_PulseAmp_cut60[3]->SetLineWidth(2);
  hgc_PulseAmp_cut70[3]->SetLineColor(41);
  hgc_PulseAmp_cut70[3]->SetLineWidth(2);

  hgc_PulseAmp_cut70[3]->SetTitle("Points Removed with PulseAmp from 10 - 70 (mV) PMT4");
  hgc_PulseAmp_cut70[3]->GetXaxis()->SetRangeUser(0,2000);
  hgc_PulseAmp_cut70[3]->Draw();
  hgc_PulseAmp_cut20[3]->Draw("same");
  hgc_PulseAmp_cut30[3]->Draw("same");
  hgc_PulseAmp_cut40[3]->Draw("same");
  hgc_PulseAmp_cut50[3]->Draw("same");
  hgc_PulseAmp_cut60[3]->Draw("same");
  hgc_PulseAmp_cut10[3]->Draw("same");

}
