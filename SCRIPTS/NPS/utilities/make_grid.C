#include <tuple>
#include "parse_utils.h"

/*
  Author: Carlos Yero
  Date: Feb. 16, 2021
  email: cyero@jlab.org
 */

std::pair<int, int> GetBlockij(int blk_id=0, string detec="")
 {

   //Brief: This method returns the pair (irow, jcol) block indices based on the block id number

   //detector geometry
   int fNRows;
   int fNColumns;

   if(detec=="SHMS"){
     fNRows = 16;
     fNColumns = 14;
   }
   else if (detec=="NPS"){
     fNRows = 32;
     fNColumns = 28;
   }
   

   //temporary placeholders (ith row, jth colum and block id)
   int itmp, jtmp, id_tmp;
   itmp = jtmp = id_tmp = -1; //defaults to -1 if no match is found

   for (int irow=0; irow<fNRows; irow++){
     for (int jcol=0; jcol<fNColumns; jcol++){

       id_tmp = jcol * fNRows + irow;

       //check if block id matches input id
       if(id_tmp == blk_id){
 	itmp = irow;
 	jtmp = jcol;
 	break;
       }   
     }
   }

   return std::make_pair(itmp, jtmp);

 }

void plot_cal(vector<int> evNum_clust, vector<int> NClusters_clust,
	      vector<int> iCluster_clust, vector<int> blk_id_clust,
	      vector<double> time_clust, vector<double> energy_clust,
	      string detec="", string clust_method="", string fout_name="")
{


  //Open ROOTFile in UPDATE mode (to write/save clusters for every event)
  TFile *fout = new TFile(fout_name.c_str(), "UPDATE");  

  vector<int> irow_vec;
  vector<int> jcol_vec;

  
  //temporary storage of (row, column) indices 
  Int_t irow, jcol;


  //Loop over ALL BLOCKS of a given event
  for(int i=0; i<blk_id_clust.size(); i++){

    //call function to get (irow, jcol) given the block id
    std::tie(irow,jcol) = GetBlockij(blk_id_clust.at(i), detec);

    irow_vec.push_back(irow);
    jcol_vec.push_back(jcol);

  }
  
  
  //detector geometry
  int fNRows;
  int fNColumns;

  //tick label and marker size
  double xtick_size;
  double ytick_size;
  double marker_size;

  if(detec=="SHMS"){
    fNRows = 16;
    fNColumns = 14;
    
    xtick_size = 0.02;
    ytick_size = 0.02;

    marker_size = 1.;

    for(int i=0; i<blk_id_clust.size(); i++){

      //Add +1 to (row, col), since ROOT bin numbering starts at (1, 1) (block id 0)
      //shms cal. map (block id starts at 0)
      irow_vec.at(i) = irow_vec.at(i) + 1;
      jcol_vec.at(i) = jcol_vec.at(i) + 1;

    }

  }
  
  else if(detec=="NPS"){
    fNRows = 32;
    fNColumns = 28;

    xtick_size = 0.02;
    ytick_size = 0.02;

    //font size in block
    marker_size = 0.5;


    for(int i=0; i<blk_id_clust.size(); i++){
      
      //nps quadrant
      irow_vec.at(i) = irow_vec.at(i) + 1;
      jcol_vec.at(i) = fNColumns-(jcol_vec.at(i));  // nps mapping (columns start from right to left)
      
    }
     
  }
  
  //cout << "(irow, jcol) = " << irow << ", " << jcol << endl;
    
  TCanvas *c1 = new TCanvas(Form("evNum_%d_clusters", evNum_clust.at(0)), Form("%s %s: evNum %d", detec.c_str(), clust_method.c_str(), evNum_clust.at(0)),1400,800);
  gStyle->SetOptStat(0);

  TCanvas *c2 = new TCanvas(Form("evNum_%d", evNum_clust.at(0)), Form("%s %s: evNum %d", detec.c_str(), clust_method.c_str(), evNum_clust.at(0)),1400,800);
  gStyle->SetOptStat(0);
  
  //2D histogram to visualize calorimeter hits
  TH2F *h2 = new TH2F("h2",Form("%s (%s) Calorimeter Map (front)", detec.c_str(), clust_method.c_str()),fNColumns, 0., fNColumns, fNRows, 0, fNRows);
  
  //histogram to draw block pulse integral (or any relevant adc numerical quantity)
  TH2F *htxt1 = new TH2F("htxt1","htxt1",fNColumns, 0., fNColumns, fNRows, 0, fNRows);
  TH2F *htxt2 = new TH2F("htxt2","htxt2",fNColumns, 0., fNColumns, fNRows, 0, fNRows);

  //histogram to draw block id
  TH2F *hblk_id = new TH2F("hblk_id","hblk_id",fNColumns, 0., fNColumns, fNRows, 0, fNRows);
  
  //Draw Gridlines to identify blocks
  c1->SetGrid();
  h2->GetXaxis()->SetNdivisions(fNColumns);
  h2->GetYaxis()->SetNdivisions(fNRows);

  c2->SetGrid();
  h2->GetXaxis()->SetNdivisions(fNColumns);
  h2->GetYaxis()->SetNdivisions(fNRows);


  //--Fill Blocks with Information--
  for(int i=0; i<blk_id_clust.size(); i++){

    //SetBinContent(jcol, irow, cluster_id)   
    h2->SetBinContent(jcol_vec.at(i), irow_vec.at(i),  iCluster_clust.at(i));           
    
    //draw text at (jcol-0.5, irow-0.5, text) | the 0.5 offset is so it displays at center of block
    htxt1->Fill(jcol_vec.at(i)-0.5, irow_vec.at(i)-0.5, iCluster_clust.at(i));     
    htxt2->Fill(jcol_vec.at(i)-0.5, irow_vec.at(i)-0.5, energy_clust.at(i));     

    hblk_id->Fill(jcol_vec.at(i)-0.5, irow_vec.at(i)-0.5, blk_id_clust.at(i)); 

  }
  
  //-Aesthetics
  //Set x-y tick label size
  h2->GetXaxis()->SetLabelSize(xtick_size);
  h2->GetYaxis()->SetLabelSize(ytick_size);
  
  //Set text font size
  htxt1->SetMarkerSize(marker_size);
  htxt2->SetMarkerSize(marker_size);

  hblk_id->SetMarkerSize(marker_size);
  hblk_id->SetMarkerColor(kRed);
  
  //set text offset, 0.2, 0.4, 0, etc
  htxt1->SetBarOffset(-0.2);   
  htxt2->SetBarOffset(-0.2);   

  hblk_id->SetBarOffset(0.2);   

  //set number of significant figures to display
  //gStyle->SetPaintTextFormat(".2f ");  
 
  //---Draw/Save canvas to root file---
  //c1->cd();
  //h2->Draw("COLZ");   
  //htxt1->Draw("TEXT SAME");  //clusters are color-coded
  //hblk_id->Draw("TEXT SAME");

  c2->cd();
  h2->Draw("COLZ");   
  htxt2->Draw("TEXT SAME");  //energy is color-coded
  hblk_id->Draw("TEXT SAME");

  fout->cd();
  //c1->Write();
  c2->Write();
  fout->Close();

}

