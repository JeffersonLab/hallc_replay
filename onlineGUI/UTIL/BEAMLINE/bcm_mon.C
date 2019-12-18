
void UserScript()
{

  TTree *TSP = (TTree*) gDirectory->Get("TSP");
  UInt_t ne = TSP->GetEntries();

  Double_t ibcm1, ibcm2, ibcm4a, ibcm4b, ibcm4c;
  TSP->SetBranchAddress("P.BCM1.scalerCurrent",  &ibcm1);
  TSP->SetBranchAddress("P.BCM2.scalerCurrent",  &ibcm2);
  TSP->SetBranchAddress("P.BCM4A.scalerCurrent", &ibcm4a);
  TSP->SetBranchAddress("P.BCM4B.scalerCurrent", &ibcm4b);
  TSP->SetBranchAddress("P.BCM4C.scalerCurrent", &ibcm4c);

  TH1F *hrbcm12   = new TH1F("hrbcm12",   "BCM 1 & 2 Ratio;   BCM1 / BCM2;   Number of Entries", 100, 0.5, 1.5);
  TH1F *hrbcm4a4b = new TH1F("hrbcm4a4b", "BCM 4A & 4B Ratio; BCM4A / BCM4B; Number of Entries", 100, 0.5, 1.5);
  TH1F *hrbcm4a4c = new TH1F("hrbcm4a4c", "BCM 4A & 4C Ratio; BCM4A / BCM4C; Number of Entries", 500, 0.0, 5.0);
  TH1F *hrbcm4b4c = new TH1F("hrbcm4b4c", "BCM 4B & 4C Ratio; BCM4B / BCM4C; Number of Entries", 500, 0.0, 5.0);

  TH1F *hdbcm12   = new TH1F("hdbcm12",   "BCM 1 & 2 Difference;   BCM1 - BCM2 (uA);   Number of Entries", 100, -0.5, 0.5);
  TH1F *hdbcm4a4b = new TH1F("hdbcm4a4b", "BCM 4A & 4B Difference; BCM4A - BCM4B (uA); Number of Entries", 100, -0.5, 0.5);
  TH1F *hdbcm4a4c = new TH1F("hdbcm4a4c", "BCM 4A & 4C Difference; BCM4A - BCM4C (uA); Number of Entries", 500, -25.0, 25.0);
  TH1F *hdbcm4b4c = new TH1F("hdbcm4b4c", "BCM 4B & 4C Difference; BCM4B - BCM4C (uA); Number of Entries", 500, -25.0, 25.0);

  for (UInt_t iev = 0; iev < ne; iev++) {
    TSP->GetEntry(iev);
    if (ibcm1 > 0.0 && ibcm2 > 0.0) {
      hrbcm12->Fill(ibcm1/ibcm2);
      hdbcm12->Fill(abs(ibcm1-ibcm2));
    }
    if (ibcm4a > 0.0 && ibcm4b > 0.0) {
      hrbcm4a4b->Fill(ibcm4a/ibcm4b);
      hdbcm4a4b->Fill(abs(ibcm4a-ibcm4b));
    }
    if (ibcm4a > 0.0 && ibcm4c > 0.0) {
      hrbcm4a4c->Fill(ibcm4a/ibcm4c);
      hdbcm4a4c->Fill(abs(ibcm4a-ibcm4c));
    }
    if (ibcm4b > 0.0 && ibcm4c > 0.0) {
      hrbcm4b4c->Fill(ibcm4b/ibcm4c);
      hdbcm4b4c->Fill(abs(ibcm4b-ibcm4c));
    }
  }

}

void bcm_mon(TString histname) {

  TH1F* h1d;
  h1d = (TH1F*) gDirectory->Get(histname);
  if (!h1d) {
    UserScript();
    h1d = (TH1F*) gDirectory->Get(histname);
    if (!h1d) {
      cout << "User histogram " << histname << " not found" << endl;
      exit(1);
    }
  }
  if (h1d) {
    h1d->SetStats(0);
    h1d->Draw();
  }

}
