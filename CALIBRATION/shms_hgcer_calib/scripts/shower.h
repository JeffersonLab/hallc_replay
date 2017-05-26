//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Mar 10 06:57:50 2017 by ROOT version 5.34/36
// from TTree T/Hall A Analyzer Output DST
// found on file: ROOTfiles/shms_replay_488_1000000.root
//////////////////////////////////////////////////////////

#ifndef shower_h
#define shower_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class shower {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           Ndata_P_aero_aneg;
   Double_t        P_aero_aneg[7];   //[Ndata.P.aero.aneg]
   Int_t           Ndata_P_aero_aneg_p;
   Double_t        P_aero_aneg_p[7];   //[Ndata.P.aero.aneg_p]
   Int_t           Ndata_P_aero_apos;
   Double_t        P_aero_apos[7];   //[Ndata.P.aero.apos]
   Int_t           Ndata_P_aero_apos_p;
   Double_t        P_aero_apos_p[7];   //[Ndata.P.aero.apos_p]
   Int_t           Ndata_P_aero_negAdcCounter;
   Double_t        P_aero_negAdcCounter[7];   //[Ndata.P.aero.negAdcCounter]
   Int_t           Ndata_P_aero_negAdcPed;
   Double_t        P_aero_negAdcPed[7];   //[Ndata.P.aero.negAdcPed]
   Int_t           Ndata_P_aero_negAdcPedRaw;
   Double_t        P_aero_negAdcPedRaw[7];   //[Ndata.P.aero.negAdcPedRaw]
   Int_t           Ndata_P_aero_negAdcPulseAmp;
   Double_t        P_aero_negAdcPulseAmp[7];   //[Ndata.P.aero.negAdcPulseAmp]
   Int_t           Ndata_P_aero_negAdcPulseAmpRaw;
   Double_t        P_aero_negAdcPulseAmpRaw[7];   //[Ndata.P.aero.negAdcPulseAmpRaw]
   Int_t           Ndata_P_aero_negAdcPulseInt;
   Double_t        P_aero_negAdcPulseInt[7];   //[Ndata.P.aero.negAdcPulseInt]
   Int_t           Ndata_P_aero_negAdcPulseIntRaw;
   Double_t        P_aero_negAdcPulseIntRaw[7];   //[Ndata.P.aero.negAdcPulseIntRaw]
   Int_t           Ndata_P_aero_negAdcPulseTimeRaw;
   Double_t        P_aero_negAdcPulseTimeRaw[7];   //[Ndata.P.aero.negAdcPulseTimeRaw]
   Int_t           Ndata_P_aero_neg_npe;
   Double_t        P_aero_neg_npe[7];   //[Ndata.P.aero.neg_npe]
   Int_t           Ndata_P_aero_negadchits;
   Double_t        P_aero_negadchits[7];   //[Ndata.P.aero.negadchits]
   Int_t           Ndata_P_aero_negtdchits;
   Double_t        P_aero_negtdchits[1];   //[Ndata.P.aero.negtdchits]
   Int_t           Ndata_P_aero_posAdcCounter;
   Double_t        P_aero_posAdcCounter[7];   //[Ndata.P.aero.posAdcCounter]
   Int_t           Ndata_P_aero_posAdcPed;
   Double_t        P_aero_posAdcPed[7];   //[Ndata.P.aero.posAdcPed]
   Int_t           Ndata_P_aero_posAdcPedRaw;
   Double_t        P_aero_posAdcPedRaw[7];   //[Ndata.P.aero.posAdcPedRaw]
   Int_t           Ndata_P_aero_posAdcPulseAmp;
   Double_t        P_aero_posAdcPulseAmp[7];   //[Ndata.P.aero.posAdcPulseAmp]
   Int_t           Ndata_P_aero_posAdcPulseAmpRaw;
   Double_t        P_aero_posAdcPulseAmpRaw[7];   //[Ndata.P.aero.posAdcPulseAmpRaw]
   Int_t           Ndata_P_aero_posAdcPulseInt;
   Double_t        P_aero_posAdcPulseInt[7];   //[Ndata.P.aero.posAdcPulseInt]
   Int_t           Ndata_P_aero_posAdcPulseIntRaw;
   Double_t        P_aero_posAdcPulseIntRaw[7];   //[Ndata.P.aero.posAdcPulseIntRaw]
   Int_t           Ndata_P_aero_posAdcPulseTimeRaw;
   Double_t        P_aero_posAdcPulseTimeRaw[7];   //[Ndata.P.aero.posAdcPulseTimeRaw]
   Int_t           Ndata_P_aero_pos_npe;
   Double_t        P_aero_pos_npe[7];   //[Ndata.P.aero.pos_npe]
   Int_t           Ndata_P_aero_posadchits;
   Double_t        P_aero_posadchits[7];   //[Ndata.P.aero.posadchits]
   Int_t           Ndata_P_aero_postdchits;
   Double_t        P_aero_postdchits[1];   //[Ndata.P.aero.postdchits]
   Int_t           Ndata_P_aero_tneg;
   Double_t        P_aero_tneg[7];   //[Ndata.P.aero.tneg]
   Int_t           Ndata_P_aero_tpos;
   Double_t        P_aero_tpos[7];   //[Ndata.P.aero.tpos]
   Int_t           Ndata_P_cal_fly_a;
   Double_t        P_cal_fly_a[224];   //[Ndata.P.cal.fly.a]
   Int_t           Ndata_P_cal_fly_a_p;
   Double_t        P_cal_fly_a_p[224];   //[Ndata.P.cal.fly.a_p]
   Int_t           Ndata_P_cal_fly_adcCounter;
   Double_t        P_cal_fly_adcCounter[22];   //[Ndata.P.cal.fly.adcCounter]
   Int_t           Ndata_P_cal_fly_adcPed;
   Double_t        P_cal_fly_adcPed[22];   //[Ndata.P.cal.fly.adcPed]
   Int_t           Ndata_P_cal_fly_adcPedRaw;
   Double_t        P_cal_fly_adcPedRaw[22];   //[Ndata.P.cal.fly.adcPedRaw]
   Int_t           Ndata_P_cal_fly_adcPulseAmp;
   Double_t        P_cal_fly_adcPulseAmp[22];   //[Ndata.P.cal.fly.adcPulseAmp]
   Int_t           Ndata_P_cal_fly_adcPulseAmpRaw;
   Double_t        P_cal_fly_adcPulseAmpRaw[22];   //[Ndata.P.cal.fly.adcPulseAmpRaw]
   Int_t           Ndata_P_cal_fly_adcPulseInt;
   Double_t        P_cal_fly_adcPulseInt[22];   //[Ndata.P.cal.fly.adcPulseInt]
   Int_t           Ndata_P_cal_fly_adcPulseIntRaw;
   Double_t        P_cal_fly_adcPulseIntRaw[22];   //[Ndata.P.cal.fly.adcPulseIntRaw]
   Int_t           Ndata_P_cal_fly_adcPulseTimeRaw;
   Double_t        P_cal_fly_adcPulseTimeRaw[22];   //[Ndata.P.cal.fly.adcPulseTimeRaw]
   Int_t           Ndata_P_cal_fly_adchits;
   Double_t        P_cal_fly_adchits[1];   //[Ndata.P.cal.fly.adchits]
   Int_t           Ndata_P_cal_fly_e;
   Double_t        P_cal_fly_e[224];   //[Ndata.P.cal.fly.e]
   Int_t           Ndata_P_cal_fly_p;
   Double_t        P_cal_fly_p[224];   //[Ndata.P.cal.fly.p]
   Int_t           Ndata_P_cal_pr_aneg;
   Double_t        P_cal_pr_aneg[14];   //[Ndata.P.cal.pr.aneg]
   Int_t           Ndata_P_cal_pr_aneg_p;
   Double_t        P_cal_pr_aneg_p[14];   //[Ndata.P.cal.pr.aneg_p]
   Int_t           Ndata_P_cal_pr_apos;
   Double_t        P_cal_pr_apos[14];   //[Ndata.P.cal.pr.apos]
   Int_t           Ndata_P_cal_pr_apos_p;
   Double_t        P_cal_pr_apos_p[14];   //[Ndata.P.cal.pr.apos_p]
   Int_t           Ndata_P_cal_pr_emean;
   Double_t        P_cal_pr_emean[14];   //[Ndata.P.cal.pr.emean]
   Int_t           Ndata_P_cal_pr_eneg;
   Double_t        P_cal_pr_eneg[14];   //[Ndata.P.cal.pr.eneg]
   Int_t           Ndata_P_cal_pr_epos;
   Double_t        P_cal_pr_epos[14];   //[Ndata.P.cal.pr.epos]
   Int_t           Ndata_P_cal_pr_negAdcCounter;
   Double_t        P_cal_pr_negAdcCounter[9];   //[Ndata.P.cal.pr.negAdcCounter]
   Int_t           Ndata_P_cal_pr_negAdcPed;
   Double_t        P_cal_pr_negAdcPed[9];   //[Ndata.P.cal.pr.negAdcPed]
   Int_t           Ndata_P_cal_pr_negAdcPedRaw;
   Double_t        P_cal_pr_negAdcPedRaw[9];   //[Ndata.P.cal.pr.negAdcPedRaw]
   Int_t           Ndata_P_cal_pr_negAdcPulseAmp;
   Double_t        P_cal_pr_negAdcPulseAmp[9];   //[Ndata.P.cal.pr.negAdcPulseAmp]
   Int_t           Ndata_P_cal_pr_negAdcPulseAmpRaw;
   Double_t        P_cal_pr_negAdcPulseAmpRaw[9];   //[Ndata.P.cal.pr.negAdcPulseAmpRaw]
   Int_t           Ndata_P_cal_pr_negAdcPulseInt;
   Double_t        P_cal_pr_negAdcPulseInt[9];   //[Ndata.P.cal.pr.negAdcPulseInt]
   Int_t           Ndata_P_cal_pr_negAdcPulseIntRaw;
   Double_t        P_cal_pr_negAdcPulseIntRaw[9];   //[Ndata.P.cal.pr.negAdcPulseIntRaw]
   Int_t           Ndata_P_cal_pr_negAdcPulseTimeRaw;
   Double_t        P_cal_pr_negAdcPulseTimeRaw[9];   //[Ndata.P.cal.pr.negAdcPulseTimeRaw]
   Int_t           Ndata_P_cal_pr_negadchits;
   Double_t        P_cal_pr_negadchits[1];   //[Ndata.P.cal.pr.negadchits]
   Int_t           Ndata_P_cal_pr_posAdcCounter;
   Double_t        P_cal_pr_posAdcCounter[14];   //[Ndata.P.cal.pr.posAdcCounter]
   Int_t           Ndata_P_cal_pr_posAdcPed;
   Double_t        P_cal_pr_posAdcPed[14];   //[Ndata.P.cal.pr.posAdcPed]
   Int_t           Ndata_P_cal_pr_posAdcPedRaw;
   Double_t        P_cal_pr_posAdcPedRaw[14];   //[Ndata.P.cal.pr.posAdcPedRaw]
   Int_t           Ndata_P_cal_pr_posAdcPulseAmp;
   Double_t        P_cal_pr_posAdcPulseAmp[14];   //[Ndata.P.cal.pr.posAdcPulseAmp]
   Int_t           Ndata_P_cal_pr_posAdcPulseAmpRaw;
   Double_t        P_cal_pr_posAdcPulseAmpRaw[14];   //[Ndata.P.cal.pr.posAdcPulseAmpRaw]
   Int_t           Ndata_P_cal_pr_posAdcPulseInt;
   Double_t        P_cal_pr_posAdcPulseInt[14];   //[Ndata.P.cal.pr.posAdcPulseInt]
   Int_t           Ndata_P_cal_pr_posAdcPulseIntRaw;
   Double_t        P_cal_pr_posAdcPulseIntRaw[14];   //[Ndata.P.cal.pr.posAdcPulseIntRaw]
   Int_t           Ndata_P_cal_pr_posAdcPulseTimeRaw;
   Double_t        P_cal_pr_posAdcPulseTimeRaw[14];   //[Ndata.P.cal.pr.posAdcPulseTimeRaw]
   Int_t           Ndata_P_cal_pr_posadchits;
   Double_t        P_cal_pr_posadchits[1];   //[Ndata.P.cal.pr.posadchits]
   Int_t           Ndata_P_dc_1u1_dist;
   Double_t        P_dc_1u1_dist[53];   //[Ndata.P.dc.1u1.dist]
   Int_t           Ndata_P_dc_1u1_rawtdc;
   Double_t        P_dc_1u1_rawtdc[53];   //[Ndata.P.dc.1u1.rawtdc]
   Int_t           Ndata_P_dc_1u1_time;
   Double_t        P_dc_1u1_time[53];   //[Ndata.P.dc.1u1.time]
   Int_t           Ndata_P_dc_1u1_wirenum;
   Double_t        P_dc_1u1_wirenum[53];   //[Ndata.P.dc.1u1.wirenum]
   Int_t           Ndata_P_dc_1u2_dist;
   Double_t        P_dc_1u2_dist[37];   //[Ndata.P.dc.1u2.dist]
   Int_t           Ndata_P_dc_1u2_rawtdc;
   Double_t        P_dc_1u2_rawtdc[37];   //[Ndata.P.dc.1u2.rawtdc]
   Int_t           Ndata_P_dc_1u2_time;
   Double_t        P_dc_1u2_time[37];   //[Ndata.P.dc.1u2.time]
   Int_t           Ndata_P_dc_1u2_wirenum;
   Double_t        P_dc_1u2_wirenum[37];   //[Ndata.P.dc.1u2.wirenum]
   Int_t           Ndata_P_dc_1v1_dist;
   Double_t        P_dc_1v1_dist[53];   //[Ndata.P.dc.1v1.dist]
   Int_t           Ndata_P_dc_1v1_rawtdc;
   Double_t        P_dc_1v1_rawtdc[53];   //[Ndata.P.dc.1v1.rawtdc]
   Int_t           Ndata_P_dc_1v1_time;
   Double_t        P_dc_1v1_time[53];   //[Ndata.P.dc.1v1.time]
   Int_t           Ndata_P_dc_1v1_wirenum;
   Double_t        P_dc_1v1_wirenum[53];   //[Ndata.P.dc.1v1.wirenum]
   Int_t           Ndata_P_dc_1v2_dist;
   Double_t        P_dc_1v2_dist[75];   //[Ndata.P.dc.1v2.dist]
   Int_t           Ndata_P_dc_1v2_rawtdc;
   Double_t        P_dc_1v2_rawtdc[75];   //[Ndata.P.dc.1v2.rawtdc]
   Int_t           Ndata_P_dc_1v2_time;
   Double_t        P_dc_1v2_time[75];   //[Ndata.P.dc.1v2.time]
   Int_t           Ndata_P_dc_1v2_wirenum;
   Double_t        P_dc_1v2_wirenum[75];   //[Ndata.P.dc.1v2.wirenum]
   Int_t           Ndata_P_dc_1x1_dist;
   Double_t        P_dc_1x1_dist[54];   //[Ndata.P.dc.1x1.dist]
   Int_t           Ndata_P_dc_1x1_rawtdc;
   Double_t        P_dc_1x1_rawtdc[54];   //[Ndata.P.dc.1x1.rawtdc]
   Int_t           Ndata_P_dc_1x1_time;
   Double_t        P_dc_1x1_time[54];   //[Ndata.P.dc.1x1.time]
   Int_t           Ndata_P_dc_1x1_wirenum;
   Double_t        P_dc_1x1_wirenum[54];   //[Ndata.P.dc.1x1.wirenum]
   Int_t           Ndata_P_dc_1x2_dist;
   Double_t        P_dc_1x2_dist[78];   //[Ndata.P.dc.1x2.dist]
   Int_t           Ndata_P_dc_1x2_rawtdc;
   Double_t        P_dc_1x2_rawtdc[78];   //[Ndata.P.dc.1x2.rawtdc]
   Int_t           Ndata_P_dc_1x2_time;
   Double_t        P_dc_1x2_time[78];   //[Ndata.P.dc.1x2.time]
   Int_t           Ndata_P_dc_1x2_wirenum;
   Double_t        P_dc_1x2_wirenum[78];   //[Ndata.P.dc.1x2.wirenum]
   Int_t           Ndata_P_dc_2u1_dist;
   Double_t        P_dc_2u1_dist[55];   //[Ndata.P.dc.2u1.dist]
   Int_t           Ndata_P_dc_2u1_rawtdc;
   Double_t        P_dc_2u1_rawtdc[55];   //[Ndata.P.dc.2u1.rawtdc]
   Int_t           Ndata_P_dc_2u1_time;
   Double_t        P_dc_2u1_time[55];   //[Ndata.P.dc.2u1.time]
   Int_t           Ndata_P_dc_2u1_wirenum;
   Double_t        P_dc_2u1_wirenum[55];   //[Ndata.P.dc.2u1.wirenum]
   Int_t           Ndata_P_dc_2u2_dist;
   Double_t        P_dc_2u2_dist[40];   //[Ndata.P.dc.2u2.dist]
   Int_t           Ndata_P_dc_2u2_rawtdc;
   Double_t        P_dc_2u2_rawtdc[40];   //[Ndata.P.dc.2u2.rawtdc]
   Int_t           Ndata_P_dc_2u2_time;
   Double_t        P_dc_2u2_time[40];   //[Ndata.P.dc.2u2.time]
   Int_t           Ndata_P_dc_2u2_wirenum;
   Double_t        P_dc_2u2_wirenum[40];   //[Ndata.P.dc.2u2.wirenum]
   Int_t           Ndata_P_dc_2v1_dist;
   Double_t        P_dc_2v1_dist[53];   //[Ndata.P.dc.2v1.dist]
   Int_t           Ndata_P_dc_2v1_rawtdc;
   Double_t        P_dc_2v1_rawtdc[53];   //[Ndata.P.dc.2v1.rawtdc]
   Int_t           Ndata_P_dc_2v1_time;
   Double_t        P_dc_2v1_time[53];   //[Ndata.P.dc.2v1.time]
   Int_t           Ndata_P_dc_2v1_wirenum;
   Double_t        P_dc_2v1_wirenum[53];   //[Ndata.P.dc.2v1.wirenum]
   Int_t           Ndata_P_dc_2v2_dist;
   Double_t        P_dc_2v2_dist[57];   //[Ndata.P.dc.2v2.dist]
   Int_t           Ndata_P_dc_2v2_rawtdc;
   Double_t        P_dc_2v2_rawtdc[57];   //[Ndata.P.dc.2v2.rawtdc]
   Int_t           Ndata_P_dc_2v2_time;
   Double_t        P_dc_2v2_time[57];   //[Ndata.P.dc.2v2.time]
   Int_t           Ndata_P_dc_2v2_wirenum;
   Double_t        P_dc_2v2_wirenum[57];   //[Ndata.P.dc.2v2.wirenum]
   Int_t           Ndata_P_dc_2x1_dist;
   Double_t        P_dc_2x1_dist[69];   //[Ndata.P.dc.2x1.dist]
   Int_t           Ndata_P_dc_2x1_rawtdc;
   Double_t        P_dc_2x1_rawtdc[69];   //[Ndata.P.dc.2x1.rawtdc]
   Int_t           Ndata_P_dc_2x1_time;
   Double_t        P_dc_2x1_time[69];   //[Ndata.P.dc.2x1.time]
   Int_t           Ndata_P_dc_2x1_wirenum;
   Double_t        P_dc_2x1_wirenum[69];   //[Ndata.P.dc.2x1.wirenum]
   Int_t           Ndata_P_dc_2x2_dist;
   Double_t        P_dc_2x2_dist[48];   //[Ndata.P.dc.2x2.dist]
   Int_t           Ndata_P_dc_2x2_rawtdc;
   Double_t        P_dc_2x2_rawtdc[48];   //[Ndata.P.dc.2x2.rawtdc]
   Int_t           Ndata_P_dc_2x2_time;
   Double_t        P_dc_2x2_time[48];   //[Ndata.P.dc.2x2.time]
   Int_t           Ndata_P_dc_2x2_wirenum;
   Double_t        P_dc_2x2_wirenum[48];   //[Ndata.P.dc.2x2.wirenum]
   Int_t           Ndata_P_dc_residual;
   Double_t        P_dc_residual[12];   //[Ndata.P.dc.residual]
   Int_t           Ndata_P_dc_x;
   Double_t        P_dc_x[10];   //[Ndata.P.dc.x]
   Int_t           Ndata_P_dc_xp;
   Double_t        P_dc_xp[10];   //[Ndata.P.dc.xp]
   Int_t           Ndata_P_dc_y;
   Double_t        P_dc_y[10];   //[Ndata.P.dc.y]
   Int_t           Ndata_P_dc_yp;
   Double_t        P_dc_yp[10];   //[Ndata.P.dc.yp]
   Int_t           Ndata_P_hgcer_adc;
   Double_t        P_hgcer_adc[4];   //[Ndata.P.hgcer.adc]
   Int_t           Ndata_P_hgcer_adcCounter;
   Double_t        P_hgcer_adcCounter[4];   //[Ndata.P.hgcer.adcCounter]
   Int_t           Ndata_P_hgcer_adcPed;
   Double_t        P_hgcer_adcPed[4];   //[Ndata.P.hgcer.adcPed]
   Int_t           Ndata_P_hgcer_adcPedRaw;
   Double_t        P_hgcer_adcPedRaw[4];   //[Ndata.P.hgcer.adcPedRaw]
   Int_t           Ndata_P_hgcer_adcPulseAmp;
   Double_t        P_hgcer_adcPulseAmp[4];   //[Ndata.P.hgcer.adcPulseAmp]
   Int_t           Ndata_P_hgcer_adcPulseAmpRaw;
   Double_t        P_hgcer_adcPulseAmpRaw[4];   //[Ndata.P.hgcer.adcPulseAmpRaw]
   Int_t           Ndata_P_hgcer_adcPulseInt;
   Double_t        P_hgcer_adcPulseInt[4];   //[Ndata.P.hgcer.adcPulseInt]
   Int_t           Ndata_P_hgcer_adcPulseIntRaw;
   Double_t        P_hgcer_adcPulseIntRaw[4];   //[Ndata.P.hgcer.adcPulseIntRaw]
   Int_t           Ndata_P_hgcer_adcPulseTimeRaw;
   Double_t        P_hgcer_adcPulseTimeRaw[4];   //[Ndata.P.hgcer.adcPulseTimeRaw]
   Int_t           Ndata_P_hgcer_adc_hit;
   Double_t        P_hgcer_adc_hit[4];   //[Ndata.P.hgcer.adc_hit]
   Int_t           Ndata_P_hgcer_adc_p;
   Double_t        P_hgcer_adc_p[4];   //[Ndata.P.hgcer.adc_p]
   Int_t           Ndata_P_hgcer_cerfiredcounter;
   Double_t        P_hgcer_cerfiredcounter[3];   //[Ndata.P.hgcer.cerfiredcounter]
   Int_t           Ndata_P_hgcer_certrackcounter;
   Double_t        P_hgcer_certrackcounter[3];   //[Ndata.P.hgcer.certrackcounter]
   Int_t           Ndata_P_hgcer_npe;
   Double_t        P_hgcer_npe[4];   //[Ndata.P.hgcer.npe]
   Int_t           Ndata_P_hgcer_phototubes;
   Double_t        P_hgcer_phototubes[4];   //[Ndata.P.hgcer.phototubes]
   Int_t           Ndata_P_hod_1x_GoodNegAdcPulseAmp;
   Double_t        P_hod_1x_GoodNegAdcPulseAmp[10];   //[Ndata.P.hod.1x.GoodNegAdcPulseAmp]
   Int_t           Ndata_P_hod_1x_GoodNegAdcPulseInt;
   Double_t        P_hod_1x_GoodNegAdcPulseInt[10];   //[Ndata.P.hod.1x.GoodNegAdcPulseInt]
   Int_t           Ndata_P_hod_1x_GoodNegAdcPulseTime;
   Double_t        P_hod_1x_GoodNegAdcPulseTime[10];   //[Ndata.P.hod.1x.GoodNegAdcPulseTime]
   Int_t           Ndata_P_hod_1x_GoodNegTdcChan;
   Double_t        P_hod_1x_GoodNegTdcChan[10];   //[Ndata.P.hod.1x.GoodNegTdcChan]
   Int_t           Ndata_P_hod_1x_GoodNegTdcTimeCorr;
   Double_t        P_hod_1x_GoodNegTdcTimeCorr[10];   //[Ndata.P.hod.1x.GoodNegTdcTimeCorr]
   Int_t           Ndata_P_hod_1x_GoodNegTdcTimeTOFCorr;
   Double_t        P_hod_1x_GoodNegTdcTimeTOFCorr[10];   //[Ndata.P.hod.1x.GoodNegTdcTimeTOFCorr]
   Int_t           Ndata_P_hod_1x_GoodPaddle;
   Double_t        P_hod_1x_GoodPaddle[10];   //[Ndata.P.hod.1x.GoodPaddle]
   Int_t           Ndata_P_hod_1x_GoodPosAdcPulseAmp;
   Double_t        P_hod_1x_GoodPosAdcPulseAmp[10];   //[Ndata.P.hod.1x.GoodPosAdcPulseAmp]
   Int_t           Ndata_P_hod_1x_GoodPosAdcPulseInt;
   Double_t        P_hod_1x_GoodPosAdcPulseInt[10];   //[Ndata.P.hod.1x.GoodPosAdcPulseInt]
   Int_t           Ndata_P_hod_1x_GoodPosAdcPulseTime;
   Double_t        P_hod_1x_GoodPosAdcPulseTime[10];   //[Ndata.P.hod.1x.GoodPosAdcPulseTime]
   Int_t           Ndata_P_hod_1x_GoodPosTdcChan;
   Double_t        P_hod_1x_GoodPosTdcChan[10];   //[Ndata.P.hod.1x.GoodPosTdcChan]
   Int_t           Ndata_P_hod_1x_GoodPosTdcTimeCorr;
   Double_t        P_hod_1x_GoodPosTdcTimeCorr[10];   //[Ndata.P.hod.1x.GoodPosTdcTimeCorr]
   Int_t           Ndata_P_hod_1x_GoodPosTdcTimeTOFCorr;
   Double_t        P_hod_1x_GoodPosTdcTimeTOFCorr[10];   //[Ndata.P.hod.1x.GoodPosTdcTimeTOFCorr]
   Int_t           Ndata_P_hod_1x_negAdcCounter;
   Double_t        P_hod_1x_negAdcCounter[13];   //[Ndata.P.hod.1x.negAdcCounter]
   Int_t           Ndata_P_hod_1x_negAdcPed;
   Double_t        P_hod_1x_negAdcPed[13];   //[Ndata.P.hod.1x.negAdcPed]
   Int_t           Ndata_P_hod_1x_negAdcPedRaw;
   Double_t        P_hod_1x_negAdcPedRaw[13];   //[Ndata.P.hod.1x.negAdcPedRaw]
   Int_t           Ndata_P_hod_1x_negAdcPulseAmp;
   Double_t        P_hod_1x_negAdcPulseAmp[13];   //[Ndata.P.hod.1x.negAdcPulseAmp]
   Int_t           Ndata_P_hod_1x_negAdcPulseAmpRaw;
   Double_t        P_hod_1x_negAdcPulseAmpRaw[13];   //[Ndata.P.hod.1x.negAdcPulseAmpRaw]
   Int_t           Ndata_P_hod_1x_negAdcPulseInt;
   Double_t        P_hod_1x_negAdcPulseInt[13];   //[Ndata.P.hod.1x.negAdcPulseInt]
   Int_t           Ndata_P_hod_1x_negAdcPulseIntRaw;
   Double_t        P_hod_1x_negAdcPulseIntRaw[13];   //[Ndata.P.hod.1x.negAdcPulseIntRaw]
   Int_t           Ndata_P_hod_1x_negAdcPulseTimeRaw;
   Double_t        P_hod_1x_negAdcPulseTimeRaw[13];   //[Ndata.P.hod.1x.negAdcPulseTimeRaw]
   Int_t           Ndata_P_hod_1x_negTdcCounter;
   Double_t        P_hod_1x_negTdcCounter[11];   //[Ndata.P.hod.1x.negTdcCounter]
   Int_t           Ndata_P_hod_1x_negTdcTime;
   Double_t        P_hod_1x_negTdcTime[11];   //[Ndata.P.hod.1x.negTdcTime]
   Int_t           Ndata_P_hod_1x_negTdcTimeRaw;
   Double_t        P_hod_1x_negTdcTimeRaw[11];   //[Ndata.P.hod.1x.negTdcTimeRaw]
   Int_t           Ndata_P_hod_1x_posAdcCounter;
   Double_t        P_hod_1x_posAdcCounter[13];   //[Ndata.P.hod.1x.posAdcCounter]
   Int_t           Ndata_P_hod_1x_posAdcPed;
   Double_t        P_hod_1x_posAdcPed[13];   //[Ndata.P.hod.1x.posAdcPed]
   Int_t           Ndata_P_hod_1x_posAdcPedRaw;
   Double_t        P_hod_1x_posAdcPedRaw[13];   //[Ndata.P.hod.1x.posAdcPedRaw]
   Int_t           Ndata_P_hod_1x_posAdcPulseAmp;
   Double_t        P_hod_1x_posAdcPulseAmp[13];   //[Ndata.P.hod.1x.posAdcPulseAmp]
   Int_t           Ndata_P_hod_1x_posAdcPulseAmpRaw;
   Double_t        P_hod_1x_posAdcPulseAmpRaw[13];   //[Ndata.P.hod.1x.posAdcPulseAmpRaw]
   Int_t           Ndata_P_hod_1x_posAdcPulseInt;
   Double_t        P_hod_1x_posAdcPulseInt[13];   //[Ndata.P.hod.1x.posAdcPulseInt]
   Int_t           Ndata_P_hod_1x_posAdcPulseIntRaw;
   Double_t        P_hod_1x_posAdcPulseIntRaw[13];   //[Ndata.P.hod.1x.posAdcPulseIntRaw]
   Int_t           Ndata_P_hod_1x_posAdcPulseTimeRaw;
   Double_t        P_hod_1x_posAdcPulseTimeRaw[13];   //[Ndata.P.hod.1x.posAdcPulseTimeRaw]
   Int_t           Ndata_P_hod_1x_posTdcCounter;
   Double_t        P_hod_1x_posTdcCounter[11];   //[Ndata.P.hod.1x.posTdcCounter]
   Int_t           Ndata_P_hod_1x_posTdcTime;
   Double_t        P_hod_1x_posTdcTime[11];   //[Ndata.P.hod.1x.posTdcTime]
   Int_t           Ndata_P_hod_1x_posTdcTimeRaw;
   Double_t        P_hod_1x_posTdcTimeRaw[11];   //[Ndata.P.hod.1x.posTdcTimeRaw]
   Int_t           Ndata_P_hod_1y_GoodNegAdcPulseAmp;
   Double_t        P_hod_1y_GoodNegAdcPulseAmp[13];   //[Ndata.P.hod.1y.GoodNegAdcPulseAmp]
   Int_t           Ndata_P_hod_1y_GoodNegAdcPulseInt;
   Double_t        P_hod_1y_GoodNegAdcPulseInt[13];   //[Ndata.P.hod.1y.GoodNegAdcPulseInt]
   Int_t           Ndata_P_hod_1y_GoodNegAdcPulseTime;
   Double_t        P_hod_1y_GoodNegAdcPulseTime[13];   //[Ndata.P.hod.1y.GoodNegAdcPulseTime]
   Int_t           Ndata_P_hod_1y_GoodNegTdcChan;
   Double_t        P_hod_1y_GoodNegTdcChan[13];   //[Ndata.P.hod.1y.GoodNegTdcChan]
   Int_t           Ndata_P_hod_1y_GoodNegTdcTimeCorr;
   Double_t        P_hod_1y_GoodNegTdcTimeCorr[13];   //[Ndata.P.hod.1y.GoodNegTdcTimeCorr]
   Int_t           Ndata_P_hod_1y_GoodNegTdcTimeTOFCorr;
   Double_t        P_hod_1y_GoodNegTdcTimeTOFCorr[13];   //[Ndata.P.hod.1y.GoodNegTdcTimeTOFCorr]
   Int_t           Ndata_P_hod_1y_GoodPaddle;
   Double_t        P_hod_1y_GoodPaddle[13];   //[Ndata.P.hod.1y.GoodPaddle]
   Int_t           Ndata_P_hod_1y_GoodPosAdcPulseAmp;
   Double_t        P_hod_1y_GoodPosAdcPulseAmp[13];   //[Ndata.P.hod.1y.GoodPosAdcPulseAmp]
   Int_t           Ndata_P_hod_1y_GoodPosAdcPulseInt;
   Double_t        P_hod_1y_GoodPosAdcPulseInt[13];   //[Ndata.P.hod.1y.GoodPosAdcPulseInt]
   Int_t           Ndata_P_hod_1y_GoodPosAdcPulseTime;
   Double_t        P_hod_1y_GoodPosAdcPulseTime[13];   //[Ndata.P.hod.1y.GoodPosAdcPulseTime]
   Int_t           Ndata_P_hod_1y_GoodPosTdcChan;
   Double_t        P_hod_1y_GoodPosTdcChan[13];   //[Ndata.P.hod.1y.GoodPosTdcChan]
   Int_t           Ndata_P_hod_1y_GoodPosTdcTimeCorr;
   Double_t        P_hod_1y_GoodPosTdcTimeCorr[13];   //[Ndata.P.hod.1y.GoodPosTdcTimeCorr]
   Int_t           Ndata_P_hod_1y_GoodPosTdcTimeTOFCorr;
   Double_t        P_hod_1y_GoodPosTdcTimeTOFCorr[13];   //[Ndata.P.hod.1y.GoodPosTdcTimeTOFCorr]
   Int_t           Ndata_P_hod_1y_negAdcCounter;
   Double_t        P_hod_1y_negAdcCounter[13];   //[Ndata.P.hod.1y.negAdcCounter]
   Int_t           Ndata_P_hod_1y_negAdcPed;
   Double_t        P_hod_1y_negAdcPed[13];   //[Ndata.P.hod.1y.negAdcPed]
   Int_t           Ndata_P_hod_1y_negAdcPedRaw;
   Double_t        P_hod_1y_negAdcPedRaw[13];   //[Ndata.P.hod.1y.negAdcPedRaw]
   Int_t           Ndata_P_hod_1y_negAdcPulseAmp;
   Double_t        P_hod_1y_negAdcPulseAmp[13];   //[Ndata.P.hod.1y.negAdcPulseAmp]
   Int_t           Ndata_P_hod_1y_negAdcPulseAmpRaw;
   Double_t        P_hod_1y_negAdcPulseAmpRaw[13];   //[Ndata.P.hod.1y.negAdcPulseAmpRaw]
   Int_t           Ndata_P_hod_1y_negAdcPulseInt;
   Double_t        P_hod_1y_negAdcPulseInt[13];   //[Ndata.P.hod.1y.negAdcPulseInt]
   Int_t           Ndata_P_hod_1y_negAdcPulseIntRaw;
   Double_t        P_hod_1y_negAdcPulseIntRaw[13];   //[Ndata.P.hod.1y.negAdcPulseIntRaw]
   Int_t           Ndata_P_hod_1y_negAdcPulseTimeRaw;
   Double_t        P_hod_1y_negAdcPulseTimeRaw[13];   //[Ndata.P.hod.1y.negAdcPulseTimeRaw]
   Int_t           Ndata_P_hod_1y_negTdcCounter;
   Double_t        P_hod_1y_negTdcCounter[18];   //[Ndata.P.hod.1y.negTdcCounter]
   Int_t           Ndata_P_hod_1y_negTdcTime;
   Double_t        P_hod_1y_negTdcTime[18];   //[Ndata.P.hod.1y.negTdcTime]
   Int_t           Ndata_P_hod_1y_negTdcTimeRaw;
   Double_t        P_hod_1y_negTdcTimeRaw[18];   //[Ndata.P.hod.1y.negTdcTimeRaw]
   Int_t           Ndata_P_hod_1y_posAdcCounter;
   Double_t        P_hod_1y_posAdcCounter[13];   //[Ndata.P.hod.1y.posAdcCounter]
   Int_t           Ndata_P_hod_1y_posAdcPed;
   Double_t        P_hod_1y_posAdcPed[13];   //[Ndata.P.hod.1y.posAdcPed]
   Int_t           Ndata_P_hod_1y_posAdcPedRaw;
   Double_t        P_hod_1y_posAdcPedRaw[13];   //[Ndata.P.hod.1y.posAdcPedRaw]
   Int_t           Ndata_P_hod_1y_posAdcPulseAmp;
   Double_t        P_hod_1y_posAdcPulseAmp[13];   //[Ndata.P.hod.1y.posAdcPulseAmp]
   Int_t           Ndata_P_hod_1y_posAdcPulseAmpRaw;
   Double_t        P_hod_1y_posAdcPulseAmpRaw[13];   //[Ndata.P.hod.1y.posAdcPulseAmpRaw]
   Int_t           Ndata_P_hod_1y_posAdcPulseInt;
   Double_t        P_hod_1y_posAdcPulseInt[13];   //[Ndata.P.hod.1y.posAdcPulseInt]
   Int_t           Ndata_P_hod_1y_posAdcPulseIntRaw;
   Double_t        P_hod_1y_posAdcPulseIntRaw[13];   //[Ndata.P.hod.1y.posAdcPulseIntRaw]
   Int_t           Ndata_P_hod_1y_posAdcPulseTimeRaw;
   Double_t        P_hod_1y_posAdcPulseTimeRaw[13];   //[Ndata.P.hod.1y.posAdcPulseTimeRaw]
   Int_t           Ndata_P_hod_1y_posTdcCounter;
   Double_t        P_hod_1y_posTdcCounter[20];   //[Ndata.P.hod.1y.posTdcCounter]
   Int_t           Ndata_P_hod_1y_posTdcTime;
   Double_t        P_hod_1y_posTdcTime[20];   //[Ndata.P.hod.1y.posTdcTime]
   Int_t           Ndata_P_hod_1y_posTdcTimeRaw;
   Double_t        P_hod_1y_posTdcTimeRaw[20];   //[Ndata.P.hod.1y.posTdcTimeRaw]
   Int_t           Ndata_P_hod_2x_GoodNegAdcPulseAmp;
   Double_t        P_hod_2x_GoodNegAdcPulseAmp[12];   //[Ndata.P.hod.2x.GoodNegAdcPulseAmp]
   Int_t           Ndata_P_hod_2x_GoodNegAdcPulseInt;
   Double_t        P_hod_2x_GoodNegAdcPulseInt[12];   //[Ndata.P.hod.2x.GoodNegAdcPulseInt]
   Int_t           Ndata_P_hod_2x_GoodNegAdcPulseTime;
   Double_t        P_hod_2x_GoodNegAdcPulseTime[12];   //[Ndata.P.hod.2x.GoodNegAdcPulseTime]
   Int_t           Ndata_P_hod_2x_GoodNegTdcChan;
   Double_t        P_hod_2x_GoodNegTdcChan[12];   //[Ndata.P.hod.2x.GoodNegTdcChan]
   Int_t           Ndata_P_hod_2x_GoodNegTdcTimeCorr;
   Double_t        P_hod_2x_GoodNegTdcTimeCorr[12];   //[Ndata.P.hod.2x.GoodNegTdcTimeCorr]
   Int_t           Ndata_P_hod_2x_GoodNegTdcTimeTOFCorr;
   Double_t        P_hod_2x_GoodNegTdcTimeTOFCorr[12];   //[Ndata.P.hod.2x.GoodNegTdcTimeTOFCorr]
   Int_t           Ndata_P_hod_2x_GoodPaddle;
   Double_t        P_hod_2x_GoodPaddle[12];   //[Ndata.P.hod.2x.GoodPaddle]
   Int_t           Ndata_P_hod_2x_GoodPosAdcPulseAmp;
   Double_t        P_hod_2x_GoodPosAdcPulseAmp[12];   //[Ndata.P.hod.2x.GoodPosAdcPulseAmp]
   Int_t           Ndata_P_hod_2x_GoodPosAdcPulseInt;
   Double_t        P_hod_2x_GoodPosAdcPulseInt[12];   //[Ndata.P.hod.2x.GoodPosAdcPulseInt]
   Int_t           Ndata_P_hod_2x_GoodPosAdcPulseTime;
   Double_t        P_hod_2x_GoodPosAdcPulseTime[12];   //[Ndata.P.hod.2x.GoodPosAdcPulseTime]
   Int_t           Ndata_P_hod_2x_GoodPosTdcChan;
   Double_t        P_hod_2x_GoodPosTdcChan[12];   //[Ndata.P.hod.2x.GoodPosTdcChan]
   Int_t           Ndata_P_hod_2x_GoodPosTdcTimeCorr;
   Double_t        P_hod_2x_GoodPosTdcTimeCorr[12];   //[Ndata.P.hod.2x.GoodPosTdcTimeCorr]
   Int_t           Ndata_P_hod_2x_GoodPosTdcTimeTOFCorr;
   Double_t        P_hod_2x_GoodPosTdcTimeTOFCorr[12];   //[Ndata.P.hod.2x.GoodPosTdcTimeTOFCorr]
   Int_t           Ndata_P_hod_2x_negAdcCounter;
   Double_t        P_hod_2x_negAdcCounter[14];   //[Ndata.P.hod.2x.negAdcCounter]
   Int_t           Ndata_P_hod_2x_negAdcPed;
   Double_t        P_hod_2x_negAdcPed[14];   //[Ndata.P.hod.2x.negAdcPed]
   Int_t           Ndata_P_hod_2x_negAdcPedRaw;
   Double_t        P_hod_2x_negAdcPedRaw[14];   //[Ndata.P.hod.2x.negAdcPedRaw]
   Int_t           Ndata_P_hod_2x_negAdcPulseAmp;
   Double_t        P_hod_2x_negAdcPulseAmp[14];   //[Ndata.P.hod.2x.negAdcPulseAmp]
   Int_t           Ndata_P_hod_2x_negAdcPulseAmpRaw;
   Double_t        P_hod_2x_negAdcPulseAmpRaw[14];   //[Ndata.P.hod.2x.negAdcPulseAmpRaw]
   Int_t           Ndata_P_hod_2x_negAdcPulseInt;
   Double_t        P_hod_2x_negAdcPulseInt[14];   //[Ndata.P.hod.2x.negAdcPulseInt]
   Int_t           Ndata_P_hod_2x_negAdcPulseIntRaw;
   Double_t        P_hod_2x_negAdcPulseIntRaw[14];   //[Ndata.P.hod.2x.negAdcPulseIntRaw]
   Int_t           Ndata_P_hod_2x_negAdcPulseTimeRaw;
   Double_t        P_hod_2x_negAdcPulseTimeRaw[14];   //[Ndata.P.hod.2x.negAdcPulseTimeRaw]
   Int_t           Ndata_P_hod_2x_negTdcCounter;
   Double_t        P_hod_2x_negTdcCounter[21];   //[Ndata.P.hod.2x.negTdcCounter]
   Int_t           Ndata_P_hod_2x_negTdcTime;
   Double_t        P_hod_2x_negTdcTime[21];   //[Ndata.P.hod.2x.negTdcTime]
   Int_t           Ndata_P_hod_2x_negTdcTimeRaw;
   Double_t        P_hod_2x_negTdcTimeRaw[21];   //[Ndata.P.hod.2x.negTdcTimeRaw]
   Int_t           Ndata_P_hod_2x_posAdcCounter;
   Double_t        P_hod_2x_posAdcCounter[14];   //[Ndata.P.hod.2x.posAdcCounter]
   Int_t           Ndata_P_hod_2x_posAdcPed;
   Double_t        P_hod_2x_posAdcPed[14];   //[Ndata.P.hod.2x.posAdcPed]
   Int_t           Ndata_P_hod_2x_posAdcPedRaw;
   Double_t        P_hod_2x_posAdcPedRaw[14];   //[Ndata.P.hod.2x.posAdcPedRaw]
   Int_t           Ndata_P_hod_2x_posAdcPulseAmp;
   Double_t        P_hod_2x_posAdcPulseAmp[14];   //[Ndata.P.hod.2x.posAdcPulseAmp]
   Int_t           Ndata_P_hod_2x_posAdcPulseAmpRaw;
   Double_t        P_hod_2x_posAdcPulseAmpRaw[14];   //[Ndata.P.hod.2x.posAdcPulseAmpRaw]
   Int_t           Ndata_P_hod_2x_posAdcPulseInt;
   Double_t        P_hod_2x_posAdcPulseInt[14];   //[Ndata.P.hod.2x.posAdcPulseInt]
   Int_t           Ndata_P_hod_2x_posAdcPulseIntRaw;
   Double_t        P_hod_2x_posAdcPulseIntRaw[14];   //[Ndata.P.hod.2x.posAdcPulseIntRaw]
   Int_t           Ndata_P_hod_2x_posAdcPulseTimeRaw;
   Double_t        P_hod_2x_posAdcPulseTimeRaw[14];   //[Ndata.P.hod.2x.posAdcPulseTimeRaw]
   Int_t           Ndata_P_hod_2x_posTdcCounter;
   Double_t        P_hod_2x_posTdcCounter[16];   //[Ndata.P.hod.2x.posTdcCounter]
   Int_t           Ndata_P_hod_2x_posTdcTime;
   Double_t        P_hod_2x_posTdcTime[16];   //[Ndata.P.hod.2x.posTdcTime]
   Int_t           Ndata_P_hod_2x_posTdcTimeRaw;
   Double_t        P_hod_2x_posTdcTimeRaw[16];   //[Ndata.P.hod.2x.posTdcTimeRaw]
   Int_t           Ndata_P_hod_2y_GoodNegAdcPulseAmp;
   Double_t        P_hod_2y_GoodNegAdcPulseAmp[9];   //[Ndata.P.hod.2y.GoodNegAdcPulseAmp]
   Int_t           Ndata_P_hod_2y_GoodNegAdcPulseInt;
   Double_t        P_hod_2y_GoodNegAdcPulseInt[9];   //[Ndata.P.hod.2y.GoodNegAdcPulseInt]
   Int_t           Ndata_P_hod_2y_GoodNegAdcPulseTime;
   Double_t        P_hod_2y_GoodNegAdcPulseTime[9];   //[Ndata.P.hod.2y.GoodNegAdcPulseTime]
   Int_t           Ndata_P_hod_2y_GoodNegTdcChan;
   Double_t        P_hod_2y_GoodNegTdcChan[9];   //[Ndata.P.hod.2y.GoodNegTdcChan]
   Int_t           Ndata_P_hod_2y_GoodNegTdcTimeCorr;
   Double_t        P_hod_2y_GoodNegTdcTimeCorr[9];   //[Ndata.P.hod.2y.GoodNegTdcTimeCorr]
   Int_t           Ndata_P_hod_2y_GoodNegTdcTimeTOFCorr;
   Double_t        P_hod_2y_GoodNegTdcTimeTOFCorr[9];   //[Ndata.P.hod.2y.GoodNegTdcTimeTOFCorr]
   Int_t           Ndata_P_hod_2y_GoodPaddle;
   Double_t        P_hod_2y_GoodPaddle[9];   //[Ndata.P.hod.2y.GoodPaddle]
   Int_t           Ndata_P_hod_2y_GoodPosAdcPulseAmp;
   Double_t        P_hod_2y_GoodPosAdcPulseAmp[9];   //[Ndata.P.hod.2y.GoodPosAdcPulseAmp]
   Int_t           Ndata_P_hod_2y_GoodPosAdcPulseInt;
   Double_t        P_hod_2y_GoodPosAdcPulseInt[9];   //[Ndata.P.hod.2y.GoodPosAdcPulseInt]
   Int_t           Ndata_P_hod_2y_GoodPosAdcPulseTime;
   Double_t        P_hod_2y_GoodPosAdcPulseTime[9];   //[Ndata.P.hod.2y.GoodPosAdcPulseTime]
   Int_t           Ndata_P_hod_2y_GoodPosTdcChan;
   Double_t        P_hod_2y_GoodPosTdcChan[9];   //[Ndata.P.hod.2y.GoodPosTdcChan]
   Int_t           Ndata_P_hod_2y_GoodPosTdcTimeCorr;
   Double_t        P_hod_2y_GoodPosTdcTimeCorr[9];   //[Ndata.P.hod.2y.GoodPosTdcTimeCorr]
   Int_t           Ndata_P_hod_2y_GoodPosTdcTimeTOFCorr;
   Double_t        P_hod_2y_GoodPosTdcTimeTOFCorr[9];   //[Ndata.P.hod.2y.GoodPosTdcTimeTOFCorr]
   Int_t           Ndata_P_hod_2y_negAdcCounter;
   Double_t        P_hod_2y_negAdcCounter[9];   //[Ndata.P.hod.2y.negAdcCounter]
   Int_t           Ndata_P_hod_2y_negAdcPed;
   Double_t        P_hod_2y_negAdcPed[9];   //[Ndata.P.hod.2y.negAdcPed]
   Int_t           Ndata_P_hod_2y_negAdcPedRaw;
   Double_t        P_hod_2y_negAdcPedRaw[9];   //[Ndata.P.hod.2y.negAdcPedRaw]
   Int_t           Ndata_P_hod_2y_negAdcPulseAmp;
   Double_t        P_hod_2y_negAdcPulseAmp[9];   //[Ndata.P.hod.2y.negAdcPulseAmp]
   Int_t           Ndata_P_hod_2y_negAdcPulseAmpRaw;
   Double_t        P_hod_2y_negAdcPulseAmpRaw[9];   //[Ndata.P.hod.2y.negAdcPulseAmpRaw]
   Int_t           Ndata_P_hod_2y_negAdcPulseInt;
   Double_t        P_hod_2y_negAdcPulseInt[9];   //[Ndata.P.hod.2y.negAdcPulseInt]
   Int_t           Ndata_P_hod_2y_negAdcPulseIntRaw;
   Double_t        P_hod_2y_negAdcPulseIntRaw[9];   //[Ndata.P.hod.2y.negAdcPulseIntRaw]
   Int_t           Ndata_P_hod_2y_negAdcPulseTimeRaw;
   Double_t        P_hod_2y_negAdcPulseTimeRaw[9];   //[Ndata.P.hod.2y.negAdcPulseTimeRaw]
   Int_t           Ndata_P_hod_2y_negTdcCounter;
   Double_t        P_hod_2y_negTdcCounter[14];   //[Ndata.P.hod.2y.negTdcCounter]
   Int_t           Ndata_P_hod_2y_negTdcTime;
   Double_t        P_hod_2y_negTdcTime[14];   //[Ndata.P.hod.2y.negTdcTime]
   Int_t           Ndata_P_hod_2y_negTdcTimeRaw;
   Double_t        P_hod_2y_negTdcTimeRaw[14];   //[Ndata.P.hod.2y.negTdcTimeRaw]
   Int_t           Ndata_P_hod_2y_posAdcCounter;
   Double_t        P_hod_2y_posAdcCounter[10];   //[Ndata.P.hod.2y.posAdcCounter]
   Int_t           Ndata_P_hod_2y_posAdcPed;
   Double_t        P_hod_2y_posAdcPed[10];   //[Ndata.P.hod.2y.posAdcPed]
   Int_t           Ndata_P_hod_2y_posAdcPedRaw;
   Double_t        P_hod_2y_posAdcPedRaw[10];   //[Ndata.P.hod.2y.posAdcPedRaw]
   Int_t           Ndata_P_hod_2y_posAdcPulseAmp;
   Double_t        P_hod_2y_posAdcPulseAmp[10];   //[Ndata.P.hod.2y.posAdcPulseAmp]
   Int_t           Ndata_P_hod_2y_posAdcPulseAmpRaw;
   Double_t        P_hod_2y_posAdcPulseAmpRaw[10];   //[Ndata.P.hod.2y.posAdcPulseAmpRaw]
   Int_t           Ndata_P_hod_2y_posAdcPulseInt;
   Double_t        P_hod_2y_posAdcPulseInt[10];   //[Ndata.P.hod.2y.posAdcPulseInt]
   Int_t           Ndata_P_hod_2y_posAdcPulseIntRaw;
   Double_t        P_hod_2y_posAdcPulseIntRaw[10];   //[Ndata.P.hod.2y.posAdcPulseIntRaw]
   Int_t           Ndata_P_hod_2y_posAdcPulseTimeRaw;
   Double_t        P_hod_2y_posAdcPulseTimeRaw[10];   //[Ndata.P.hod.2y.posAdcPulseTimeRaw]
   Int_t           Ndata_P_hod_2y_posTdcCounter;
   Double_t        P_hod_2y_posTdcCounter[16];   //[Ndata.P.hod.2y.posTdcCounter]
   Int_t           Ndata_P_hod_2y_posTdcTime;
   Double_t        P_hod_2y_posTdcTime[16];   //[Ndata.P.hod.2y.posTdcTime]
   Int_t           Ndata_P_hod_2y_posTdcTimeRaw;
   Double_t        P_hod_2y_posTdcTimeRaw[16];   //[Ndata.P.hod.2y.posTdcTimeRaw]
   Int_t           Ndata_P_ngcer_adc;
   Double_t        P_ngcer_adc[4];   //[Ndata.P.ngcer.adc]
   Int_t           Ndata_P_ngcer_adcCounter;
   Double_t        P_ngcer_adcCounter[4];   //[Ndata.P.ngcer.adcCounter]
   Int_t           Ndata_P_ngcer_adcPed;
   Double_t        P_ngcer_adcPed[4];   //[Ndata.P.ngcer.adcPed]
   Int_t           Ndata_P_ngcer_adcPedRaw;
   Double_t        P_ngcer_adcPedRaw[4];   //[Ndata.P.ngcer.adcPedRaw]
   Int_t           Ndata_P_ngcer_adcPulseAmp;
   Double_t        P_ngcer_adcPulseAmp[4];   //[Ndata.P.ngcer.adcPulseAmp]
   Int_t           Ndata_P_ngcer_adcPulseAmpRaw;
   Double_t        P_ngcer_adcPulseAmpRaw[4];   //[Ndata.P.ngcer.adcPulseAmpRaw]
   Int_t           Ndata_P_ngcer_adcPulseInt;
   Double_t        P_ngcer_adcPulseInt[4];   //[Ndata.P.ngcer.adcPulseInt]
   Int_t           Ndata_P_ngcer_adcPulseIntRaw;
   Double_t        P_ngcer_adcPulseIntRaw[4];   //[Ndata.P.ngcer.adcPulseIntRaw]
   Int_t           Ndata_P_ngcer_adcPulseTimeRaw;
   Double_t        P_ngcer_adcPulseTimeRaw[4];   //[Ndata.P.ngcer.adcPulseTimeRaw]
   Int_t           Ndata_P_ngcer_adc_hit;
   Double_t        P_ngcer_adc_hit[4];   //[Ndata.P.ngcer.adc_hit]
   Int_t           Ndata_P_ngcer_adc_p;
   Double_t        P_ngcer_adc_p[4];   //[Ndata.P.ngcer.adc_p]
   Int_t           Ndata_P_ngcer_cerfiredcounter;
   Double_t        P_ngcer_cerfiredcounter[3];   //[Ndata.P.ngcer.cerfiredcounter]
   Int_t           Ndata_P_ngcer_certrackcounter;
   Double_t        P_ngcer_certrackcounter[3];   //[Ndata.P.ngcer.certrackcounter]
   Int_t           Ndata_P_ngcer_npe;
   Double_t        P_ngcer_npe[4];   //[Ndata.P.ngcer.npe]
   Int_t           Ndata_P_ngcer_phototubes;
   Double_t        P_ngcer_phototubes[4];   //[Ndata.P.ngcer.phototubes]
   Int_t           Ndata_P_tr_beta;
   Double_t        P_tr_beta[10];   //[Ndata.P.tr.beta]
   Int_t           Ndata_P_tr_betachisq;
   Double_t        P_tr_betachisq[10];   //[Ndata.P.tr.betachisq]
   Int_t           Ndata_P_tr_chi2;
   Double_t        P_tr_chi2[10];   //[Ndata.P.tr.chi2]
   Int_t           Ndata_P_tr_d_ph;
   Double_t        P_tr_d_ph[10];   //[Ndata.P.tr.d_ph]
   Int_t           Ndata_P_tr_d_th;
   Double_t        P_tr_d_th[10];   //[Ndata.P.tr.d_th]
   Int_t           Ndata_P_tr_d_x;
   Double_t        P_tr_d_x[10];   //[Ndata.P.tr.d_x]
   Int_t           Ndata_P_tr_d_y;
   Double_t        P_tr_d_y[10];   //[Ndata.P.tr.d_y]
   Int_t           Ndata_P_tr_dbeta;
   Double_t        P_tr_dbeta[10];   //[Ndata.P.tr.dbeta]
   Int_t           Ndata_P_tr_dtime;
   Double_t        P_tr_dtime[10];   //[Ndata.P.tr.dtime]
   Int_t           Ndata_P_tr_flag;
   Double_t        P_tr_flag[10];   //[Ndata.P.tr.flag]
   Int_t           Ndata_P_tr_ndof;
   Double_t        P_tr_ndof[10];   //[Ndata.P.tr.ndof]
   Int_t           Ndata_P_tr_p;
   Double_t        P_tr_p[10];   //[Ndata.P.tr.p]
   Int_t           Ndata_P_tr_pathl;
   Double_t        P_tr_pathl[10];   //[Ndata.P.tr.pathl]
   Int_t           Ndata_P_tr_ph;
   Double_t        P_tr_ph[10];   //[Ndata.P.tr.ph]
   Int_t           Ndata_P_tr_px;
   Double_t        P_tr_px[10];   //[Ndata.P.tr.px]
   Int_t           Ndata_P_tr_py;
   Double_t        P_tr_py[10];   //[Ndata.P.tr.py]
   Int_t           Ndata_P_tr_pz;
   Double_t        P_tr_pz[10];   //[Ndata.P.tr.pz]
   Int_t           Ndata_P_tr_r_ph;
   Double_t        P_tr_r_ph[10];   //[Ndata.P.tr.r_ph]
   Int_t           Ndata_P_tr_r_th;
   Double_t        P_tr_r_th[10];   //[Ndata.P.tr.r_th]
   Int_t           Ndata_P_tr_r_x;
   Double_t        P_tr_r_x[10];   //[Ndata.P.tr.r_x]
   Int_t           Ndata_P_tr_r_y;
   Double_t        P_tr_r_y[10];   //[Ndata.P.tr.r_y]
   Int_t           Ndata_P_tr_tg_dp;
   Double_t        P_tr_tg_dp[10];   //[Ndata.P.tr.tg_dp]
   Int_t           Ndata_P_tr_tg_ph;
   Double_t        P_tr_tg_ph[10];   //[Ndata.P.tr.tg_ph]
   Int_t           Ndata_P_tr_tg_th;
   Double_t        P_tr_tg_th[10];   //[Ndata.P.tr.tg_th]
   Int_t           Ndata_P_tr_tg_y;
   Double_t        P_tr_tg_y[10];   //[Ndata.P.tr.tg_y]
   Int_t           Ndata_P_tr_th;
   Double_t        P_tr_th[10];   //[Ndata.P.tr.th]
   Int_t           Ndata_P_tr_time;
   Double_t        P_tr_time[10];   //[Ndata.P.tr.time]
   Int_t           Ndata_P_tr_vx;
   Double_t        P_tr_vx[10];   //[Ndata.P.tr.vx]
   Int_t           Ndata_P_tr_vy;
   Double_t        P_tr_vy[10];   //[Ndata.P.tr.vy]
   Int_t           Ndata_P_tr_vz;
   Double_t        P_tr_vz[10];   //[Ndata.P.tr.vz]
   Int_t           Ndata_P_tr_x;
   Double_t        P_tr_x[10];   //[Ndata.P.tr.x]
   Int_t           Ndata_P_tr_y;
   Double_t        P_tr_y[10];   //[Ndata.P.tr.y]
   Double_t        P_aero_neg_npe_sum;
   Double_t        P_aero_ngood_hits;
   Double_t        P_aero_npe_sum;
   Double_t        P_aero_ntdc_neg_hits;
   Double_t        P_aero_ntdc_pos_hits;
   Double_t        P_aero_pos_npe_sum;
   Double_t        P_cal_etot;
   Double_t        P_cal_etotnorm;
   Double_t        P_cal_etrack;
   Double_t        P_cal_fly_earray;
   Double_t        P_cal_fly_nclust;
   Double_t        P_cal_fly_nhits;
   Double_t        P_cal_fly_ntracks;
   Double_t        P_cal_nclust;
   Double_t        P_cal_nhits;
   Double_t        P_cal_ntracks;
   Double_t        P_cal_pr_eplane;
   Double_t        P_cal_pr_eplane_neg;
   Double_t        P_cal_pr_eplane_pos;
   Double_t        P_dc_1u1_nhit;
   Double_t        P_dc_1u2_nhit;
   Double_t        P_dc_1v1_nhit;
   Double_t        P_dc_1v2_nhit;
   Double_t        P_dc_1x1_nhit;
   Double_t        P_dc_1x2_nhit;
   Double_t        P_dc_2u1_nhit;
   Double_t        P_dc_2u2_nhit;
   Double_t        P_dc_2v1_nhit;
   Double_t        P_dc_2v2_nhit;
   Double_t        P_dc_2x1_nhit;
   Double_t        P_dc_2x2_nhit;
   Double_t        P_dc_Ch1_maxhits;
   Double_t        P_dc_Ch1_nhit;
   Double_t        P_dc_Ch1_spacepoints;
   Double_t        P_dc_Ch1_trawhit;
   Double_t        P_dc_Ch2_maxhits;
   Double_t        P_dc_Ch2_nhit;
   Double_t        P_dc_Ch2_spacepoints;
   Double_t        P_dc_Ch2_trawhit;
   Double_t        P_dc_nhit;
   Double_t        P_dc_nsp;
   Double_t        P_dc_ntrack;
   Double_t        P_dc_stubtest;
   Double_t        P_dc_tnhit;
   Double_t        P_dc_trawhit;
   Double_t        P_hgcer_ncherhit;
   Double_t        P_hgcer_npesum;
   Double_t        P_hod_1x_fptime;
   Double_t        P_hod_1x_ngoodhits;
   Double_t        P_hod_1x_nhits;
   Double_t        P_hod_1y_fptime;
   Double_t        P_hod_1y_ngoodhits;
   Double_t        P_hod_1y_nhits;
   Double_t        P_hod_2x_fptime;
   Double_t        P_hod_2x_ngoodhits;
   Double_t        P_hod_2x_nhits;
   Double_t        P_hod_2y_fptime;
   Double_t        P_hod_2y_ngoodhits;
   Double_t        P_hod_2y_nhits;
   Double_t        P_hod_betachisqnotrack;
   Double_t        P_hod_betanotrack;
   Double_t        P_hod_betap;
   Double_t        P_hod_fpHitsTime;
   Double_t        P_hod_goodscinhit;
   Double_t        P_hod_goodstarttime;
   Double_t        P_hod_scindid;
   Double_t        P_hod_scinshould;
   Double_t        P_hod_starttime;
   Double_t        P_ngcer_ncherhit;
   Double_t        P_ngcer_npesum;
   Double_t        P_tr_n;
   Double_t        T_shms_p1T_tdcMultiplicity;
   Double_t        T_shms_p1T_tdcTime;
   Double_t        T_shms_p1T_tdcTimeRaw;
   Double_t        T_shms_p1X_tdcMultiplicity;
   Double_t        T_shms_p1X_tdcTime;
   Double_t        T_shms_p1X_tdcTimeRaw;
   Double_t        T_shms_p1Y_tdcMultiplicity;
   Double_t        T_shms_p1Y_tdcTime;
   Double_t        T_shms_p1Y_tdcTimeRaw;
   Double_t        T_shms_p2T_tdcMultiplicity;
   Double_t        T_shms_p2T_tdcTime;
   Double_t        T_shms_p2T_tdcTimeRaw;
   Double_t        T_shms_p2X_tdcMultiplicity;
   Double_t        T_shms_p2X_tdcTime;
   Double_t        T_shms_p2X_tdcTimeRaw;
   Double_t        T_shms_p2Y_tdcMultiplicity;
   Double_t        T_shms_p2Y_tdcTime;
   Double_t        T_shms_p2Y_tdcTimeRaw;
   Double_t        T_shms_pAERSUM_adcMultiplicity;
   Double_t        T_shms_pAERSUM_adcPed;
   Double_t        T_shms_pAERSUM_adcPedRaw;
   Double_t        T_shms_pAERSUM_adcPulseAmp;
   Double_t        T_shms_pAERSUM_adcPulseAmpRaw;
   Double_t        T_shms_pAERSUM_adcPulseInt;
   Double_t        T_shms_pAERSUM_adcPulseIntRaw;
   Double_t        T_shms_pAERSUM_adcPulseTimeRaw;
   Double_t        T_shms_pAERSUM_tdcMultiplicity;
   Double_t        T_shms_pAERSUM_tdcTime;
   Double_t        T_shms_pAERSUM_tdcTimeRaw;
   Double_t        T_shms_pDCREF10_tdcMultiplicity;
   Double_t        T_shms_pDCREF10_tdcTime;
   Double_t        T_shms_pDCREF10_tdcTimeRaw;
   Double_t        T_shms_pDCREF1_tdcMultiplicity;
   Double_t        T_shms_pDCREF1_tdcTime;
   Double_t        T_shms_pDCREF1_tdcTimeRaw;
   Double_t        T_shms_pDCREF2_tdcMultiplicity;
   Double_t        T_shms_pDCREF2_tdcTime;
   Double_t        T_shms_pDCREF2_tdcTimeRaw;
   Double_t        T_shms_pDCREF3_tdcMultiplicity;
   Double_t        T_shms_pDCREF3_tdcTime;
   Double_t        T_shms_pDCREF3_tdcTimeRaw;
   Double_t        T_shms_pDCREF4_tdcMultiplicity;
   Double_t        T_shms_pDCREF4_tdcTime;
   Double_t        T_shms_pDCREF4_tdcTimeRaw;
   Double_t        T_shms_pDCREF5_tdcMultiplicity;
   Double_t        T_shms_pDCREF5_tdcTime;
   Double_t        T_shms_pDCREF5_tdcTimeRaw;
   Double_t        T_shms_pDCREF6_tdcMultiplicity;
   Double_t        T_shms_pDCREF6_tdcTime;
   Double_t        T_shms_pDCREF6_tdcTimeRaw;
   Double_t        T_shms_pDCREF7_tdcMultiplicity;
   Double_t        T_shms_pDCREF7_tdcTime;
   Double_t        T_shms_pDCREF7_tdcTimeRaw;
   Double_t        T_shms_pDCREF8_tdcMultiplicity;
   Double_t        T_shms_pDCREF8_tdcTime;
   Double_t        T_shms_pDCREF8_tdcTimeRaw;
   Double_t        T_shms_pDCREF9_tdcMultiplicity;
   Double_t        T_shms_pDCREF9_tdcTime;
   Double_t        T_shms_pDCREF9_tdcTimeRaw;
   Double_t        T_shms_pHGCSUM_adcMultiplicity;
   Double_t        T_shms_pHGCSUM_adcPed;
   Double_t        T_shms_pHGCSUM_adcPedRaw;
   Double_t        T_shms_pHGCSUM_adcPulseAmp;
   Double_t        T_shms_pHGCSUM_adcPulseAmpRaw;
   Double_t        T_shms_pHGCSUM_adcPulseInt;
   Double_t        T_shms_pHGCSUM_adcPulseIntRaw;
   Double_t        T_shms_pHGCSUM_adcPulseTimeRaw;
   Double_t        T_shms_pHGCSUM_tdcMultiplicity;
   Double_t        T_shms_pHGCSUM_tdcTime;
   Double_t        T_shms_pHGCSUM_tdcTimeRaw;
   Double_t        T_shms_pNGCSUM_adcMultiplicity;
   Double_t        T_shms_pNGCSUM_adcPed;
   Double_t        T_shms_pNGCSUM_adcPedRaw;
   Double_t        T_shms_pNGCSUM_adcPulseAmp;
   Double_t        T_shms_pNGCSUM_adcPulseAmpRaw;
   Double_t        T_shms_pNGCSUM_adcPulseInt;
   Double_t        T_shms_pNGCSUM_adcPulseIntRaw;
   Double_t        T_shms_pNGCSUM_adcPulseTimeRaw;
   Double_t        T_shms_pNGCSUM_tdcMultiplicity;
   Double_t        T_shms_pNGCSUM_tdcTime;
   Double_t        T_shms_pNGCSUM_tdcTimeRaw;
   Double_t        T_shms_pT1_tdcMultiplicity;
   Double_t        T_shms_pT1_tdcTime;
   Double_t        T_shms_pT1_tdcTimeRaw;
   Double_t        T_shms_pT2_tdcMultiplicity;
   Double_t        T_shms_pT2_tdcTime;
   Double_t        T_shms_pT2_tdcTimeRaw;
   Double_t        T_shms_pT3_tdcMultiplicity;
   Double_t        T_shms_pT3_tdcTime;
   Double_t        T_shms_pT3_tdcTimeRaw;
 //THaEvent        *Event_Branch;
   ULong64_t       fEvtHdr_fEvtTime;
   UInt_t          fEvtHdr_fEvtNum;
   Int_t           fEvtHdr_fEvtType;
   Int_t           fEvtHdr_fEvtLen;
   Int_t           fEvtHdr_fHelicity;
   Int_t           fEvtHdr_fTargetPol;
   Int_t           fEvtHdr_fRun;

   // List of branches
   TBranch        *b_Ndata_P_aero_aneg;   //!
   TBranch        *b_P_aero_aneg;   //!
   TBranch        *b_Ndata_P_aero_aneg_p;   //!
   TBranch        *b_P_aero_aneg_p;   //!
   TBranch        *b_Ndata_P_aero_apos;   //!
   TBranch        *b_P_aero_apos;   //!
   TBranch        *b_Ndata_P_aero_apos_p;   //!
   TBranch        *b_P_aero_apos_p;   //!
   TBranch        *b_Ndata_P_aero_negAdcCounter;   //!
   TBranch        *b_P_aero_negAdcCounter;   //!
   TBranch        *b_Ndata_P_aero_negAdcPed;   //!
   TBranch        *b_P_aero_negAdcPed;   //!
   TBranch        *b_Ndata_P_aero_negAdcPedRaw;   //!
   TBranch        *b_P_aero_negAdcPedRaw;   //!
   TBranch        *b_Ndata_P_aero_negAdcPulseAmp;   //!
   TBranch        *b_P_aero_negAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_aero_negAdcPulseAmpRaw;   //!
   TBranch        *b_P_aero_negAdcPulseAmpRaw;   //!
   TBranch        *b_Ndata_P_aero_negAdcPulseInt;   //!
   TBranch        *b_P_aero_negAdcPulseInt;   //!
   TBranch        *b_Ndata_P_aero_negAdcPulseIntRaw;   //!
   TBranch        *b_P_aero_negAdcPulseIntRaw;   //!
   TBranch        *b_Ndata_P_aero_negAdcPulseTimeRaw;   //!
   TBranch        *b_P_aero_negAdcPulseTimeRaw;   //!
   TBranch        *b_Ndata_P_aero_neg_npe;   //!
   TBranch        *b_P_aero_neg_npe;   //!
   TBranch        *b_Ndata_P_aero_negadchits;   //!
   TBranch        *b_P_aero_negadchits;   //!
   TBranch        *b_Ndata_P_aero_negtdchits;   //!
   TBranch        *b_P_aero_negtdchits;   //!
   TBranch        *b_Ndata_P_aero_posAdcCounter;   //!
   TBranch        *b_P_aero_posAdcCounter;   //!
   TBranch        *b_Ndata_P_aero_posAdcPed;   //!
   TBranch        *b_P_aero_posAdcPed;   //!
   TBranch        *b_Ndata_P_aero_posAdcPedRaw;   //!
   TBranch        *b_P_aero_posAdcPedRaw;   //!
   TBranch        *b_Ndata_P_aero_posAdcPulseAmp;   //!
   TBranch        *b_P_aero_posAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_aero_posAdcPulseAmpRaw;   //!
   TBranch        *b_P_aero_posAdcPulseAmpRaw;   //!
   TBranch        *b_Ndata_P_aero_posAdcPulseInt;   //!
   TBranch        *b_P_aero_posAdcPulseInt;   //!
   TBranch        *b_Ndata_P_aero_posAdcPulseIntRaw;   //!
   TBranch        *b_P_aero_posAdcPulseIntRaw;   //!
   TBranch        *b_Ndata_P_aero_posAdcPulseTimeRaw;   //!
   TBranch        *b_P_aero_posAdcPulseTimeRaw;   //!
   TBranch        *b_Ndata_P_aero_pos_npe;   //!
   TBranch        *b_P_aero_pos_npe;   //!
   TBranch        *b_Ndata_P_aero_posadchits;   //!
   TBranch        *b_P_aero_posadchits;   //!
   TBranch        *b_Ndata_P_aero_postdchits;   //!
   TBranch        *b_P_aero_postdchits;   //!
   TBranch        *b_Ndata_P_aero_tneg;   //!
   TBranch        *b_P_aero_tneg;   //!
   TBranch        *b_Ndata_P_aero_tpos;   //!
   TBranch        *b_P_aero_tpos;   //!
   TBranch        *b_Ndata_P_cal_fly_a;   //!
   TBranch        *b_P_cal_fly_a;   //!
   TBranch        *b_Ndata_P_cal_fly_a_p;   //!
   TBranch        *b_P_cal_fly_a_p;   //!
   TBranch        *b_Ndata_P_cal_fly_adcCounter;   //!
   TBranch        *b_P_cal_fly_adcCounter;   //!
   TBranch        *b_Ndata_P_cal_fly_adcPed;   //!
   TBranch        *b_P_cal_fly_adcPed;   //!
   TBranch        *b_Ndata_P_cal_fly_adcPedRaw;   //!
   TBranch        *b_P_cal_fly_adcPedRaw;   //!
   TBranch        *b_Ndata_P_cal_fly_adcPulseAmp;   //!
   TBranch        *b_P_cal_fly_adcPulseAmp;   //!
   TBranch        *b_Ndata_P_cal_fly_adcPulseAmpRaw;   //!
   TBranch        *b_P_cal_fly_adcPulseAmpRaw;   //!
   TBranch        *b_Ndata_P_cal_fly_adcPulseInt;   //!
   TBranch        *b_P_cal_fly_adcPulseInt;   //!
   TBranch        *b_Ndata_P_cal_fly_adcPulseIntRaw;   //!
   TBranch        *b_P_cal_fly_adcPulseIntRaw;   //!
   TBranch        *b_Ndata_P_cal_fly_adcPulseTimeRaw;   //!
   TBranch        *b_P_cal_fly_adcPulseTimeRaw;   //!
   TBranch        *b_Ndata_P_cal_fly_adchits;   //!
   TBranch        *b_P_cal_fly_adchits;   //!
   TBranch        *b_Ndata_P_cal_fly_e;   //!
   TBranch        *b_P_cal_fly_e;   //!
   TBranch        *b_Ndata_P_cal_fly_p;   //!
   TBranch        *b_P_cal_fly_p;   //!
   TBranch        *b_Ndata_P_cal_pr_aneg;   //!
   TBranch        *b_P_cal_pr_aneg;   //!
   TBranch        *b_Ndata_P_cal_pr_aneg_p;   //!
   TBranch        *b_P_cal_pr_aneg_p;   //!
   TBranch        *b_Ndata_P_cal_pr_apos;   //!
   TBranch        *b_P_cal_pr_apos;   //!
   TBranch        *b_Ndata_P_cal_pr_apos_p;   //!
   TBranch        *b_P_cal_pr_apos_p;   //!
   TBranch        *b_Ndata_P_cal_pr_emean;   //!
   TBranch        *b_P_cal_pr_emean;   //!
   TBranch        *b_Ndata_P_cal_pr_eneg;   //!
   TBranch        *b_P_cal_pr_eneg;   //!
   TBranch        *b_Ndata_P_cal_pr_epos;   //!
   TBranch        *b_P_cal_pr_epos;   //!
   TBranch        *b_Ndata_P_cal_pr_negAdcCounter;   //!
   TBranch        *b_P_cal_pr_negAdcCounter;   //!
   TBranch        *b_Ndata_P_cal_pr_negAdcPed;   //!
   TBranch        *b_P_cal_pr_negAdcPed;   //!
   TBranch        *b_Ndata_P_cal_pr_negAdcPedRaw;   //!
   TBranch        *b_P_cal_pr_negAdcPedRaw;   //!
   TBranch        *b_Ndata_P_cal_pr_negAdcPulseAmp;   //!
   TBranch        *b_P_cal_pr_negAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_cal_pr_negAdcPulseAmpRaw;   //!
   TBranch        *b_P_cal_pr_negAdcPulseAmpRaw;   //!
   TBranch        *b_Ndata_P_cal_pr_negAdcPulseInt;   //!
   TBranch        *b_P_cal_pr_negAdcPulseInt;   //!
   TBranch        *b_Ndata_P_cal_pr_negAdcPulseIntRaw;   //!
   TBranch        *b_P_cal_pr_negAdcPulseIntRaw;   //!
   TBranch        *b_Ndata_P_cal_pr_negAdcPulseTimeRaw;   //!
   TBranch        *b_P_cal_pr_negAdcPulseTimeRaw;   //!
   TBranch        *b_Ndata_P_cal_pr_negadchits;   //!
   TBranch        *b_P_cal_pr_negadchits;   //!
   TBranch        *b_Ndata_P_cal_pr_posAdcCounter;   //!
   TBranch        *b_P_cal_pr_posAdcCounter;   //!
   TBranch        *b_Ndata_P_cal_pr_posAdcPed;   //!
   TBranch        *b_P_cal_pr_posAdcPed;   //!
   TBranch        *b_Ndata_P_cal_pr_posAdcPedRaw;   //!
   TBranch        *b_P_cal_pr_posAdcPedRaw;   //!
   TBranch        *b_Ndata_P_cal_pr_posAdcPulseAmp;   //!
   TBranch        *b_P_cal_pr_posAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_cal_pr_posAdcPulseAmpRaw;   //!
   TBranch        *b_P_cal_pr_posAdcPulseAmpRaw;   //!
   TBranch        *b_Ndata_P_cal_pr_posAdcPulseInt;   //!
   TBranch        *b_P_cal_pr_posAdcPulseInt;   //!
   TBranch        *b_Ndata_P_cal_pr_posAdcPulseIntRaw;   //!
   TBranch        *b_P_cal_pr_posAdcPulseIntRaw;   //!
   TBranch        *b_Ndata_P_cal_pr_posAdcPulseTimeRaw;   //!
   TBranch        *b_P_cal_pr_posAdcPulseTimeRaw;   //!
   TBranch        *b_Ndata_P_cal_pr_posadchits;   //!
   TBranch        *b_P_cal_pr_posadchits;   //!
   TBranch        *b_Ndata_P_dc_1u1_dist;   //!
   TBranch        *b_P_dc_1u1_dist;   //!
   TBranch        *b_Ndata_P_dc_1u1_rawtdc;   //!
   TBranch        *b_P_dc_1u1_rawtdc;   //!
   TBranch        *b_Ndata_P_dc_1u1_time;   //!
   TBranch        *b_P_dc_1u1_time;   //!
   TBranch        *b_Ndata_P_dc_1u1_wirenum;   //!
   TBranch        *b_P_dc_1u1_wirenum;   //!
   TBranch        *b_Ndata_P_dc_1u2_dist;   //!
   TBranch        *b_P_dc_1u2_dist;   //!
   TBranch        *b_Ndata_P_dc_1u2_rawtdc;   //!
   TBranch        *b_P_dc_1u2_rawtdc;   //!
   TBranch        *b_Ndata_P_dc_1u2_time;   //!
   TBranch        *b_P_dc_1u2_time;   //!
   TBranch        *b_Ndata_P_dc_1u2_wirenum;   //!
   TBranch        *b_P_dc_1u2_wirenum;   //!
   TBranch        *b_Ndata_P_dc_1v1_dist;   //!
   TBranch        *b_P_dc_1v1_dist;   //!
   TBranch        *b_Ndata_P_dc_1v1_rawtdc;   //!
   TBranch        *b_P_dc_1v1_rawtdc;   //!
   TBranch        *b_Ndata_P_dc_1v1_time;   //!
   TBranch        *b_P_dc_1v1_time;   //!
   TBranch        *b_Ndata_P_dc_1v1_wirenum;   //!
   TBranch        *b_P_dc_1v1_wirenum;   //!
   TBranch        *b_Ndata_P_dc_1v2_dist;   //!
   TBranch        *b_P_dc_1v2_dist;   //!
   TBranch        *b_Ndata_P_dc_1v2_rawtdc;   //!
   TBranch        *b_P_dc_1v2_rawtdc;   //!
   TBranch        *b_Ndata_P_dc_1v2_time;   //!
   TBranch        *b_P_dc_1v2_time;   //!
   TBranch        *b_Ndata_P_dc_1v2_wirenum;   //!
   TBranch        *b_P_dc_1v2_wirenum;   //!
   TBranch        *b_Ndata_P_dc_1x1_dist;   //!
   TBranch        *b_P_dc_1x1_dist;   //!
   TBranch        *b_Ndata_P_dc_1x1_rawtdc;   //!
   TBranch        *b_P_dc_1x1_rawtdc;   //!
   TBranch        *b_Ndata_P_dc_1x1_time;   //!
   TBranch        *b_P_dc_1x1_time;   //!
   TBranch        *b_Ndata_P_dc_1x1_wirenum;   //!
   TBranch        *b_P_dc_1x1_wirenum;   //!
   TBranch        *b_Ndata_P_dc_1x2_dist;   //!
   TBranch        *b_P_dc_1x2_dist;   //!
   TBranch        *b_Ndata_P_dc_1x2_rawtdc;   //!
   TBranch        *b_P_dc_1x2_rawtdc;   //!
   TBranch        *b_Ndata_P_dc_1x2_time;   //!
   TBranch        *b_P_dc_1x2_time;   //!
   TBranch        *b_Ndata_P_dc_1x2_wirenum;   //!
   TBranch        *b_P_dc_1x2_wirenum;   //!
   TBranch        *b_Ndata_P_dc_2u1_dist;   //!
   TBranch        *b_P_dc_2u1_dist;   //!
   TBranch        *b_Ndata_P_dc_2u1_rawtdc;   //!
   TBranch        *b_P_dc_2u1_rawtdc;   //!
   TBranch        *b_Ndata_P_dc_2u1_time;   //!
   TBranch        *b_P_dc_2u1_time;   //!
   TBranch        *b_Ndata_P_dc_2u1_wirenum;   //!
   TBranch        *b_P_dc_2u1_wirenum;   //!
   TBranch        *b_Ndata_P_dc_2u2_dist;   //!
   TBranch        *b_P_dc_2u2_dist;   //!
   TBranch        *b_Ndata_P_dc_2u2_rawtdc;   //!
   TBranch        *b_P_dc_2u2_rawtdc;   //!
   TBranch        *b_Ndata_P_dc_2u2_time;   //!
   TBranch        *b_P_dc_2u2_time;   //!
   TBranch        *b_Ndata_P_dc_2u2_wirenum;   //!
   TBranch        *b_P_dc_2u2_wirenum;   //!
   TBranch        *b_Ndata_P_dc_2v1_dist;   //!
   TBranch        *b_P_dc_2v1_dist;   //!
   TBranch        *b_Ndata_P_dc_2v1_rawtdc;   //!
   TBranch        *b_P_dc_2v1_rawtdc;   //!
   TBranch        *b_Ndata_P_dc_2v1_time;   //!
   TBranch        *b_P_dc_2v1_time;   //!
   TBranch        *b_Ndata_P_dc_2v1_wirenum;   //!
   TBranch        *b_P_dc_2v1_wirenum;   //!
   TBranch        *b_Ndata_P_dc_2v2_dist;   //!
   TBranch        *b_P_dc_2v2_dist;   //!
   TBranch        *b_Ndata_P_dc_2v2_rawtdc;   //!
   TBranch        *b_P_dc_2v2_rawtdc;   //!
   TBranch        *b_Ndata_P_dc_2v2_time;   //!
   TBranch        *b_P_dc_2v2_time;   //!
   TBranch        *b_Ndata_P_dc_2v2_wirenum;   //!
   TBranch        *b_P_dc_2v2_wirenum;   //!
   TBranch        *b_Ndata_P_dc_2x1_dist;   //!
   TBranch        *b_P_dc_2x1_dist;   //!
   TBranch        *b_Ndata_P_dc_2x1_rawtdc;   //!
   TBranch        *b_P_dc_2x1_rawtdc;   //!
   TBranch        *b_Ndata_P_dc_2x1_time;   //!
   TBranch        *b_P_dc_2x1_time;   //!
   TBranch        *b_Ndata_P_dc_2x1_wirenum;   //!
   TBranch        *b_P_dc_2x1_wirenum;   //!
   TBranch        *b_Ndata_P_dc_2x2_dist;   //!
   TBranch        *b_P_dc_2x2_dist;   //!
   TBranch        *b_Ndata_P_dc_2x2_rawtdc;   //!
   TBranch        *b_P_dc_2x2_rawtdc;   //!
   TBranch        *b_Ndata_P_dc_2x2_time;   //!
   TBranch        *b_P_dc_2x2_time;   //!
   TBranch        *b_Ndata_P_dc_2x2_wirenum;   //!
   TBranch        *b_P_dc_2x2_wirenum;   //!
   TBranch        *b_Ndata_P_dc_residual;   //!
   TBranch        *b_P_dc_residual;   //!
   TBranch        *b_Ndata_P_dc_x;   //!
   TBranch        *b_P_dc_x;   //!
   TBranch        *b_Ndata_P_dc_xp;   //!
   TBranch        *b_P_dc_xp;   //!
   TBranch        *b_Ndata_P_dc_y;   //!
   TBranch        *b_P_dc_y;   //!
   TBranch        *b_Ndata_P_dc_yp;   //!
   TBranch        *b_P_dc_yp;   //!
   TBranch        *b_Ndata_P_hgcer_adc;   //!
   TBranch        *b_P_hgcer_adc;   //!
   TBranch        *b_Ndata_P_hgcer_adcCounter;   //!
   TBranch        *b_P_hgcer_adcCounter;   //!
   TBranch        *b_Ndata_P_hgcer_adcPed;   //!
   TBranch        *b_P_hgcer_adcPed;   //!
   TBranch        *b_Ndata_P_hgcer_adcPedRaw;   //!
   TBranch        *b_P_hgcer_adcPedRaw;   //!
   TBranch        *b_Ndata_P_hgcer_adcPulseAmp;   //!
   TBranch        *b_P_hgcer_adcPulseAmp;   //!
   TBranch        *b_Ndata_P_hgcer_adcPulseAmpRaw;   //!
   TBranch        *b_P_hgcer_adcPulseAmpRaw;   //!
   TBranch        *b_Ndata_P_hgcer_adcPulseInt;   //!
   TBranch        *b_P_hgcer_adcPulseInt;   //!
   TBranch        *b_Ndata_P_hgcer_adcPulseIntRaw;   //!
   TBranch        *b_P_hgcer_adcPulseIntRaw;   //!
   TBranch        *b_Ndata_P_hgcer_adcPulseTimeRaw;   //!
   TBranch        *b_P_hgcer_adcPulseTimeRaw;   //!
   TBranch        *b_Ndata_P_hgcer_adc_hit;   //!
   TBranch        *b_P_hgcer_adc_hit;   //!
   TBranch        *b_Ndata_P_hgcer_adc_p;   //!
   TBranch        *b_P_hgcer_adc_p;   //!
   TBranch        *b_Ndata_P_hgcer_cerfiredcounter;   //!
   TBranch        *b_P_hgcer_cerfiredcounter;   //!
   TBranch        *b_Ndata_P_hgcer_certrackcounter;   //!
   TBranch        *b_P_hgcer_certrackcounter;   //!
   TBranch        *b_Ndata_P_hgcer_npe;   //!
   TBranch        *b_P_hgcer_npe;   //!
   TBranch        *b_Ndata_P_hgcer_phototubes;   //!
   TBranch        *b_P_hgcer_phototubes;   //!
   TBranch        *b_Ndata_P_hod_1x_GoodNegAdcPulseAmp;   //!
   TBranch        *b_P_hod_1x_GoodNegAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_hod_1x_GoodNegAdcPulseInt;   //!
   TBranch        *b_P_hod_1x_GoodNegAdcPulseInt;   //!
   TBranch        *b_Ndata_P_hod_1x_GoodNegAdcPulseTime;   //!
   TBranch        *b_P_hod_1x_GoodNegAdcPulseTime;   //!
   TBranch        *b_Ndata_P_hod_1x_GoodNegTdcChan;   //!
   TBranch        *b_P_hod_1x_GoodNegTdcChan;   //!
   TBranch        *b_Ndata_P_hod_1x_GoodNegTdcTimeCorr;   //!
   TBranch        *b_P_hod_1x_GoodNegTdcTimeCorr;   //!
   TBranch        *b_Ndata_P_hod_1x_GoodNegTdcTimeTOFCorr;   //!
   TBranch        *b_P_hod_1x_GoodNegTdcTimeTOFCorr;   //!
   TBranch        *b_Ndata_P_hod_1x_GoodPaddle;   //!
   TBranch        *b_P_hod_1x_GoodPaddle;   //!
   TBranch        *b_Ndata_P_hod_1x_GoodPosAdcPulseAmp;   //!
   TBranch        *b_P_hod_1x_GoodPosAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_hod_1x_GoodPosAdcPulseInt;   //!
   TBranch        *b_P_hod_1x_GoodPosAdcPulseInt;   //!
   TBranch        *b_Ndata_P_hod_1x_GoodPosAdcPulseTime;   //!
   TBranch        *b_P_hod_1x_GoodPosAdcPulseTime;   //!
   TBranch        *b_Ndata_P_hod_1x_GoodPosTdcChan;   //!
   TBranch        *b_P_hod_1x_GoodPosTdcChan;   //!
   TBranch        *b_Ndata_P_hod_1x_GoodPosTdcTimeCorr;   //!
   TBranch        *b_P_hod_1x_GoodPosTdcTimeCorr;   //!
   TBranch        *b_Ndata_P_hod_1x_GoodPosTdcTimeTOFCorr;   //!
   TBranch        *b_P_hod_1x_GoodPosTdcTimeTOFCorr;   //!
   TBranch        *b_Ndata_P_hod_1x_negAdcCounter;   //!
   TBranch        *b_P_hod_1x_negAdcCounter;   //!
   TBranch        *b_Ndata_P_hod_1x_negAdcPed;   //!
   TBranch        *b_P_hod_1x_negAdcPed;   //!
   TBranch        *b_Ndata_P_hod_1x_negAdcPedRaw;   //!
   TBranch        *b_P_hod_1x_negAdcPedRaw;   //!
   TBranch        *b_Ndata_P_hod_1x_negAdcPulseAmp;   //!
   TBranch        *b_P_hod_1x_negAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_hod_1x_negAdcPulseAmpRaw;   //!
   TBranch        *b_P_hod_1x_negAdcPulseAmpRaw;   //!
   TBranch        *b_Ndata_P_hod_1x_negAdcPulseInt;   //!
   TBranch        *b_P_hod_1x_negAdcPulseInt;   //!
   TBranch        *b_Ndata_P_hod_1x_negAdcPulseIntRaw;   //!
   TBranch        *b_P_hod_1x_negAdcPulseIntRaw;   //!
   TBranch        *b_Ndata_P_hod_1x_negAdcPulseTimeRaw;   //!
   TBranch        *b_P_hod_1x_negAdcPulseTimeRaw;   //!
   TBranch        *b_Ndata_P_hod_1x_negTdcCounter;   //!
   TBranch        *b_P_hod_1x_negTdcCounter;   //!
   TBranch        *b_Ndata_P_hod_1x_negTdcTime;   //!
   TBranch        *b_P_hod_1x_negTdcTime;   //!
   TBranch        *b_Ndata_P_hod_1x_negTdcTimeRaw;   //!
   TBranch        *b_P_hod_1x_negTdcTimeRaw;   //!
   TBranch        *b_Ndata_P_hod_1x_posAdcCounter;   //!
   TBranch        *b_P_hod_1x_posAdcCounter;   //!
   TBranch        *b_Ndata_P_hod_1x_posAdcPed;   //!
   TBranch        *b_P_hod_1x_posAdcPed;   //!
   TBranch        *b_Ndata_P_hod_1x_posAdcPedRaw;   //!
   TBranch        *b_P_hod_1x_posAdcPedRaw;   //!
   TBranch        *b_Ndata_P_hod_1x_posAdcPulseAmp;   //!
   TBranch        *b_P_hod_1x_posAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_hod_1x_posAdcPulseAmpRaw;   //!
   TBranch        *b_P_hod_1x_posAdcPulseAmpRaw;   //!
   TBranch        *b_Ndata_P_hod_1x_posAdcPulseInt;   //!
   TBranch        *b_P_hod_1x_posAdcPulseInt;   //!
   TBranch        *b_Ndata_P_hod_1x_posAdcPulseIntRaw;   //!
   TBranch        *b_P_hod_1x_posAdcPulseIntRaw;   //!
   TBranch        *b_Ndata_P_hod_1x_posAdcPulseTimeRaw;   //!
   TBranch        *b_P_hod_1x_posAdcPulseTimeRaw;   //!
   TBranch        *b_Ndata_P_hod_1x_posTdcCounter;   //!
   TBranch        *b_P_hod_1x_posTdcCounter;   //!
   TBranch        *b_Ndata_P_hod_1x_posTdcTime;   //!
   TBranch        *b_P_hod_1x_posTdcTime;   //!
   TBranch        *b_Ndata_P_hod_1x_posTdcTimeRaw;   //!
   TBranch        *b_P_hod_1x_posTdcTimeRaw;   //!
   TBranch        *b_Ndata_P_hod_1y_GoodNegAdcPulseAmp;   //!
   TBranch        *b_P_hod_1y_GoodNegAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_hod_1y_GoodNegAdcPulseInt;   //!
   TBranch        *b_P_hod_1y_GoodNegAdcPulseInt;   //!
   TBranch        *b_Ndata_P_hod_1y_GoodNegAdcPulseTime;   //!
   TBranch        *b_P_hod_1y_GoodNegAdcPulseTime;   //!
   TBranch        *b_Ndata_P_hod_1y_GoodNegTdcChan;   //!
   TBranch        *b_P_hod_1y_GoodNegTdcChan;   //!
   TBranch        *b_Ndata_P_hod_1y_GoodNegTdcTimeCorr;   //!
   TBranch        *b_P_hod_1y_GoodNegTdcTimeCorr;   //!
   TBranch        *b_Ndata_P_hod_1y_GoodNegTdcTimeTOFCorr;   //!
   TBranch        *b_P_hod_1y_GoodNegTdcTimeTOFCorr;   //!
   TBranch        *b_Ndata_P_hod_1y_GoodPaddle;   //!
   TBranch        *b_P_hod_1y_GoodPaddle;   //!
   TBranch        *b_Ndata_P_hod_1y_GoodPosAdcPulseAmp;   //!
   TBranch        *b_P_hod_1y_GoodPosAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_hod_1y_GoodPosAdcPulseInt;   //!
   TBranch        *b_P_hod_1y_GoodPosAdcPulseInt;   //!
   TBranch        *b_Ndata_P_hod_1y_GoodPosAdcPulseTime;   //!
   TBranch        *b_P_hod_1y_GoodPosAdcPulseTime;   //!
   TBranch        *b_Ndata_P_hod_1y_GoodPosTdcChan;   //!
   TBranch        *b_P_hod_1y_GoodPosTdcChan;   //!
   TBranch        *b_Ndata_P_hod_1y_GoodPosTdcTimeCorr;   //!
   TBranch        *b_P_hod_1y_GoodPosTdcTimeCorr;   //!
   TBranch        *b_Ndata_P_hod_1y_GoodPosTdcTimeTOFCorr;   //!
   TBranch        *b_P_hod_1y_GoodPosTdcTimeTOFCorr;   //!
   TBranch        *b_Ndata_P_hod_1y_negAdcCounter;   //!
   TBranch        *b_P_hod_1y_negAdcCounter;   //!
   TBranch        *b_Ndata_P_hod_1y_negAdcPed;   //!
   TBranch        *b_P_hod_1y_negAdcPed;   //!
   TBranch        *b_Ndata_P_hod_1y_negAdcPedRaw;   //!
   TBranch        *b_P_hod_1y_negAdcPedRaw;   //!
   TBranch        *b_Ndata_P_hod_1y_negAdcPulseAmp;   //!
   TBranch        *b_P_hod_1y_negAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_hod_1y_negAdcPulseAmpRaw;   //!
   TBranch        *b_P_hod_1y_negAdcPulseAmpRaw;   //!
   TBranch        *b_Ndata_P_hod_1y_negAdcPulseInt;   //!
   TBranch        *b_P_hod_1y_negAdcPulseInt;   //!
   TBranch        *b_Ndata_P_hod_1y_negAdcPulseIntRaw;   //!
   TBranch        *b_P_hod_1y_negAdcPulseIntRaw;   //!
   TBranch        *b_Ndata_P_hod_1y_negAdcPulseTimeRaw;   //!
   TBranch        *b_P_hod_1y_negAdcPulseTimeRaw;   //!
   TBranch        *b_Ndata_P_hod_1y_negTdcCounter;   //!
   TBranch        *b_P_hod_1y_negTdcCounter;   //!
   TBranch        *b_Ndata_P_hod_1y_negTdcTime;   //!
   TBranch        *b_P_hod_1y_negTdcTime;   //!
   TBranch        *b_Ndata_P_hod_1y_negTdcTimeRaw;   //!
   TBranch        *b_P_hod_1y_negTdcTimeRaw;   //!
   TBranch        *b_Ndata_P_hod_1y_posAdcCounter;   //!
   TBranch        *b_P_hod_1y_posAdcCounter;   //!
   TBranch        *b_Ndata_P_hod_1y_posAdcPed;   //!
   TBranch        *b_P_hod_1y_posAdcPed;   //!
   TBranch        *b_Ndata_P_hod_1y_posAdcPedRaw;   //!
   TBranch        *b_P_hod_1y_posAdcPedRaw;   //!
   TBranch        *b_Ndata_P_hod_1y_posAdcPulseAmp;   //!
   TBranch        *b_P_hod_1y_posAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_hod_1y_posAdcPulseAmpRaw;   //!
   TBranch        *b_P_hod_1y_posAdcPulseAmpRaw;   //!
   TBranch        *b_Ndata_P_hod_1y_posAdcPulseInt;   //!
   TBranch        *b_P_hod_1y_posAdcPulseInt;   //!
   TBranch        *b_Ndata_P_hod_1y_posAdcPulseIntRaw;   //!
   TBranch        *b_P_hod_1y_posAdcPulseIntRaw;   //!
   TBranch        *b_Ndata_P_hod_1y_posAdcPulseTimeRaw;   //!
   TBranch        *b_P_hod_1y_posAdcPulseTimeRaw;   //!
   TBranch        *b_Ndata_P_hod_1y_posTdcCounter;   //!
   TBranch        *b_P_hod_1y_posTdcCounter;   //!
   TBranch        *b_Ndata_P_hod_1y_posTdcTime;   //!
   TBranch        *b_P_hod_1y_posTdcTime;   //!
   TBranch        *b_Ndata_P_hod_1y_posTdcTimeRaw;   //!
   TBranch        *b_P_hod_1y_posTdcTimeRaw;   //!
   TBranch        *b_Ndata_P_hod_2x_GoodNegAdcPulseAmp;   //!
   TBranch        *b_P_hod_2x_GoodNegAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_hod_2x_GoodNegAdcPulseInt;   //!
   TBranch        *b_P_hod_2x_GoodNegAdcPulseInt;   //!
   TBranch        *b_Ndata_P_hod_2x_GoodNegAdcPulseTime;   //!
   TBranch        *b_P_hod_2x_GoodNegAdcPulseTime;   //!
   TBranch        *b_Ndata_P_hod_2x_GoodNegTdcChan;   //!
   TBranch        *b_P_hod_2x_GoodNegTdcChan;   //!
   TBranch        *b_Ndata_P_hod_2x_GoodNegTdcTimeCorr;   //!
   TBranch        *b_P_hod_2x_GoodNegTdcTimeCorr;   //!
   TBranch        *b_Ndata_P_hod_2x_GoodNegTdcTimeTOFCorr;   //!
   TBranch        *b_P_hod_2x_GoodNegTdcTimeTOFCorr;   //!
   TBranch        *b_Ndata_P_hod_2x_GoodPaddle;   //!
   TBranch        *b_P_hod_2x_GoodPaddle;   //!
   TBranch        *b_Ndata_P_hod_2x_GoodPosAdcPulseAmp;   //!
   TBranch        *b_P_hod_2x_GoodPosAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_hod_2x_GoodPosAdcPulseInt;   //!
   TBranch        *b_P_hod_2x_GoodPosAdcPulseInt;   //!
   TBranch        *b_Ndata_P_hod_2x_GoodPosAdcPulseTime;   //!
   TBranch        *b_P_hod_2x_GoodPosAdcPulseTime;   //!
   TBranch        *b_Ndata_P_hod_2x_GoodPosTdcChan;   //!
   TBranch        *b_P_hod_2x_GoodPosTdcChan;   //!
   TBranch        *b_Ndata_P_hod_2x_GoodPosTdcTimeCorr;   //!
   TBranch        *b_P_hod_2x_GoodPosTdcTimeCorr;   //!
   TBranch        *b_Ndata_P_hod_2x_GoodPosTdcTimeTOFCorr;   //!
   TBranch        *b_P_hod_2x_GoodPosTdcTimeTOFCorr;   //!
   TBranch        *b_Ndata_P_hod_2x_negAdcCounter;   //!
   TBranch        *b_P_hod_2x_negAdcCounter;   //!
   TBranch        *b_Ndata_P_hod_2x_negAdcPed;   //!
   TBranch        *b_P_hod_2x_negAdcPed;   //!
   TBranch        *b_Ndata_P_hod_2x_negAdcPedRaw;   //!
   TBranch        *b_P_hod_2x_negAdcPedRaw;   //!
   TBranch        *b_Ndata_P_hod_2x_negAdcPulseAmp;   //!
   TBranch        *b_P_hod_2x_negAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_hod_2x_negAdcPulseAmpRaw;   //!
   TBranch        *b_P_hod_2x_negAdcPulseAmpRaw;   //!
   TBranch        *b_Ndata_P_hod_2x_negAdcPulseInt;   //!
   TBranch        *b_P_hod_2x_negAdcPulseInt;   //!
   TBranch        *b_Ndata_P_hod_2x_negAdcPulseIntRaw;   //!
   TBranch        *b_P_hod_2x_negAdcPulseIntRaw;   //!
   TBranch        *b_Ndata_P_hod_2x_negAdcPulseTimeRaw;   //!
   TBranch        *b_P_hod_2x_negAdcPulseTimeRaw;   //!
   TBranch        *b_Ndata_P_hod_2x_negTdcCounter;   //!
   TBranch        *b_P_hod_2x_negTdcCounter;   //!
   TBranch        *b_Ndata_P_hod_2x_negTdcTime;   //!
   TBranch        *b_P_hod_2x_negTdcTime;   //!
   TBranch        *b_Ndata_P_hod_2x_negTdcTimeRaw;   //!
   TBranch        *b_P_hod_2x_negTdcTimeRaw;   //!
   TBranch        *b_Ndata_P_hod_2x_posAdcCounter;   //!
   TBranch        *b_P_hod_2x_posAdcCounter;   //!
   TBranch        *b_Ndata_P_hod_2x_posAdcPed;   //!
   TBranch        *b_P_hod_2x_posAdcPed;   //!
   TBranch        *b_Ndata_P_hod_2x_posAdcPedRaw;   //!
   TBranch        *b_P_hod_2x_posAdcPedRaw;   //!
   TBranch        *b_Ndata_P_hod_2x_posAdcPulseAmp;   //!
   TBranch        *b_P_hod_2x_posAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_hod_2x_posAdcPulseAmpRaw;   //!
   TBranch        *b_P_hod_2x_posAdcPulseAmpRaw;   //!
   TBranch        *b_Ndata_P_hod_2x_posAdcPulseInt;   //!
   TBranch        *b_P_hod_2x_posAdcPulseInt;   //!
   TBranch        *b_Ndata_P_hod_2x_posAdcPulseIntRaw;   //!
   TBranch        *b_P_hod_2x_posAdcPulseIntRaw;   //!
   TBranch        *b_Ndata_P_hod_2x_posAdcPulseTimeRaw;   //!
   TBranch        *b_P_hod_2x_posAdcPulseTimeRaw;   //!
   TBranch        *b_Ndata_P_hod_2x_posTdcCounter;   //!
   TBranch        *b_P_hod_2x_posTdcCounter;   //!
   TBranch        *b_Ndata_P_hod_2x_posTdcTime;   //!
   TBranch        *b_P_hod_2x_posTdcTime;   //!
   TBranch        *b_Ndata_P_hod_2x_posTdcTimeRaw;   //!
   TBranch        *b_P_hod_2x_posTdcTimeRaw;   //!
   TBranch        *b_Ndata_P_hod_2y_GoodNegAdcPulseAmp;   //!
   TBranch        *b_P_hod_2y_GoodNegAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_hod_2y_GoodNegAdcPulseInt;   //!
   TBranch        *b_P_hod_2y_GoodNegAdcPulseInt;   //!
   TBranch        *b_Ndata_P_hod_2y_GoodNegAdcPulseTime;   //!
   TBranch        *b_P_hod_2y_GoodNegAdcPulseTime;   //!
   TBranch        *b_Ndata_P_hod_2y_GoodNegTdcChan;   //!
   TBranch        *b_P_hod_2y_GoodNegTdcChan;   //!
   TBranch        *b_Ndata_P_hod_2y_GoodNegTdcTimeCorr;   //!
   TBranch        *b_P_hod_2y_GoodNegTdcTimeCorr;   //!
   TBranch        *b_Ndata_P_hod_2y_GoodNegTdcTimeTOFCorr;   //!
   TBranch        *b_P_hod_2y_GoodNegTdcTimeTOFCorr;   //!
   TBranch        *b_Ndata_P_hod_2y_GoodPaddle;   //!
   TBranch        *b_P_hod_2y_GoodPaddle;   //!
   TBranch        *b_Ndata_P_hod_2y_GoodPosAdcPulseAmp;   //!
   TBranch        *b_P_hod_2y_GoodPosAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_hod_2y_GoodPosAdcPulseInt;   //!
   TBranch        *b_P_hod_2y_GoodPosAdcPulseInt;   //!
   TBranch        *b_Ndata_P_hod_2y_GoodPosAdcPulseTime;   //!
   TBranch        *b_P_hod_2y_GoodPosAdcPulseTime;   //!
   TBranch        *b_Ndata_P_hod_2y_GoodPosTdcChan;   //!
   TBranch        *b_P_hod_2y_GoodPosTdcChan;   //!
   TBranch        *b_Ndata_P_hod_2y_GoodPosTdcTimeCorr;   //!
   TBranch        *b_P_hod_2y_GoodPosTdcTimeCorr;   //!
   TBranch        *b_Ndata_P_hod_2y_GoodPosTdcTimeTOFCorr;   //!
   TBranch        *b_P_hod_2y_GoodPosTdcTimeTOFCorr;   //!
   TBranch        *b_Ndata_P_hod_2y_negAdcCounter;   //!
   TBranch        *b_P_hod_2y_negAdcCounter;   //!
   TBranch        *b_Ndata_P_hod_2y_negAdcPed;   //!
   TBranch        *b_P_hod_2y_negAdcPed;   //!
   TBranch        *b_Ndata_P_hod_2y_negAdcPedRaw;   //!
   TBranch        *b_P_hod_2y_negAdcPedRaw;   //!
   TBranch        *b_Ndata_P_hod_2y_negAdcPulseAmp;   //!
   TBranch        *b_P_hod_2y_negAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_hod_2y_negAdcPulseAmpRaw;   //!
   TBranch        *b_P_hod_2y_negAdcPulseAmpRaw;   //!
   TBranch        *b_Ndata_P_hod_2y_negAdcPulseInt;   //!
   TBranch        *b_P_hod_2y_negAdcPulseInt;   //!
   TBranch        *b_Ndata_P_hod_2y_negAdcPulseIntRaw;   //!
   TBranch        *b_P_hod_2y_negAdcPulseIntRaw;   //!
   TBranch        *b_Ndata_P_hod_2y_negAdcPulseTimeRaw;   //!
   TBranch        *b_P_hod_2y_negAdcPulseTimeRaw;   //!
   TBranch        *b_Ndata_P_hod_2y_negTdcCounter;   //!
   TBranch        *b_P_hod_2y_negTdcCounter;   //!
   TBranch        *b_Ndata_P_hod_2y_negTdcTime;   //!
   TBranch        *b_P_hod_2y_negTdcTime;   //!
   TBranch        *b_Ndata_P_hod_2y_negTdcTimeRaw;   //!
   TBranch        *b_P_hod_2y_negTdcTimeRaw;   //!
   TBranch        *b_Ndata_P_hod_2y_posAdcCounter;   //!
   TBranch        *b_P_hod_2y_posAdcCounter;   //!
   TBranch        *b_Ndata_P_hod_2y_posAdcPed;   //!
   TBranch        *b_P_hod_2y_posAdcPed;   //!
   TBranch        *b_Ndata_P_hod_2y_posAdcPedRaw;   //!
   TBranch        *b_P_hod_2y_posAdcPedRaw;   //!
   TBranch        *b_Ndata_P_hod_2y_posAdcPulseAmp;   //!
   TBranch        *b_P_hod_2y_posAdcPulseAmp;   //!
   TBranch        *b_Ndata_P_hod_2y_posAdcPulseAmpRaw;   //!
   TBranch        *b_P_hod_2y_posAdcPulseAmpRaw;   //!
   TBranch        *b_Ndata_P_hod_2y_posAdcPulseInt;   //!
   TBranch        *b_P_hod_2y_posAdcPulseInt;   //!
   TBranch        *b_Ndata_P_hod_2y_posAdcPulseIntRaw;   //!
   TBranch        *b_P_hod_2y_posAdcPulseIntRaw;   //!
   TBranch        *b_Ndata_P_hod_2y_posAdcPulseTimeRaw;   //!
   TBranch        *b_P_hod_2y_posAdcPulseTimeRaw;   //!
   TBranch        *b_Ndata_P_hod_2y_posTdcCounter;   //!
   TBranch        *b_P_hod_2y_posTdcCounter;   //!
   TBranch        *b_Ndata_P_hod_2y_posTdcTime;   //!
   TBranch        *b_P_hod_2y_posTdcTime;   //!
   TBranch        *b_Ndata_P_hod_2y_posTdcTimeRaw;   //!
   TBranch        *b_P_hod_2y_posTdcTimeRaw;   //!
   TBranch        *b_Ndata_P_ngcer_adc;   //!
   TBranch        *b_P_ngcer_adc;   //!
   TBranch        *b_Ndata_P_ngcer_adcCounter;   //!
   TBranch        *b_P_ngcer_adcCounter;   //!
   TBranch        *b_Ndata_P_ngcer_adcPed;   //!
   TBranch        *b_P_ngcer_adcPed;   //!
   TBranch        *b_Ndata_P_ngcer_adcPedRaw;   //!
   TBranch        *b_P_ngcer_adcPedRaw;   //!
   TBranch        *b_Ndata_P_ngcer_adcPulseAmp;   //!
   TBranch        *b_P_ngcer_adcPulseAmp;   //!
   TBranch        *b_Ndata_P_ngcer_adcPulseAmpRaw;   //!
   TBranch        *b_P_ngcer_adcPulseAmpRaw;   //!
   TBranch        *b_Ndata_P_ngcer_adcPulseInt;   //!
   TBranch        *b_P_ngcer_adcPulseInt;   //!
   TBranch        *b_Ndata_P_ngcer_adcPulseIntRaw;   //!
   TBranch        *b_P_ngcer_adcPulseIntRaw;   //!
   TBranch        *b_Ndata_P_ngcer_adcPulseTimeRaw;   //!
   TBranch        *b_P_ngcer_adcPulseTimeRaw;   //!
   TBranch        *b_Ndata_P_ngcer_adc_hit;   //!
   TBranch        *b_P_ngcer_adc_hit;   //!
   TBranch        *b_Ndata_P_ngcer_adc_p;   //!
   TBranch        *b_P_ngcer_adc_p;   //!
   TBranch        *b_Ndata_P_ngcer_cerfiredcounter;   //!
   TBranch        *b_P_ngcer_cerfiredcounter;   //!
   TBranch        *b_Ndata_P_ngcer_certrackcounter;   //!
   TBranch        *b_P_ngcer_certrackcounter;   //!
   TBranch        *b_Ndata_P_ngcer_npe;   //!
   TBranch        *b_P_ngcer_npe;   //!
   TBranch        *b_Ndata_P_ngcer_phototubes;   //!
   TBranch        *b_P_ngcer_phototubes;   //!
   TBranch        *b_Ndata_P_tr_beta;   //!
   TBranch        *b_P_tr_beta;   //!
   TBranch        *b_Ndata_P_tr_betachisq;   //!
   TBranch        *b_P_tr_betachisq;   //!
   TBranch        *b_Ndata_P_tr_chi2;   //!
   TBranch        *b_P_tr_chi2;   //!
   TBranch        *b_Ndata_P_tr_d_ph;   //!
   TBranch        *b_P_tr_d_ph;   //!
   TBranch        *b_Ndata_P_tr_d_th;   //!
   TBranch        *b_P_tr_d_th;   //!
   TBranch        *b_Ndata_P_tr_d_x;   //!
   TBranch        *b_P_tr_d_x;   //!
   TBranch        *b_Ndata_P_tr_d_y;   //!
   TBranch        *b_P_tr_d_y;   //!
   TBranch        *b_Ndata_P_tr_dbeta;   //!
   TBranch        *b_P_tr_dbeta;   //!
   TBranch        *b_Ndata_P_tr_dtime;   //!
   TBranch        *b_P_tr_dtime;   //!
   TBranch        *b_Ndata_P_tr_flag;   //!
   TBranch        *b_P_tr_flag;   //!
   TBranch        *b_Ndata_P_tr_ndof;   //!
   TBranch        *b_P_tr_ndof;   //!
   TBranch        *b_Ndata_P_tr_p;   //!
   TBranch        *b_P_tr_p;   //!
   TBranch        *b_Ndata_P_tr_pathl;   //!
   TBranch        *b_P_tr_pathl;   //!
   TBranch        *b_Ndata_P_tr_ph;   //!
   TBranch        *b_P_tr_ph;   //!
   TBranch        *b_Ndata_P_tr_px;   //!
   TBranch        *b_P_tr_px;   //!
   TBranch        *b_Ndata_P_tr_py;   //!
   TBranch        *b_P_tr_py;   //!
   TBranch        *b_Ndata_P_tr_pz;   //!
   TBranch        *b_P_tr_pz;   //!
   TBranch        *b_Ndata_P_tr_r_ph;   //!
   TBranch        *b_P_tr_r_ph;   //!
   TBranch        *b_Ndata_P_tr_r_th;   //!
   TBranch        *b_P_tr_r_th;   //!
   TBranch        *b_Ndata_P_tr_r_x;   //!
   TBranch        *b_P_tr_r_x;   //!
   TBranch        *b_Ndata_P_tr_r_y;   //!
   TBranch        *b_P_tr_r_y;   //!
   TBranch        *b_Ndata_P_tr_tg_dp;   //!
   TBranch        *b_P_tr_tg_dp;   //!
   TBranch        *b_Ndata_P_tr_tg_ph;   //!
   TBranch        *b_P_tr_tg_ph;   //!
   TBranch        *b_Ndata_P_tr_tg_th;   //!
   TBranch        *b_P_tr_tg_th;   //!
   TBranch        *b_Ndata_P_tr_tg_y;   //!
   TBranch        *b_P_tr_tg_y;   //!
   TBranch        *b_Ndata_P_tr_th;   //!
   TBranch        *b_P_tr_th;   //!
   TBranch        *b_Ndata_P_tr_time;   //!
   TBranch        *b_P_tr_time;   //!
   TBranch        *b_Ndata_P_tr_vx;   //!
   TBranch        *b_P_tr_vx;   //!
   TBranch        *b_Ndata_P_tr_vy;   //!
   TBranch        *b_P_tr_vy;   //!
   TBranch        *b_Ndata_P_tr_vz;   //!
   TBranch        *b_P_tr_vz;   //!
   TBranch        *b_Ndata_P_tr_x;   //!
   TBranch        *b_P_tr_x;   //!
   TBranch        *b_Ndata_P_tr_y;   //!
   TBranch        *b_P_tr_y;   //!
   TBranch        *b_P_aero_neg_npe_sum;   //!
   TBranch        *b_P_aero_ngood_hits;   //!
   TBranch        *b_P_aero_npe_sum;   //!
   TBranch        *b_P_aero_ntdc_neg_hits;   //!
   TBranch        *b_P_aero_ntdc_pos_hits;   //!
   TBranch        *b_P_aero_pos_npe_sum;   //!
   TBranch        *b_P_cal_etot;   //!
   TBranch        *b_P_cal_etotnorm;   //!
   TBranch        *b_P_cal_etrack;   //!
   TBranch        *b_P_cal_fly_earray;   //!
   TBranch        *b_P_cal_fly_nclust;   //!
   TBranch        *b_P_cal_fly_nhits;   //!
   TBranch        *b_P_cal_fly_ntracks;   //!
   TBranch        *b_P_cal_nclust;   //!
   TBranch        *b_P_cal_nhits;   //!
   TBranch        *b_P_cal_ntracks;   //!
   TBranch        *b_P_cal_pr_eplane;   //!
   TBranch        *b_P_cal_pr_eplane_neg;   //!
   TBranch        *b_P_cal_pr_eplane_pos;   //!
   TBranch        *b_P_dc_1u1_nhit;   //!
   TBranch        *b_P_dc_1u2_nhit;   //!
   TBranch        *b_P_dc_1v1_nhit;   //!
   TBranch        *b_P_dc_1v2_nhit;   //!
   TBranch        *b_P_dc_1x1_nhit;   //!
   TBranch        *b_P_dc_1x2_nhit;   //!
   TBranch        *b_P_dc_2u1_nhit;   //!
   TBranch        *b_P_dc_2u2_nhit;   //!
   TBranch        *b_P_dc_2v1_nhit;   //!
   TBranch        *b_P_dc_2v2_nhit;   //!
   TBranch        *b_P_dc_2x1_nhit;   //!
   TBranch        *b_P_dc_2x2_nhit;   //!
   TBranch        *b_P_dc_Ch1_maxhits;   //!
   TBranch        *b_P_dc_Ch1_nhit;   //!
   TBranch        *b_P_dc_Ch1_spacepoints;   //!
   TBranch        *b_P_dc_Ch1_trawhit;   //!
   TBranch        *b_P_dc_Ch2_maxhits;   //!
   TBranch        *b_P_dc_Ch2_nhit;   //!
   TBranch        *b_P_dc_Ch2_spacepoints;   //!
   TBranch        *b_P_dc_Ch2_trawhit;   //!
   TBranch        *b_P_dc_nhit;   //!
   TBranch        *b_P_dc_nsp;   //!
   TBranch        *b_P_dc_ntrack;   //!
   TBranch        *b_P_dc_stubtest;   //!
   TBranch        *b_P_dc_tnhit;   //!
   TBranch        *b_P_dc_trawhit;   //!
   TBranch        *b_P_hgcer_ncherhit;   //!
   TBranch        *b_P_hgcer_npesum;   //!
   TBranch        *b_P_hod_1x_fptime;   //!
   TBranch        *b_P_hod_1x_ngoodhits;   //!
   TBranch        *b_P_hod_1x_nhits;   //!
   TBranch        *b_P_hod_1y_fptime;   //!
   TBranch        *b_P_hod_1y_ngoodhits;   //!
   TBranch        *b_P_hod_1y_nhits;   //!
   TBranch        *b_P_hod_2x_fptime;   //!
   TBranch        *b_P_hod_2x_ngoodhits;   //!
   TBranch        *b_P_hod_2x_nhits;   //!
   TBranch        *b_P_hod_2y_fptime;   //!
   TBranch        *b_P_hod_2y_ngoodhits;   //!
   TBranch        *b_P_hod_2y_nhits;   //!
   TBranch        *b_P_hod_betachisqnotrack;   //!
   TBranch        *b_P_hod_betanotrack;   //!
   TBranch        *b_P_hod_betap;   //!
   TBranch        *b_P_hod_fpHitsTime;   //!
   TBranch        *b_P_hod_goodscinhit;   //!
   TBranch        *b_P_hod_goodstarttime;   //!
   TBranch        *b_P_hod_scindid;   //!
   TBranch        *b_P_hod_scinshould;   //!
   TBranch        *b_P_hod_starttime;   //!
   TBranch        *b_P_ngcer_ncherhit;   //!
   TBranch        *b_P_ngcer_npesum;   //!
   TBranch        *b_P_tr_n;   //!
   TBranch        *b_T_shms_p1T_tdcMultiplicity;   //!
   TBranch        *b_T_shms_p1T_tdcTime;   //!
   TBranch        *b_T_shms_p1T_tdcTimeRaw;   //!
   TBranch        *b_T_shms_p1X_tdcMultiplicity;   //!
   TBranch        *b_T_shms_p1X_tdcTime;   //!
   TBranch        *b_T_shms_p1X_tdcTimeRaw;   //!
   TBranch        *b_T_shms_p1Y_tdcMultiplicity;   //!
   TBranch        *b_T_shms_p1Y_tdcTime;   //!
   TBranch        *b_T_shms_p1Y_tdcTimeRaw;   //!
   TBranch        *b_T_shms_p2T_tdcMultiplicity;   //!
   TBranch        *b_T_shms_p2T_tdcTime;   //!
   TBranch        *b_T_shms_p2T_tdcTimeRaw;   //!
   TBranch        *b_T_shms_p2X_tdcMultiplicity;   //!
   TBranch        *b_T_shms_p2X_tdcTime;   //!
   TBranch        *b_T_shms_p2X_tdcTimeRaw;   //!
   TBranch        *b_T_shms_p2Y_tdcMultiplicity;   //!
   TBranch        *b_T_shms_p2Y_tdcTime;   //!
   TBranch        *b_T_shms_p2Y_tdcTimeRaw;   //!
   TBranch        *b_T_shms_pAERSUM_adcMultiplicity;   //!
   TBranch        *b_T_shms_pAERSUM_adcPed;   //!
   TBranch        *b_T_shms_pAERSUM_adcPedRaw;   //!
   TBranch        *b_T_shms_pAERSUM_adcPulseAmp;   //!
   TBranch        *b_T_shms_pAERSUM_adcPulseAmpRaw;   //!
   TBranch        *b_T_shms_pAERSUM_adcPulseInt;   //!
   TBranch        *b_T_shms_pAERSUM_adcPulseIntRaw;   //!
   TBranch        *b_T_shms_pAERSUM_adcPulseTimeRaw;   //!
   TBranch        *b_T_shms_pAERSUM_tdcMultiplicity;   //!
   TBranch        *b_T_shms_pAERSUM_tdcTime;   //!
   TBranch        *b_T_shms_pAERSUM_tdcTimeRaw;   //!
   TBranch        *b_T_shms_pDCREF10_tdcMultiplicity;   //!
   TBranch        *b_T_shms_pDCREF10_tdcTime;   //!
   TBranch        *b_T_shms_pDCREF10_tdcTimeRaw;   //!
   TBranch        *b_T_shms_pDCREF1_tdcMultiplicity;   //!
   TBranch        *b_T_shms_pDCREF1_tdcTime;   //!
   TBranch        *b_T_shms_pDCREF1_tdcTimeRaw;   //!
   TBranch        *b_T_shms_pDCREF2_tdcMultiplicity;   //!
   TBranch        *b_T_shms_pDCREF2_tdcTime;   //!
   TBranch        *b_T_shms_pDCREF2_tdcTimeRaw;   //!
   TBranch        *b_T_shms_pDCREF3_tdcMultiplicity;   //!
   TBranch        *b_T_shms_pDCREF3_tdcTime;   //!
   TBranch        *b_T_shms_pDCREF3_tdcTimeRaw;   //!
   TBranch        *b_T_shms_pDCREF4_tdcMultiplicity;   //!
   TBranch        *b_T_shms_pDCREF4_tdcTime;   //!
   TBranch        *b_T_shms_pDCREF4_tdcTimeRaw;   //!
   TBranch        *b_T_shms_pDCREF5_tdcMultiplicity;   //!
   TBranch        *b_T_shms_pDCREF5_tdcTime;   //!
   TBranch        *b_T_shms_pDCREF5_tdcTimeRaw;   //!
   TBranch        *b_T_shms_pDCREF6_tdcMultiplicity;   //!
   TBranch        *b_T_shms_pDCREF6_tdcTime;   //!
   TBranch        *b_T_shms_pDCREF6_tdcTimeRaw;   //!
   TBranch        *b_T_shms_pDCREF7_tdcMultiplicity;   //!
   TBranch        *b_T_shms_pDCREF7_tdcTime;   //!
   TBranch        *b_T_shms_pDCREF7_tdcTimeRaw;   //!
   TBranch        *b_T_shms_pDCREF8_tdcMultiplicity;   //!
   TBranch        *b_T_shms_pDCREF8_tdcTime;   //!
   TBranch        *b_T_shms_pDCREF8_tdcTimeRaw;   //!
   TBranch        *b_T_shms_pDCREF9_tdcMultiplicity;   //!
   TBranch        *b_T_shms_pDCREF9_tdcTime;   //!
   TBranch        *b_T_shms_pDCREF9_tdcTimeRaw;   //!
   TBranch        *b_T_shms_pHGCSUM_adcMultiplicity;   //!
   TBranch        *b_T_shms_pHGCSUM_adcPed;   //!
   TBranch        *b_T_shms_pHGCSUM_adcPedRaw;   //!
   TBranch        *b_T_shms_pHGCSUM_adcPulseAmp;   //!
   TBranch        *b_T_shms_pHGCSUM_adcPulseAmpRaw;   //!
   TBranch        *b_T_shms_pHGCSUM_adcPulseInt;   //!
   TBranch        *b_T_shms_pHGCSUM_adcPulseIntRaw;   //!
   TBranch        *b_T_shms_pHGCSUM_adcPulseTimeRaw;   //!
   TBranch        *b_T_shms_pHGCSUM_tdcMultiplicity;   //!
   TBranch        *b_T_shms_pHGCSUM_tdcTime;   //!
   TBranch        *b_T_shms_pHGCSUM_tdcTimeRaw;   //!
   TBranch        *b_T_shms_pNGCSUM_adcMultiplicity;   //!
   TBranch        *b_T_shms_pNGCSUM_adcPed;   //!
   TBranch        *b_T_shms_pNGCSUM_adcPedRaw;   //!
   TBranch        *b_T_shms_pNGCSUM_adcPulseAmp;   //!
   TBranch        *b_T_shms_pNGCSUM_adcPulseAmpRaw;   //!
   TBranch        *b_T_shms_pNGCSUM_adcPulseInt;   //!
   TBranch        *b_T_shms_pNGCSUM_adcPulseIntRaw;   //!
   TBranch        *b_T_shms_pNGCSUM_adcPulseTimeRaw;   //!
   TBranch        *b_T_shms_pNGCSUM_tdcMultiplicity;   //!
   TBranch        *b_T_shms_pNGCSUM_tdcTime;   //!
   TBranch        *b_T_shms_pNGCSUM_tdcTimeRaw;   //!
   TBranch        *b_T_shms_pT1_tdcMultiplicity;   //!
   TBranch        *b_T_shms_pT1_tdcTime;   //!
   TBranch        *b_T_shms_pT1_tdcTimeRaw;   //!
   TBranch        *b_T_shms_pT2_tdcMultiplicity;   //!
   TBranch        *b_T_shms_pT2_tdcTime;   //!
   TBranch        *b_T_shms_pT2_tdcTimeRaw;   //!
   TBranch        *b_T_shms_pT3_tdcMultiplicity;   //!
   TBranch        *b_T_shms_pT3_tdcTime;   //!
   TBranch        *b_T_shms_pT3_tdcTimeRaw;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fEvtTime;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fEvtNum;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fEvtType;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fEvtLen;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fHelicity;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fTargetPol;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fRun;   //!

   shower(TTree *tree=0);
   virtual ~shower();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef shower_cxx