int make_grid(string detec="", string clust_method="", int evMin=0, int evMax=0) {

  
  //prevent root from displaying histos
  gROOT->SetBatch(1);

  //NOTE: Selecting a range of up to ~ 1000 events is sufficient. Too many events cannot be handled as each event need to be written to root Canvas, which takes space.

  
  //Check if there exists an nps_grid.root file. If it does not exist, create it, otherwise, delete it.
  
  //----USER INPUT-----
  //string detec = "NPS";  //"NPS" or "SHMS"
  //string clust_method = "CellularAutomata"; 
  //string clust_method = "Standard";
  
  //Input Fule Name
  string ifname = detec + "_" + clust_method + "_Cal_Grid.csv";
  
  //Output File Name
  string ofname = detec + "_" + clust_method + "_Cal_Grid.root";
  
  
  //---------------------
  
  
  //Check if Output ROOTFile exists
  if(gSystem->AccessPathName(ofname.c_str())){
    
    std::cout << "file does not exist, will create/update it . . ." << std::endl;
    
  } else {
    
    std::cout << "file exists . . . will delete/overwrite it . . ." << std::endl;
    gSystem->Exec(Form("rm %s", ofname.c_str()));
  }
  
  
  //----Read CSV data file from NPS------
  
  //open file to be read
  ifstream file;
  file.open(ifname.c_str());
  
  //temporarily store read-in variables 
  int evNum, Nclusters, iCluster, blk_id;
  double time, energy;

  int counter = 0;
  
  //vectors to store temporary read-in variables
  vector<int>    evNum_vec;
  vector<int>    Nclusters_vec;
  vector<int>    iCluster_vec;
  vector<int>    blk_id_vec;
  vector<double> time_vec;
  vector<double> energy_vec;
  
  //string to read in each line
  string line;
  
  vector<string> parsed;

  
  //Check if dat file is open
  if(file.is_open()){
    
    //Loop over and get each line
    while (getline(file, line)){
      
      //ignore commented lines (headers or unwanted lines)
      if(line[0]=='#') continue;

      
      //parse each line based on delimiter ','
      parsed = parse_line(line, ',');
      
      //trim each parsed element, and convert accordingly to a number (int, double, etc.)
      evNum      = stoi(trim(parsed[0]));
      Nclusters  = stoi(trim(parsed[1]));
      iCluster   = stoi(trim(parsed[2]));
      blk_id     = stoi(trim(parsed[3]));
      time       = stod(trim(parsed[4]));
      energy     = stod(trim(parsed[5]));

      if(evNum > evMin && evNum < evMax) {
	//Add variables read-in to vector (each vector contains an entire columns of variables)
	evNum_vec.push_back(evNum); 
	Nclusters_vec.push_back(Nclusters);
	iCluster_vec.push_back(iCluster);
	blk_id_vec.push_back(blk_id);
	time_vec.push_back(time);
	energy_vec.push_back(energy);
      }
      
    } //end read line
    
  } //end file.open()

  //----------------------------------------
  
  //variable to store previous event number
  int prev_ev; 
  
  //vectors to store grouped block hits (event clusters)
  vector<int>    evNum_clust;
  vector<int>    Nclusters_clust;
  vector<int>    iCluster_clust;
  vector<int>    blk_id_clust;
  vector<double> time_clust;
  vector<double> energy_clust;
  
  
  //----Loop over the full event vector (contains multiple events grouped)-----
  for(int i=0; i<evNum_vec.size(); i++){
    
    
    //Get a starting event number and store as previous, for comparison with next event
    if(i==0){   prev_ev = evNum_vec.at(i); } 
    
    //Check that current event = previous event ("SAME EVENT (grouped)")
    if (evNum_vec.at(i) == prev_ev)
      {	
	evNum_clust.push_back(evNum_vec.at(i));
	Nclusters_clust.push_back(Nclusters_vec.at(1));
	iCluster_clust.push_back(iCluster_vec.at(i));
	blk_id_clust.push_back(blk_id_vec.at(i));
	time_clust.push_back(time_vec.at(i));
	energy_clust.push_back(energy_vec.at(i));
      }
    
    //Check if new event found
    else if (evNum_vec.at(i) > prev_ev){
      
      cout << "Events Completed: " << std::setprecision(2) << float(counter) / evNum_vec.size() * 100. << "  % " << std::flush << "\r";

      //If new event encountered, plot 2d grid of clustered block hits (from previous event)
      plot_cal(evNum_clust, Nclusters_clust, iCluster_clust, blk_id_clust, time_clust, energy_clust, detec, clust_method, ofname);      
    
      //Clear previous event cluster to fill new cluster
      evNum_clust.clear();
      Nclusters_clust.clear();
      iCluster_clust.clear();
      blk_id_clust.clear();
      time_clust.clear();
      energy_clust.clear();
      
      //Add 1st event of new cluster
      evNum_clust.push_back(evNum_vec.at(i));
      Nclusters_clust.push_back(Nclusters_vec.at(1));
      iCluster_clust.push_back(iCluster_vec.at(i));
      blk_id_clust.push_back(blk_id_vec.at(i));
      time_clust.push_back(time_vec.at(i));
      energy_clust.push_back(energy_vec.at(i));

      counter++;
    }
    
    //Check for last event
    if (i==(evNum_vec.size()-1)) {
      
      //If last entry encountered, plot 2d grid of block hits from last vector
      plot_cal(evNum_clust, Nclusters_clust, iCluster_clust, blk_id_clust, time_clust, energy_clust, detec, clust_method, ofname);      
      
    }
    
    prev_ev = evNum_vec.at(i);

  }//end loop over event vector

  
  return 0;
  
}
