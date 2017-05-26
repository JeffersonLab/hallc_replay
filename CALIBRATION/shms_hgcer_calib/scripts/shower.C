#define shower_cxx
#include "shower.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void shower::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L shower.C
//      Root > shower t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
  const Int_t nPreShowerBlocks = 14;
  const Int_t nShowerBlocks = 224;

  Double_t preShowerNeg_adc2GeV[nPreShowerBlocks] = {
    1.0/466.2, 1.0/514.7, 1.0/325.5, 1.0/247.8,
    1.0/322.0, 1.0/176.2, 1.0/161.9, 1.0/197.7,
    1.0/269.9, 1.0/241.6, 1.0/193.7, 1.0/337.5,
    1.0/237.3, 1.0/82.0
  };
  Double_t preShowerPos_adc2GeV[nPreShowerBlocks] = {
    1.0/411.2, 1.0/378.6, 1.0/357.9, 1.0/254.8,
    1.0/315.6, 1.0/331.0, 1.0/264.6, 1.0/305.4,
    1.0/149.8, 1.0/380.6, 1.0/183.1, 1.0/206.5,
    1.0/139.8, 1.0/163.1
  };
  Double_t shower_adc2GeV = 0.0005;
   TH2D* s_ps = new TH2D("s_ps", "Shower vs Preshower; Preshower; Shower", 100, -1, 30, 100, -1, 30);
   TH2D* s_ps_cutpi = new TH2D("s_ps_cutpi", "Shower vs Preshower (Cher pion cut); Preshower; Shower", 100, -1, 30, 100, -1, 30);
   TH2D* s_ps_cutelec = new TH2D("s_ps_cutelece", "Shower vs Preshower (Cher elec cut); Preshower; Shower", 100, -1, 30, 100, -1, 30);
  //
  TH1F *hNGCer_adc[4];
  TH2F *hNGCer_adc_pos[4];
  TH2F *hNGCer_pos[4];
  TH2F *hNGCer_rat[4];
  TH2F *hHGCer_adc_pos[4];
  TH2F *hHGCer_pos[4];
  TH2F *hHGCer_rat[4];
  TH1F *hHGCer_adc[4];
  TH1F *hNG_adc_sum;
  TH1F *hHG_adc_sum;
  TH2F *hNG_HG;
  for (Int_t npmt=0 ; npmt<4 ;npmt++) {
    hNGCer_adc[npmt] = new TH1F(Form("NGCer_adc_%d",npmt),Form("NG PMT %d ; NG Cer adc ; Counts ",npmt),100,0.,15000.);
    hNGCer_adc_pos[npmt] = new TH2F(Form("NGCer_adc_pos_%d",npmt),Form("NG PMT %d ADC weighted ; X  ; Y ",npmt),100,-40.,40,100,-40,40);
    hNGCer_pos[npmt] = new TH2F(Form("NGCer_pos_%d",npmt),Form("NG PMT %d  ; X  ; Y ",npmt),100,-40.,40,100,-40,40);
    hNGCer_rat[npmt] = new TH2F(Form("NGCer_adc_rat_%d",npmt),Form("NG PMT %d  ; X  ; Y ",npmt),100,-40.,40,100,-40,40);
    hHGCer_adc_pos[npmt] = new TH2F(Form("HGCer_adc_pos_%d",npmt),Form("HG PMT %d ADC weighted ; X  ; Y ",npmt),100,-80.,80,100,-80,80);
    hHGCer_pos[npmt] = new TH2F(Form("HGCer_pos_%d",npmt),Form("HG PMT %d  ; X  ; Y ",npmt),100,-80.,80,100,-80,80);
    hHGCer_rat[npmt] = new TH2F(Form("HGCer_adc_rat_%d",npmt),Form("HG PMT %d  ; X at Z=230 (cm) ; Y at Z=230 (cm) ",npmt),100,-80.,80,100,-80,80);
    hHGCer_adc[npmt] = new TH1F(Form("HGCer_adc_%d",npmt),Form("HG PMT %d ; HG Cer adc ; Counts ",npmt),100,0.,15000.);
  }
    hNGCer_adc_sum = new TH1F("NGCer_adc_sum","NG PMT Sum ; NG Cer sum adc ; Counts ",100,0.,20000.);
    hHGCer_adc_sum = new TH1F("HGCer_adc_sum","HG PMT Sum ; HG Cer sum adc ; Counts ",100,0.,20000.);
    hNG_HG = new TH2F("NG_HG","HG v NG ; NG Cer sum adc ;  NG Cer sum adc ",100,0.,20000.,100,0.,20000.);
	Double_t x_ng_pos,y_ng_pos;
	Double_t x_hg_pos,y_hg_pos;

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   //      nentries=10000;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (jentry%10000==0) cout << jentry << endl;
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if (P_tr_n > 0) {
	Double_t NGCer_adc_sum =0;
	Double_t HGCer_adc_sum =0;
	x_ng_pos=P_tr_x[0] + P_tr_th[0]*-40.;
	y_ng_pos=P_tr_y[0] + P_tr_ph[0]*-40.;
	x_hg_pos=P_tr_x[0] + P_tr_th[0]*230.;
	y_hg_pos=P_tr_y[0] + P_tr_ph[0]*230.;
      for (Int_t npmt=0 ; npmt<4 ;npmt++) {
		hNGCer_adc[npmt]->Fill(P_ngcer_adc_p[npmt]);
		hHGCer_adc[npmt]->Fill(P_hgcer_adc_p[npmt]);
		NGCer_adc_sum = NGCer_adc_sum + P_ngcer_adc_p[npmt];
		HGCer_adc_sum = HGCer_adc_sum + P_hgcer_adc_p[npmt];
                hNGCer_pos[npmt]->Fill(x_ng_pos,y_ng_pos);
                if (P_ngcer_adc_p[npmt]>20) hNGCer_adc_pos[npmt]->Fill(x_ng_pos,y_hg_pos,P_ngcer_adc_p[npmt]);
                hHGCer_pos[npmt]->Fill(x_hg_pos,y_hg_pos);
                if (P_hgcer_adc_p[npmt]>20) hHGCer_adc_pos[npmt]->Fill(x_hg_pos,y_hg_pos,P_hgcer_adc_p[npmt]);
	}
      hNGCer_adc_sum->Fill(NGCer_adc_sum);
      hHGCer_adc_sum->Fill(HGCer_adc_sum);
      hNG_HG->Fill(NGCer_adc_sum,HGCer_adc_sum);
      
     }
      //
      if (P_tr_n==1 && fabs(P_tr_x[0] + P_tr_th[0]*330 + 9)<9 || fabs(P_tr_y[0] + P_tr_ph[0]*330 - 9)<9) {
       Double_t preShower_energy = 0.0;
       for (Int_t iPS=0; iPS<Ndata_P_cal_pr_posAdcCounter; ++iPS) {
       Int_t psc = P_cal_pr_posAdcCounter[iPS];
        if (psc==7) {
	  if ((P_cal_pr_posAdcPulseInt[iPS]*preShowerPos_adc2GeV[psc-1]) > 0.1) preShower_energy += P_cal_pr_posAdcPulseInt[iPS] * preShowerPos_adc2GeV[psc-1];
        }
       }
      //
    Double_t shower_energy = 0.0;
    for (Int_t iS=0; iS<Ndata_P_cal_fly_adcCounter; ++iS) {
      Int_t sc = P_cal_fly_adcCounter[iS];
      if ( sc==104) {
	if ((P_cal_fly_adcPulseInt[iS]*shower_adc2GeV)>.1) shower_energy += P_cal_fly_adcPulseInt[iS] * shower_adc2GeV;
      }
    }
    if (shower_energy > .1 && preShower_energy> .1) {
    s_ps->Fill(preShower_energy,shower_energy );
      if (NGCer_adc_sum>2000 && HGCer_adc_sum>500) s_ps_cutelec->Fill(preShower_energy,shower_energy );
      if (NGCer_adc_sum<2000 && HGCer_adc_sum<500) s_ps_cutpi->Fill(preShower_energy,shower_energy );
    }
      } // shower check
      //
   }

   //