shower::shower(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("ROOTfiles/shms_replay_488_1000000.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("ROOTfiles/shms_replay_488_-1.root");
      }
      f->GetObject("T",tree);

   }
   Init(tree);
}

shower::~shower()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t shower::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t shower::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void shower::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Ndata.P.aero.aneg", &Ndata_P_aero_aneg, &b_Ndata_P_aero_aneg);
   fChain->SetBranchAddress("P.aero.aneg", P_aero_aneg, &b_P_aero_aneg);
   fChain->SetBranchAddress("Ndata.P.aero.aneg_p", &Ndata_P_aero_aneg_p, &b_Ndata_P_aero_aneg_p);
   fChain->SetBranchAddress("P.aero.aneg_p", P_aero_aneg_p, &b_P_aero_aneg_p);
   fChain->SetBranchAddress("Ndata.P.aero.apos", &Ndata_P_aero_apos, &b_Ndata_P_aero_apos);
   fChain->SetBranchAddress("P.aero.apos", P_aero_apos, &b_P_aero_apos);
   fChain->SetBranchAddress("Ndata.P.aero.apos_p", &Ndata_P_aero_apos_p, &b_Ndata_P_aero_apos_p);
   fChain->SetBranchAddress("P.aero.apos_p", P_aero_apos_p, &b_P_aero_apos_p);
   fChain->SetBranchAddress("Ndata.P.aero.negAdcCounter", &Ndata_P_aero_negAdcCounter, &b_Ndata_P_aero_negAdcCounter);
   fChain->SetBranchAddress("P.aero.negAdcCounter", P_aero_negAdcCounter, &b_P_aero_negAdcCounter);
   fChain->SetBranchAddress("Ndata.P.aero.negAdcPed", &Ndata_P_aero_negAdcPed, &b_Ndata_P_aero_negAdcPed);
   fChain->SetBranchAddress("P.aero.negAdcPed", P_aero_negAdcPed, &b_P_aero_negAdcPed);
   fChain->SetBranchAddress("Ndata.P.aero.negAdcPedRaw", &Ndata_P_aero_negAdcPedRaw, &b_Ndata_P_aero_negAdcPedRaw);
   fChain->SetBranchAddress("P.aero.negAdcPedRaw", P_aero_negAdcPedRaw, &b_P_aero_negAdcPedRaw);
   fChain->SetBranchAddress("Ndata.P.aero.negAdcPulseAmp", &Ndata_P_aero_negAdcPulseAmp, &b_Ndata_P_aero_negAdcPulseAmp);
   fChain->SetBranchAddress("P.aero.negAdcPulseAmp", P_aero_negAdcPulseAmp, &b_P_aero_negAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.aero.negAdcPulseAmpRaw", &Ndata_P_aero_negAdcPulseAmpRaw, &b_Ndata_P_aero_negAdcPulseAmpRaw);
   fChain->SetBranchAddress("P.aero.negAdcPulseAmpRaw", P_aero_negAdcPulseAmpRaw, &b_P_aero_negAdcPulseAmpRaw);
   fChain->SetBranchAddress("Ndata.P.aero.negAdcPulseInt", &Ndata_P_aero_negAdcPulseInt, &b_Ndata_P_aero_negAdcPulseInt);
   fChain->SetBranchAddress("P.aero.negAdcPulseInt", P_aero_negAdcPulseInt, &b_P_aero_negAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.aero.negAdcPulseIntRaw", &Ndata_P_aero_negAdcPulseIntRaw, &b_Ndata_P_aero_negAdcPulseIntRaw);
   fChain->SetBranchAddress("P.aero.negAdcPulseIntRaw", P_aero_negAdcPulseIntRaw, &b_P_aero_negAdcPulseIntRaw);
   fChain->SetBranchAddress("Ndata.P.aero.negAdcPulseTimeRaw", &Ndata_P_aero_negAdcPulseTimeRaw, &b_Ndata_P_aero_negAdcPulseTimeRaw);
   fChain->SetBranchAddress("P.aero.negAdcPulseTimeRaw", P_aero_negAdcPulseTimeRaw, &b_P_aero_negAdcPulseTimeRaw);
   fChain->SetBranchAddress("Ndata.P.aero.neg_npe", &Ndata_P_aero_neg_npe, &b_Ndata_P_aero_neg_npe);
   fChain->SetBranchAddress("P.aero.neg_npe", P_aero_neg_npe, &b_P_aero_neg_npe);
   fChain->SetBranchAddress("Ndata.P.aero.negadchits", &Ndata_P_aero_negadchits, &b_Ndata_P_aero_negadchits);
   fChain->SetBranchAddress("P.aero.negadchits", P_aero_negadchits, &b_P_aero_negadchits);
   fChain->SetBranchAddress("Ndata.P.aero.negtdchits", &Ndata_P_aero_negtdchits, &b_Ndata_P_aero_negtdchits);
   fChain->SetBranchAddress("P.aero.negtdchits", &P_aero_negtdchits, &b_P_aero_negtdchits);
   fChain->SetBranchAddress("Ndata.P.aero.posAdcCounter", &Ndata_P_aero_posAdcCounter, &b_Ndata_P_aero_posAdcCounter);
   fChain->SetBranchAddress("P.aero.posAdcCounter", P_aero_posAdcCounter, &b_P_aero_posAdcCounter);
   fChain->SetBranchAddress("Ndata.P.aero.posAdcPed", &Ndata_P_aero_posAdcPed, &b_Ndata_P_aero_posAdcPed);
   fChain->SetBranchAddress("P.aero.posAdcPed", P_aero_posAdcPed, &b_P_aero_posAdcPed);
   fChain->SetBranchAddress("Ndata.P.aero.posAdcPedRaw", &Ndata_P_aero_posAdcPedRaw, &b_Ndata_P_aero_posAdcPedRaw);
   fChain->SetBranchAddress("P.aero.posAdcPedRaw", P_aero_posAdcPedRaw, &b_P_aero_posAdcPedRaw);
   fChain->SetBranchAddress("Ndata.P.aero.posAdcPulseAmp", &Ndata_P_aero_posAdcPulseAmp, &b_Ndata_P_aero_posAdcPulseAmp);
   fChain->SetBranchAddress("P.aero.posAdcPulseAmp", P_aero_posAdcPulseAmp, &b_P_aero_posAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.aero.posAdcPulseAmpRaw", &Ndata_P_aero_posAdcPulseAmpRaw, &b_Ndata_P_aero_posAdcPulseAmpRaw);
   fChain->SetBranchAddress("P.aero.posAdcPulseAmpRaw", P_aero_posAdcPulseAmpRaw, &b_P_aero_posAdcPulseAmpRaw);
   fChain->SetBranchAddress("Ndata.P.aero.posAdcPulseInt", &Ndata_P_aero_posAdcPulseInt, &b_Ndata_P_aero_posAdcPulseInt);
   fChain->SetBranchAddress("P.aero.posAdcPulseInt", P_aero_posAdcPulseInt, &b_P_aero_posAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.aero.posAdcPulseIntRaw", &Ndata_P_aero_posAdcPulseIntRaw, &b_Ndata_P_aero_posAdcPulseIntRaw);
   fChain->SetBranchAddress("P.aero.posAdcPulseIntRaw", P_aero_posAdcPulseIntRaw, &b_P_aero_posAdcPulseIntRaw);
   fChain->SetBranchAddress("Ndata.P.aero.posAdcPulseTimeRaw", &Ndata_P_aero_posAdcPulseTimeRaw, &b_Ndata_P_aero_posAdcPulseTimeRaw);
   fChain->SetBranchAddress("P.aero.posAdcPulseTimeRaw", P_aero_posAdcPulseTimeRaw, &b_P_aero_posAdcPulseTimeRaw);
   fChain->SetBranchAddress("Ndata.P.aero.pos_npe", &Ndata_P_aero_pos_npe, &b_Ndata_P_aero_pos_npe);
   fChain->SetBranchAddress("P.aero.pos_npe", P_aero_pos_npe, &b_P_aero_pos_npe);
   fChain->SetBranchAddress("Ndata.P.aero.posadchits", &Ndata_P_aero_posadchits, &b_Ndata_P_aero_posadchits);
   fChain->SetBranchAddress("P.aero.posadchits", P_aero_posadchits, &b_P_aero_posadchits);
   fChain->SetBranchAddress("Ndata.P.aero.postdchits", &Ndata_P_aero_postdchits, &b_Ndata_P_aero_postdchits);
   fChain->SetBranchAddress("P.aero.postdchits", &P_aero_postdchits, &b_P_aero_postdchits);
   fChain->SetBranchAddress("Ndata.P.aero.tneg", &Ndata_P_aero_tneg, &b_Ndata_P_aero_tneg);
   fChain->SetBranchAddress("P.aero.tneg", P_aero_tneg, &b_P_aero_tneg);
   fChain->SetBranchAddress("Ndata.P.aero.tpos", &Ndata_P_aero_tpos, &b_Ndata_P_aero_tpos);
   fChain->SetBranchAddress("P.aero.tpos", P_aero_tpos, &b_P_aero_tpos);
   fChain->SetBranchAddress("Ndata.P.cal.fly.a", &Ndata_P_cal_fly_a, &b_Ndata_P_cal_fly_a);
   fChain->SetBranchAddress("P.cal.fly.a", P_cal_fly_a, &b_P_cal_fly_a);
   fChain->SetBranchAddress("Ndata.P.cal.fly.a_p", &Ndata_P_cal_fly_a_p, &b_Ndata_P_cal_fly_a_p);
   fChain->SetBranchAddress("P.cal.fly.a_p", P_cal_fly_a_p, &b_P_cal_fly_a_p);
   fChain->SetBranchAddress("Ndata.P.cal.fly.adcCounter", &Ndata_P_cal_fly_adcCounter, &b_Ndata_P_cal_fly_adcCounter);
   fChain->SetBranchAddress("P.cal.fly.adcCounter", P_cal_fly_adcCounter, &b_P_cal_fly_adcCounter);
   fChain->SetBranchAddress("Ndata.P.cal.fly.adcPed", &Ndata_P_cal_fly_adcPed, &b_Ndata_P_cal_fly_adcPed);
   fChain->SetBranchAddress("P.cal.fly.adcPed", P_cal_fly_adcPed, &b_P_cal_fly_adcPed);
   fChain->SetBranchAddress("Ndata.P.cal.fly.adcPedRaw", &Ndata_P_cal_fly_adcPedRaw, &b_Ndata_P_cal_fly_adcPedRaw);
   fChain->SetBranchAddress("P.cal.fly.adcPedRaw", P_cal_fly_adcPedRaw, &b_P_cal_fly_adcPedRaw);
   fChain->SetBranchAddress("Ndata.P.cal.fly.adcPulseAmp", &Ndata_P_cal_fly_adcPulseAmp, &b_Ndata_P_cal_fly_adcPulseAmp);
   fChain->SetBranchAddress("P.cal.fly.adcPulseAmp", P_cal_fly_adcPulseAmp, &b_P_cal_fly_adcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.cal.fly.adcPulseAmpRaw", &Ndata_P_cal_fly_adcPulseAmpRaw, &b_Ndata_P_cal_fly_adcPulseAmpRaw);
   fChain->SetBranchAddress("P.cal.fly.adcPulseAmpRaw", P_cal_fly_adcPulseAmpRaw, &b_P_cal_fly_adcPulseAmpRaw);
   fChain->SetBranchAddress("Ndata.P.cal.fly.adcPulseInt", &Ndata_P_cal_fly_adcPulseInt, &b_Ndata_P_cal_fly_adcPulseInt);
   fChain->SetBranchAddress("P.cal.fly.adcPulseInt", P_cal_fly_adcPulseInt, &b_P_cal_fly_adcPulseInt);
   fChain->SetBranchAddress("Ndata.P.cal.fly.adcPulseIntRaw", &Ndata_P_cal_fly_adcPulseIntRaw, &b_Ndata_P_cal_fly_adcPulseIntRaw);
   fChain->SetBranchAddress("P.cal.fly.adcPulseIntRaw", P_cal_fly_adcPulseIntRaw, &b_P_cal_fly_adcPulseIntRaw);
   fChain->SetBranchAddress("Ndata.P.cal.fly.adcPulseTimeRaw", &Ndata_P_cal_fly_adcPulseTimeRaw, &b_Ndata_P_cal_fly_adcPulseTimeRaw);
   fChain->SetBranchAddress("P.cal.fly.adcPulseTimeRaw", P_cal_fly_adcPulseTimeRaw, &b_P_cal_fly_adcPulseTimeRaw);
   fChain->SetBranchAddress("Ndata.P.cal.fly.adchits", &Ndata_P_cal_fly_adchits, &b_Ndata_P_cal_fly_adchits);
   fChain->SetBranchAddress("P.cal.fly.adchits", &P_cal_fly_adchits, &b_P_cal_fly_adchits);
   fChain->SetBranchAddress("Ndata.P.cal.fly.e", &Ndata_P_cal_fly_e, &b_Ndata_P_cal_fly_e);
   fChain->SetBranchAddress("P.cal.fly.e", P_cal_fly_e, &b_P_cal_fly_e);
   fChain->SetBranchAddress("Ndata.P.cal.fly.p", &Ndata_P_cal_fly_p, &b_Ndata_P_cal_fly_p);
   fChain->SetBranchAddress("P.cal.fly.p", P_cal_fly_p, &b_P_cal_fly_p);
   fChain->SetBranchAddress("Ndata.P.cal.pr.aneg", &Ndata_P_cal_pr_aneg, &b_Ndata_P_cal_pr_aneg);
   fChain->SetBranchAddress("P.cal.pr.aneg", P_cal_pr_aneg, &b_P_cal_pr_aneg);
   fChain->SetBranchAddress("Ndata.P.cal.pr.aneg_p", &Ndata_P_cal_pr_aneg_p, &b_Ndata_P_cal_pr_aneg_p);
   fChain->SetBranchAddress("P.cal.pr.aneg_p", P_cal_pr_aneg_p, &b_P_cal_pr_aneg_p);
   fChain->SetBranchAddress("Ndata.P.cal.pr.apos", &Ndata_P_cal_pr_apos, &b_Ndata_P_cal_pr_apos);
   fChain->SetBranchAddress("P.cal.pr.apos", P_cal_pr_apos, &b_P_cal_pr_apos);
   fChain->SetBranchAddress("Ndata.P.cal.pr.apos_p", &Ndata_P_cal_pr_apos_p, &b_Ndata_P_cal_pr_apos_p);
   fChain->SetBranchAddress("P.cal.pr.apos_p", P_cal_pr_apos_p, &b_P_cal_pr_apos_p);
   fChain->SetBranchAddress("Ndata.P.cal.pr.emean", &Ndata_P_cal_pr_emean, &b_Ndata_P_cal_pr_emean);
   fChain->SetBranchAddress("P.cal.pr.emean", P_cal_pr_emean, &b_P_cal_pr_emean);
   fChain->SetBranchAddress("Ndata.P.cal.pr.eneg", &Ndata_P_cal_pr_eneg, &b_Ndata_P_cal_pr_eneg);
   fChain->SetBranchAddress("P.cal.pr.eneg", P_cal_pr_eneg, &b_P_cal_pr_eneg);
   fChain->SetBranchAddress("Ndata.P.cal.pr.epos", &Ndata_P_cal_pr_epos, &b_Ndata_P_cal_pr_epos);
   fChain->SetBranchAddress("P.cal.pr.epos", P_cal_pr_epos, &b_P_cal_pr_epos);
   fChain->SetBranchAddress("Ndata.P.cal.pr.negAdcCounter", &Ndata_P_cal_pr_negAdcCounter, &b_Ndata_P_cal_pr_negAdcCounter);
   fChain->SetBranchAddress("P.cal.pr.negAdcCounter", P_cal_pr_negAdcCounter, &b_P_cal_pr_negAdcCounter);
   fChain->SetBranchAddress("Ndata.P.cal.pr.negAdcPed", &Ndata_P_cal_pr_negAdcPed, &b_Ndata_P_cal_pr_negAdcPed);
   fChain->SetBranchAddress("P.cal.pr.negAdcPed", P_cal_pr_negAdcPed, &b_P_cal_pr_negAdcPed);
   fChain->SetBranchAddress("Ndata.P.cal.pr.negAdcPedRaw", &Ndata_P_cal_pr_negAdcPedRaw, &b_Ndata_P_cal_pr_negAdcPedRaw);
   fChain->SetBranchAddress("P.cal.pr.negAdcPedRaw", P_cal_pr_negAdcPedRaw, &b_P_cal_pr_negAdcPedRaw);
   fChain->SetBranchAddress("Ndata.P.cal.pr.negAdcPulseAmp", &Ndata_P_cal_pr_negAdcPulseAmp, &b_Ndata_P_cal_pr_negAdcPulseAmp);
   fChain->SetBranchAddress("P.cal.pr.negAdcPulseAmp", P_cal_pr_negAdcPulseAmp, &b_P_cal_pr_negAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.cal.pr.negAdcPulseAmpRaw", &Ndata_P_cal_pr_negAdcPulseAmpRaw, &b_Ndata_P_cal_pr_negAdcPulseAmpRaw);
   fChain->SetBranchAddress("P.cal.pr.negAdcPulseAmpRaw", P_cal_pr_negAdcPulseAmpRaw, &b_P_cal_pr_negAdcPulseAmpRaw);
   fChain->SetBranchAddress("Ndata.P.cal.pr.negAdcPulseInt", &Ndata_P_cal_pr_negAdcPulseInt, &b_Ndata_P_cal_pr_negAdcPulseInt);
   fChain->SetBranchAddress("P.cal.pr.negAdcPulseInt", P_cal_pr_negAdcPulseInt, &b_P_cal_pr_negAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.cal.pr.negAdcPulseIntRaw", &Ndata_P_cal_pr_negAdcPulseIntRaw, &b_Ndata_P_cal_pr_negAdcPulseIntRaw);
   fChain->SetBranchAddress("P.cal.pr.negAdcPulseIntRaw", P_cal_pr_negAdcPulseIntRaw, &b_P_cal_pr_negAdcPulseIntRaw);
   fChain->SetBranchAddress("Ndata.P.cal.pr.negAdcPulseTimeRaw", &Ndata_P_cal_pr_negAdcPulseTimeRaw, &b_Ndata_P_cal_pr_negAdcPulseTimeRaw);
   fChain->SetBranchAddress("P.cal.pr.negAdcPulseTimeRaw", P_cal_pr_negAdcPulseTimeRaw, &b_P_cal_pr_negAdcPulseTimeRaw);
   fChain->SetBranchAddress("Ndata.P.cal.pr.negadchits", &Ndata_P_cal_pr_negadchits, &b_Ndata_P_cal_pr_negadchits);
   fChain->SetBranchAddress("P.cal.pr.negadchits", &P_cal_pr_negadchits, &b_P_cal_pr_negadchits);
   fChain->SetBranchAddress("Ndata.P.cal.pr.posAdcCounter", &Ndata_P_cal_pr_posAdcCounter, &b_Ndata_P_cal_pr_posAdcCounter);
   fChain->SetBranchAddress("P.cal.pr.posAdcCounter", P_cal_pr_posAdcCounter, &b_P_cal_pr_posAdcCounter);
   fChain->SetBranchAddress("Ndata.P.cal.pr.posAdcPed", &Ndata_P_cal_pr_posAdcPed, &b_Ndata_P_cal_pr_posAdcPed);
   fChain->SetBranchAddress("P.cal.pr.posAdcPed", P_cal_pr_posAdcPed, &b_P_cal_pr_posAdcPed);
   fChain->SetBranchAddress("Ndata.P.cal.pr.posAdcPedRaw", &Ndata_P_cal_pr_posAdcPedRaw, &b_Ndata_P_cal_pr_posAdcPedRaw);
   fChain->SetBranchAddress("P.cal.pr.posAdcPedRaw", P_cal_pr_posAdcPedRaw, &b_P_cal_pr_posAdcPedRaw);
   fChain->SetBranchAddress("Ndata.P.cal.pr.posAdcPulseAmp", &Ndata_P_cal_pr_posAdcPulseAmp, &b_Ndata_P_cal_pr_posAdcPulseAmp);
   fChain->SetBranchAddress("P.cal.pr.posAdcPulseAmp", P_cal_pr_posAdcPulseAmp, &b_P_cal_pr_posAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.cal.pr.posAdcPulseAmpRaw", &Ndata_P_cal_pr_posAdcPulseAmpRaw, &b_Ndata_P_cal_pr_posAdcPulseAmpRaw);
   fChain->SetBranchAddress("P.cal.pr.posAdcPulseAmpRaw", P_cal_pr_posAdcPulseAmpRaw, &b_P_cal_pr_posAdcPulseAmpRaw);
   fChain->SetBranchAddress("Ndata.P.cal.pr.posAdcPulseInt", &Ndata_P_cal_pr_posAdcPulseInt, &b_Ndata_P_cal_pr_posAdcPulseInt);
   fChain->SetBranchAddress("P.cal.pr.posAdcPulseInt", P_cal_pr_posAdcPulseInt, &b_P_cal_pr_posAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.cal.pr.posAdcPulseIntRaw", &Ndata_P_cal_pr_posAdcPulseIntRaw, &b_Ndata_P_cal_pr_posAdcPulseIntRaw);
   fChain->SetBranchAddress("P.cal.pr.posAdcPulseIntRaw", P_cal_pr_posAdcPulseIntRaw, &b_P_cal_pr_posAdcPulseIntRaw);
   fChain->SetBranchAddress("Ndata.P.cal.pr.posAdcPulseTimeRaw", &Ndata_P_cal_pr_posAdcPulseTimeRaw, &b_Ndata_P_cal_pr_posAdcPulseTimeRaw);
   fChain->SetBranchAddress("P.cal.pr.posAdcPulseTimeRaw", P_cal_pr_posAdcPulseTimeRaw, &b_P_cal_pr_posAdcPulseTimeRaw);
   fChain->SetBranchAddress("Ndata.P.cal.pr.posadchits", &Ndata_P_cal_pr_posadchits, &b_Ndata_P_cal_pr_posadchits);
   fChain->SetBranchAddress("P.cal.pr.posadchits", &P_cal_pr_posadchits, &b_P_cal_pr_posadchits);
   fChain->SetBranchAddress("Ndata.P.dc.1u1.dist", &Ndata_P_dc_1u1_dist, &b_Ndata_P_dc_1u1_dist);
   fChain->SetBranchAddress("P.dc.1u1.dist", P_dc_1u1_dist, &b_P_dc_1u1_dist);
   fChain->SetBranchAddress("Ndata.P.dc.1u1.rawtdc", &Ndata_P_dc_1u1_rawtdc, &b_Ndata_P_dc_1u1_rawtdc);
   fChain->SetBranchAddress("P.dc.1u1.rawtdc", P_dc_1u1_rawtdc, &b_P_dc_1u1_rawtdc);
   fChain->SetBranchAddress("Ndata.P.dc.1u1.time", &Ndata_P_dc_1u1_time, &b_Ndata_P_dc_1u1_time);
   fChain->SetBranchAddress("P.dc.1u1.time", P_dc_1u1_time, &b_P_dc_1u1_time);
   fChain->SetBranchAddress("Ndata.P.dc.1u1.wirenum", &Ndata_P_dc_1u1_wirenum, &b_Ndata_P_dc_1u1_wirenum);
   fChain->SetBranchAddress("P.dc.1u1.wirenum", P_dc_1u1_wirenum, &b_P_dc_1u1_wirenum);
   fChain->SetBranchAddress("Ndata.P.dc.1u2.dist", &Ndata_P_dc_1u2_dist, &b_Ndata_P_dc_1u2_dist);
   fChain->SetBranchAddress("P.dc.1u2.dist", P_dc_1u2_dist, &b_P_dc_1u2_dist);
   fChain->SetBranchAddress("Ndata.P.dc.1u2.rawtdc", &Ndata_P_dc_1u2_rawtdc, &b_Ndata_P_dc_1u2_rawtdc);
   fChain->SetBranchAddress("P.dc.1u2.rawtdc", P_dc_1u2_rawtdc, &b_P_dc_1u2_rawtdc);
   fChain->SetBranchAddress("Ndata.P.dc.1u2.time", &Ndata_P_dc_1u2_time, &b_Ndata_P_dc_1u2_time);
   fChain->SetBranchAddress("P.dc.1u2.time", P_dc_1u2_time, &b_P_dc_1u2_time);
   fChain->SetBranchAddress("Ndata.P.dc.1u2.wirenum", &Ndata_P_dc_1u2_wirenum, &b_Ndata_P_dc_1u2_wirenum);
   fChain->SetBranchAddress("P.dc.1u2.wirenum", P_dc_1u2_wirenum, &b_P_dc_1u2_wirenum);
   fChain->SetBranchAddress("Ndata.P.dc.1v1.dist", &Ndata_P_dc_1v1_dist, &b_Ndata_P_dc_1v1_dist);
   fChain->SetBranchAddress("P.dc.1v1.dist", P_dc_1v1_dist, &b_P_dc_1v1_dist);
   fChain->SetBranchAddress("Ndata.P.dc.1v1.rawtdc", &Ndata_P_dc_1v1_rawtdc, &b_Ndata_P_dc_1v1_rawtdc);
   fChain->SetBranchAddress("P.dc.1v1.rawtdc", P_dc_1v1_rawtdc, &b_P_dc_1v1_rawtdc);
   fChain->SetBranchAddress("Ndata.P.dc.1v1.time", &Ndata_P_dc_1v1_time, &b_Ndata_P_dc_1v1_time);
   fChain->SetBranchAddress("P.dc.1v1.time", P_dc_1v1_time, &b_P_dc_1v1_time);
   fChain->SetBranchAddress("Ndata.P.dc.1v1.wirenum", &Ndata_P_dc_1v1_wirenum, &b_Ndata_P_dc_1v1_wirenum);
   fChain->SetBranchAddress("P.dc.1v1.wirenum", P_dc_1v1_wirenum, &b_P_dc_1v1_wirenum);
   fChain->SetBranchAddress("Ndata.P.dc.1v2.dist", &Ndata_P_dc_1v2_dist, &b_Ndata_P_dc_1v2_dist);
   fChain->SetBranchAddress("P.dc.1v2.dist", P_dc_1v2_dist, &b_P_dc_1v2_dist);
   fChain->SetBranchAddress("Ndata.P.dc.1v2.rawtdc", &Ndata_P_dc_1v2_rawtdc, &b_Ndata_P_dc_1v2_rawtdc);
   fChain->SetBranchAddress("P.dc.1v2.rawtdc", P_dc_1v2_rawtdc, &b_P_dc_1v2_rawtdc);
   fChain->SetBranchAddress("Ndata.P.dc.1v2.time", &Ndata_P_dc_1v2_time, &b_Ndata_P_dc_1v2_time);
   fChain->SetBranchAddress("P.dc.1v2.time", P_dc_1v2_time, &b_P_dc_1v2_time);
   fChain->SetBranchAddress("Ndata.P.dc.1v2.wirenum", &Ndata_P_dc_1v2_wirenum, &b_Ndata_P_dc_1v2_wirenum);
   fChain->SetBranchAddress("P.dc.1v2.wirenum", P_dc_1v2_wirenum, &b_P_dc_1v2_wirenum);
   fChain->SetBranchAddress("Ndata.P.dc.1x1.dist", &Ndata_P_dc_1x1_dist, &b_Ndata_P_dc_1x1_dist);
   fChain->SetBranchAddress("P.dc.1x1.dist", P_dc_1x1_dist, &b_P_dc_1x1_dist);
   fChain->SetBranchAddress("Ndata.P.dc.1x1.rawtdc", &Ndata_P_dc_1x1_rawtdc, &b_Ndata_P_dc_1x1_rawtdc);
   fChain->SetBranchAddress("P.dc.1x1.rawtdc", P_dc_1x1_rawtdc, &b_P_dc_1x1_rawtdc);
   fChain->SetBranchAddress("Ndata.P.dc.1x1.time", &Ndata_P_dc_1x1_time, &b_Ndata_P_dc_1x1_time);
   fChain->SetBranchAddress("P.dc.1x1.time", P_dc_1x1_time, &b_P_dc_1x1_time);
   fChain->SetBranchAddress("Ndata.P.dc.1x1.wirenum", &Ndata_P_dc_1x1_wirenum, &b_Ndata_P_dc_1x1_wirenum);
   fChain->SetBranchAddress("P.dc.1x1.wirenum", P_dc_1x1_wirenum, &b_P_dc_1x1_wirenum);
   fChain->SetBranchAddress("Ndata.P.dc.1x2.dist", &Ndata_P_dc_1x2_dist, &b_Ndata_P_dc_1x2_dist);
   fChain->SetBranchAddress("P.dc.1x2.dist", P_dc_1x2_dist, &b_P_dc_1x2_dist);
   fChain->SetBranchAddress("Ndata.P.dc.1x2.rawtdc", &Ndata_P_dc_1x2_rawtdc, &b_Ndata_P_dc_1x2_rawtdc);
   fChain->SetBranchAddress("P.dc.1x2.rawtdc", P_dc_1x2_rawtdc, &b_P_dc_1x2_rawtdc);
   fChain->SetBranchAddress("Ndata.P.dc.1x2.time", &Ndata_P_dc_1x2_time, &b_Ndata_P_dc_1x2_time);
   fChain->SetBranchAddress("P.dc.1x2.time", P_dc_1x2_time, &b_P_dc_1x2_time);
   fChain->SetBranchAddress("Ndata.P.dc.1x2.wirenum", &Ndata_P_dc_1x2_wirenum, &b_Ndata_P_dc_1x2_wirenum);
   fChain->SetBranchAddress("P.dc.1x2.wirenum", P_dc_1x2_wirenum, &b_P_dc_1x2_wirenum);
   fChain->SetBranchAddress("Ndata.P.dc.2u1.dist", &Ndata_P_dc_2u1_dist, &b_Ndata_P_dc_2u1_dist);
   fChain->SetBranchAddress("P.dc.2u1.dist", P_dc_2u1_dist, &b_P_dc_2u1_dist);
   fChain->SetBranchAddress("Ndata.P.dc.2u1.rawtdc", &Ndata_P_dc_2u1_rawtdc, &b_Ndata_P_dc_2u1_rawtdc);
   fChain->SetBranchAddress("P.dc.2u1.rawtdc", P_dc_2u1_rawtdc, &b_P_dc_2u1_rawtdc);
   fChain->SetBranchAddress("Ndata.P.dc.2u1.time", &Ndata_P_dc_2u1_time, &b_Ndata_P_dc_2u1_time);
   fChain->SetBranchAddress("P.dc.2u1.time", P_dc_2u1_time, &b_P_dc_2u1_time);
   fChain->SetBranchAddress("Ndata.P.dc.2u1.wirenum", &Ndata_P_dc_2u1_wirenum, &b_Ndata_P_dc_2u1_wirenum);
   fChain->SetBranchAddress("P.dc.2u1.wirenum", P_dc_2u1_wirenum, &b_P_dc_2u1_wirenum);
   fChain->SetBranchAddress("Ndata.P.dc.2u2.dist", &Ndata_P_dc_2u2_dist, &b_Ndata_P_dc_2u2_dist);
   fChain->SetBranchAddress("P.dc.2u2.dist", P_dc_2u2_dist, &b_P_dc_2u2_dist);
   fChain->SetBranchAddress("Ndata.P.dc.2u2.rawtdc", &Ndata_P_dc_2u2_rawtdc, &b_Ndata_P_dc_2u2_rawtdc);
   fChain->SetBranchAddress("P.dc.2u2.rawtdc", P_dc_2u2_rawtdc, &b_P_dc_2u2_rawtdc);
   fChain->SetBranchAddress("Ndata.P.dc.2u2.time", &Ndata_P_dc_2u2_time, &b_Ndata_P_dc_2u2_time);
   fChain->SetBranchAddress("P.dc.2u2.time", P_dc_2u2_time, &b_P_dc_2u2_time);
   fChain->SetBranchAddress("Ndata.P.dc.2u2.wirenum", &Ndata_P_dc_2u2_wirenum, &b_Ndata_P_dc_2u2_wirenum);
   fChain->SetBranchAddress("P.dc.2u2.wirenum", P_dc_2u2_wirenum, &b_P_dc_2u2_wirenum);
   fChain->SetBranchAddress("Ndata.P.dc.2v1.dist", &Ndata_P_dc_2v1_dist, &b_Ndata_P_dc_2v1_dist);
   fChain->SetBranchAddress("P.dc.2v1.dist", P_dc_2v1_dist, &b_P_dc_2v1_dist);
   fChain->SetBranchAddress("Ndata.P.dc.2v1.rawtdc", &Ndata_P_dc_2v1_rawtdc, &b_Ndata_P_dc_2v1_rawtdc);
   fChain->SetBranchAddress("P.dc.2v1.rawtdc", P_dc_2v1_rawtdc, &b_P_dc_2v1_rawtdc);
   fChain->SetBranchAddress("Ndata.P.dc.2v1.time", &Ndata_P_dc_2v1_time, &b_Ndata_P_dc_2v1_time);
   fChain->SetBranchAddress("P.dc.2v1.time", P_dc_2v1_time, &b_P_dc_2v1_time);
   fChain->SetBranchAddress("Ndata.P.dc.2v1.wirenum", &Ndata_P_dc_2v1_wirenum, &b_Ndata_P_dc_2v1_wirenum);
   fChain->SetBranchAddress("P.dc.2v1.wirenum", P_dc_2v1_wirenum, &b_P_dc_2v1_wirenum);
   fChain->SetBranchAddress("Ndata.P.dc.2v2.dist", &Ndata_P_dc_2v2_dist, &b_Ndata_P_dc_2v2_dist);
   fChain->SetBranchAddress("P.dc.2v2.dist", P_dc_2v2_dist, &b_P_dc_2v2_dist);
   fChain->SetBranchAddress("Ndata.P.dc.2v2.rawtdc", &Ndata_P_dc_2v2_rawtdc, &b_Ndata_P_dc_2v2_rawtdc);
   fChain->SetBranchAddress("P.dc.2v2.rawtdc", P_dc_2v2_rawtdc, &b_P_dc_2v2_rawtdc);
   fChain->SetBranchAddress("Ndata.P.dc.2v2.time", &Ndata_P_dc_2v2_time, &b_Ndata_P_dc_2v2_time);
   fChain->SetBranchAddress("P.dc.2v2.time", P_dc_2v2_time, &b_P_dc_2v2_time);
   fChain->SetBranchAddress("Ndata.P.dc.2v2.wirenum", &Ndata_P_dc_2v2_wirenum, &b_Ndata_P_dc_2v2_wirenum);
   fChain->SetBranchAddress("P.dc.2v2.wirenum", P_dc_2v2_wirenum, &b_P_dc_2v2_wirenum);
   fChain->SetBranchAddress("Ndata.P.dc.2x1.dist", &Ndata_P_dc_2x1_dist, &b_Ndata_P_dc_2x1_dist);
   fChain->SetBranchAddress("P.dc.2x1.dist", P_dc_2x1_dist, &b_P_dc_2x1_dist);
   fChain->SetBranchAddress("Ndata.P.dc.2x1.rawtdc", &Ndata_P_dc_2x1_rawtdc, &b_Ndata_P_dc_2x1_rawtdc);
   fChain->SetBranchAddress("P.dc.2x1.rawtdc", P_dc_2x1_rawtdc, &b_P_dc_2x1_rawtdc);
   fChain->SetBranchAddress("Ndata.P.dc.2x1.time", &Ndata_P_dc_2x1_time, &b_Ndata_P_dc_2x1_time);
   fChain->SetBranchAddress("P.dc.2x1.time", P_dc_2x1_time, &b_P_dc_2x1_time);
   fChain->SetBranchAddress("Ndata.P.dc.2x1.wirenum", &Ndata_P_dc_2x1_wirenum, &b_Ndata_P_dc_2x1_wirenum);
   fChain->SetBranchAddress("P.dc.2x1.wirenum", P_dc_2x1_wirenum, &b_P_dc_2x1_wirenum);
   fChain->SetBranchAddress("Ndata.P.dc.2x2.dist", &Ndata_P_dc_2x2_dist, &b_Ndata_P_dc_2x2_dist);
   fChain->SetBranchAddress("P.dc.2x2.dist", P_dc_2x2_dist, &b_P_dc_2x2_dist);
   fChain->SetBranchAddress("Ndata.P.dc.2x2.rawtdc", &Ndata_P_dc_2x2_rawtdc, &b_Ndata_P_dc_2x2_rawtdc);
   fChain->SetBranchAddress("P.dc.2x2.rawtdc", P_dc_2x2_rawtdc, &b_P_dc_2x2_rawtdc);
   fChain->SetBranchAddress("Ndata.P.dc.2x2.time", &Ndata_P_dc_2x2_time, &b_Ndata_P_dc_2x2_time);
   fChain->SetBranchAddress("P.dc.2x2.time", P_dc_2x2_time, &b_P_dc_2x2_time);
   fChain->SetBranchAddress("Ndata.P.dc.2x2.wirenum", &Ndata_P_dc_2x2_wirenum, &b_Ndata_P_dc_2x2_wirenum);
   fChain->SetBranchAddress("P.dc.2x2.wirenum", P_dc_2x2_wirenum, &b_P_dc_2x2_wirenum);
   fChain->SetBranchAddress("Ndata.P.dc.residual", &Ndata_P_dc_residual, &b_Ndata_P_dc_residual);
   fChain->SetBranchAddress("P.dc.residual", P_dc_residual, &b_P_dc_residual);
   fChain->SetBranchAddress("Ndata.P.dc.x", &Ndata_P_dc_x, &b_Ndata_P_dc_x);
   fChain->SetBranchAddress("P.dc.x", P_dc_x, &b_P_dc_x);
   fChain->SetBranchAddress("Ndata.P.dc.xp", &Ndata_P_dc_xp, &b_Ndata_P_dc_xp);
   fChain->SetBranchAddress("P.dc.xp", P_dc_xp, &b_P_dc_xp);
   fChain->SetBranchAddress("Ndata.P.dc.y", &Ndata_P_dc_y, &b_Ndata_P_dc_y);
   fChain->SetBranchAddress("P.dc.y", P_dc_y, &b_P_dc_y);
   fChain->SetBranchAddress("Ndata.P.dc.yp", &Ndata_P_dc_yp, &b_Ndata_P_dc_yp);
   fChain->SetBranchAddress("P.dc.yp", P_dc_yp, &b_P_dc_yp);
   fChain->SetBranchAddress("Ndata.P.hgcer.adc", &Ndata_P_hgcer_adc, &b_Ndata_P_hgcer_adc);
   fChain->SetBranchAddress("P.hgcer.adc", P_hgcer_adc, &b_P_hgcer_adc);
   fChain->SetBranchAddress("Ndata.P.hgcer.adcCounter", &Ndata_P_hgcer_adcCounter, &b_Ndata_P_hgcer_adcCounter);
   fChain->SetBranchAddress("P.hgcer.adcCounter", P_hgcer_adcCounter, &b_P_hgcer_adcCounter);
   fChain->SetBranchAddress("Ndata.P.hgcer.adcPed", &Ndata_P_hgcer_adcPed, &b_Ndata_P_hgcer_adcPed);
   fChain->SetBranchAddress("P.hgcer.adcPed", P_hgcer_adcPed, &b_P_hgcer_adcPed);
   fChain->SetBranchAddress("Ndata.P.hgcer.adcPedRaw", &Ndata_P_hgcer_adcPedRaw, &b_Ndata_P_hgcer_adcPedRaw);
   fChain->SetBranchAddress("P.hgcer.adcPedRaw", P_hgcer_adcPedRaw, &b_P_hgcer_adcPedRaw);
   fChain->SetBranchAddress("Ndata.P.hgcer.adcPulseAmp", &Ndata_P_hgcer_adcPulseAmp, &b_Ndata_P_hgcer_adcPulseAmp);
   fChain->SetBranchAddress("P.hgcer.adcPulseAmp", P_hgcer_adcPulseAmp, &b_P_hgcer_adcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hgcer.adcPulseAmpRaw", &Ndata_P_hgcer_adcPulseAmpRaw, &b_Ndata_P_hgcer_adcPulseAmpRaw);
   fChain->SetBranchAddress("P.hgcer.adcPulseAmpRaw", P_hgcer_adcPulseAmpRaw, &b_P_hgcer_adcPulseAmpRaw);
   fChain->SetBranchAddress("Ndata.P.hgcer.adcPulseInt", &Ndata_P_hgcer_adcPulseInt, &b_Ndata_P_hgcer_adcPulseInt);
   fChain->SetBranchAddress("P.hgcer.adcPulseInt", P_hgcer_adcPulseInt, &b_P_hgcer_adcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hgcer.adcPulseIntRaw", &Ndata_P_hgcer_adcPulseIntRaw, &b_Ndata_P_hgcer_adcPulseIntRaw);
   fChain->SetBranchAddress("P.hgcer.adcPulseIntRaw", P_hgcer_adcPulseIntRaw, &b_P_hgcer_adcPulseIntRaw);
   fChain->SetBranchAddress("Ndata.P.hgcer.adcPulseTimeRaw", &Ndata_P_hgcer_adcPulseTimeRaw, &b_Ndata_P_hgcer_adcPulseTimeRaw);
   fChain->SetBranchAddress("P.hgcer.adcPulseTimeRaw", P_hgcer_adcPulseTimeRaw, &b_P_hgcer_adcPulseTimeRaw);
   fChain->SetBranchAddress("Ndata.P.hgcer.adc_hit", &Ndata_P_hgcer_adc_hit, &b_Ndata_P_hgcer_adc_hit);
   fChain->SetBranchAddress("P.hgcer.adc_hit", P_hgcer_adc_hit, &b_P_hgcer_adc_hit);
   fChain->SetBranchAddress("Ndata.P.hgcer.adc_p", &Ndata_P_hgcer_adc_p, &b_Ndata_P_hgcer_adc_p);
   fChain->SetBranchAddress("P.hgcer.adc_p", P_hgcer_adc_p, &b_P_hgcer_adc_p);
   fChain->SetBranchAddress("Ndata.P.hgcer.cerfiredcounter", &Ndata_P_hgcer_cerfiredcounter, &b_Ndata_P_hgcer_cerfiredcounter);
   fChain->SetBranchAddress("P.hgcer.cerfiredcounter", P_hgcer_cerfiredcounter, &b_P_hgcer_cerfiredcounter);
   fChain->SetBranchAddress("Ndata.P.hgcer.certrackcounter", &Ndata_P_hgcer_certrackcounter, &b_Ndata_P_hgcer_certrackcounter);
   fChain->SetBranchAddress("P.hgcer.certrackcounter", P_hgcer_certrackcounter, &b_P_hgcer_certrackcounter);
   fChain->SetBranchAddress("Ndata.P.hgcer.npe", &Ndata_P_hgcer_npe, &b_Ndata_P_hgcer_npe);
   fChain->SetBranchAddress("P.hgcer.npe", P_hgcer_npe, &b_P_hgcer_npe);
   fChain->SetBranchAddress("Ndata.P.hgcer.phototubes", &Ndata_P_hgcer_phototubes, &b_Ndata_P_hgcer_phototubes);
   fChain->SetBranchAddress("P.hgcer.phototubes", P_hgcer_phototubes, &b_P_hgcer_phototubes);
   fChain->SetBranchAddress("Ndata.P.hod.1x.GoodNegAdcPulseAmp", &Ndata_P_hod_1x_GoodNegAdcPulseAmp, &b_Ndata_P_hod_1x_GoodNegAdcPulseAmp);
   fChain->SetBranchAddress("P.hod.1x.GoodNegAdcPulseAmp", P_hod_1x_GoodNegAdcPulseAmp, &b_P_hod_1x_GoodNegAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hod.1x.GoodNegAdcPulseInt", &Ndata_P_hod_1x_GoodNegAdcPulseInt, &b_Ndata_P_hod_1x_GoodNegAdcPulseInt);
   fChain->SetBranchAddress("P.hod.1x.GoodNegAdcPulseInt", P_hod_1x_GoodNegAdcPulseInt, &b_P_hod_1x_GoodNegAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hod.1x.GoodNegAdcPulseTime", &Ndata_P_hod_1x_GoodNegAdcPulseTime, &b_Ndata_P_hod_1x_GoodNegAdcPulseTime);
   fChain->SetBranchAddress("P.hod.1x.GoodNegAdcPulseTime", P_hod_1x_GoodNegAdcPulseTime, &b_P_hod_1x_GoodNegAdcPulseTime);
   fChain->SetBranchAddress("Ndata.P.hod.1x.GoodNegTdcChan", &Ndata_P_hod_1x_GoodNegTdcChan, &b_Ndata_P_hod_1x_GoodNegTdcChan);
   fChain->SetBranchAddress("P.hod.1x.GoodNegTdcChan", P_hod_1x_GoodNegTdcChan, &b_P_hod_1x_GoodNegTdcChan);
   fChain->SetBranchAddress("Ndata.P.hod.1x.GoodNegTdcTimeCorr", &Ndata_P_hod_1x_GoodNegTdcTimeCorr, &b_Ndata_P_hod_1x_GoodNegTdcTimeCorr);
   fChain->SetBranchAddress("P.hod.1x.GoodNegTdcTimeCorr", P_hod_1x_GoodNegTdcTimeCorr, &b_P_hod_1x_GoodNegTdcTimeCorr);
   fChain->SetBranchAddress("Ndata.P.hod.1x.GoodNegTdcTimeTOFCorr", &Ndata_P_hod_1x_GoodNegTdcTimeTOFCorr, &b_Ndata_P_hod_1x_GoodNegTdcTimeTOFCorr);
   fChain->SetBranchAddress("P.hod.1x.GoodNegTdcTimeTOFCorr", P_hod_1x_GoodNegTdcTimeTOFCorr, &b_P_hod_1x_GoodNegTdcTimeTOFCorr);
   fChain->SetBranchAddress("Ndata.P.hod.1x.GoodPaddle", &Ndata_P_hod_1x_GoodPaddle, &b_Ndata_P_hod_1x_GoodPaddle);
   fChain->SetBranchAddress("P.hod.1x.GoodPaddle", P_hod_1x_GoodPaddle, &b_P_hod_1x_GoodPaddle);
   fChain->SetBranchAddress("Ndata.P.hod.1x.GoodPosAdcPulseAmp", &Ndata_P_hod_1x_GoodPosAdcPulseAmp, &b_Ndata_P_hod_1x_GoodPosAdcPulseAmp);
   fChain->SetBranchAddress("P.hod.1x.GoodPosAdcPulseAmp", P_hod_1x_GoodPosAdcPulseAmp, &b_P_hod_1x_GoodPosAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hod.1x.GoodPosAdcPulseInt", &Ndata_P_hod_1x_GoodPosAdcPulseInt, &b_Ndata_P_hod_1x_GoodPosAdcPulseInt);
   fChain->SetBranchAddress("P.hod.1x.GoodPosAdcPulseInt", P_hod_1x_GoodPosAdcPulseInt, &b_P_hod_1x_GoodPosAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hod.1x.GoodPosAdcPulseTime", &Ndata_P_hod_1x_GoodPosAdcPulseTime, &b_Ndata_P_hod_1x_GoodPosAdcPulseTime);
   fChain->SetBranchAddress("P.hod.1x.GoodPosAdcPulseTime", P_hod_1x_GoodPosAdcPulseTime, &b_P_hod_1x_GoodPosAdcPulseTime);
   fChain->SetBranchAddress("Ndata.P.hod.1x.GoodPosTdcChan", &Ndata_P_hod_1x_GoodPosTdcChan, &b_Ndata_P_hod_1x_GoodPosTdcChan);
   fChain->SetBranchAddress("P.hod.1x.GoodPosTdcChan", P_hod_1x_GoodPosTdcChan, &b_P_hod_1x_GoodPosTdcChan);
   fChain->SetBranchAddress("Ndata.P.hod.1x.GoodPosTdcTimeCorr", &Ndata_P_hod_1x_GoodPosTdcTimeCorr, &b_Ndata_P_hod_1x_GoodPosTdcTimeCorr);
   fChain->SetBranchAddress("P.hod.1x.GoodPosTdcTimeCorr", P_hod_1x_GoodPosTdcTimeCorr, &b_P_hod_1x_GoodPosTdcTimeCorr);
   fChain->SetBranchAddress("Ndata.P.hod.1x.GoodPosTdcTimeTOFCorr", &Ndata_P_hod_1x_GoodPosTdcTimeTOFCorr, &b_Ndata_P_hod_1x_GoodPosTdcTimeTOFCorr);
   fChain->SetBranchAddress("P.hod.1x.GoodPosTdcTimeTOFCorr", P_hod_1x_GoodPosTdcTimeTOFCorr, &b_P_hod_1x_GoodPosTdcTimeTOFCorr);
   fChain->SetBranchAddress("Ndata.P.hod.1x.negAdcCounter", &Ndata_P_hod_1x_negAdcCounter, &b_Ndata_P_hod_1x_negAdcCounter);
   fChain->SetBranchAddress("P.hod.1x.negAdcCounter", P_hod_1x_negAdcCounter, &b_P_hod_1x_negAdcCounter);
   fChain->SetBranchAddress("Ndata.P.hod.1x.negAdcPed", &Ndata_P_hod_1x_negAdcPed, &b_Ndata_P_hod_1x_negAdcPed);
   fChain->SetBranchAddress("P.hod.1x.negAdcPed", P_hod_1x_negAdcPed, &b_P_hod_1x_negAdcPed);
   fChain->SetBranchAddress("Ndata.P.hod.1x.negAdcPedRaw", &Ndata_P_hod_1x_negAdcPedRaw, &b_Ndata_P_hod_1x_negAdcPedRaw);
   fChain->SetBranchAddress("P.hod.1x.negAdcPedRaw", P_hod_1x_negAdcPedRaw, &b_P_hod_1x_negAdcPedRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1x.negAdcPulseAmp", &Ndata_P_hod_1x_negAdcPulseAmp, &b_Ndata_P_hod_1x_negAdcPulseAmp);
   fChain->SetBranchAddress("P.hod.1x.negAdcPulseAmp", P_hod_1x_negAdcPulseAmp, &b_P_hod_1x_negAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hod.1x.negAdcPulseAmpRaw", &Ndata_P_hod_1x_negAdcPulseAmpRaw, &b_Ndata_P_hod_1x_negAdcPulseAmpRaw);
   fChain->SetBranchAddress("P.hod.1x.negAdcPulseAmpRaw", P_hod_1x_negAdcPulseAmpRaw, &b_P_hod_1x_negAdcPulseAmpRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1x.negAdcPulseInt", &Ndata_P_hod_1x_negAdcPulseInt, &b_Ndata_P_hod_1x_negAdcPulseInt);
   fChain->SetBranchAddress("P.hod.1x.negAdcPulseInt", P_hod_1x_negAdcPulseInt, &b_P_hod_1x_negAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hod.1x.negAdcPulseIntRaw", &Ndata_P_hod_1x_negAdcPulseIntRaw, &b_Ndata_P_hod_1x_negAdcPulseIntRaw);
   fChain->SetBranchAddress("P.hod.1x.negAdcPulseIntRaw", P_hod_1x_negAdcPulseIntRaw, &b_P_hod_1x_negAdcPulseIntRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1x.negAdcPulseTimeRaw", &Ndata_P_hod_1x_negAdcPulseTimeRaw, &b_Ndata_P_hod_1x_negAdcPulseTimeRaw);
   fChain->SetBranchAddress("P.hod.1x.negAdcPulseTimeRaw", P_hod_1x_negAdcPulseTimeRaw, &b_P_hod_1x_negAdcPulseTimeRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1x.negTdcCounter", &Ndata_P_hod_1x_negTdcCounter, &b_Ndata_P_hod_1x_negTdcCounter);
   fChain->SetBranchAddress("P.hod.1x.negTdcCounter", P_hod_1x_negTdcCounter, &b_P_hod_1x_negTdcCounter);
   fChain->SetBranchAddress("Ndata.P.hod.1x.negTdcTime", &Ndata_P_hod_1x_negTdcTime, &b_Ndata_P_hod_1x_negTdcTime);
   fChain->SetBranchAddress("P.hod.1x.negTdcTime", P_hod_1x_negTdcTime, &b_P_hod_1x_negTdcTime);
   fChain->SetBranchAddress("Ndata.P.hod.1x.negTdcTimeRaw", &Ndata_P_hod_1x_negTdcTimeRaw, &b_Ndata_P_hod_1x_negTdcTimeRaw);
   fChain->SetBranchAddress("P.hod.1x.negTdcTimeRaw", P_hod_1x_negTdcTimeRaw, &b_P_hod_1x_negTdcTimeRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1x.posAdcCounter", &Ndata_P_hod_1x_posAdcCounter, &b_Ndata_P_hod_1x_posAdcCounter);
   fChain->SetBranchAddress("P.hod.1x.posAdcCounter", P_hod_1x_posAdcCounter, &b_P_hod_1x_posAdcCounter);
   fChain->SetBranchAddress("Ndata.P.hod.1x.posAdcPed", &Ndata_P_hod_1x_posAdcPed, &b_Ndata_P_hod_1x_posAdcPed);
   fChain->SetBranchAddress("P.hod.1x.posAdcPed", P_hod_1x_posAdcPed, &b_P_hod_1x_posAdcPed);
   fChain->SetBranchAddress("Ndata.P.hod.1x.posAdcPedRaw", &Ndata_P_hod_1x_posAdcPedRaw, &b_Ndata_P_hod_1x_posAdcPedRaw);
   fChain->SetBranchAddress("P.hod.1x.posAdcPedRaw", P_hod_1x_posAdcPedRaw, &b_P_hod_1x_posAdcPedRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1x.posAdcPulseAmp", &Ndata_P_hod_1x_posAdcPulseAmp, &b_Ndata_P_hod_1x_posAdcPulseAmp);
   fChain->SetBranchAddress("P.hod.1x.posAdcPulseAmp", P_hod_1x_posAdcPulseAmp, &b_P_hod_1x_posAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hod.1x.posAdcPulseAmpRaw", &Ndata_P_hod_1x_posAdcPulseAmpRaw, &b_Ndata_P_hod_1x_posAdcPulseAmpRaw);
   fChain->SetBranchAddress("P.hod.1x.posAdcPulseAmpRaw", P_hod_1x_posAdcPulseAmpRaw, &b_P_hod_1x_posAdcPulseAmpRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1x.posAdcPulseInt", &Ndata_P_hod_1x_posAdcPulseInt, &b_Ndata_P_hod_1x_posAdcPulseInt);
   fChain->SetBranchAddress("P.hod.1x.posAdcPulseInt", P_hod_1x_posAdcPulseInt, &b_P_hod_1x_posAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hod.1x.posAdcPulseIntRaw", &Ndata_P_hod_1x_posAdcPulseIntRaw, &b_Ndata_P_hod_1x_posAdcPulseIntRaw);
   fChain->SetBranchAddress("P.hod.1x.posAdcPulseIntRaw", P_hod_1x_posAdcPulseIntRaw, &b_P_hod_1x_posAdcPulseIntRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1x.posAdcPulseTimeRaw", &Ndata_P_hod_1x_posAdcPulseTimeRaw, &b_Ndata_P_hod_1x_posAdcPulseTimeRaw);
   fChain->SetBranchAddress("P.hod.1x.posAdcPulseTimeRaw", P_hod_1x_posAdcPulseTimeRaw, &b_P_hod_1x_posAdcPulseTimeRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1x.posTdcCounter", &Ndata_P_hod_1x_posTdcCounter, &b_Ndata_P_hod_1x_posTdcCounter);
   fChain->SetBranchAddress("P.hod.1x.posTdcCounter", P_hod_1x_posTdcCounter, &b_P_hod_1x_posTdcCounter);
   fChain->SetBranchAddress("Ndata.P.hod.1x.posTdcTime", &Ndata_P_hod_1x_posTdcTime, &b_Ndata_P_hod_1x_posTdcTime);
   fChain->SetBranchAddress("P.hod.1x.posTdcTime", P_hod_1x_posTdcTime, &b_P_hod_1x_posTdcTime);
   fChain->SetBranchAddress("Ndata.P.hod.1x.posTdcTimeRaw", &Ndata_P_hod_1x_posTdcTimeRaw, &b_Ndata_P_hod_1x_posTdcTimeRaw);
   fChain->SetBranchAddress("P.hod.1x.posTdcTimeRaw", P_hod_1x_posTdcTimeRaw, &b_P_hod_1x_posTdcTimeRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1y.GoodNegAdcPulseAmp", &Ndata_P_hod_1y_GoodNegAdcPulseAmp, &b_Ndata_P_hod_1y_GoodNegAdcPulseAmp);
   fChain->SetBranchAddress("P.hod.1y.GoodNegAdcPulseAmp", P_hod_1y_GoodNegAdcPulseAmp, &b_P_hod_1y_GoodNegAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hod.1y.GoodNegAdcPulseInt", &Ndata_P_hod_1y_GoodNegAdcPulseInt, &b_Ndata_P_hod_1y_GoodNegAdcPulseInt);
   fChain->SetBranchAddress("P.hod.1y.GoodNegAdcPulseInt", P_hod_1y_GoodNegAdcPulseInt, &b_P_hod_1y_GoodNegAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hod.1y.GoodNegAdcPulseTime", &Ndata_P_hod_1y_GoodNegAdcPulseTime, &b_Ndata_P_hod_1y_GoodNegAdcPulseTime);
   fChain->SetBranchAddress("P.hod.1y.GoodNegAdcPulseTime", P_hod_1y_GoodNegAdcPulseTime, &b_P_hod_1y_GoodNegAdcPulseTime);
   fChain->SetBranchAddress("Ndata.P.hod.1y.GoodNegTdcChan", &Ndata_P_hod_1y_GoodNegTdcChan, &b_Ndata_P_hod_1y_GoodNegTdcChan);
   fChain->SetBranchAddress("P.hod.1y.GoodNegTdcChan", P_hod_1y_GoodNegTdcChan, &b_P_hod_1y_GoodNegTdcChan);
   fChain->SetBranchAddress("Ndata.P.hod.1y.GoodNegTdcTimeCorr", &Ndata_P_hod_1y_GoodNegTdcTimeCorr, &b_Ndata_P_hod_1y_GoodNegTdcTimeCorr);
   fChain->SetBranchAddress("P.hod.1y.GoodNegTdcTimeCorr", P_hod_1y_GoodNegTdcTimeCorr, &b_P_hod_1y_GoodNegTdcTimeCorr);
   fChain->SetBranchAddress("Ndata.P.hod.1y.GoodNegTdcTimeTOFCorr", &Ndata_P_hod_1y_GoodNegTdcTimeTOFCorr, &b_Ndata_P_hod_1y_GoodNegTdcTimeTOFCorr);
   fChain->SetBranchAddress("P.hod.1y.GoodNegTdcTimeTOFCorr", P_hod_1y_GoodNegTdcTimeTOFCorr, &b_P_hod_1y_GoodNegTdcTimeTOFCorr);
   fChain->SetBranchAddress("Ndata.P.hod.1y.GoodPaddle", &Ndata_P_hod_1y_GoodPaddle, &b_Ndata_P_hod_1y_GoodPaddle);
   fChain->SetBranchAddress("P.hod.1y.GoodPaddle", P_hod_1y_GoodPaddle, &b_P_hod_1y_GoodPaddle);
   fChain->SetBranchAddress("Ndata.P.hod.1y.GoodPosAdcPulseAmp", &Ndata_P_hod_1y_GoodPosAdcPulseAmp, &b_Ndata_P_hod_1y_GoodPosAdcPulseAmp);
   fChain->SetBranchAddress("P.hod.1y.GoodPosAdcPulseAmp", P_hod_1y_GoodPosAdcPulseAmp, &b_P_hod_1y_GoodPosAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hod.1y.GoodPosAdcPulseInt", &Ndata_P_hod_1y_GoodPosAdcPulseInt, &b_Ndata_P_hod_1y_GoodPosAdcPulseInt);
   fChain->SetBranchAddress("P.hod.1y.GoodPosAdcPulseInt", P_hod_1y_GoodPosAdcPulseInt, &b_P_hod_1y_GoodPosAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hod.1y.GoodPosAdcPulseTime", &Ndata_P_hod_1y_GoodPosAdcPulseTime, &b_Ndata_P_hod_1y_GoodPosAdcPulseTime);
   fChain->SetBranchAddress("P.hod.1y.GoodPosAdcPulseTime", P_hod_1y_GoodPosAdcPulseTime, &b_P_hod_1y_GoodPosAdcPulseTime);
   fChain->SetBranchAddress("Ndata.P.hod.1y.GoodPosTdcChan", &Ndata_P_hod_1y_GoodPosTdcChan, &b_Ndata_P_hod_1y_GoodPosTdcChan);
   fChain->SetBranchAddress("P.hod.1y.GoodPosTdcChan", P_hod_1y_GoodPosTdcChan, &b_P_hod_1y_GoodPosTdcChan);
   fChain->SetBranchAddress("Ndata.P.hod.1y.GoodPosTdcTimeCorr", &Ndata_P_hod_1y_GoodPosTdcTimeCorr, &b_Ndata_P_hod_1y_GoodPosTdcTimeCorr);
   fChain->SetBranchAddress("P.hod.1y.GoodPosTdcTimeCorr", P_hod_1y_GoodPosTdcTimeCorr, &b_P_hod_1y_GoodPosTdcTimeCorr);
   fChain->SetBranchAddress("Ndata.P.hod.1y.GoodPosTdcTimeTOFCorr", &Ndata_P_hod_1y_GoodPosTdcTimeTOFCorr, &b_Ndata_P_hod_1y_GoodPosTdcTimeTOFCorr);
   fChain->SetBranchAddress("P.hod.1y.GoodPosTdcTimeTOFCorr", P_hod_1y_GoodPosTdcTimeTOFCorr, &b_P_hod_1y_GoodPosTdcTimeTOFCorr);
   fChain->SetBranchAddress("Ndata.P.hod.1y.negAdcCounter", &Ndata_P_hod_1y_negAdcCounter, &b_Ndata_P_hod_1y_negAdcCounter);
   fChain->SetBranchAddress("P.hod.1y.negAdcCounter", P_hod_1y_negAdcCounter, &b_P_hod_1y_negAdcCounter);
   fChain->SetBranchAddress("Ndata.P.hod.1y.negAdcPed", &Ndata_P_hod_1y_negAdcPed, &b_Ndata_P_hod_1y_negAdcPed);
   fChain->SetBranchAddress("P.hod.1y.negAdcPed", P_hod_1y_negAdcPed, &b_P_hod_1y_negAdcPed);
   fChain->SetBranchAddress("Ndata.P.hod.1y.negAdcPedRaw", &Ndata_P_hod_1y_negAdcPedRaw, &b_Ndata_P_hod_1y_negAdcPedRaw);
   fChain->SetBranchAddress("P.hod.1y.negAdcPedRaw", P_hod_1y_negAdcPedRaw, &b_P_hod_1y_negAdcPedRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1y.negAdcPulseAmp", &Ndata_P_hod_1y_negAdcPulseAmp, &b_Ndata_P_hod_1y_negAdcPulseAmp);
   fChain->SetBranchAddress("P.hod.1y.negAdcPulseAmp", P_hod_1y_negAdcPulseAmp, &b_P_hod_1y_negAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hod.1y.negAdcPulseAmpRaw", &Ndata_P_hod_1y_negAdcPulseAmpRaw, &b_Ndata_P_hod_1y_negAdcPulseAmpRaw);
   fChain->SetBranchAddress("P.hod.1y.negAdcPulseAmpRaw", P_hod_1y_negAdcPulseAmpRaw, &b_P_hod_1y_negAdcPulseAmpRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1y.negAdcPulseInt", &Ndata_P_hod_1y_negAdcPulseInt, &b_Ndata_P_hod_1y_negAdcPulseInt);
   fChain->SetBranchAddress("P.hod.1y.negAdcPulseInt", P_hod_1y_negAdcPulseInt, &b_P_hod_1y_negAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hod.1y.negAdcPulseIntRaw", &Ndata_P_hod_1y_negAdcPulseIntRaw, &b_Ndata_P_hod_1y_negAdcPulseIntRaw);
   fChain->SetBranchAddress("P.hod.1y.negAdcPulseIntRaw", P_hod_1y_negAdcPulseIntRaw, &b_P_hod_1y_negAdcPulseIntRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1y.negAdcPulseTimeRaw", &Ndata_P_hod_1y_negAdcPulseTimeRaw, &b_Ndata_P_hod_1y_negAdcPulseTimeRaw);
   fChain->SetBranchAddress("P.hod.1y.negAdcPulseTimeRaw", P_hod_1y_negAdcPulseTimeRaw, &b_P_hod_1y_negAdcPulseTimeRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1y.negTdcCounter", &Ndata_P_hod_1y_negTdcCounter, &b_Ndata_P_hod_1y_negTdcCounter);
   fChain->SetBranchAddress("P.hod.1y.negTdcCounter", P_hod_1y_negTdcCounter, &b_P_hod_1y_negTdcCounter);
   fChain->SetBranchAddress("Ndata.P.hod.1y.negTdcTime", &Ndata_P_hod_1y_negTdcTime, &b_Ndata_P_hod_1y_negTdcTime);
   fChain->SetBranchAddress("P.hod.1y.negTdcTime", P_hod_1y_negTdcTime, &b_P_hod_1y_negTdcTime);
   fChain->SetBranchAddress("Ndata.P.hod.1y.negTdcTimeRaw", &Ndata_P_hod_1y_negTdcTimeRaw, &b_Ndata_P_hod_1y_negTdcTimeRaw);
   fChain->SetBranchAddress("P.hod.1y.negTdcTimeRaw", P_hod_1y_negTdcTimeRaw, &b_P_hod_1y_negTdcTimeRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1y.posAdcCounter", &Ndata_P_hod_1y_posAdcCounter, &b_Ndata_P_hod_1y_posAdcCounter);
   fChain->SetBranchAddress("P.hod.1y.posAdcCounter", P_hod_1y_posAdcCounter, &b_P_hod_1y_posAdcCounter);
   fChain->SetBranchAddress("Ndata.P.hod.1y.posAdcPed", &Ndata_P_hod_1y_posAdcPed, &b_Ndata_P_hod_1y_posAdcPed);
   fChain->SetBranchAddress("P.hod.1y.posAdcPed", P_hod_1y_posAdcPed, &b_P_hod_1y_posAdcPed);
   fChain->SetBranchAddress("Ndata.P.hod.1y.posAdcPedRaw", &Ndata_P_hod_1y_posAdcPedRaw, &b_Ndata_P_hod_1y_posAdcPedRaw);
   fChain->SetBranchAddress("P.hod.1y.posAdcPedRaw", P_hod_1y_posAdcPedRaw, &b_P_hod_1y_posAdcPedRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1y.posAdcPulseAmp", &Ndata_P_hod_1y_posAdcPulseAmp, &b_Ndata_P_hod_1y_posAdcPulseAmp);
   fChain->SetBranchAddress("P.hod.1y.posAdcPulseAmp", P_hod_1y_posAdcPulseAmp, &b_P_hod_1y_posAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hod.1y.posAdcPulseAmpRaw", &Ndata_P_hod_1y_posAdcPulseAmpRaw, &b_Ndata_P_hod_1y_posAdcPulseAmpRaw);
   fChain->SetBranchAddress("P.hod.1y.posAdcPulseAmpRaw", P_hod_1y_posAdcPulseAmpRaw, &b_P_hod_1y_posAdcPulseAmpRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1y.posAdcPulseInt", &Ndata_P_hod_1y_posAdcPulseInt, &b_Ndata_P_hod_1y_posAdcPulseInt);
   fChain->SetBranchAddress("P.hod.1y.posAdcPulseInt", P_hod_1y_posAdcPulseInt, &b_P_hod_1y_posAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hod.1y.posAdcPulseIntRaw", &Ndata_P_hod_1y_posAdcPulseIntRaw, &b_Ndata_P_hod_1y_posAdcPulseIntRaw);
   fChain->SetBranchAddress("P.hod.1y.posAdcPulseIntRaw", P_hod_1y_posAdcPulseIntRaw, &b_P_hod_1y_posAdcPulseIntRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1y.posAdcPulseTimeRaw", &Ndata_P_hod_1y_posAdcPulseTimeRaw, &b_Ndata_P_hod_1y_posAdcPulseTimeRaw);
   fChain->SetBranchAddress("P.hod.1y.posAdcPulseTimeRaw", P_hod_1y_posAdcPulseTimeRaw, &b_P_hod_1y_posAdcPulseTimeRaw);
   fChain->SetBranchAddress("Ndata.P.hod.1y.posTdcCounter", &Ndata_P_hod_1y_posTdcCounter, &b_Ndata_P_hod_1y_posTdcCounter);
   fChain->SetBranchAddress("P.hod.1y.posTdcCounter", P_hod_1y_posTdcCounter, &b_P_hod_1y_posTdcCounter);
   fChain->SetBranchAddress("Ndata.P.hod.1y.posTdcTime", &Ndata_P_hod_1y_posTdcTime, &b_Ndata_P_hod_1y_posTdcTime);
   fChain->SetBranchAddress("P.hod.1y.posTdcTime", P_hod_1y_posTdcTime, &b_P_hod_1y_posTdcTime);
   fChain->SetBranchAddress("Ndata.P.hod.1y.posTdcTimeRaw", &Ndata_P_hod_1y_posTdcTimeRaw, &b_Ndata_P_hod_1y_posTdcTimeRaw);
   fChain->SetBranchAddress("P.hod.1y.posTdcTimeRaw", P_hod_1y_posTdcTimeRaw, &b_P_hod_1y_posTdcTimeRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2x.GoodNegAdcPulseAmp", &Ndata_P_hod_2x_GoodNegAdcPulseAmp, &b_Ndata_P_hod_2x_GoodNegAdcPulseAmp);
   fChain->SetBranchAddress("P.hod.2x.GoodNegAdcPulseAmp", P_hod_2x_GoodNegAdcPulseAmp, &b_P_hod_2x_GoodNegAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hod.2x.GoodNegAdcPulseInt", &Ndata_P_hod_2x_GoodNegAdcPulseInt, &b_Ndata_P_hod_2x_GoodNegAdcPulseInt);
   fChain->SetBranchAddress("P.hod.2x.GoodNegAdcPulseInt", P_hod_2x_GoodNegAdcPulseInt, &b_P_hod_2x_GoodNegAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hod.2x.GoodNegAdcPulseTime", &Ndata_P_hod_2x_GoodNegAdcPulseTime, &b_Ndata_P_hod_2x_GoodNegAdcPulseTime);
   fChain->SetBranchAddress("P.hod.2x.GoodNegAdcPulseTime", P_hod_2x_GoodNegAdcPulseTime, &b_P_hod_2x_GoodNegAdcPulseTime);
   fChain->SetBranchAddress("Ndata.P.hod.2x.GoodNegTdcChan", &Ndata_P_hod_2x_GoodNegTdcChan, &b_Ndata_P_hod_2x_GoodNegTdcChan);
   fChain->SetBranchAddress("P.hod.2x.GoodNegTdcChan", P_hod_2x_GoodNegTdcChan, &b_P_hod_2x_GoodNegTdcChan);
   fChain->SetBranchAddress("Ndata.P.hod.2x.GoodNegTdcTimeCorr", &Ndata_P_hod_2x_GoodNegTdcTimeCorr, &b_Ndata_P_hod_2x_GoodNegTdcTimeCorr);
   fChain->SetBranchAddress("P.hod.2x.GoodNegTdcTimeCorr", P_hod_2x_GoodNegTdcTimeCorr, &b_P_hod_2x_GoodNegTdcTimeCorr);
   fChain->SetBranchAddress("Ndata.P.hod.2x.GoodNegTdcTimeTOFCorr", &Ndata_P_hod_2x_GoodNegTdcTimeTOFCorr, &b_Ndata_P_hod_2x_GoodNegTdcTimeTOFCorr);
   fChain->SetBranchAddress("P.hod.2x.GoodNegTdcTimeTOFCorr", P_hod_2x_GoodNegTdcTimeTOFCorr, &b_P_hod_2x_GoodNegTdcTimeTOFCorr);
   fChain->SetBranchAddress("Ndata.P.hod.2x.GoodPaddle", &Ndata_P_hod_2x_GoodPaddle, &b_Ndata_P_hod_2x_GoodPaddle);
   fChain->SetBranchAddress("P.hod.2x.GoodPaddle", P_hod_2x_GoodPaddle, &b_P_hod_2x_GoodPaddle);
   fChain->SetBranchAddress("Ndata.P.hod.2x.GoodPosAdcPulseAmp", &Ndata_P_hod_2x_GoodPosAdcPulseAmp, &b_Ndata_P_hod_2x_GoodPosAdcPulseAmp);
   fChain->SetBranchAddress("P.hod.2x.GoodPosAdcPulseAmp", P_hod_2x_GoodPosAdcPulseAmp, &b_P_hod_2x_GoodPosAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hod.2x.GoodPosAdcPulseInt", &Ndata_P_hod_2x_GoodPosAdcPulseInt, &b_Ndata_P_hod_2x_GoodPosAdcPulseInt);
   fChain->SetBranchAddress("P.hod.2x.GoodPosAdcPulseInt", P_hod_2x_GoodPosAdcPulseInt, &b_P_hod_2x_GoodPosAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hod.2x.GoodPosAdcPulseTime", &Ndata_P_hod_2x_GoodPosAdcPulseTime, &b_Ndata_P_hod_2x_GoodPosAdcPulseTime);
   fChain->SetBranchAddress("P.hod.2x.GoodPosAdcPulseTime", P_hod_2x_GoodPosAdcPulseTime, &b_P_hod_2x_GoodPosAdcPulseTime);
   fChain->SetBranchAddress("Ndata.P.hod.2x.GoodPosTdcChan", &Ndata_P_hod_2x_GoodPosTdcChan, &b_Ndata_P_hod_2x_GoodPosTdcChan);
   fChain->SetBranchAddress("P.hod.2x.GoodPosTdcChan", P_hod_2x_GoodPosTdcChan, &b_P_hod_2x_GoodPosTdcChan);
   fChain->SetBranchAddress("Ndata.P.hod.2x.GoodPosTdcTimeCorr", &Ndata_P_hod_2x_GoodPosTdcTimeCorr, &b_Ndata_P_hod_2x_GoodPosTdcTimeCorr);
   fChain->SetBranchAddress("P.hod.2x.GoodPosTdcTimeCorr", P_hod_2x_GoodPosTdcTimeCorr, &b_P_hod_2x_GoodPosTdcTimeCorr);
   fChain->SetBranchAddress("Ndata.P.hod.2x.GoodPosTdcTimeTOFCorr", &Ndata_P_hod_2x_GoodPosTdcTimeTOFCorr, &b_Ndata_P_hod_2x_GoodPosTdcTimeTOFCorr);
   fChain->SetBranchAddress("P.hod.2x.GoodPosTdcTimeTOFCorr", P_hod_2x_GoodPosTdcTimeTOFCorr, &b_P_hod_2x_GoodPosTdcTimeTOFCorr);
   fChain->SetBranchAddress("Ndata.P.hod.2x.negAdcCounter", &Ndata_P_hod_2x_negAdcCounter, &b_Ndata_P_hod_2x_negAdcCounter);
   fChain->SetBranchAddress("P.hod.2x.negAdcCounter", P_hod_2x_negAdcCounter, &b_P_hod_2x_negAdcCounter);
   fChain->SetBranchAddress("Ndata.P.hod.2x.negAdcPed", &Ndata_P_hod_2x_negAdcPed, &b_Ndata_P_hod_2x_negAdcPed);
   fChain->SetBranchAddress("P.hod.2x.negAdcPed", P_hod_2x_negAdcPed, &b_P_hod_2x_negAdcPed);
   fChain->SetBranchAddress("Ndata.P.hod.2x.negAdcPedRaw", &Ndata_P_hod_2x_negAdcPedRaw, &b_Ndata_P_hod_2x_negAdcPedRaw);
   fChain->SetBranchAddress("P.hod.2x.negAdcPedRaw", P_hod_2x_negAdcPedRaw, &b_P_hod_2x_negAdcPedRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2x.negAdcPulseAmp", &Ndata_P_hod_2x_negAdcPulseAmp, &b_Ndata_P_hod_2x_negAdcPulseAmp);
   fChain->SetBranchAddress("P.hod.2x.negAdcPulseAmp", P_hod_2x_negAdcPulseAmp, &b_P_hod_2x_negAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hod.2x.negAdcPulseAmpRaw", &Ndata_P_hod_2x_negAdcPulseAmpRaw, &b_Ndata_P_hod_2x_negAdcPulseAmpRaw);
   fChain->SetBranchAddress("P.hod.2x.negAdcPulseAmpRaw", P_hod_2x_negAdcPulseAmpRaw, &b_P_hod_2x_negAdcPulseAmpRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2x.negAdcPulseInt", &Ndata_P_hod_2x_negAdcPulseInt, &b_Ndata_P_hod_2x_negAdcPulseInt);
   fChain->SetBranchAddress("P.hod.2x.negAdcPulseInt", P_hod_2x_negAdcPulseInt, &b_P_hod_2x_negAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hod.2x.negAdcPulseIntRaw", &Ndata_P_hod_2x_negAdcPulseIntRaw, &b_Ndata_P_hod_2x_negAdcPulseIntRaw);
   fChain->SetBranchAddress("P.hod.2x.negAdcPulseIntRaw", P_hod_2x_negAdcPulseIntRaw, &b_P_hod_2x_negAdcPulseIntRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2x.negAdcPulseTimeRaw", &Ndata_P_hod_2x_negAdcPulseTimeRaw, &b_Ndata_P_hod_2x_negAdcPulseTimeRaw);
   fChain->SetBranchAddress("P.hod.2x.negAdcPulseTimeRaw", P_hod_2x_negAdcPulseTimeRaw, &b_P_hod_2x_negAdcPulseTimeRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2x.negTdcCounter", &Ndata_P_hod_2x_negTdcCounter, &b_Ndata_P_hod_2x_negTdcCounter);
   fChain->SetBranchAddress("P.hod.2x.negTdcCounter", P_hod_2x_negTdcCounter, &b_P_hod_2x_negTdcCounter);
   fChain->SetBranchAddress("Ndata.P.hod.2x.negTdcTime", &Ndata_P_hod_2x_negTdcTime, &b_Ndata_P_hod_2x_negTdcTime);
   fChain->SetBranchAddress("P.hod.2x.negTdcTime", P_hod_2x_negTdcTime, &b_P_hod_2x_negTdcTime);
   fChain->SetBranchAddress("Ndata.P.hod.2x.negTdcTimeRaw", &Ndata_P_hod_2x_negTdcTimeRaw, &b_Ndata_P_hod_2x_negTdcTimeRaw);
   fChain->SetBranchAddress("P.hod.2x.negTdcTimeRaw", P_hod_2x_negTdcTimeRaw, &b_P_hod_2x_negTdcTimeRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2x.posAdcCounter", &Ndata_P_hod_2x_posAdcCounter, &b_Ndata_P_hod_2x_posAdcCounter);
   fChain->SetBranchAddress("P.hod.2x.posAdcCounter", P_hod_2x_posAdcCounter, &b_P_hod_2x_posAdcCounter);
   fChain->SetBranchAddress("Ndata.P.hod.2x.posAdcPed", &Ndata_P_hod_2x_posAdcPed, &b_Ndata_P_hod_2x_posAdcPed);
   fChain->SetBranchAddress("P.hod.2x.posAdcPed", P_hod_2x_posAdcPed, &b_P_hod_2x_posAdcPed);
   fChain->SetBranchAddress("Ndata.P.hod.2x.posAdcPedRaw", &Ndata_P_hod_2x_posAdcPedRaw, &b_Ndata_P_hod_2x_posAdcPedRaw);
   fChain->SetBranchAddress("P.hod.2x.posAdcPedRaw", P_hod_2x_posAdcPedRaw, &b_P_hod_2x_posAdcPedRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2x.posAdcPulseAmp", &Ndata_P_hod_2x_posAdcPulseAmp, &b_Ndata_P_hod_2x_posAdcPulseAmp);
   fChain->SetBranchAddress("P.hod.2x.posAdcPulseAmp", P_hod_2x_posAdcPulseAmp, &b_P_hod_2x_posAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hod.2x.posAdcPulseAmpRaw", &Ndata_P_hod_2x_posAdcPulseAmpRaw, &b_Ndata_P_hod_2x_posAdcPulseAmpRaw);
   fChain->SetBranchAddress("P.hod.2x.posAdcPulseAmpRaw", P_hod_2x_posAdcPulseAmpRaw, &b_P_hod_2x_posAdcPulseAmpRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2x.posAdcPulseInt", &Ndata_P_hod_2x_posAdcPulseInt, &b_Ndata_P_hod_2x_posAdcPulseInt);
   fChain->SetBranchAddress("P.hod.2x.posAdcPulseInt", P_hod_2x_posAdcPulseInt, &b_P_hod_2x_posAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hod.2x.posAdcPulseIntRaw", &Ndata_P_hod_2x_posAdcPulseIntRaw, &b_Ndata_P_hod_2x_posAdcPulseIntRaw);
   fChain->SetBranchAddress("P.hod.2x.posAdcPulseIntRaw", P_hod_2x_posAdcPulseIntRaw, &b_P_hod_2x_posAdcPulseIntRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2x.posAdcPulseTimeRaw", &Ndata_P_hod_2x_posAdcPulseTimeRaw, &b_Ndata_P_hod_2x_posAdcPulseTimeRaw);
   fChain->SetBranchAddress("P.hod.2x.posAdcPulseTimeRaw", P_hod_2x_posAdcPulseTimeRaw, &b_P_hod_2x_posAdcPulseTimeRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2x.posTdcCounter", &Ndata_P_hod_2x_posTdcCounter, &b_Ndata_P_hod_2x_posTdcCounter);
   fChain->SetBranchAddress("P.hod.2x.posTdcCounter", P_hod_2x_posTdcCounter, &b_P_hod_2x_posTdcCounter);
   fChain->SetBranchAddress("Ndata.P.hod.2x.posTdcTime", &Ndata_P_hod_2x_posTdcTime, &b_Ndata_P_hod_2x_posTdcTime);
   fChain->SetBranchAddress("P.hod.2x.posTdcTime", P_hod_2x_posTdcTime, &b_P_hod_2x_posTdcTime);
   fChain->SetBranchAddress("Ndata.P.hod.2x.posTdcTimeRaw", &Ndata_P_hod_2x_posTdcTimeRaw, &b_Ndata_P_hod_2x_posTdcTimeRaw);
   fChain->SetBranchAddress("P.hod.2x.posTdcTimeRaw", P_hod_2x_posTdcTimeRaw, &b_P_hod_2x_posTdcTimeRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2y.GoodNegAdcPulseAmp", &Ndata_P_hod_2y_GoodNegAdcPulseAmp, &b_Ndata_P_hod_2y_GoodNegAdcPulseAmp);
   fChain->SetBranchAddress("P.hod.2y.GoodNegAdcPulseAmp", P_hod_2y_GoodNegAdcPulseAmp, &b_P_hod_2y_GoodNegAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hod.2y.GoodNegAdcPulseInt", &Ndata_P_hod_2y_GoodNegAdcPulseInt, &b_Ndata_P_hod_2y_GoodNegAdcPulseInt);
   fChain->SetBranchAddress("P.hod.2y.GoodNegAdcPulseInt", P_hod_2y_GoodNegAdcPulseInt, &b_P_hod_2y_GoodNegAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hod.2y.GoodNegAdcPulseTime", &Ndata_P_hod_2y_GoodNegAdcPulseTime, &b_Ndata_P_hod_2y_GoodNegAdcPulseTime);
   fChain->SetBranchAddress("P.hod.2y.GoodNegAdcPulseTime", P_hod_2y_GoodNegAdcPulseTime, &b_P_hod_2y_GoodNegAdcPulseTime);
   fChain->SetBranchAddress("Ndata.P.hod.2y.GoodNegTdcChan", &Ndata_P_hod_2y_GoodNegTdcChan, &b_Ndata_P_hod_2y_GoodNegTdcChan);
   fChain->SetBranchAddress("P.hod.2y.GoodNegTdcChan", P_hod_2y_GoodNegTdcChan, &b_P_hod_2y_GoodNegTdcChan);
   fChain->SetBranchAddress("Ndata.P.hod.2y.GoodNegTdcTimeCorr", &Ndata_P_hod_2y_GoodNegTdcTimeCorr, &b_Ndata_P_hod_2y_GoodNegTdcTimeCorr);
   fChain->SetBranchAddress("P.hod.2y.GoodNegTdcTimeCorr", P_hod_2y_GoodNegTdcTimeCorr, &b_P_hod_2y_GoodNegTdcTimeCorr);
   fChain->SetBranchAddress("Ndata.P.hod.2y.GoodNegTdcTimeTOFCorr", &Ndata_P_hod_2y_GoodNegTdcTimeTOFCorr, &b_Ndata_P_hod_2y_GoodNegTdcTimeTOFCorr);
   fChain->SetBranchAddress("P.hod.2y.GoodNegTdcTimeTOFCorr", P_hod_2y_GoodNegTdcTimeTOFCorr, &b_P_hod_2y_GoodNegTdcTimeTOFCorr);
   fChain->SetBranchAddress("Ndata.P.hod.2y.GoodPaddle", &Ndata_P_hod_2y_GoodPaddle, &b_Ndata_P_hod_2y_GoodPaddle);
   fChain->SetBranchAddress("P.hod.2y.GoodPaddle", P_hod_2y_GoodPaddle, &b_P_hod_2y_GoodPaddle);
   fChain->SetBranchAddress("Ndata.P.hod.2y.GoodPosAdcPulseAmp", &Ndata_P_hod_2y_GoodPosAdcPulseAmp, &b_Ndata_P_hod_2y_GoodPosAdcPulseAmp);
   fChain->SetBranchAddress("P.hod.2y.GoodPosAdcPulseAmp", P_hod_2y_GoodPosAdcPulseAmp, &b_P_hod_2y_GoodPosAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hod.2y.GoodPosAdcPulseInt", &Ndata_P_hod_2y_GoodPosAdcPulseInt, &b_Ndata_P_hod_2y_GoodPosAdcPulseInt);
   fChain->SetBranchAddress("P.hod.2y.GoodPosAdcPulseInt", P_hod_2y_GoodPosAdcPulseInt, &b_P_hod_2y_GoodPosAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hod.2y.GoodPosAdcPulseTime", &Ndata_P_hod_2y_GoodPosAdcPulseTime, &b_Ndata_P_hod_2y_GoodPosAdcPulseTime);
   fChain->SetBranchAddress("P.hod.2y.GoodPosAdcPulseTime", P_hod_2y_GoodPosAdcPulseTime, &b_P_hod_2y_GoodPosAdcPulseTime);
   fChain->SetBranchAddress("Ndata.P.hod.2y.GoodPosTdcChan", &Ndata_P_hod_2y_GoodPosTdcChan, &b_Ndata_P_hod_2y_GoodPosTdcChan);
   fChain->SetBranchAddress("P.hod.2y.GoodPosTdcChan", P_hod_2y_GoodPosTdcChan, &b_P_hod_2y_GoodPosTdcChan);
   fChain->SetBranchAddress("Ndata.P.hod.2y.GoodPosTdcTimeCorr", &Ndata_P_hod_2y_GoodPosTdcTimeCorr, &b_Ndata_P_hod_2y_GoodPosTdcTimeCorr);
   fChain->SetBranchAddress("P.hod.2y.GoodPosTdcTimeCorr", P_hod_2y_GoodPosTdcTimeCorr, &b_P_hod_2y_GoodPosTdcTimeCorr);
   fChain->SetBranchAddress("Ndata.P.hod.2y.GoodPosTdcTimeTOFCorr", &Ndata_P_hod_2y_GoodPosTdcTimeTOFCorr, &b_Ndata_P_hod_2y_GoodPosTdcTimeTOFCorr);
   fChain->SetBranchAddress("P.hod.2y.GoodPosTdcTimeTOFCorr", P_hod_2y_GoodPosTdcTimeTOFCorr, &b_P_hod_2y_GoodPosTdcTimeTOFCorr);
   fChain->SetBranchAddress("Ndata.P.hod.2y.negAdcCounter", &Ndata_P_hod_2y_negAdcCounter, &b_Ndata_P_hod_2y_negAdcCounter);
   fChain->SetBranchAddress("P.hod.2y.negAdcCounter", P_hod_2y_negAdcCounter, &b_P_hod_2y_negAdcCounter);
   fChain->SetBranchAddress("Ndata.P.hod.2y.negAdcPed", &Ndata_P_hod_2y_negAdcPed, &b_Ndata_P_hod_2y_negAdcPed);
   fChain->SetBranchAddress("P.hod.2y.negAdcPed", P_hod_2y_negAdcPed, &b_P_hod_2y_negAdcPed);
   fChain->SetBranchAddress("Ndata.P.hod.2y.negAdcPedRaw", &Ndata_P_hod_2y_negAdcPedRaw, &b_Ndata_P_hod_2y_negAdcPedRaw);
   fChain->SetBranchAddress("P.hod.2y.negAdcPedRaw", P_hod_2y_negAdcPedRaw, &b_P_hod_2y_negAdcPedRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2y.negAdcPulseAmp", &Ndata_P_hod_2y_negAdcPulseAmp, &b_Ndata_P_hod_2y_negAdcPulseAmp);
   fChain->SetBranchAddress("P.hod.2y.negAdcPulseAmp", P_hod_2y_negAdcPulseAmp, &b_P_hod_2y_negAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hod.2y.negAdcPulseAmpRaw", &Ndata_P_hod_2y_negAdcPulseAmpRaw, &b_Ndata_P_hod_2y_negAdcPulseAmpRaw);
   fChain->SetBranchAddress("P.hod.2y.negAdcPulseAmpRaw", P_hod_2y_negAdcPulseAmpRaw, &b_P_hod_2y_negAdcPulseAmpRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2y.negAdcPulseInt", &Ndata_P_hod_2y_negAdcPulseInt, &b_Ndata_P_hod_2y_negAdcPulseInt);
   fChain->SetBranchAddress("P.hod.2y.negAdcPulseInt", P_hod_2y_negAdcPulseInt, &b_P_hod_2y_negAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hod.2y.negAdcPulseIntRaw", &Ndata_P_hod_2y_negAdcPulseIntRaw, &b_Ndata_P_hod_2y_negAdcPulseIntRaw);
   fChain->SetBranchAddress("P.hod.2y.negAdcPulseIntRaw", P_hod_2y_negAdcPulseIntRaw, &b_P_hod_2y_negAdcPulseIntRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2y.negAdcPulseTimeRaw", &Ndata_P_hod_2y_negAdcPulseTimeRaw, &b_Ndata_P_hod_2y_negAdcPulseTimeRaw);
   fChain->SetBranchAddress("P.hod.2y.negAdcPulseTimeRaw", P_hod_2y_negAdcPulseTimeRaw, &b_P_hod_2y_negAdcPulseTimeRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2y.negTdcCounter", &Ndata_P_hod_2y_negTdcCounter, &b_Ndata_P_hod_2y_negTdcCounter);
   fChain->SetBranchAddress("P.hod.2y.negTdcCounter", P_hod_2y_negTdcCounter, &b_P_hod_2y_negTdcCounter);
   fChain->SetBranchAddress("Ndata.P.hod.2y.negTdcTime", &Ndata_P_hod_2y_negTdcTime, &b_Ndata_P_hod_2y_negTdcTime);
   fChain->SetBranchAddress("P.hod.2y.negTdcTime", P_hod_2y_negTdcTime, &b_P_hod_2y_negTdcTime);
   fChain->SetBranchAddress("Ndata.P.hod.2y.negTdcTimeRaw", &Ndata_P_hod_2y_negTdcTimeRaw, &b_Ndata_P_hod_2y_negTdcTimeRaw);
   fChain->SetBranchAddress("P.hod.2y.negTdcTimeRaw", P_hod_2y_negTdcTimeRaw, &b_P_hod_2y_negTdcTimeRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2y.posAdcCounter", &Ndata_P_hod_2y_posAdcCounter, &b_Ndata_P_hod_2y_posAdcCounter);
   fChain->SetBranchAddress("P.hod.2y.posAdcCounter", P_hod_2y_posAdcCounter, &b_P_hod_2y_posAdcCounter);
   fChain->SetBranchAddress("Ndata.P.hod.2y.posAdcPed", &Ndata_P_hod_2y_posAdcPed, &b_Ndata_P_hod_2y_posAdcPed);
   fChain->SetBranchAddress("P.hod.2y.posAdcPed", P_hod_2y_posAdcPed, &b_P_hod_2y_posAdcPed);
   fChain->SetBranchAddress("Ndata.P.hod.2y.posAdcPedRaw", &Ndata_P_hod_2y_posAdcPedRaw, &b_Ndata_P_hod_2y_posAdcPedRaw);
   fChain->SetBranchAddress("P.hod.2y.posAdcPedRaw", P_hod_2y_posAdcPedRaw, &b_P_hod_2y_posAdcPedRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2y.posAdcPulseAmp", &Ndata_P_hod_2y_posAdcPulseAmp, &b_Ndata_P_hod_2y_posAdcPulseAmp);
   fChain->SetBranchAddress("P.hod.2y.posAdcPulseAmp", P_hod_2y_posAdcPulseAmp, &b_P_hod_2y_posAdcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.hod.2y.posAdcPulseAmpRaw", &Ndata_P_hod_2y_posAdcPulseAmpRaw, &b_Ndata_P_hod_2y_posAdcPulseAmpRaw);
   fChain->SetBranchAddress("P.hod.2y.posAdcPulseAmpRaw", P_hod_2y_posAdcPulseAmpRaw, &b_P_hod_2y_posAdcPulseAmpRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2y.posAdcPulseInt", &Ndata_P_hod_2y_posAdcPulseInt, &b_Ndata_P_hod_2y_posAdcPulseInt);
   fChain->SetBranchAddress("P.hod.2y.posAdcPulseInt", P_hod_2y_posAdcPulseInt, &b_P_hod_2y_posAdcPulseInt);
   fChain->SetBranchAddress("Ndata.P.hod.2y.posAdcPulseIntRaw", &Ndata_P_hod_2y_posAdcPulseIntRaw, &b_Ndata_P_hod_2y_posAdcPulseIntRaw);
   fChain->SetBranchAddress("P.hod.2y.posAdcPulseIntRaw", P_hod_2y_posAdcPulseIntRaw, &b_P_hod_2y_posAdcPulseIntRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2y.posAdcPulseTimeRaw", &Ndata_P_hod_2y_posAdcPulseTimeRaw, &b_Ndata_P_hod_2y_posAdcPulseTimeRaw);
   fChain->SetBranchAddress("P.hod.2y.posAdcPulseTimeRaw", P_hod_2y_posAdcPulseTimeRaw, &b_P_hod_2y_posAdcPulseTimeRaw);
   fChain->SetBranchAddress("Ndata.P.hod.2y.posTdcCounter", &Ndata_P_hod_2y_posTdcCounter, &b_Ndata_P_hod_2y_posTdcCounter);
   fChain->SetBranchAddress("P.hod.2y.posTdcCounter", P_hod_2y_posTdcCounter, &b_P_hod_2y_posTdcCounter);
   fChain->SetBranchAddress("Ndata.P.hod.2y.posTdcTime", &Ndata_P_hod_2y_posTdcTime, &b_Ndata_P_hod_2y_posTdcTime);
   fChain->SetBranchAddress("P.hod.2y.posTdcTime", P_hod_2y_posTdcTime, &b_P_hod_2y_posTdcTime);
   fChain->SetBranchAddress("Ndata.P.hod.2y.posTdcTimeRaw", &Ndata_P_hod_2y_posTdcTimeRaw, &b_Ndata_P_hod_2y_posTdcTimeRaw);
   fChain->SetBranchAddress("P.hod.2y.posTdcTimeRaw", P_hod_2y_posTdcTimeRaw, &b_P_hod_2y_posTdcTimeRaw);
   fChain->SetBranchAddress("Ndata.P.ngcer.adc", &Ndata_P_ngcer_adc, &b_Ndata_P_ngcer_adc);
   fChain->SetBranchAddress("P.ngcer.adc", P_ngcer_adc, &b_P_ngcer_adc);
   fChain->SetBranchAddress("Ndata.P.ngcer.adcCounter", &Ndata_P_ngcer_adcCounter, &b_Ndata_P_ngcer_adcCounter);
   fChain->SetBranchAddress("P.ngcer.adcCounter", P_ngcer_adcCounter, &b_P_ngcer_adcCounter);
   fChain->SetBranchAddress("Ndata.P.ngcer.adcPed", &Ndata_P_ngcer_adcPed, &b_Ndata_P_ngcer_adcPed);
   fChain->SetBranchAddress("P.ngcer.adcPed", P_ngcer_adcPed, &b_P_ngcer_adcPed);
   fChain->SetBranchAddress("Ndata.P.ngcer.adcPedRaw", &Ndata_P_ngcer_adcPedRaw, &b_Ndata_P_ngcer_adcPedRaw);
   fChain->SetBranchAddress("P.ngcer.adcPedRaw", P_ngcer_adcPedRaw, &b_P_ngcer_adcPedRaw);
   fChain->SetBranchAddress("Ndata.P.ngcer.adcPulseAmp", &Ndata_P_ngcer_adcPulseAmp, &b_Ndata_P_ngcer_adcPulseAmp);
   fChain->SetBranchAddress("P.ngcer.adcPulseAmp", P_ngcer_adcPulseAmp, &b_P_ngcer_adcPulseAmp);
   fChain->SetBranchAddress("Ndata.P.ngcer.adcPulseAmpRaw", &Ndata_P_ngcer_adcPulseAmpRaw, &b_Ndata_P_ngcer_adcPulseAmpRaw);
   fChain->SetBranchAddress("P.ngcer.adcPulseAmpRaw", P_ngcer_adcPulseAmpRaw, &b_P_ngcer_adcPulseAmpRaw);
   fChain->SetBranchAddress("Ndata.P.ngcer.adcPulseInt", &Ndata_P_ngcer_adcPulseInt, &b_Ndata_P_ngcer_adcPulseInt);
   fChain->SetBranchAddress("P.ngcer.adcPulseInt", P_ngcer_adcPulseInt, &b_P_ngcer_adcPulseInt);
   fChain->SetBranchAddress("Ndata.P.ngcer.adcPulseIntRaw", &Ndata_P_ngcer_adcPulseIntRaw, &b_Ndata_P_ngcer_adcPulseIntRaw);
   fChain->SetBranchAddress("P.ngcer.adcPulseIntRaw", P_ngcer_adcPulseIntRaw, &b_P_ngcer_adcPulseIntRaw);
   fChain->SetBranchAddress("Ndata.P.ngcer.adcPulseTimeRaw", &Ndata_P_ngcer_adcPulseTimeRaw, &b_Ndata_P_ngcer_adcPulseTimeRaw);
   fChain->SetBranchAddress("P.ngcer.adcPulseTimeRaw", P_ngcer_adcPulseTimeRaw, &b_P_ngcer_adcPulseTimeRaw);
   fChain->SetBranchAddress("Ndata.P.ngcer.adc_hit", &Ndata_P_ngcer_adc_hit, &b_Ndata_P_ngcer_adc_hit);
   fChain->SetBranchAddress("P.ngcer.adc_hit", P_ngcer_adc_hit, &b_P_ngcer_adc_hit);
   fChain->SetBranchAddress("Ndata.P.ngcer.adc_p", &Ndata_P_ngcer_adc_p, &b_Ndata_P_ngcer_adc_p);
   fChain->SetBranchAddress("P.ngcer.adc_p", P_ngcer_adc_p, &b_P_ngcer_adc_p);
   fChain->SetBranchAddress("Ndata.P.ngcer.cerfiredcounter", &Ndata_P_ngcer_cerfiredcounter, &b_Ndata_P_ngcer_cerfiredcounter);
   fChain->SetBranchAddress("P.ngcer.cerfiredcounter", P_ngcer_cerfiredcounter, &b_P_ngcer_cerfiredcounter);
   fChain->SetBranchAddress("Ndata.P.ngcer.certrackcounter", &Ndata_P_ngcer_certrackcounter, &b_Ndata_P_ngcer_certrackcounter);
   fChain->SetBranchAddress("P.ngcer.certrackcounter", P_ngcer_certrackcounter, &b_P_ngcer_certrackcounter);
   fChain->SetBranchAddress("Ndata.P.ngcer.npe", &Ndata_P_ngcer_npe, &b_Ndata_P_ngcer_npe);
   fChain->SetBranchAddress("P.ngcer.npe", P_ngcer_npe, &b_P_ngcer_npe);
   fChain->SetBranchAddress("Ndata.P.ngcer.phototubes", &Ndata_P_ngcer_phototubes, &b_Ndata_P_ngcer_phototubes);
   fChain->SetBranchAddress("P.ngcer.phototubes", P_ngcer_phototubes, &b_P_ngcer_phototubes);
   fChain->SetBranchAddress("Ndata.P.tr.beta", &Ndata_P_tr_beta, &b_Ndata_P_tr_beta);
   fChain->SetBranchAddress("P.tr.beta", P_tr_beta, &b_P_tr_beta);
   fChain->SetBranchAddress("Ndata.P.tr.betachisq", &Ndata_P_tr_betachisq, &b_Ndata_P_tr_betachisq);
   fChain->SetBranchAddress("P.tr.betachisq", P_tr_betachisq, &b_P_tr_betachisq);
   fChain->SetBranchAddress("Ndata.P.tr.chi2", &Ndata_P_tr_chi2, &b_Ndata_P_tr_chi2);
   fChain->SetBranchAddress("P.tr.chi2", P_tr_chi2, &b_P_tr_chi2);
   fChain->SetBranchAddress("Ndata.P.tr.d_ph", &Ndata_P_tr_d_ph, &b_Ndata_P_tr_d_ph);
   fChain->SetBranchAddress("P.tr.d_ph", P_tr_d_ph, &b_P_tr_d_ph);
   fChain->SetBranchAddress("Ndata.P.tr.d_th", &Ndata_P_tr_d_th, &b_Ndata_P_tr_d_th);
   fChain->SetBranchAddress("P.tr.d_th", P_tr_d_th, &b_P_tr_d_th);
   fChain->SetBranchAddress("Ndata.P.tr.d_x", &Ndata_P_tr_d_x, &b_Ndata_P_tr_d_x);
   fChain->SetBranchAddress("P.tr.d_x", P_tr_d_x, &b_P_tr_d_x);
   fChain->SetBranchAddress("Ndata.P.tr.d_y", &Ndata_P_tr_d_y, &b_Ndata_P_tr_d_y);
   fChain->SetBranchAddress("P.tr.d_y", P_tr_d_y, &b_P_tr_d_y);
   fChain->SetBranchAddress("Ndata.P.tr.dbeta", &Ndata_P_tr_dbeta, &b_Ndata_P_tr_dbeta);
   fChain->SetBranchAddress("P.tr.dbeta", P_tr_dbeta, &b_P_tr_dbeta);
   fChain->SetBranchAddress("Ndata.P.tr.dtime", &Ndata_P_tr_dtime, &b_Ndata_P_tr_dtime);
   fChain->SetBranchAddress("P.tr.dtime", P_tr_dtime, &b_P_tr_dtime);
   fChain->SetBranchAddress("Ndata.P.tr.flag", &Ndata_P_tr_flag, &b_Ndata_P_tr_flag);
   fChain->SetBranchAddress("P.tr.flag", P_tr_flag, &b_P_tr_flag);
   fChain->SetBranchAddress("Ndata.P.tr.ndof", &Ndata_P_tr_ndof, &b_Ndata_P_tr_ndof);
   fChain->SetBranchAddress("P.tr.ndof", P_tr_ndof, &b_P_tr_ndof);
   fChain->SetBranchAddress("Ndata.P.tr.p", &Ndata_P_tr_p, &b_Ndata_P_tr_p);
   fChain->SetBranchAddress("P.tr.p", P_tr_p, &b_P_tr_p);
   fChain->SetBranchAddress("Ndata.P.tr.pathl", &Ndata_P_tr_pathl, &b_Ndata_P_tr_pathl);
   fChain->SetBranchAddress("P.tr.pathl", P_tr_pathl, &b_P_tr_pathl);
   fChain->SetBranchAddress("Ndata.P.tr.ph", &Ndata_P_tr_ph, &b_Ndata_P_tr_ph);
   fChain->SetBranchAddress("P.tr.ph", P_tr_ph, &b_P_tr_ph);
   fChain->SetBranchAddress("Ndata.P.tr.px", &Ndata_P_tr_px, &b_Ndata_P_tr_px);
   fChain->SetBranchAddress("P.tr.px", P_tr_px, &b_P_tr_px);
   fChain->SetBranchAddress("Ndata.P.tr.py", &Ndata_P_tr_py, &b_Ndata_P_tr_py);
   fChain->SetBranchAddress("P.tr.py", P_tr_py, &b_P_tr_py);
   fChain->SetBranchAddress("Ndata.P.tr.pz", &Ndata_P_tr_pz, &b_Ndata_P_tr_pz);
   fChain->SetBranchAddress("P.tr.pz", P_tr_pz, &b_P_tr_pz);
   fChain->SetBranchAddress("Ndata.P.tr.r_ph", &Ndata_P_tr_r_ph, &b_Ndata_P_tr_r_ph);
   fChain->SetBranchAddress("P.tr.r_ph", P_tr_r_ph, &b_P_tr_r_ph);
   fChain->SetBranchAddress("Ndata.P.tr.r_th", &Ndata_P_tr_r_th, &b_Ndata_P_tr_r_th);
   fChain->SetBranchAddress("P.tr.r_th", P_tr_r_th, &b_P_tr_r_th);
   fChain->SetBranchAddress("Ndata.P.tr.r_x", &Ndata_P_tr_r_x, &b_Ndata_P_tr_r_x);
   fChain->SetBranchAddress("P.tr.r_x", P_tr_r_x, &b_P_tr_r_x);
   fChain->SetBranchAddress("Ndata.P.tr.r_y", &Ndata_P_tr_r_y, &b_Ndata_P_tr_r_y);
   fChain->SetBranchAddress("P.tr.r_y", P_tr_r_y, &b_P_tr_r_y);
   fChain->SetBranchAddress("Ndata.P.tr.tg_dp", &Ndata_P_tr_tg_dp, &b_Ndata_P_tr_tg_dp);
   fChain->SetBranchAddress("P.tr.tg_dp", P_tr_tg_dp, &b_P_tr_tg_dp);
   fChain->SetBranchAddress("Ndata.P.tr.tg_ph", &Ndata_P_tr_tg_ph, &b_Ndata_P_tr_tg_ph);
   fChain->SetBranchAddress("P.tr.tg_ph", P_tr_tg_ph, &b_P_tr_tg_ph);
   fChain->SetBranchAddress("Ndata.P.tr.tg_th", &Ndata_P_tr_tg_th, &b_Ndata_P_tr_tg_th);
   fChain->SetBranchAddress("P.tr.tg_th", P_tr_tg_th, &b_P_tr_tg_th);
   fChain->SetBranchAddress("Ndata.P.tr.tg_y", &Ndata_P_tr_tg_y, &b_Ndata_P_tr_tg_y);
   fChain->SetBranchAddress("P.tr.tg_y", P_tr_tg_y, &b_P_tr_tg_y);
   fChain->SetBranchAddress("Ndata.P.tr.th", &Ndata_P_tr_th, &b_Ndata_P_tr_th);
   fChain->SetBranchAddress("P.tr.th", P_tr_th, &b_P_tr_th);
   fChain->SetBranchAddress("Ndata.P.tr.time", &Ndata_P_tr_time, &b_Ndata_P_tr_time);
   fChain->SetBranchAddress("P.tr.time", P_tr_time, &b_P_tr_time);
   fChain->SetBranchAddress("Ndata.P.tr.vx", &Ndata_P_tr_vx, &b_Ndata_P_tr_vx);
   fChain->SetBranchAddress("P.tr.vx", P_tr_vx, &b_P_tr_vx);
   fChain->SetBranchAddress("Ndata.P.tr.vy", &Ndata_P_tr_vy, &b_Ndata_P_tr_vy);
   fChain->SetBranchAddress("P.tr.vy", P_tr_vy, &b_P_tr_vy);
   fChain->SetBranchAddress("Ndata.P.tr.vz", &Ndata_P_tr_vz, &b_Ndata_P_tr_vz);
   fChain->SetBranchAddress("P.tr.vz", P_tr_vz, &b_P_tr_vz);
   fChain->SetBranchAddress("Ndata.P.tr.x", &Ndata_P_tr_x, &b_Ndata_P_tr_x);
   fChain->SetBranchAddress("P.tr.x", P_tr_x, &b_P_tr_x);
   fChain->SetBranchAddress("Ndata.P.tr.y", &Ndata_P_tr_y, &b_Ndata_P_tr_y);
   fChain->SetBranchAddress("P.tr.y", P_tr_y, &b_P_tr_y);
   fChain->SetBranchAddress("P.aero.neg_npe_sum", &P_aero_neg_npe_sum, &b_P_aero_neg_npe_sum);
   fChain->SetBranchAddress("P.aero.ngood_hits", &P_aero_ngood_hits, &b_P_aero_ngood_hits);
   fChain->SetBranchAddress("P.aero.npe_sum", &P_aero_npe_sum, &b_P_aero_npe_sum);
   fChain->SetBranchAddress("P.aero.ntdc_neg_hits", &P_aero_ntdc_neg_hits, &b_P_aero_ntdc_neg_hits);
   fChain->SetBranchAddress("P.aero.ntdc_pos_hits", &P_aero_ntdc_pos_hits, &b_P_aero_ntdc_pos_hits);
   fChain->SetBranchAddress("P.aero.pos_npe_sum", &P_aero_pos_npe_sum, &b_P_aero_pos_npe_sum);
   fChain->SetBranchAddress("P.cal.etot", &P_cal_etot, &b_P_cal_etot);
   fChain->SetBranchAddress("P.cal.etotnorm", &P_cal_etotnorm, &b_P_cal_etotnorm);
   fChain->SetBranchAddress("P.cal.etrack", &P_cal_etrack, &b_P_cal_etrack);
   fChain->SetBranchAddress("P.cal.fly.earray", &P_cal_fly_earray, &b_P_cal_fly_earray);
   fChain->SetBranchAddress("P.cal.fly.nclust", &P_cal_fly_nclust, &b_P_cal_fly_nclust);
   fChain->SetBranchAddress("P.cal.fly.nhits", &P_cal_fly_nhits, &b_P_cal_fly_nhits);
   fChain->SetBranchAddress("P.cal.fly.ntracks", &P_cal_fly_ntracks, &b_P_cal_fly_ntracks);
   fChain->SetBranchAddress("P.cal.nclust", &P_cal_nclust, &b_P_cal_nclust);
   fChain->SetBranchAddress("P.cal.nhits", &P_cal_nhits, &b_P_cal_nhits);
   fChain->SetBranchAddress("P.cal.ntracks", &P_cal_ntracks, &b_P_cal_ntracks);
   fChain->SetBranchAddress("P.cal.pr.eplane", &P_cal_pr_eplane, &b_P_cal_pr_eplane);
   fChain->SetBranchAddress("P.cal.pr.eplane_neg", &P_cal_pr_eplane_neg, &b_P_cal_pr_eplane_neg);
   fChain->SetBranchAddress("P.cal.pr.eplane_pos", &P_cal_pr_eplane_pos, &b_P_cal_pr_eplane_pos);
   fChain->SetBranchAddress("P.dc.1u1.nhit", &P_dc_1u1_nhit, &b_P_dc_1u1_nhit);
   fChain->SetBranchAddress("P.dc.1u2.nhit", &P_dc_1u2_nhit, &b_P_dc_1u2_nhit);
   fChain->SetBranchAddress("P.dc.1v1.nhit", &P_dc_1v1_nhit, &b_P_dc_1v1_nhit);
   fChain->SetBranchAddress("P.dc.1v2.nhit", &P_dc_1v2_nhit, &b_P_dc_1v2_nhit);
   fChain->SetBranchAddress("P.dc.1x1.nhit", &P_dc_1x1_nhit, &b_P_dc_1x1_nhit);
   fChain->SetBranchAddress("P.dc.1x2.nhit", &P_dc_1x2_nhit, &b_P_dc_1x2_nhit);
   fChain->SetBranchAddress("P.dc.2u1.nhit", &P_dc_2u1_nhit, &b_P_dc_2u1_nhit);
   fChain->SetBranchAddress("P.dc.2u2.nhit", &P_dc_2u2_nhit, &b_P_dc_2u2_nhit);
   fChain->SetBranchAddress("P.dc.2v1.nhit", &P_dc_2v1_nhit, &b_P_dc_2v1_nhit);
   fChain->SetBranchAddress("P.dc.2v2.nhit", &P_dc_2v2_nhit, &b_P_dc_2v2_nhit);
   fChain->SetBranchAddress("P.dc.2x1.nhit", &P_dc_2x1_nhit, &b_P_dc_2x1_nhit);
   fChain->SetBranchAddress("P.dc.2x2.nhit", &P_dc_2x2_nhit, &b_P_dc_2x2_nhit);
   fChain->SetBranchAddress("P.dc.Ch1.maxhits", &P_dc_Ch1_maxhits, &b_P_dc_Ch1_maxhits);
   fChain->SetBranchAddress("P.dc.Ch1.nhit", &P_dc_Ch1_nhit, &b_P_dc_Ch1_nhit);
   fChain->SetBranchAddress("P.dc.Ch1.spacepoints", &P_dc_Ch1_spacepoints, &b_P_dc_Ch1_spacepoints);
   fChain->SetBranchAddress("P.dc.Ch1.trawhit", &P_dc_Ch1_trawhit, &b_P_dc_Ch1_trawhit);
   fChain->SetBranchAddress("P.dc.Ch2.maxhits", &P_dc_Ch2_maxhits, &b_P_dc_Ch2_maxhits);
   fChain->SetBranchAddress("P.dc.Ch2.nhit", &P_dc_Ch2_nhit, &b_P_dc_Ch2_nhit);
   fChain->SetBranchAddress("P.dc.Ch2.spacepoints", &P_dc_Ch2_spacepoints, &b_P_dc_Ch2_spacepoints);
   fChain->SetBranchAddress("P.dc.Ch2.trawhit", &P_dc_Ch2_trawhit, &b_P_dc_Ch2_trawhit);
   fChain->SetBranchAddress("P.dc.nhit", &P_dc_nhit, &b_P_dc_nhit);
   fChain->SetBranchAddress("P.dc.nsp", &P_dc_nsp, &b_P_dc_nsp);
   fChain->SetBranchAddress("P.dc.ntrack", &P_dc_ntrack, &b_P_dc_ntrack);
   fChain->SetBranchAddress("P.dc.stubtest", &P_dc_stubtest, &b_P_dc_stubtest);
   fChain->SetBranchAddress("P.dc.tnhit", &P_dc_tnhit, &b_P_dc_tnhit);
   fChain->SetBranchAddress("P.dc.trawhit", &P_dc_trawhit, &b_P_dc_trawhit);
   fChain->SetBranchAddress("P.hgcer.ncherhit", &P_hgcer_ncherhit, &b_P_hgcer_ncherhit);
   fChain->SetBranchAddress("P.hgcer.npesum", &P_hgcer_npesum, &b_P_hgcer_npesum);
   fChain->SetBranchAddress("P.hod.1x.fptime", &P_hod_1x_fptime, &b_P_hod_1x_fptime);
   fChain->SetBranchAddress("P.hod.1x.ngoodhits", &P_hod_1x_ngoodhits, &b_P_hod_1x_ngoodhits);
   fChain->SetBranchAddress("P.hod.1x.nhits", &P_hod_1x_nhits, &b_P_hod_1x_nhits);
   fChain->SetBranchAddress("P.hod.1y.fptime", &P_hod_1y_fptime, &b_P_hod_1y_fptime);
   fChain->SetBranchAddress("P.hod.1y.ngoodhits", &P_hod_1y_ngoodhits, &b_P_hod_1y_ngoodhits);
   fChain->SetBranchAddress("P.hod.1y.nhits", &P_hod_1y_nhits, &b_P_hod_1y_nhits);
   fChain->SetBranchAddress("P.hod.2x.fptime", &P_hod_2x_fptime, &b_P_hod_2x_fptime);
   fChain->SetBranchAddress("P.hod.2x.ngoodhits", &P_hod_2x_ngoodhits, &b_P_hod_2x_ngoodhits);
   fChain->SetBranchAddress("P.hod.2x.nhits", &P_hod_2x_nhits, &b_P_hod_2x_nhits);
   fChain->SetBranchAddress("P.hod.2y.fptime", &P_hod_2y_fptime, &b_P_hod_2y_fptime);
   fChain->SetBranchAddress("P.hod.2y.ngoodhits", &P_hod_2y_ngoodhits, &b_P_hod_2y_ngoodhits);
   fChain->SetBranchAddress("P.hod.2y.nhits", &P_hod_2y_nhits, &b_P_hod_2y_nhits);
   fChain->SetBranchAddress("P.hod.betachisqnotrack", &P_hod_betachisqnotrack, &b_P_hod_betachisqnotrack);
   fChain->SetBranchAddress("P.hod.betanotrack", &P_hod_betanotrack, &b_P_hod_betanotrack);
   fChain->SetBranchAddress("P.hod.betap", &P_hod_betap, &b_P_hod_betap);
   fChain->SetBranchAddress("P.hod.fpHitsTime", &P_hod_fpHitsTime, &b_P_hod_fpHitsTime);
   fChain->SetBranchAddress("P.hod.goodscinhit", &P_hod_goodscinhit, &b_P_hod_goodscinhit);
   fChain->SetBranchAddress("P.hod.goodstarttime", &P_hod_goodstarttime, &b_P_hod_goodstarttime);
   fChain->SetBranchAddress("P.hod.scindid", &P_hod_scindid, &b_P_hod_scindid);
   fChain->SetBranchAddress("P.hod.scinshould", &P_hod_scinshould, &b_P_hod_scinshould);
   fChain->SetBranchAddress("P.hod.starttime", &P_hod_starttime, &b_P_hod_starttime);
   fChain->SetBranchAddress("P.ngcer.ncherhit", &P_ngcer_ncherhit, &b_P_ngcer_ncherhit);
   fChain->SetBranchAddress("P.ngcer.npesum", &P_ngcer_npesum, &b_P_ngcer_npesum);
   fChain->SetBranchAddress("P.tr.n", &P_tr_n, &b_P_tr_n);
   fChain->SetBranchAddress("T.shms.p1T_tdcMultiplicity", &T_shms_p1T_tdcMultiplicity, &b_T_shms_p1T_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.p1T_tdcTime", &T_shms_p1T_tdcTime, &b_T_shms_p1T_tdcTime);
   fChain->SetBranchAddress("T.shms.p1T_tdcTimeRaw", &T_shms_p1T_tdcTimeRaw, &b_T_shms_p1T_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.p1X_tdcMultiplicity", &T_shms_p1X_tdcMultiplicity, &b_T_shms_p1X_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.p1X_tdcTime", &T_shms_p1X_tdcTime, &b_T_shms_p1X_tdcTime);
   fChain->SetBranchAddress("T.shms.p1X_tdcTimeRaw", &T_shms_p1X_tdcTimeRaw, &b_T_shms_p1X_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.p1Y_tdcMultiplicity", &T_shms_p1Y_tdcMultiplicity, &b_T_shms_p1Y_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.p1Y_tdcTime", &T_shms_p1Y_tdcTime, &b_T_shms_p1Y_tdcTime);
   fChain->SetBranchAddress("T.shms.p1Y_tdcTimeRaw", &T_shms_p1Y_tdcTimeRaw, &b_T_shms_p1Y_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.p2T_tdcMultiplicity", &T_shms_p2T_tdcMultiplicity, &b_T_shms_p2T_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.p2T_tdcTime", &T_shms_p2T_tdcTime, &b_T_shms_p2T_tdcTime);
   fChain->SetBranchAddress("T.shms.p2T_tdcTimeRaw", &T_shms_p2T_tdcTimeRaw, &b_T_shms_p2T_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.p2X_tdcMultiplicity", &T_shms_p2X_tdcMultiplicity, &b_T_shms_p2X_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.p2X_tdcTime", &T_shms_p2X_tdcTime, &b_T_shms_p2X_tdcTime);
   fChain->SetBranchAddress("T.shms.p2X_tdcTimeRaw", &T_shms_p2X_tdcTimeRaw, &b_T_shms_p2X_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.p2Y_tdcMultiplicity", &T_shms_p2Y_tdcMultiplicity, &b_T_shms_p2Y_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.p2Y_tdcTime", &T_shms_p2Y_tdcTime, &b_T_shms_p2Y_tdcTime);
   fChain->SetBranchAddress("T.shms.p2Y_tdcTimeRaw", &T_shms_p2Y_tdcTimeRaw, &b_T_shms_p2Y_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.pAERSUM_adcMultiplicity", &T_shms_pAERSUM_adcMultiplicity, &b_T_shms_pAERSUM_adcMultiplicity);
   fChain->SetBranchAddress("T.shms.pAERSUM_adcPed", &T_shms_pAERSUM_adcPed, &b_T_shms_pAERSUM_adcPed);
   fChain->SetBranchAddress("T.shms.pAERSUM_adcPedRaw", &T_shms_pAERSUM_adcPedRaw, &b_T_shms_pAERSUM_adcPedRaw);
   fChain->SetBranchAddress("T.shms.pAERSUM_adcPulseAmp", &T_shms_pAERSUM_adcPulseAmp, &b_T_shms_pAERSUM_adcPulseAmp);
   fChain->SetBranchAddress("T.shms.pAERSUM_adcPulseAmpRaw", &T_shms_pAERSUM_adcPulseAmpRaw, &b_T_shms_pAERSUM_adcPulseAmpRaw);
   fChain->SetBranchAddress("T.shms.pAERSUM_adcPulseInt", &T_shms_pAERSUM_adcPulseInt, &b_T_shms_pAERSUM_adcPulseInt);
   fChain->SetBranchAddress("T.shms.pAERSUM_adcPulseIntRaw", &T_shms_pAERSUM_adcPulseIntRaw, &b_T_shms_pAERSUM_adcPulseIntRaw);
   fChain->SetBranchAddress("T.shms.pAERSUM_adcPulseTimeRaw", &T_shms_pAERSUM_adcPulseTimeRaw, &b_T_shms_pAERSUM_adcPulseTimeRaw);
   fChain->SetBranchAddress("T.shms.pAERSUM_tdcMultiplicity", &T_shms_pAERSUM_tdcMultiplicity, &b_T_shms_pAERSUM_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.pAERSUM_tdcTime", &T_shms_pAERSUM_tdcTime, &b_T_shms_pAERSUM_tdcTime);
   fChain->SetBranchAddress("T.shms.pAERSUM_tdcTimeRaw", &T_shms_pAERSUM_tdcTimeRaw, &b_T_shms_pAERSUM_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.pDCREF10_tdcMultiplicity", &T_shms_pDCREF10_tdcMultiplicity, &b_T_shms_pDCREF10_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.pDCREF10_tdcTime", &T_shms_pDCREF10_tdcTime, &b_T_shms_pDCREF10_tdcTime);
   fChain->SetBranchAddress("T.shms.pDCREF10_tdcTimeRaw", &T_shms_pDCREF10_tdcTimeRaw, &b_T_shms_pDCREF10_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.pDCREF1_tdcMultiplicity", &T_shms_pDCREF1_tdcMultiplicity, &b_T_shms_pDCREF1_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.pDCREF1_tdcTime", &T_shms_pDCREF1_tdcTime, &b_T_shms_pDCREF1_tdcTime);
   fChain->SetBranchAddress("T.shms.pDCREF1_tdcTimeRaw", &T_shms_pDCREF1_tdcTimeRaw, &b_T_shms_pDCREF1_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.pDCREF2_tdcMultiplicity", &T_shms_pDCREF2_tdcMultiplicity, &b_T_shms_pDCREF2_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.pDCREF2_tdcTime", &T_shms_pDCREF2_tdcTime, &b_T_shms_pDCREF2_tdcTime);
   fChain->SetBranchAddress("T.shms.pDCREF2_tdcTimeRaw", &T_shms_pDCREF2_tdcTimeRaw, &b_T_shms_pDCREF2_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.pDCREF3_tdcMultiplicity", &T_shms_pDCREF3_tdcMultiplicity, &b_T_shms_pDCREF3_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.pDCREF3_tdcTime", &T_shms_pDCREF3_tdcTime, &b_T_shms_pDCREF3_tdcTime);
   fChain->SetBranchAddress("T.shms.pDCREF3_tdcTimeRaw", &T_shms_pDCREF3_tdcTimeRaw, &b_T_shms_pDCREF3_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.pDCREF4_tdcMultiplicity", &T_shms_pDCREF4_tdcMultiplicity, &b_T_shms_pDCREF4_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.pDCREF4_tdcTime", &T_shms_pDCREF4_tdcTime, &b_T_shms_pDCREF4_tdcTime);
   fChain->SetBranchAddress("T.shms.pDCREF4_tdcTimeRaw", &T_shms_pDCREF4_tdcTimeRaw, &b_T_shms_pDCREF4_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.pDCREF5_tdcMultiplicity", &T_shms_pDCREF5_tdcMultiplicity, &b_T_shms_pDCREF5_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.pDCREF5_tdcTime", &T_shms_pDCREF5_tdcTime, &b_T_shms_pDCREF5_tdcTime);
   fChain->SetBranchAddress("T.shms.pDCREF5_tdcTimeRaw", &T_shms_pDCREF5_tdcTimeRaw, &b_T_shms_pDCREF5_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.pDCREF6_tdcMultiplicity", &T_shms_pDCREF6_tdcMultiplicity, &b_T_shms_pDCREF6_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.pDCREF6_tdcTime", &T_shms_pDCREF6_tdcTime, &b_T_shms_pDCREF6_tdcTime);
   fChain->SetBranchAddress("T.shms.pDCREF6_tdcTimeRaw", &T_shms_pDCREF6_tdcTimeRaw, &b_T_shms_pDCREF6_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.pDCREF7_tdcMultiplicity", &T_shms_pDCREF7_tdcMultiplicity, &b_T_shms_pDCREF7_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.pDCREF7_tdcTime", &T_shms_pDCREF7_tdcTime, &b_T_shms_pDCREF7_tdcTime);
   fChain->SetBranchAddress("T.shms.pDCREF7_tdcTimeRaw", &T_shms_pDCREF7_tdcTimeRaw, &b_T_shms_pDCREF7_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.pDCREF8_tdcMultiplicity", &T_shms_pDCREF8_tdcMultiplicity, &b_T_shms_pDCREF8_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.pDCREF8_tdcTime", &T_shms_pDCREF8_tdcTime, &b_T_shms_pDCREF8_tdcTime);
   fChain->SetBranchAddress("T.shms.pDCREF8_tdcTimeRaw", &T_shms_pDCREF8_tdcTimeRaw, &b_T_shms_pDCREF8_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.pDCREF9_tdcMultiplicity", &T_shms_pDCREF9_tdcMultiplicity, &b_T_shms_pDCREF9_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.pDCREF9_tdcTime", &T_shms_pDCREF9_tdcTime, &b_T_shms_pDCREF9_tdcTime);
   fChain->SetBranchAddress("T.shms.pDCREF9_tdcTimeRaw", &T_shms_pDCREF9_tdcTimeRaw, &b_T_shms_pDCREF9_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.pHGCSUM_adcMultiplicity", &T_shms_pHGCSUM_adcMultiplicity, &b_T_shms_pHGCSUM_adcMultiplicity);
   fChain->SetBranchAddress("T.shms.pHGCSUM_adcPed", &T_shms_pHGCSUM_adcPed, &b_T_shms_pHGCSUM_adcPed);
   fChain->SetBranchAddress("T.shms.pHGCSUM_adcPedRaw", &T_shms_pHGCSUM_adcPedRaw, &b_T_shms_pHGCSUM_adcPedRaw);
   fChain->SetBranchAddress("T.shms.pHGCSUM_adcPulseAmp", &T_shms_pHGCSUM_adcPulseAmp, &b_T_shms_pHGCSUM_adcPulseAmp);
   fChain->SetBranchAddress("T.shms.pHGCSUM_adcPulseAmpRaw", &T_shms_pHGCSUM_adcPulseAmpRaw, &b_T_shms_pHGCSUM_adcPulseAmpRaw);
   fChain->SetBranchAddress("T.shms.pHGCSUM_adcPulseInt", &T_shms_pHGCSUM_adcPulseInt, &b_T_shms_pHGCSUM_adcPulseInt);
   fChain->SetBranchAddress("T.shms.pHGCSUM_adcPulseIntRaw", &T_shms_pHGCSUM_adcPulseIntRaw, &b_T_shms_pHGCSUM_adcPulseIntRaw);
   fChain->SetBranchAddress("T.shms.pHGCSUM_adcPulseTimeRaw", &T_shms_pHGCSUM_adcPulseTimeRaw, &b_T_shms_pHGCSUM_adcPulseTimeRaw);
   fChain->SetBranchAddress("T.shms.pHGCSUM_tdcMultiplicity", &T_shms_pHGCSUM_tdcMultiplicity, &b_T_shms_pHGCSUM_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.pHGCSUM_tdcTime", &T_shms_pHGCSUM_tdcTime, &b_T_shms_pHGCSUM_tdcTime);
   fChain->SetBranchAddress("T.shms.pHGCSUM_tdcTimeRaw", &T_shms_pHGCSUM_tdcTimeRaw, &b_T_shms_pHGCSUM_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.pNGCSUM_adcMultiplicity", &T_shms_pNGCSUM_adcMultiplicity, &b_T_shms_pNGCSUM_adcMultiplicity);
   fChain->SetBranchAddress("T.shms.pNGCSUM_adcPed", &T_shms_pNGCSUM_adcPed, &b_T_shms_pNGCSUM_adcPed);
   fChain->SetBranchAddress("T.shms.pNGCSUM_adcPedRaw", &T_shms_pNGCSUM_adcPedRaw, &b_T_shms_pNGCSUM_adcPedRaw);
   fChain->SetBranchAddress("T.shms.pNGCSUM_adcPulseAmp", &T_shms_pNGCSUM_adcPulseAmp, &b_T_shms_pNGCSUM_adcPulseAmp);
   fChain->SetBranchAddress("T.shms.pNGCSUM_adcPulseAmpRaw", &T_shms_pNGCSUM_adcPulseAmpRaw, &b_T_shms_pNGCSUM_adcPulseAmpRaw);
   fChain->SetBranchAddress("T.shms.pNGCSUM_adcPulseInt", &T_shms_pNGCSUM_adcPulseInt, &b_T_shms_pNGCSUM_adcPulseInt);
   fChain->SetBranchAddress("T.shms.pNGCSUM_adcPulseIntRaw", &T_shms_pNGCSUM_adcPulseIntRaw, &b_T_shms_pNGCSUM_adcPulseIntRaw);
   fChain->SetBranchAddress("T.shms.pNGCSUM_adcPulseTimeRaw", &T_shms_pNGCSUM_adcPulseTimeRaw, &b_T_shms_pNGCSUM_adcPulseTimeRaw);
   fChain->SetBranchAddress("T.shms.pNGCSUM_tdcMultiplicity", &T_shms_pNGCSUM_tdcMultiplicity, &b_T_shms_pNGCSUM_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.pNGCSUM_tdcTime", &T_shms_pNGCSUM_tdcTime, &b_T_shms_pNGCSUM_tdcTime);
   fChain->SetBranchAddress("T.shms.pNGCSUM_tdcTimeRaw", &T_shms_pNGCSUM_tdcTimeRaw, &b_T_shms_pNGCSUM_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.pT1_tdcMultiplicity", &T_shms_pT1_tdcMultiplicity, &b_T_shms_pT1_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.pT1_tdcTime", &T_shms_pT1_tdcTime, &b_T_shms_pT1_tdcTime);
   fChain->SetBranchAddress("T.shms.pT1_tdcTimeRaw", &T_shms_pT1_tdcTimeRaw, &b_T_shms_pT1_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.pT2_tdcMultiplicity", &T_shms_pT2_tdcMultiplicity, &b_T_shms_pT2_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.pT2_tdcTime", &T_shms_pT2_tdcTime, &b_T_shms_pT2_tdcTime);
   fChain->SetBranchAddress("T.shms.pT2_tdcTimeRaw", &T_shms_pT2_tdcTimeRaw, &b_T_shms_pT2_tdcTimeRaw);
   fChain->SetBranchAddress("T.shms.pT3_tdcMultiplicity", &T_shms_pT3_tdcMultiplicity, &b_T_shms_pT3_tdcMultiplicity);
   fChain->SetBranchAddress("T.shms.pT3_tdcTime", &T_shms_pT3_tdcTime, &b_T_shms_pT3_tdcTime);
   fChain->SetBranchAddress("T.shms.pT3_tdcTimeRaw", &T_shms_pT3_tdcTimeRaw, &b_T_shms_pT3_tdcTimeRaw);
   fChain->SetBranchAddress("fEvtHdr.fEvtTime", &fEvtHdr_fEvtTime, &b_Event_Branch_fEvtHdr_fEvtTime);
   fChain->SetBranchAddress("fEvtHdr.fEvtNum", &fEvtHdr_fEvtNum, &b_Event_Branch_fEvtHdr_fEvtNum);
   fChain->SetBranchAddress("fEvtHdr.fEvtType", &fEvtHdr_fEvtType, &b_Event_Branch_fEvtHdr_fEvtType);
   fChain->SetBranchAddress("fEvtHdr.fEvtLen", &fEvtHdr_fEvtLen, &b_Event_Branch_fEvtHdr_fEvtLen);
   fChain->SetBranchAddress("fEvtHdr.fHelicity", &fEvtHdr_fHelicity, &b_Event_Branch_fEvtHdr_fHelicity);
   fChain->SetBranchAddress("fEvtHdr.fTargetPol", &fEvtHdr_fTargetPol, &b_Event_Branch_fEvtHdr_fTargetPol);
   fChain->SetBranchAddress("fEvtHdr.fRun", &fEvtHdr_fRun, &b_Event_Branch_fEvtHdr_fRun);
   Notify();
}

Bool_t shower::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void shower::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t shower::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef shower_cxx
