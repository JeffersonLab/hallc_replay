#define calibration_cxx
// The class definition in calibration.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("calibration.C+")
// Root > T->Process("calibration.C+","some options")
//


#include "calibration.h"
#include <TH1.h>
#include <TH2.h>
#include <TF1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TPaveText.h>
#include <TSpectrum.h>
#include <TList.h>
#include <TPolyMarker.h>
#include <TGraphErrors.h>
#include <TMath.h>
#include <iostream>

using namespace TMath;

void calibration::Begin(TTree * /*tree*/)
{
  // The Begin() function is called at the start of the query.
  // When running with PROOF Begin() is only called on the client.
  // The tree argument is deprecated (on PROOF 0 is passed).
  printf("\n\n");

  TString option = GetOption();
  Info("Begin", "Script will fail unless 'calibration.C+' is used");
  Info("Begin", "Starting calibration process with option: %s", option.Data());
  Info("Begin", "To load all branches, use option readall (warning, very slow)");
  Info("Begin", "To see details of calibration, use option showall");
  Info("Begin", "Default calibration is the HGC, for NGC use option NGC");
  Info("Begin", "To calibrate using TrackFired leaf, use option trackfired");
  Info("Begin", "Default is no particle cut, use option cut if desired");
  Info("Begin", "Default particle ID is electrons, use option pions if desired");
}

void calibration::SlaveBegin(TTree * /*tree*/)
{
  // The SlaveBegin() function is called after the Begin() function.
  // When running with PROOF SlaveBegin() is called on each slave server.
  // The tree argument is deprecated (on PROOF 0 is passed).

  printf("\n\n");
  TString option = GetOption();

  // How much to read
  fFullRead = kFALSE;
  // Which detector to calibrate
  fNGC = kFALSE;
  // How much of the calibration to show
  fFullShow = kFALSE;
  // Calibration strategy
  fTrack = kFALSE;
  // Particle ID cuts used
  fCut = kFALSE;
  // Which particle ID to use
  fPions = kFALSE;
   
  //Check option
  if (option.Contains("readall")) fFullRead = kTRUE;
  if (option.Contains("NGC")) fNGC = kTRUE;
  if (option.Contains("showall")) fFullShow = kTRUE;
  if (option.Contains("trackfired")) fTrack = kTRUE;
  if (option.Contains("pions") || option.Contains("pion")) fPions = kTRUE;
  if (option.Contains("cut") || fPions || option.Contains("cuts")) fCut = kTRUE;

  Info("SlaveBegin", "'%s' reading", (fFullRead ? "full" : "optimized"));
  Info("SlaveBegin", "calibrating '%s'", (fNGC ? "NGC" : "HGC"));
  Info("SlaveBegin", "'%s' showing", (fFullShow ? "full" : "minimal"));
  Info("SlaveBegin", "'%s' strategy", (fTrack ? "tracking" : "quadrant"));
  Info("SlaveBegin", "cuts %s performed", (fCut ? "are" : "are not"));
  if (fCut) Info("SlaveBegin", "cutting for '%s'", (fPions ? "pions" : "electrons"));

  // Inintialize the histograms. Note they are binned per ADC channel which will be changed in the calibration analysis.
  Int_t ADC_min;
  Int_t ADC_max;
  Int_t bins;

  if (fNGC) //Set up histograms for NGC
    {
      ADC_min = -500;
      ADC_max = 12000;
      bins = abs(ADC_min) + abs(ADC_max);
    }
  if (!fNGC) //Set up histograms for HGC
    {
      ADC_min = -500;
      ADC_max = 7000;
      bins = abs(ADC_min) + abs(ADC_max);
    }

  fPulseInt[0] = new TH1F("PulseInt_PMT1", "Pulse Integral PMT1", bins, ADC_min, ADC_max);
  fPulseInt[1] = new TH1F("PulseInt_PMT2", "Pulse Integral PMT2", bins, ADC_min, ADC_max);
  fPulseInt[2] = new TH1F("PulseInt_PMT3", "Pulse Integral PMT3", bins, ADC_min, ADC_max);
  fPulseInt[3] = new TH1F("PulseInt_PMT4", "Pulse Integral PMT4", bins, ADC_min, ADC_max);
  fPulseInt_quad[0][0] = new TH1F("PulseInt_quad1_PMT1", "Pulse Integral PMT1 Quadrant 1", bins, ADC_min, ADC_max);
  fPulseInt_quad[0][1] = new TH1F("PulseInt_quad1_PMT2", "Pulse Integral PMT2 Quadrant 1", bins, ADC_min, ADC_max);
  fPulseInt_quad[0][2] = new TH1F("PulseInt_quad1_PMT3", "Pulse Integral PMT3 Quadrant 1", bins, ADC_min, ADC_max);
  fPulseInt_quad[0][3] = new TH1F("PulseInt_quad1_PMT4", "Pulse Integral PMT4 Quadrant 1", bins, ADC_min, ADC_max);
  fPulseInt_quad[1][0] = new TH1F("PulseInt_quad2_PMT1", "Pulse Integral PMT1 Quadrant 2", bins, ADC_min, ADC_max);
  fPulseInt_quad[1][1] = new TH1F("PulseInt_quad2_PMT2", "Pulse Integral PMT2 Quadrant 2", bins, ADC_min, ADC_max);
  fPulseInt_quad[1][2] = new TH1F("PulseInt_quad2_PMT3", "Pulse Integral PMT3 Quadrant 2", bins, ADC_min, ADC_max);
  fPulseInt_quad[1][3] = new TH1F("PulseInt_quad2_PMT4", "Pulse Integral PMT4 Quadrant 2", bins, ADC_min, ADC_max);
  fPulseInt_quad[2][0] = new TH1F("PulseInt_quad3_PMT1", "Pulse Integral PMT1 Quadrant 3", bins, ADC_min, ADC_max);
  fPulseInt_quad[2][1] = new TH1F("PulseInt_quad3_PMT2", "Pulse Integral PMT2 Quadrant 3", bins, ADC_min, ADC_max);
  fPulseInt_quad[2][2] = new TH1F("PulseInt_quad3_PMT3", "Pulse Integral PMT3 Quadrant 3", bins, ADC_min, ADC_max);
  fPulseInt_quad[2][3] = new TH1F("PulseInt_quad3_PMT4", "Pulse Integral PMT4 Quadrant 3", bins, ADC_min, ADC_max);
  fPulseInt_quad[3][0] = new TH1F("PulseInt_quad4_PMT1", "Pulse Integral PMT1 Quadrant 4", bins, ADC_min, ADC_max);
  fPulseInt_quad[3][1] = new TH1F("PulseInt_quad4_PMT2", "Pulse Integral PMT2 Quadrant 4", bins, ADC_min, ADC_max);
  fPulseInt_quad[3][2] = new TH1F("PulseInt_quad4_PMT3", "Pulse Integral PMT3 Quadrant 4", bins, ADC_min, ADC_max);
  fPulseInt_quad[3][3] = new TH1F("PulseInt_quad4_PMT4", "Pulse Integral PMT4 Quadrant 4", bins, ADC_min, ADC_max);
  fCut_everything = new TH2F("Cut_everything", "Visualization of no cuts", 1000, 0, 6.60, 1000, 0, 210.0);
  fCut_electron = new TH2F("Cut_electron", "Visualization of electron cut", 1000, 0, 6.60, 1000, 0, 210.0);
  fCut_pion = new TH2F("Cut_pion", "Visualization of pion cut", 1000, 0, 6.60, 1000, 0, 210.0);
  
  printf("\n\n");
}