TCanvas *cplot3 = new TCanvas("cplot3"," NG Cer",800,800);
 cplot3->Divide(2,3);
       cplot3->SetLogy();
     for (Int_t npmt=0 ; npmt<4 ;npmt++) {
       cplot3->cd(npmt+1);
          hNGCer_adc[npmt]->Draw();   
    }
        cplot3->cd(5);
       hNGCer_adc_sum->Draw();
TCanvas *cplot4 = new TCanvas("cplot4"," HG Cer",800,800);
 cplot4->Divide(2,3);
       cplot4->SetLogy();
     for (Int_t npmt=0 ; npmt<4 ;npmt++) {
       cplot4->cd(npmt+1);
          hHGCer_adc[npmt]->Draw();   
    }
        cplot4->cd(5);
       hHGCer_adc_sum->Draw();
TCanvas *cplot5 = new TCanvas("cplot5"," HG Cer v NG cer",800,800);
 cplot5->Divide(1,1);
 cplot5->cd(1);
 hNG_HG->Draw("colz");
TCanvas *cplot7 = new TCanvas("cplot7"," NG X vs Y ADC",800,800);
 cplot7->Divide(2,2);
     for (Int_t npmt=0 ; npmt<4 ;npmt++) {
       cplot7->cd(npmt+1);
       hNGCer_rat[npmt]->Divide(hNGCer_adc_pos[npmt],hNGCer_pos[npmt],1.,1.,"B");
       hNGCer_rat[npmt]->SetMinimum(100);
       hNGCer_rat[npmt]->SetMaximum(20000);
       hNGCer_rat[npmt]->Draw("colz");   
    }
TCanvas *cplot8 = new TCanvas("cplot8"," HG X vs Y ADC",800,800);
 cplot8->Divide(2,2);
     for (Int_t npmt=0 ; npmt<4 ;npmt++) {
       cplot8->cd(npmt+1);
       hHGCer_rat[npmt]->Divide(hHGCer_adc_pos[npmt],hHGCer_pos[npmt],1.,1.,"B");
       hHGCer_rat[npmt]->SetMinimum(10);
       hHGCer_rat[npmt]->SetMaximum(20000);
       hHGCer_rat[npmt]->Draw("colz");   
    }
TCanvas *cplot6 = new TCanvas("cplot6"," Shower v Preshower",800,800);
 cplot6->Divide(2,2);
 cplot6->cd(1);
 s_ps->Draw("colz");
 cplot6->cd(2);
 s_ps_cutpi->Draw("colz");
 cplot6->cd(3);
 s_ps_cutelec->Draw("colz");
   //
}