Bool_t calibration::Process(Long64_t entry)
{
  // The Process() function is called for each entry in the tree (or possibly
  // keyed object in the case of PROOF) to be processed. The entry argument
  // specifies which entry in the currently loaded tree is to be processed.
  // It can be passed to either calibration::GetEntry() or TBranch::GetEntry()
  // to read either all or the required parts of the data. When processing
  // keyed objects with PROOF, the object is already loaded and is available
  // via the fObject pointer.
  //
  // This function should contain the "body" of the analysis. It can contain
  // simple or elaborate selection criteria, run algorithms on the data
  // of the event and typically fill histograms.
  //
  // The processing can be stopped by calling Abort().
  //
  // Use fStatus to set the return value of TTree::Process().
  //
  // The return value is currently not used.


  //Output to verify script is working, and store the total number of events
  if (entry % 100000 == 0) printf("Processing Entry number %lld\n",entry);
  ++fNumberOfEvents;

  //Define quantities to loop over
  Int_t fpmts;
  fpmts = fNGC ? fngc_pmts : fhgc_pmts;   //Note HGC & NGC have the same # of PMTS

  //Get the entry to loop over
  if (fFullRead) fChain->GetTree()->GetEntry(entry);
  else b_Ndata_P_tr_p->GetEntry(entry);
  
  //Require only one good track reconstruction for the event
  if (Ndata_P_tr_p != 1) return kTRUE;
  
  //Redundant, but useful if multiple tracks are eventually allowed
  for (Int_t itrack = 0; itrack < Ndata_P_tr_p; itrack++) 
    {
      if (!fFullRead) b_P_tr_beta->GetEntry(entry);
      //Require loose cut on particle velocity
      if (TMath::Abs(P_tr_beta[itrack] -1.) > 0.2) return kTRUE;

      //Filling the histograms
      for (Int_t ipmt = 0; ipmt < fpmts; ipmt++) 
	{	  
	  //Cuts to remove entries corresponding to a PMT not registering a hit
	  if (!fFullRead) fNGC ? b_P_ngcer_goodAdcPulseAmp->GetEntry(entry) : b_P_hgcer_goodAdcPulseAmp->GetEntry(entry);
	  if (fNGC ? P_ngcer_goodAdcPulseAmp[ipmt] == 0.0 : P_hgcer_goodAdcPulseAmp[ipmt] == 0.0) continue;
	  if (!fFullRead) fNGC ? b_P_ngcer_goodAdcPulseTime->GetEntry(entry) : b_P_hgcer_goodAdcPulseTime->GetEntry(entry);
	  if (fNGC ? P_ngcer_goodAdcPulseTime[ipmt] == 0.0 : P_hgcer_goodAdcPulseTime[ipmt] == 0.0) continue;
	 	  
	  //For quadrant cut strategy with particle ID cuts. In this case electrons are selected
	  if (!fTrack && fCut && !fPions)
	    {
	      //Retrieve information for particle tracking from focal plane
	      if (!fFullRead) b_P_tr_y->GetEntry(entry), b_P_tr_ph->GetEntry(entry);
	      if (!fFullRead) b_P_tr_x->GetEntry(entry), b_P_tr_th->GetEntry(entry);

	      if (!fFullRead) b_P_cal_fly_earray->GetEntry(entry);
	      if (!fFullRead) b_P_cal_pr_eplane->GetEntry(entry);
	      if (!fFullRead) b_P_hgcer_npeSum->GetEntry(entry);

	      //Fill histogram of the full PulseInt spectra for each PMT
	      if (!fFullRead) fNGC ? b_P_ngcer_goodAdcPulseInt->GetEntry(entry) : b_P_hgcer_goodAdcPulseInt->GetEntry(entry);
	      if (fNGC ? P_ngcer_goodAdcPulseInt[ipmt] == 0.0 : P_hgcer_goodAdcPulseInt[ipmt] == 0.0) continue;
	      fNGC ? fPulseInt[ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt[ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);

	      //Fill histograms of what each PMT registers from each quadrant
	      //Condition for quadrant 1 mirror
	      if (fNGC ? P_tr_y[0] + P_tr_ph[0]*fngc_zpos >= 0.0 && P_tr_x[0] + P_tr_th[0]*fngc_zpos >= 0.0 && P_hgcer_npeSum < 11 && P_hgcer_npeSum > 0.5
		  && P_cal_pr_eplane > 0.4 && P_cal_pr_eplane < 2.0: 
		         P_tr_y[0] + P_tr_ph[0]*fhgc_zpos >= 4.6 && P_tr_x[0] + P_tr_th[0]*fhgc_zpos >= 9.4)
		fNGC ? fPulseInt_quad[0][ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt_quad[0][ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);
	      //Condition for quadrant 2 mirror
	      if (fNGC ? P_tr_y[0] + P_tr_ph[0]*fngc_zpos < 0.0 && P_tr_x[0] + P_tr_th[0]*fngc_zpos >= 0.0 && P_hgcer_npeSum < 11 && P_hgcer_npeSum > 0.5
		  && P_cal_pr_eplane > 0.4 && P_cal_pr_eplane < 2.0: 
		         P_tr_y[0] + P_tr_ph[0]*fhgc_zpos < 4.6 && P_tr_x[0] + P_tr_th[0]*fhgc_zpos >= 9.4) 
		fNGC ? fPulseInt_quad[1][ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt_quad[1][ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);
	      //Condition for quadrant 3 mirror
	      if (fNGC ? P_tr_y[0] + P_tr_ph[0]*fngc_zpos >= 0.0 && P_tr_x[0] + P_tr_th[0]*fngc_zpos < 0.0 && P_hgcer_npeSum < 11 && P_hgcer_npeSum > 0.5
		  && P_cal_pr_eplane > 0.4 && P_cal_pr_eplane < 2.0: 
		         P_tr_y[0] + P_tr_ph[0]*fhgc_zpos >= 4.6 && P_tr_x[0] + P_tr_th[0]*fhgc_zpos < 9.4) 
		fNGC ? fPulseInt_quad[2][ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt_quad[2][ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);
	      //Condition for quadrant 4 mirror
	      if (fNGC ? P_tr_y[0] + P_tr_ph[0]*fngc_zpos < 0.0 && P_tr_x[0] + P_tr_th[0]*fngc_zpos < 0.0 && P_hgcer_npeSum < 11 && P_hgcer_npeSum > 0.5
		  && P_cal_pr_eplane > 0.4 && P_cal_pr_eplane < 2.0: 
		         P_tr_y[0] + P_tr_ph[0]*fhgc_zpos < 4.6 && P_tr_x[0] + P_tr_th[0]*fhgc_zpos < 9.4)
		fNGC ? fPulseInt_quad[3][ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt_quad[3][ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);

	      //Fill histogram visualizaing the pion cut
	      fCut_everything->Fill(P_cal_pr_eplane, P_hgcer_npeSum);
	      if (fNGC && P_hgcer_npeSum < 11 && P_hgcer_npeSum > 0.5 && P_cal_pr_eplane > 0.4 && P_cal_pr_eplane < 2.0) fCut_electron->Fill(P_cal_pr_eplane, P_hgcer_npeSum);

	    }

	  //For quadrant cut strategy with particle ID cuts. In this case pions are selected
	  if (!fTrack && fCut && fPions)
	    {
	      //Retrieve information for particle tracking from focal plane
	      if (!fFullRead) b_P_tr_y->GetEntry(entry), b_P_tr_ph->GetEntry(entry);
	      if (!fFullRead) b_P_tr_x->GetEntry(entry), b_P_tr_th->GetEntry(entry);

	      if (!fFullRead) b_P_cal_fly_earray->GetEntry(entry);
	      if (!fFullRead) b_P_cal_pr_eplane->GetEntry(entry);
	      if (!fFullRead) b_P_hgcer_npeSum->GetEntry(entry);

	      //Fill histogram of the full PulseInt spectra for each PMT
	      if (!fFullRead) fNGC ? b_P_ngcer_goodAdcPulseInt->GetEntry(entry) : b_P_hgcer_goodAdcPulseInt->GetEntry(entry);
	      if (fNGC ? P_ngcer_goodAdcPulseInt[ipmt] == 0.0 : P_hgcer_goodAdcPulseInt[ipmt] == 0.0) continue;
	      if (P_cal_fly_earray < 11 && P_cal_pr_eplane < 0.3) fNGC ? fPulseInt[ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt[ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);

	      //Condition for quadrant 1 mirror
	      if (fNGC ? P_tr_y[0] + P_tr_ph[0]*fngc_zpos >= 0.0 && P_tr_x[0] + P_tr_th[0]*fngc_zpos >= 0.0 && P_hgcer_npeSum != 0.0 && P_cal_pr_eplane != 0.0
		  && P_hgcer_npeSum < (-26.7*P_cal_pr_eplane + 8): 
		         P_tr_y[0] + P_tr_ph[0]*fhgc_zpos >= 4.6 && P_tr_x[0] + P_tr_th[0]*fhgc_zpos >= 9.4 && P_cal_fly_earray < 11 && P_cal_pr_eplane < 0.3)
		fNGC ? fPulseInt_quad[0][ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt_quad[0][ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);
	      //Condition for quadrant 2 mirror
	      if (fNGC ? P_tr_y[0] + P_tr_ph[0]*fngc_zpos < 0.0 && P_tr_x[0] + P_tr_th[0]*fngc_zpos >= 0.0 && P_hgcer_npeSum != 0.0 && P_cal_pr_eplane != 0.0
		  && P_hgcer_npeSum < (-26.7*P_cal_pr_eplane + 8): 
		         P_tr_y[0] + P_tr_ph[0]*fhgc_zpos < 4.6 && P_tr_x[0] + P_tr_th[0]*fhgc_zpos >= 9.4 && P_cal_fly_earray < 11 && P_cal_pr_eplane < 0.3) 
		fNGC ? fPulseInt_quad[1][ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt_quad[1][ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);
	      //Condition for quadrant 3 mirror
	      if (fNGC ? P_tr_y[0] + P_tr_ph[0]*fngc_zpos >= 0.0 && P_tr_x[0] + P_tr_th[0]*fngc_zpos < 0.0 && P_hgcer_npeSum != 0.0 && P_cal_pr_eplane != 0.0
		  && P_hgcer_npeSum < (-26.7*P_cal_pr_eplane + 8): 
		         P_tr_y[0] + P_tr_ph[0]*fhgc_zpos >= 4.6 && P_tr_x[0] + P_tr_th[0]*fhgc_zpos < 9.4 && P_cal_fly_earray < 11 && P_cal_pr_eplane < 0.3) 
		fNGC ? fPulseInt_quad[2][ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt_quad[2][ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);
	      //Condition for quadrant 4 mirror
	      if (fNGC ? P_tr_y[0] + P_tr_ph[0]*fngc_zpos < 0.0 && P_tr_x[0] + P_tr_th[0]*fngc_zpos < 0.0 && P_hgcer_npeSum != 0.0 && P_cal_pr_eplane != 0.0
		  && P_hgcer_npeSum < (-26.7*P_cal_pr_eplane + 8): 
		         P_tr_y[0] + P_tr_ph[0]*fhgc_zpos < 4.6 && P_tr_x[0] + P_tr_th[0]*fhgc_zpos < 9.4 && P_cal_fly_earray < 11 && P_cal_pr_eplane < 0.3)
		fNGC ? fPulseInt_quad[3][ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt_quad[3][ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);

	      //Fill histogram visualizaing the pion cut
	      fCut_everything->Fill(P_cal_pr_eplane, P_hgcer_npeSum);
	      if (fNGC && P_hgcer_npeSum != 0.0 && P_cal_pr_eplane != 0.0 && P_hgcer_npeSum < (-26.7*P_cal_pr_eplane + 8)) fCut_pion->Fill(P_cal_pr_eplane, P_hgcer_npeSum);
	    }

	  //For quadrant cut strategy with no particle ID cut
	  if (!fTrack && !fCut)
	    {
	      //Retrieve information for particle tracking from focal plane
	      if (!fFullRead) b_P_tr_y->GetEntry(entry), b_P_tr_ph->GetEntry(entry);
	      if (!fFullRead) b_P_tr_x->GetEntry(entry), b_P_tr_th->GetEntry(entry);

	      //Fill histogram of the full PulseInt spectra for each PMT
	      if (!fFullRead) fNGC ? b_P_ngcer_goodAdcPulseInt->GetEntry(entry) : b_P_hgcer_goodAdcPulseInt->GetEntry(entry);
	      if (fNGC ? P_ngcer_goodAdcPulseInt[ipmt] == 0.0 : P_hgcer_goodAdcPulseInt[ipmt] == 0.0) continue;
	      fNGC ? fPulseInt[ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt[ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);

	      //Condition for quadrant 1 mirror
	      if (fNGC ? P_tr_y[0] + P_tr_ph[0]*fngc_zpos >= 0.0 && P_tr_x[0] + P_tr_th[0]*fngc_zpos >= 0.0: 
		         P_tr_y[0] + P_tr_ph[0]*fhgc_zpos >= 4.6 && P_tr_x[0] + P_tr_th[0]*fhgc_zpos >= 9.4)
		fNGC ? fPulseInt_quad[0][ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt_quad[0][ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);
	      //Condition for quadrant 2 mirror
	      if (fNGC ? P_tr_y[0] + P_tr_ph[0]*fngc_zpos < 0.0 && P_tr_x[0] + P_tr_th[0]*fngc_zpos >= 0.0: 
		         P_tr_y[0] + P_tr_ph[0]*fhgc_zpos < 4.6 && P_tr_x[0] + P_tr_th[0]*fhgc_zpos >= 9.4)
		fNGC ? fPulseInt_quad[1][ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt_quad[1][ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);
	      //Condition for quadrant 3 mirror
	      if (fNGC ? P_tr_y[0] + P_tr_ph[0]*fngc_zpos >= 0.0 && P_tr_x[0] + P_tr_th[0]*fngc_zpos < 0.0: 
		         P_tr_y[0] + P_tr_ph[0]*fhgc_zpos >= 4.6 && P_tr_x[0] + P_tr_th[0]*fhgc_zpos < 9.4) 
		fNGC ? fPulseInt_quad[2][ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt_quad[2][ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);
	      //Condition for quadrant 4 mirror
	      if (fNGC ? P_tr_y[0] + P_tr_ph[0]*fngc_zpos < 0.0 && P_tr_x[0] + P_tr_th[0]*fngc_zpos < 0.0: 
		         P_tr_y[0] + P_tr_ph[0]*fhgc_zpos < 4.6 && P_tr_x[0] + P_tr_th[0]*fhgc_zpos < 9.4)
		fNGC ? fPulseInt_quad[3][ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt_quad[3][ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);
	    }

	  //For TracksFired cut strategy with no particle ID cut
	  if (fTrack && !fCut)
	    {
	      //Fill histogram of the full PulseInt spectra for each PMT
	      if (!fFullRead) fNGC ? b_P_ngcer_goodAdcPulseInt->GetEntry(entry) : b_P_hgcer_goodAdcPulseInt->GetEntry(entry);
	      if (fNGC ? P_ngcer_goodAdcPulseInt[ipmt] == 0.0 : P_hgcer_goodAdcPulseInt[ipmt] == 0.0) continue;
	      fNGC ? fPulseInt[ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt[ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);

	      //Fill histograms with TracksFired cut, note that quadrant cuts are included so any off quadrant histograms will be empty
	      if (!fFullRead) fNGC ? b_P_ngcer_numTracksFired->GetEntry(entry) : b_P_hgcer_numTracksFired->GetEntry(entry);
	      if (fNGC ? P_ngcer_numTracksFired[ipmt] != 0.0 : P_hgcer_numTracksFired[ipmt] != 0.0)
		fNGC ? fPulseInt_quad[ipmt][ipmt]->Fill(P_ngcer_goodAdcPulseInt[ipmt]) : fPulseInt_quad[ipmt][ipmt]->Fill(P_hgcer_goodAdcPulseInt[ipmt]);
	    }
	}  
    }

  return kTRUE;
}

void calibration::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.
}


//********************************************************
//Define functions used for fitting in calibration process

//Poisson distribution is used to remove background from larger values of NPE
Double_t poisson(Double_t *x, Double_t *par)
{
  Double_t result1 = (par[1]*pow(par[0],x[0])*exp(-par[0]))/(tgamma(x[0]+1));
  return result1;
}
//Gaussian distribution is used to find the mean of the SPE and determine spacing between subsequent NPE
Double_t gauss(Double_t *x, Double_t *par)
{
  Double_t result1 = par[0]*exp((-0.5)*(pow((x[0] - par[1]),2)/pow((par[2]),2)));
  Double_t result2 = par[3]*exp((-0.5)*(pow((x[0] - par[4]),2)/pow((par[5]),2)));
  Double_t result3 = par[6]*exp((-0.5)*(pow((x[0] - par[7]),2)/pow((par[8]),2)));
  Double_t result4 = par[9]*exp((-0.5)*(pow((x[0] - par[10]),2)/pow((par[11]),2)));
  Double_t result5 = par[12]*exp((-0.5)*(pow((x[0] - par[13]),2)/pow((par[14]),2)));
  return result1 + result2 + result3 + result4 + result5;
}

//A simple linear equation is used to determine how linear the means of the NPE are
Double_t linear(Double_t *x, Double_t *par)
{
  Double_t result1 = par[0]*x[0] + par[1];
  return result1;
}
//********************************************************


void calibration::Terminate()
{
  // The Terminate() function is the last function to be called during
  // a query. It always runs on the client, it can be used to present
  // the results graphically or save the results to file.

  //Print number of entries put into histograms
  printf("\nTotal Number of Entries: %d\n\n", fNumberOfEvents);

  Info("Terminate", "Histograms formed, now starting calibration.\n 'Peak Buffer full' is a good warning!\n");

  //Show the particle cuts performed in the histogram forming
  if (fCut)
    {
      TCanvas *cut_visualization = new TCanvas("cut_visualization", "Visualization of the particle ID cuts performed");
      cut_visualization->Divide(2,1);
      cut_visualization->cd(1);
      fCut_everything->Draw("Colz");
      cut_visualization->cd(2);
      fPions ? fCut_pion->Draw("Colz") : fCut_electron->Draw("Colz");
    }
 
  //Single Gaussian to find mean of SPE
  TF1 *Gauss1 = new TF1("Gauss1",gauss,-500,7000,3);
  Gauss1->SetParNames("Amplitude","Mean","Std. Dev.");

  //Sum of three Gaussians to determine NPE spacing
  TF1 *Gauss3 = new TF1("Gauss3",gauss,0.5,3.5,9);
  Gauss3->SetParNames("Amplitude 1","Mean 1","Std. Dev. 1","Amplitude 2","Mean 2","Std. Dev. 2","Amplitude 3","Mean 3","Std. Dev. 3");

  //Poisson distribution to remove high NPE background
  TF1 *Poisson = new TF1("Poisson",poisson,0,20,2);
  Poisson->SetParNames("Mean", "Amplitude");

  //Note about Poisson background, the mean varies between detectors/operating conditions so this quantity may require user input
  Double_t Poisson_mean = 0;
  fNGC ? Poisson_mean = 12.0 : Poisson_mean = 5.5;  

  //Linear function used to determine goodness-of-fit for NPE spacing
  TF1 *Linear = new TF1("Linear",linear,0,4,2);
  Linear->SetParNames("Slope", "Intercept");

  //Canvases to display the calibration process. Unused unless 'showall' option specified
  TCanvas *quad_cuts_ipmt;
  TCanvas *low_stats_ipmt;
  TCanvas *background_ipmt;
  TCanvas *final_spectra_ipmt;
  TCanvas *background_mk2_ipmt;
  TCanvas *final_spectra_mk2_ipmt;
  TCanvas *final_spectra_combined;
  TCanvas *final_spectra_combined_mk2;
  TCanvas *scaled_quad_cuts_ipmt;

  //Histograms to store scaling information and background removed spectra
  TH1F *fscaled[4];
  TH1F *fscaled_nobackground[4];
  TH1F *fscaled_mk2[4];
  TH1F *fscaled_mk2_nobackground[4];
  TH1F *fscaled_combined;
  TH1F *fscaled_combined_mk2;
  TH1F *fscaled_quad[4][4];

  //Rebin the histograms into something more sensible, add functionality to bin HGC & NGC independently
  for (Int_t ipmt=0; ipmt < (fNGC ? fngc_pmts : fhgc_pmts); ipmt++)
    {
      for (Int_t iquad=0; iquad<4; iquad++)
	{
	  fNGC ? fPulseInt_quad[iquad][ipmt]->Rebin(25) : fPulseInt_quad[iquad][ipmt]->Rebin(25);
	}
      fNGC ? fPulseInt[ipmt]->Rebin(25) : fPulseInt[ipmt]->Rebin(25);
    }
 
      
  //An array is used to store the means for the SPE, and to determine NPE spacing
  Double_t mean[3];
  Double_t x_npe[3], y_npe[3], x_err[3], y_err[3];
      
  //Two more arrays are used to store the estimates for the calibration constants
  Double_t calibration_mk1[4], calibration_mk2[4];

  gStyle->SetOptFit(111);

  //Main loop for calibration
  for (Int_t ipmt=0; ipmt < (fNGC ? fngc_pmts : fhgc_pmts); ipmt++)
    {
      //Initialize the various arrays
      for (Int_t i=0; i<3; i++)
	{
	  mean[i] = 0.0;
	  x_npe[i] = 0, y_npe[i] = 0, x_err[i] = 0, y_err[i] = 0;
	}

      //Begin strategy for quadrant cut calibration
      if (!fTrack)
	{
	  //TSpectrum class is used to find the SPE peak using the search method
	  TSpectrum *s = new TSpectrum(2);  

	  //Create Canvas to see the search result for the SPE  
	  if (fFullShow) quad_cuts_ipmt = new TCanvas(Form("quad_cuts_%d",ipmt), Form("First Photoelectron peaks PMT%d",ipmt+1));
	  if (fFullShow) quad_cuts_ipmt->Divide(3,1);  
	  
	  Int_t ipad = 1; //Variable to draw over pads correctly
	  for (Int_t iquad=0; iquad<4; iquad++)
	    {
	      if (iquad == ipmt) continue; //ignore a PMT looking at its own quadrant
	      if (fFullShow) quad_cuts_ipmt->cd(ipad);

	      //Perform search for the SPE and save the peak into the array xpeaks
	      fFullShow ? s->Search(fPulseInt_quad[iquad][ipmt], 2.5, "nobackground", 0.001) : s->Search(fPulseInt_quad[iquad][ipmt], 2.5, "nobackground&&nodraw", 0.001);
	      TList *functions = fPulseInt_quad[iquad][ipmt]->GetListOfFunctions();
	      TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
	      Double_t *xpeaks = pm->GetX();

	      //Use the peak to fit the SPE with a Gaussian to determine the mean
	      Gauss1->SetRange(xpeaks[1]-150, xpeaks[1]+150);
	      Gauss1->SetParameter(1, xpeaks[1]);
	      Gauss1->SetParameter(2, 200.);
	      Gauss1->SetParLimits(0, 0., 2000.);
	      Gauss1->SetParLimits(1, xpeaks[1]-150, xpeaks[1]+150);
	      Gauss1->SetParLimits(2, 10., 500.);
	      fFullShow ? fPulseInt_quad[iquad][ipmt]->Fit("Gauss1","RQ") : fPulseInt_quad[iquad][ipmt]->Fit("Gauss1","RQN");

	      //Store the mean of the SPE in the mean array provided it is not zero and passes a loose statistical cut. Note that indexing by ipad-1 is for convienience 
	      if (xpeaks[1] != 0.0 && fPulseInt_quad[iquad][ipmt]->GetBinContent(fPulseInt_quad[iquad][ipmt]->GetXaxis()->FindBin(xpeaks[1])) > 90) mean[ipad-1] = Gauss1->GetParameter(1); 
	      ipad++;
	    }

	  //Scale full ADC spectra according to the mean of the SPE. This requires filling a new histogram with the same number of bins but scaled min/max
	  Int_t nbins;
	  nbins = fPulseInt[ipmt]->GetXaxis()->GetNbins();

	  //Obtain the conversion from ADC to NPE by taking the average of the SPE means
	  Double_t xscale = 0.0;
	  Double_t num_peaks = 0.0;
	  for (Int_t i=0; i<3; i++)
	    {
	      if (mean[i] == 0.0) continue;
	      xscale += mean[i];
	      num_peaks += 1.0;
	    }
	  if (num_peaks != 0.0) xscale = xscale/num_peaks;

	  //Perform check if the statistics were too low to get a good estimate of the SPE mean
	  if (xscale < 10.0)
	    {
	      //Repeat the exact same procedure for the SPE of each quadrant, except now its for the full PMT spectra
	      if(fFullShow) low_stats_ipmt = new TCanvas(Form("low_stats_%d",ipmt),Form("Low stats analysis for PMT%d",ipmt+1));
	      if(fFullShow) low_stats_ipmt->cd(1);
	      fFullShow ? s->Search(fPulseInt[ipmt], 2.0, "nobackground", 0.001) : s->Search(fPulseInt[ipmt], 2.0, "nobackground&&nodraw", 0.001);
	      TList *functions = fPulseInt[ipmt]->GetListOfFunctions();
	      TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
	      Double_t *xpeaks = pm->GetX();
	      Gauss1->SetRange(xpeaks[1]-100, xpeaks[1]+100);
	      Gauss1->SetParameter(1, xpeaks[1]);
	      Gauss1->SetParameter(2, 200.);
	      Gauss1->SetParLimits(0, 0., 2000.);
	      Gauss1->SetParLimits(1, xpeaks[1]-50, xpeaks[1]+50);
	      Gauss1->SetParLimits(2, 10., 500.);
	      fFullShow ? fPulseInt[ipmt]->Fit("Gauss1","RQ") : fPulseInt[ipmt]->Fit("Gauss1","RQN");
	      xscale = Gauss1->GetParameter(1);
	    }	  

	  //With the scale of ADC to NPE create a histogram that has the conversion applied
	  fscaled[ipmt] = new TH1F(Form("fscaled_PMT%d", ipmt+1), Form("Scaled ADC spectra for PMT%d",ipmt+1), nbins, fPulseInt[ipmt]->GetXaxis()->GetXmin()/xscale,fPulseInt[ipmt]->GetXaxis()->GetXmax()/xscale);
	  
	  //Fill this histogram bin by bin
	  for (Int_t ibin=0; ibin<nbins; ibin++)
	    {
	      Double_t y = fPulseInt[ipmt]->GetBinContent(ibin);
	      fscaled[ipmt]->SetBinContent(ibin,y);
	    }

	  //Normalize the histogram for ease of fitting
	  fscaled[ipmt]->Scale(1.0/fscaled[ipmt]->Integral(), "width");

	  //Begin the removal of the Poisson-like background
	  if (fFullShow) background_ipmt = new TCanvas(Form("backgrounf_pmt%d",ipmt), Form("NPE spectra for PMT%d with Poisson-like background",ipmt+1));
	  if (fFullShow) background_ipmt->cd(1);
	  Poisson->SetParameter(0, Poisson_mean);
	  Poisson->SetParameter(1, 0.25);
	  Poisson->SetParLimits(0, Poisson_mean - 2.0, Poisson_mean + 2.0);
	  fFullShow ? fscaled[ipmt]->Fit("Poisson","RQ") : fscaled[ipmt]->Fit("Poisson","RQN");

	  //Make and fill histogram with the background removed
	  fscaled_nobackground[ipmt] = new TH1F(Form("fscaled_nobackground_pmt%d", ipmt+1), Form("NPE spectra background removed for PMT%d",ipmt+1), nbins, fPulseInt[ipmt]->GetXaxis()->GetXmin()/xscale,fPulseInt[ipmt]->GetXaxis()->GetXmax()/xscale);

	  for (Int_t ibin=0; ibin<nbins; ibin++)
	    {
	      Double_t y = Poisson->Eval(fscaled[ipmt]->GetXaxis()->GetBinCenter(ibin));
	      Double_t y2 = fscaled[ipmt]->GetBinContent(ibin) - y;
	      fscaled_nobackground[ipmt]->SetBinContent(ibin,y2);
	    }

	  if (fFullShow) final_spectra_ipmt = new TCanvas(Form("final_Spectra_%d",ipmt), Form("NPE spectra Background Removed for PMT%d",ipmt+1));
	  if (fFullShow) final_spectra_ipmt->Divide(2,1);
	  if (fFullShow) final_spectra_ipmt->cd(1);
	  Gauss3->SetParameters(0.08, 1.0, 0.22, 0.029, 2, 0.5, 0.15, 3, 0.26);
	  Gauss3->SetParLimits(1, 0.5, 1.5);
	  Gauss3->SetParLimits(2, 0.0, 1.0);
	  Gauss3->SetParLimits(3, 0.0, 1.0);
	  Gauss3->SetParLimits(4, 1.5, 2.5);
	  Gauss3->SetParLimits(5, 0.2, 0.6);
	  Gauss3->SetParLimits(6, 0.0, 1.0);
	  Gauss3->SetParLimits(7, 2.5, 3.5);
	  Gauss3->SetParLimits(8, 0.2, 0.5);
	  fFullShow ? fscaled_nobackground[ipmt]->Fit("Gauss3","RQ") : fscaled_nobackground[ipmt]->Fit("Gauss3","RQN");
	  if (fFullShow) fscaled_nobackground[ipmt]->GetXaxis()->SetRangeUser(0,5);

	  //Create a TGraphErrors to determine the spacing of the NPE
	  y_npe[0] = Gauss3->GetParameter(1), y_npe[1] = Gauss3->GetParameter(4), y_npe[2] = Gauss3->GetParameter(7);
	  y_err[0] = Gauss3->GetParError(1), y_err[1] = Gauss3->GetParError(4), y_err[2] = Gauss3->GetParError(7);
	  x_npe[0] = 1, x_npe[1] = 2, x_npe[2] = 3;
	  TGraphErrors *gr_npe = new TGraphErrors(3, x_npe, y_npe, x_err, y_err);

	  //Plot this graph with the NPE spectra
	  if (fFullShow) final_spectra_ipmt->cd(2);
	  Linear->SetParameters(1.0, 0.0);
	  fFullShow ? gr_npe->Fit("Linear","RQ") : gr_npe->Fit("Linear","RQN");
	  if (fFullShow) gr_npe->Draw("A*");
	  calibration_mk1[ipmt] = xscale;
      
	  //Initial calibration constant has been obtained. Now I multiply it by the slope of the spacing of the NPE (should be approx. 1) for a second estimate

	  Double_t xscale_mk2 = xscale * Linear->GetParameter(0);

	  //Take this new xscale and repeat the exact same procedure as before
	  fscaled_mk2[ipmt] = new TH1F(Form("fhgc_scaled_mk2_PMT%d", ipmt+1), Form("Scaled ADC spectra for PMT%d",ipmt+1), nbins, fPulseInt[ipmt]->GetXaxis()->GetXmin()/xscale_mk2,fPulseInt[ipmt]->GetXaxis()->GetXmax()/xscale_mk2);
	  
	  //Fill this histogram bin by bin
	  for (Int_t ibin=0; ibin<nbins; ibin++)
	    {
	      Double_t y = fPulseInt[ipmt]->GetBinContent(ibin);
	      fscaled_mk2[ipmt]->SetBinContent(ibin,y);
	    }

	  //Normalize the histogram for ease of fitting
	  fscaled_mk2[ipmt]->Scale(1.0/fscaled_mk2[ipmt]->Integral(), "width");

	  //Begin the removal of the Poisson-like background
	  if (fFullShow) background_mk2_ipmt = new TCanvas(Form("background_mk2_pmt%d",ipmt), Form("NPE spectra for PMT%d with Poisson-like background",ipmt+1));
	  if (fFullShow) background_mk2_ipmt->cd(1);
	  Poisson->SetParameter(0, Poisson_mean);
	  Poisson->SetParameter(1, 0.25);
	  Poisson->SetParLimits(0, Poisson_mean - 2.0, Poisson_mean + 2.0);
	  fFullShow ? fscaled_mk2[ipmt]->Fit("Poisson","RQ"):fscaled_mk2[ipmt]->Fit("Poisson","RQN");

	  //Make and fill histogram with the background removed
	  fscaled_mk2_nobackground[ipmt] = new TH1F(Form("fscaled_mk2_nobackground_pmt%d", ipmt+1), Form("NPE spectra background removed for PMT%d",ipmt+1), nbins, fPulseInt[ipmt]->GetXaxis()->GetXmin()/xscale_mk2,fPulseInt[ipmt]->GetXaxis()->GetXmax()/xscale_mk2);

	  for (Int_t ibin=0; ibin<nbins; ibin++)
	    {
	      Double_t y = Poisson->Eval(fscaled_mk2[ipmt]->GetXaxis()->GetBinCenter(ibin));
	      Double_t y2 = fscaled_mk2[ipmt]->GetBinContent(ibin) - y;
	      fscaled_mk2_nobackground[ipmt]->SetBinContent(ibin,y2);
	    }

	  if (fFullShow) final_spectra_mk2_ipmt = new TCanvas(Form("final_Spectra_mk2_%d",ipmt), Form("NPE spectra Background Removed for PMT%d",ipmt+1));
	  if (fFullShow) final_spectra_mk2_ipmt->Divide(2,1);
	  if (fFullShow) final_spectra_mk2_ipmt->cd(1);
	  Gauss3->SetParameters(0.08, 1.0, 0.22, 0.029, 2, 0.5, 0.15, 3, 0.26);
	  Gauss3->SetParLimits(1, 0.5, 1.5);
	  Gauss3->SetParLimits(2, 0.0, 1.0);
	  Gauss3->SetParLimits(3, 0.0, 1.0);
	  Gauss3->SetParLimits(4, 1.5, 2.5);
	  Gauss3->SetParLimits(5, 0.2, 0.6);
	  Gauss3->SetParLimits(6, 0.0, 1.0);
	  Gauss3->SetParLimits(7, 2.5, 3.5);
	  Gauss3->SetParLimits(8, 0.2, 0.5);
	  fFullShow ? fscaled_mk2_nobackground[ipmt]->Fit("Gauss3","RQ") : fscaled_mk2_nobackground[ipmt]->Fit("Gauss3","RQN");
	  if (fFullShow) fscaled_mk2_nobackground[ipmt]->GetXaxis()->SetRangeUser(0,5);

	  //Create a TGraphErrors to determine the spacing of the NPE
	  y_npe[0] = Gauss3->GetParameter(1), y_npe[1] = Gauss3->GetParameter(4), y_npe[2] = Gauss3->GetParameter(7);
	  y_err[0] = Gauss3->GetParError(1), y_err[1] = Gauss3->GetParError(4), y_err[2] = Gauss3->GetParError(7);
	  x_npe[0] = 1, x_npe[1] = 2, x_npe[2] = 3;
	  TGraphErrors *gr_npe_mk2 = new TGraphErrors(3, x_npe, y_npe, x_err, y_err);

	  //Plot this graph with the NPE spectra
	  if (fFullShow) final_spectra_mk2_ipmt->cd(2);
	  Linear->SetParameters(1.0, 0.0);
	  fFullShow ? gr_npe_mk2->Fit("Linear","RQ") : gr_npe_mk2->Fit("Linear","RQN");
	  if (fFullShow) gr_npe_mk2->Draw("A*");
	  calibration_mk2[ipmt] = xscale_mk2;
	} // This brance marks the end of the quadrant cut strategy


      //Begin investigation of Poisson-like integration of first few peaks (requires particle ID)
      if (fCut)
	{
	  //Begin by calibrating each quadrant...assume for now the first calibration is sufficient
	  scaled_quad_cuts_ipmt = new TCanvas(Form("scaled_quad_cuts_PMT%d",ipmt),Form("Scaled Adc Spectra with Quadrant Cuts for PMT %d",ipmt+1));
	  scaled_quad_cuts_ipmt->Divide(2,2);

	  for (Int_t iquad = 0; iquad < 4; iquad++)
	    {
	      scaled_quad_cuts_ipmt->cd(iquad+1);

	      Int_t nbins = fPulseInt_quad[iquad][ipmt]->GetXaxis()->GetNbins();
	      Double_t xmean = calibration_mk1[ipmt];

	      fscaled_quad[iquad][ipmt] = new TH1F(Form("fscaled_quad%d_pmt%d",iquad+1,ipmt+1), Form("Scaled ADC spectra in Quadrant %d for PMT %d",iquad+1, ipmt+1), nbins, (fPulseInt_quad[iquad][ipmt]->GetXaxis()->GetXmin())/xmean, (fPulseInt_quad[iquad][ipmt]->GetXaxis()->GetXmax())/xmean);

	      //Fill this histogram bin by bin
	      for (Int_t ibin=0; ibin < nbins; ibin++)
		{
		  Double_t y = fPulseInt_quad[iquad][ipmt]->GetBinContent(ibin);
		  fscaled_quad[iquad][ipmt]->SetBinContent(ibin,y);
		}

	      //Normalize the histogram for ease of fitting
	      fscaled_quad[iquad][ipmt]->Scale(1.0/fscaled_quad[iquad][ipmt]->Integral(), "width");

	      //TSpectrum class is used to find the SPE peak using the search method
	      TSpectrum *s = new TSpectrum(3); 
	      fscaled_quad[iquad][ipmt]->GetXaxis()->SetRangeUser(0,4);
	      s->Search(fscaled_quad[iquad][ipmt], 2.5, "", 0.001);
	      TList *functions = fscaled_quad[iquad][ipmt]->GetListOfFunctions();
	      TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
	      Double_t *xpeaks = pm->GetX();
	      long long index[3];
	      long long size = 3;
	      TMath::Sort(size, xpeaks, index, kFALSE);
	      TPaveText *pl = new TPaveText(0.6,0.5,0.89,0.89,"NDC");
	      TF1 *Temp_Gaus1 = new TF1("Temp_Gaus1",gauss,-500,7000,3);
	      TF1 *Temp_Gaus2 = new TF1("Temp_Gaus2",gauss,-500,7000,3);
	      TF1 *Temp_Gaus3 = new TF1("Temp_Gaus3",gauss,-500,7000,3);
	      TF1 *Temp_Pois = new TF1("Temp_Pois",poisson,-500,7000,2);
	      for (Int_t i = 0; i<3; i++)
		{
		  if (xpeaks[index[i]] < 0.5) continue;
		  if (i == 0)
		    {
		      fscaled_quad[iquad][ipmt]->GetXaxis()->SetRangeUser(xpeaks[index[i]]-0.1, xpeaks[index[i]]+0.1);
		      Temp_Gaus1->SetParameter(1, xpeaks[index[i]]);
		      Temp_Gaus1->SetParameter(2, 0.1);
		      Temp_Gaus1->SetParLimits(1, xpeaks[index[i]]-0.1, xpeaks[index[i]]+0.1);
		      Temp_Gaus1->SetParLimits(2, 0.0, 0.5);
		      fscaled_quad[iquad][ipmt]->SetStats(0);
		      fscaled_quad[iquad][ipmt]->Fit("Temp_Gaus1","RQN");
		      fscaled_quad[iquad][ipmt]->GetXaxis()->SetRangeUser((fPulseInt_quad[iquad][ipmt]->GetXaxis()->GetXmin())/xmean, (fPulseInt_quad[iquad][ipmt]->GetXaxis()->GetXmax())/xmean);
		      Temp_Gaus1->Draw("same");
		      pl->AddText(Form("Integral: %f",Temp_Gaus1->Integral(0,20)));
		    }

		  if (i == 1)
		    {
		      fscaled_quad[iquad][ipmt]->GetXaxis()->SetRangeUser(xpeaks[index[i]]-0.1, xpeaks[index[i]]+0.1);
		      Temp_Gaus2->SetParameter(1, xpeaks[index[i]]);
		      Temp_Gaus2->SetParameter(2, 0.1);
		      Temp_Gaus2->SetParLimits(1, xpeaks[index[i]]-0.1, xpeaks[index[i]]+0.1);
		      Temp_Gaus2->SetParLimits(2, 0.0, 0.5);
		      fscaled_quad[iquad][ipmt]->SetStats(0);
		      fscaled_quad[iquad][ipmt]->Fit("Temp_Gaus2","RQN");
		      fscaled_quad[iquad][ipmt]->GetXaxis()->SetRangeUser((fPulseInt_quad[iquad][ipmt]->GetXaxis()->GetXmin())/xmean, (fPulseInt_quad[iquad][ipmt]->GetXaxis()->GetXmax())/xmean);
		      Temp_Gaus2->Draw("same");
		      pl->AddText(Form("Integral: %f",Temp_Gaus2->Integral(0,20)));
		    }

		  if (i == 2)
		    {
		      fscaled_quad[iquad][ipmt]->GetXaxis()->SetRangeUser(xpeaks[index[i]]-0.1, xpeaks[index[i]]+0.1);
		      Temp_Gaus3->SetParameter(1, xpeaks[index[i]]);
		      Temp_Gaus3->SetParameter(2, 0.1);
		      Temp_Gaus3->SetParLimits(1, xpeaks[index[i]]-0.1, xpeaks[index[i]]+0.1);
		      Temp_Gaus3->SetParLimits(2, 0.0, 0.5);
		      fscaled_quad[iquad][ipmt]->SetStats(0);
		      fscaled_quad[iquad][ipmt]->Fit("Temp_Gaus3","RQN");
		      fscaled_quad[iquad][ipmt]->GetXaxis()->SetRangeUser((fPulseInt_quad[iquad][ipmt]->GetXaxis()->GetXmin())/xmean, (fPulseInt_quad[iquad][ipmt]->GetXaxis()->GetXmax())/xmean);
		      Temp_Gaus3->Draw("same");
		      fscaled_quad[iquad][ipmt]->Draw("same");
		      pl->AddText(Form("Integral: %f",Temp_Gaus3->Integral(0,20)));

		      Temp_Pois->SetParameter(0, 4.3);
		      Temp_Pois->SetParameter(1, 1.0);
		      Temp_Pois->SetParLimits(0, 0.0, 6.0);
		      Temp_Pois->SetParLimits(1, 0.0, 2.0);
		      fscaled_quad[iquad][ipmt]->Fit("Temp_Pois","RQN");
		      Temp_Pois->Draw("same");
		      pl->AddText(Form("Mean #PE: %f",Temp_Pois->GetParameter(0)));
		      pl->Draw("same");
		    }
		}
	    }
	}

      //Begin the TrackFired cut calibration
      if (fTrack)
	{
	  //TSpectrum class is used to find the SPE peak using the search method
	  TSpectrum *s = new TSpectrum(1); 

	  //Create Canvas to show the search result for the SPE
	  if (fFullShow) quad_cuts_ipmt = new TCanvas(Form("quad_cuts_%d",ipmt), Form("First Photoelectron peaks PMT%d",ipmt+1));
	  if (fFullShow) quad_cuts_ipmt->cd(1);

	  //Perform search for the SPE and save the peak into the array xpeaks
	  fNGC ? fPulseInt_quad[ipmt][ipmt]->GetXaxis()->SetRangeUser(150,2000) : fPulseInt_quad[ipmt][ipmt]->GetXaxis()->SetRangeUser(150,600);
	  fFullShow ? s->Search(fPulseInt_quad[ipmt][ipmt], 1.5, "nobackground", 0.001) : s->Search(fPulseInt_quad[ipmt][ipmt], 1.5, "nobackground&&nodraw", 0.001);
	  TList *functions = fPulseInt_quad[ipmt][ipmt]->GetListOfFunctions();
	  TPolyMarker *pm = (TPolyMarker*)functions->FindObject("TPolyMarker");
	  Double_t *xpeaks = pm->GetX();

	  //Use the peak to fit the SPE with a Gaussian to determine the mean
	  Gauss1->SetRange(xpeaks[0]-150, xpeaks[0]+200);
	  Gauss1->SetParameter(1, xpeaks[0]);
	  Gauss1->SetParameter(2, 200.);
	  Gauss1->SetParLimits(0, 0., 2000.);
	  Gauss1->SetParLimits(1, xpeaks[0]-100, xpeaks[0]+100);
	  Gauss1->SetParLimits(2, 10., 500.);
	  fPulseInt_quad[ipmt][ipmt]->GetXaxis()->SetRangeUser(-500,12000);
	  fFullShow ? fPulseInt_quad[ipmt][ipmt]->Fit("Gauss1","RQ") : fPulseInt_quad[ipmt][ipmt]->Fit("Gauss1","RQN");

	  calibration_mk1[ipmt] = Gauss1->GetParameter(1);

	   //Scale full ADC spectra according to the mean of the SPE. This requires filling a new histogram with the same number of bins but scaled min/max
	  Int_t nbins;
	  nbins = fPulseInt[ipmt]->GetXaxis()->GetNbins();

	  fscaled[ipmt] = new TH1F(Form("fscaled_PMT%d", ipmt+1), Form("Scaled ADC spectra for PMT%d",ipmt+1), nbins, fPulseInt_quad[ipmt][ipmt]->GetXaxis()->GetXmin()/calibration_mk1[ipmt],fPulseInt_quad[ipmt][ipmt]->GetXaxis()->GetXmax()/calibration_mk1[ipmt]);

	  //Fill this histogram bin by bin
	  for (Int_t ibin=0; ibin<nbins; ibin++)
	    {
	      Double_t y = fPulseInt_quad[ipmt][ipmt]->GetBinContent(ibin);
	      fscaled[ipmt]->SetBinContent(ibin,y);
	    }

	  //Normalize the histogram for ease of fitting
	  fscaled[ipmt]->Scale(1.0/fscaled[ipmt]->Integral(), "width");

	  //Attempt to characterize the Poisson-like distribution for larger NPE, this requires combining the spectrum from each PMT
	  if (ipmt == 3)
	    {
	      TH1F *fscaled_combined = (TH1F*)fscaled[0]->Clone("fscaled_combined");
	      fscaled_combined->Reset();
	      fscaled_combined->Add(fscaled[0]),fscaled_combined->Add(fscaled[1]),fscaled_combined->Add(fscaled[2]),fscaled_combined->Add(fscaled[3]);
	      if (fFullShow) background_ipmt = new TCanvas(Form("backgrounf_pmt%d",ipmt), Form("NPE spectra for PMT%d with Poisson-like background",ipmt+1));
	      if (fFullShow) background_ipmt->cd(1);
	      Poisson->SetParameter(0, Poisson_mean);
	      Poisson->SetParameter(1, 0.25);
	      Poisson->SetParLimits(0, Poisson_mean - 4.0, Poisson_mean + 4.0);
	      fFullShow ? fscaled_combined->Fit("Poisson","RQ") : fscaled_combined->Fit("Poisson","RQN");

	      //Then see where the Poisson peak should be, and generate a new calibration constant
	      fFullShow ? s->Search(fscaled_combined, 5.5, "nobackground", 0.001) : s->Search(fscaled_combined, 5.5, "nobackground&&nodraw", 0.001);
	      TList *functions_poisson = fscaled_combined->GetListOfFunctions();
	      TPolyMarker *pm_poisson = (TPolyMarker*)functions_poisson->FindObject("TPolyMarker");
	      Double_t *xpeaks_poisson = pm_poisson->GetX();
	      cout << xpeaks_poisson[0] << "   " << Poisson->GetParameter(0) << endl;
	      
	      for (Int_t i=0; i<4; i++)
		{
		  calibration_mk2[i] = calibration_mk1[i] * (xpeaks_poisson[0]/Poisson->GetParameter(0));

		  //Repeat the Poisson fit to examine goodness of calibration
		  fscaled_mk2[i] = new TH1F(Form("fscaled_mk2_PMT%d", i+1), Form("Scaled ADC spectra for PMT%d",i+1), nbins, fPulseInt_quad[i][i]->GetXaxis()->GetXmin()/calibration_mk2[i],fPulseInt_quad[i][i]->GetXaxis()->GetXmax()/calibration_mk2[i]);

		  //Fill this histogram bin by bin
		  for (Int_t ibin=0; ibin<nbins; ibin++)
		    {
		      Double_t y = fPulseInt_quad[i][i]->GetBinContent(ibin);
		      fscaled_mk2[i]->SetBinContent(ibin,y);
		    }

		  //Normalize the histogram for ease of fitting
		  fscaled_mk2[i]->Scale(1.0/fscaled_mk2[i]->Integral(), "width");
		}

	      TH1F *fscaled_combined_mk2 = (TH1F*)fscaled_mk2[0]->Clone("fscaled_combined_mk2");
	      fscaled_combined_mk2->Reset();
	      fscaled_combined_mk2->Add(fscaled_mk2[0]),fscaled_combined_mk2->Add(fscaled_mk2[1]),fscaled_combined_mk2->Add(fscaled_mk2[2]),fscaled_combined_mk2->Add(fscaled_mk2[3]);
	      if (fFullShow) background_mk2_ipmt = new TCanvas(Form("background_mk2_pmt%d",ipmt), Form("NPE spectra for PMT%d with Poisson-like background",ipmt+1));
	      if (fFullShow) background_mk2_ipmt->cd(1);
	      Poisson->SetParameter(0, Poisson_mean);
	      Poisson->SetParameter(1, 0.25);
	      Poisson->SetParLimits(0, Poisson_mean - 4.0, Poisson_mean + 4.0);
	      fFullShow ? fscaled_combined_mk2->Fit("Poisson","RQ") : fscaled_combined_mk2->Fit("Poisson","RQN");
	    }

	} //This brace marks the end of TracksFired strategy

    } // This brace marks the end of the loop over PMTs

  printf("\n\n");

  cout << "Calibration constants are\nPMT#: First Guess  Second Guess\n" << endl;
  for (Int_t i=0; i<4; i++)
    {
      cout << Form("PMT%d: ",i+1) << calibration_mk1[i] << "  " << calibration_mk2[i] << endl;
    }
}
