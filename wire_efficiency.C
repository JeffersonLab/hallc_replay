//Calculate wire efficiencies for All Planes in HMS DC1
#include "TMath.h"

#define NP 6
void wire_efficiency ()
{

  Double_t deg2rad = TMath::Pi() / 180.;

  //********************************************************************
  //*********DECLARE VARIABLES TO BE READ FROM PARAM FILE***************
  //********************************************************************

  //d. chamber position from focal plane
  TString plane_name[NP];
  Double_t hdc_zpos[NP];                   //z-distance from focal plane to dc center
  Double_t hdc_plane_zpos[NP];              //z-distance from dc center to dc planes

  //Declare Chamber rotation angles in radians
  Double_t alpha[NP];            //rotation about the hut z-axis, from chi (axis || to sense wires ) towards the +x axis (defined wire orientation)
  Double_t beta[NP];             //rotation about the hut y-axis, towards the z-axis 
  Double_t gamma[NP];            //rotation about the hut x-axis (longitudinal or dispersive axis)

  //Declare d. chamber plane pos parameters 
  Int_t fNWires[NP];             //total number of wires in each plane
  Double_t fPitch[NP];           //distance between sense wires in cm   
  Double_t fCentralWire[NP];     //defines the central wire in a plane (which may not correspond to an actual wire, just the geometrical center)
  Double_t fXCenter[NP];         //defines the offset along x-axis from geometrical center
  Double_t fYCenter[NP];         //defines the offset along y-axis from geometrical center
  Double_t fWireOrder[NP];       //describes the order in which wires are counter (1== count 1st wire at +x(or +y) axis :: 0== count 1st wire at -x(or -y) axis)

  //*****************************************************************************
  //**************************READ PARAMETER FILE********************************
  //*****************************************************************************

  //Declare variable to be calclated from param variables
  Double_t z_0[NP];                            //distance from focal plane to dc planes
  Double_t z_t[NP];                            //same as above (included alpha, beta, gamma chamber small rotations)
  Double_t fCenter[NP];                        //offset from geometrical center from z-axis in hit

  
  ifstream infile ("hms_dc.param");  //
  int index = 0;
  string line;  
    
  while(getline(infile, line))
    {
      if (line[0] != "#") 
	{
	  istringstream iss(line);
	  
	  while (!infile.eof() && index < NP)
	    {
	      infile >> plane_name[index];
	      infile >> fNWires[index];
	      infile >> fPitch[index];
	      infile >> fCentralWire[index];
	      infile >> fXCenter[index];
	      infile >> fYCenter[index];
	      infile >> fWireOrder[index];
	      infile >> hdc_zpos[index];
	      infile >> hdc_plane_zpos[index];
	      infile >> alpha[index];
	      infile >> beta[index];
	      infile >> gamma[index];
	      alpha[index] = alpha[index]*deg2rad;
	      beta[index] = beta[index]*deg2rad;
	      gamma[index] = gamma[index]*deg2rad;
	      
	      
	      //calculate z coordinate and chamber offset from center
	      z_0[index] = hdc_zpos[index] + hdc_plane_zpos[index]; 
	      z_t[index] = z_0[index] + sin(alpha[index])*sin(beta[index]) + 
		cos(alpha[index])*sin(gamma[index])*cos(beta[index]);
	      fCenter[index] = fXCenter[index]*sin(alpha[index]) + fYCenter[index]*cos(alpha[index]);
	      
	      index ++;
	    }
	}
    }
   

 //**********************************************************************************************

  //read input root file
  TFile *f=new TFile("./ROOTfiles/hms_replay_303_dist_corr.root");
  TTree *tree=(TTree*)f->Get("T");


  //************************************************************************************************
  //******************Declare variables to be addressed by the TTree********************************
  //************************************************************************************************

  Double_t x_fp;                         //x-coord at focal plane (best chi-squared track)
  Double_t y_fp;                         //y-coord at focal plane (best chi-squared track)
  Double_t xp_fp;                        //xp-coord (dx/dz or theta) at focal plane (best chi-squared track)
  Double_t yp_fp;                        //yp-coord (dy/dz or phi) at focal plane (best chi-squared track)

  
  //Declare wire numbers array for each plane
  Double_t H_dc_1x1_wirenum[113];       
  Double_t H_dc_1y1_wirenum[52];
  Double_t H_dc_1u1_wirenum[107];
  Double_t H_dc_1v1_wirenum[107];
  Double_t H_dc_1y2_wirenum[52];
  Double_t H_dc_1x2_wirenum[113];
  
  //Declare NData for wire numbers (total number of hits per event per plane)
  Int_t Ndata_H_dc_1x1_wirenum;
  Int_t Ndata_H_dc_1y1_wirenum;
  Int_t Ndata_H_dc_1u1_wirenum;
  Int_t Ndata_H_dc_1v1_wirenum;
  Int_t Ndata_H_dc_1y2_wirenum;
  Int_t Ndata_H_dc_1x2_wirenum;
 
  tree->SetBranchAddress("H.dc.x_fp",&x_fp);
  tree->SetBranchAddress("H.dc.y_fp",&y_fp);
  tree->SetBranchAddress("H.dc.xp_fp",&xp_fp);
  tree->SetBranchAddress("H.dc.yp_fp",&yp_fp);

  tree->SetBranchAddress("H.dc.1x1.wirenum",&H_dc_1x1_wirenum);
  tree->SetBranchAddress("H.dc.1y1.wirenum",&H_dc_1y1_wirenum);
  tree->SetBranchAddress("H.dc.1u1.wirenum",&H_dc_1u1_wirenum);
  tree->SetBranchAddress("H.dc.1v1.wirenum",&H_dc_1v1_wirenum);
  tree->SetBranchAddress("H.dc.1y2.wirenum",&H_dc_1y2_wirenum);
  tree->SetBranchAddress("H.dc.1x2.wirenum",&H_dc_1x2_wirenum);

  tree->SetBranchAddress("Ndata.H.dc.1x1.wirenum",&Ndata_H_dc_1x1_wirenum); 
  tree->SetBranchAddress("Ndata.H.dc.1y1.wirenum",&Ndata_H_dc_1y1_wirenum);
  tree->SetBranchAddress("Ndata.H.dc.1u1.wirenum",&Ndata_H_dc_1u1_wirenum); 
  tree->SetBranchAddress("Ndata.H.dc.1v1.wirenum",&Ndata_H_dc_1v1_wirenum);
  tree->SetBranchAddress("Ndata.H.dc.1y2.wirenum",&Ndata_H_dc_1y2_wirenum); 
  tree->SetBranchAddress("Ndata.H.dc.1x2.wirenum",&Ndata_H_dc_1x2_wirenum);

  //***********************************************************************************


  //Declare coordinates at the planes (projected by the track at the focal plane)
  Double_t x_t[NP];            //x-coord of the track at the plane in question 
  Double_t y_t[NP];            //y-coord of the track at the plane in question 
  Double_t psi[NP];            //local wire coordinate (perpendicular to chi (which lies || to the wires) )


  //Declare arrays to store wire efficiency
  Double_t eff;
  Double_t eff_err;

  //Declare and initialize hit counters
  Int_t hit_counter = 0;         //counts total number of wires hit per event related to the track   
  Int_t nohit_counter = 0;       //counts total number of wires that fires, but not related to track
  
  Double_t hit[NP][113] = {0.};     //counts and stores in an array only one hit per event (given that the hit and track are related)
  Double_t no_hit[NP][113] = {0.};  //counts and stores in an array only one "no-hit", provided that hit_counter == 0


  //declare wire number hit (to be determined by projecting the track to the plane that was hit)
  Double_t wire_num[NP];
  
  //declare wire number that actually fired in each plane
  Int_t wirenum1x1;
  Int_t wirenum1y1;
  Int_t wirenum1u1;
  Int_t wirenum1v1;
  Int_t wirenum1y2;
  Int_t wirenum1x2;
    

  //Get the total number of entries (triggers)
  Int_t nentries=tree->GetEntries();
  
  //*********************************************************************************************************
  //*****************************************LOOP OVER ALL ENTRIES*******************************************
  //*********************************************************************************************************

  for(int i=0; i<100000; i++)
    {
      
      tree->GetEntry(i);
      
      if ( abs(x_fp) < 80 && abs(y_fp) < 40)    //require track coord to be within chamber geometry (not count bad events outside chamber)  
	{
	  
	  //****************************
	  //****LOOP OVER ALL PLANES****
	  //****************************
	  for (int ip=0; ip<NP; ip++)
	    {
	   
	      //project focal plane quantities to HMS DC Planes
	      x_t[ip] = z_t[ip]*tan(xp_fp) + x_fp;
	      y_t[ip] = z_t[ip]*tan(yp_fp) + y_fp;
	  
	      //Convert focal plane coord. at plane to wire local coordinates (Psi) (in X-Plane)
	      psi[ip] = (sin(alpha[ip]) * cos(beta[ip]) - cos(alpha[ip])*sin(gamma[ip])*sin(beta[ip]))*x_t[ip] +
		cos(alpha[ip])*cos(gamma[ip])*y_t[ip];
	
	       
	      //Check wire orientation in a given plane to determine which formula to use to determine wire hit from track projection:
	      if (fWireOrder[ip]==0) 
		{
		  wire_num[ip] = (psi[ip] + fCenter[ip]) / fPitch[ip] + fCentralWire[ip] - 1;
		}
	  
	      else if (fWireOrder[ip]==1) 
		{
		  wire_num[ip] = -1.0 * ( (psi[ip] + fCenter[ip]) / fPitch[ip]  + fCentralWire[ip] - fNWires[ip] );
		}
       
	      //Determine if the wire got hit (or not) for each plane
	     
	      if(ip==0) 
		{
		  
		  hit_counter = 0;  //reset hit counter to zero
		  nohit_counter = 0; //reset no hit counter to zero 
	    
		  //Loop over all wires that were hit in the event
		  for (int j=0; j< Ndata_H_dc_1x1_wirenum; j++)
		    {
		      wirenum1x1 = int(H_dc_1x1_wirenum[j]);
		  
		      //Count wire hit as true hit if wirenumber difference is less than or equal to one
		      if(abs(wirenum1x1 - wire_num[ip]) <= 1. && wirenum1x1 <=113)
			{
			  hit_counter = hit_counter + 1;   // count as a hit if wire number difference < 1
		     	}
		     
		      else if (abs(wirenum1x1 - wire_num[ip]) > 1. && wirenum1x1 <=113) 
			{
			  nohit_counter = nohit_counter + 1;
			}
		    }
		 
		  //count if ONLY one wire was hit and corresponds to the wire hit from projecting the track  
		  if (hit_counter == 1)
		    {
		      hit[ip][wirenum1x1-1] = hit[ip][wirenum1x1-1] + 1.;
		    }
		  
		  //count as not hit if the wires hit from the track projection does NOT match the actual wire hit
		  else if (nohit_counter >=1 && hit_counter == 0 )
		    {
		      no_hit[ip][wirenum1x1-1]=no_hit[ip][wirenum1x1-1] + 1.;
		    }

		}
	  //*****************************************************************************************************
	                          //PERFORM SAME OPERATIONS ABOVE FOR THE REMAINING PLANES
	    
	      if(ip==1) 
		{ 
		  hit_counter = 0;  
		  nohit_counter = 0; 
        
		  for (j=0; j< Ndata_H_dc_1y1_wirenum; j++)
		    {
		      wirenum1y1 = int(H_dc_1y1_wirenum[j]);  
 
		      if(abs(wirenum1y1 - wire_num[ip]) <=1. && wirenum1y1 <= 52) 
			{
			  hit_counter = hit_counter + 1;  
			}
		   
		      else if (abs(wirenum1y1 - wire_num[ip]) > 1. && wirenum1y1 <= 52) 
			{
			  nohit_counter = nohit_counter + 1;
			}
		    }
	     
		  if (hit_counter == 1)
		    {
		      hit[ip][wirenum1y1-1] = hit[ip][wirenum1y1-1] + 1.; 
		    }
	     
		  else if (nohit_counter >=1 && hit_counter == 0 )
		    {
		      no_hit[ip][wirenum1y1-1]=no_hit[ip][wirenum1y1-1] + 1.;
		    }
		}	  
	      //*****************************************************************************************************
	  
	      if(ip==2) 
		{ 
		  hit_counter = 0;  
		  nohit_counter = 0; 
		  
		  for (j=0; j< Ndata_H_dc_1u1_wirenum; j++)
		    {
		      wirenum1u1 = int(H_dc_1u1_wirenum[j]);  
		      if(abs(wirenum1u1 - wire_num[ip]) <=1. && wirenum1u1 <= 107) 
			{
			  hit_counter = hit_counter + 1;  
			}
		
		      else if (abs(wirenum1u1 - wire_num[ip]) > 1. && wirenum1u1 <= 107) 
			{
			  nohit_counter = nohit_counter + 1;
			}
		    }
	       
		  if (hit_counter == 1)
		    {
		      hit[ip][wirenum1u1-1] = hit[ip][wirenum1u1-1] + 1.; 
		    }
	       
		  else if (nohit_counter >=1 && hit_counter == 0 )
		    {
		      no_hit[ip][wirenum1u1-1]=no_hit[ip][wirenum1u1-1] + 1.;
		    }	       
		}	  

	      //*****************************************************************************************************
	  
	      if(ip==3) 
		{ 
		  hit_counter = 0;  
		  nohit_counter = 0;  
		  
		  for (j=0; j< Ndata_H_dc_1v1_wirenum; j++)
		    {
		      wirenum1v1 = int(H_dc_1v1_wirenum[j]);  
  
		      if(abs(wirenum1v1 - wire_num[ip]) <=1. && wirenum1v1 <= 107) 
			{
			  hit_counter = hit_counter + 1;  
			}
		
		      else if (abs(wirenum1v1 - wire_num[ip]) > 1. && wirenum1v1 <= 107) 
			{
			  nohit_counter = nohit_counter + 1;
			}
		    }
	     
		  if (hit_counter == 1)
		    {
		      hit[ip][wirenum1v1-1] = hit[ip][wirenum1v1-1] + 1.; 
		    }
	       
		  else if (nohit_counter >=1 && hit_counter == 0 )
		    {
		      no_hit[ip][wirenum1v1-1]=no_hit[ip][wirenum1v1-1] + 1.;
		    }
		}	  

	  //*****************************************************************************************************
	  
	      if(ip==4) 
		{ 
		  hit_counter = 0; 
		  nohit_counter = 0; 
	      
		  for (j=0; j< Ndata_H_dc_1y2_wirenum; j++)
		    {
		      wirenum1y2 = int(H_dc_1y2_wirenum[j]);  
  
	
		      if(abs(wirenum1y2 - wire_num[ip]) <=1. && wirenum1y2 <= 52) 
			{
			  hit_counter = hit_counter + 1;  
			}
		
		      else if (abs(wirenum1y2 - wire_num[ip]) > 1. && wirenum1y2 <= 52) 
			{
			  nohit_counter = nohit_counter + 1;
			}
		    }
	     
		  if (hit_counter == 1)
		    {
		      hit[ip][wirenum1y2-1] = hit[ip][wirenum1y2-1] + 1.; 
		    }
	       
		  else if (nohit_counter >=1 && hit_counter == 0 )
		    {
		      no_hit[ip][wirenum1y2-1]=no_hit[ip][wirenum1y2-1] + 1.;
		    }
	        }	  

	      //******************************************************************************************************************
	  
	      if(ip==5) 
		{ 
		  hit_counter = 0;  //reset hit counter to zero
		  nohit_counter = 0; //reset no hit counter to zero 
	      
		  for (j=0; j< Ndata_H_dc_1x2_wirenum; j++)
		    {
		      wirenum1x2 = int(H_dc_1x2_wirenum[j]);  
		      
		      if(abs(wirenum1x2 - wire_num[ip]) <=1. && wirenum1x2 <= 113) 
			{
			  hit_counter = hit_counter + 1;  
			}
		
		      else if (abs(wirenum1x2 - wire_num[ip]) > 1. && wirenum1x2 <= 113) 
			{
			  nohit_counter = nohit_counter + 1;
			}
		    }
	     
		  if (hit_counter == 1)
		    {
		      hit[ip][wirenum1x2-1] = hit[ip][wirenum1x2-1] + 1.; 
		    }
	       
		  else if (nohit_counter >=1 && hit_counter == 0 )
		    {
		      no_hit[ip][wirenum1x2-1]=no_hit[ip][wirenum1x2-1] + 1.;
		    }
	       
		}	  
	      
	      //******************************************************************************************************************

	    }  //end loop over all planes
	
	} // end if statement
   
    } //end loop over all triggers (nentries)


  ofstream ofile;    //create output file stream to write efficiency data
  TFile *eff_file = new TFile("./wire_efficiencies.root", "RECREATE");
  //Loop over each plane
  for (ip = 0; ip < NP; ip++) 
    {
      TString wire_eff = "wire_eff"+ plane_name[ip] +".dat";
      ofile.open(wire_eff);

  
      for (int wire = 0; wire < fNWires[ip]; wire++) 
	{
	  if ((no_hit[ip][wire] + hit[ip][wire])==0) 
	    {
	      eff = 0.;
	      eff_err = 0.;
	      ofile << wire+1 << "  " << eff << "  " << eff_err << endl;
	    }
	  else 
	    {
	      eff =  hit[ip][wire]/(no_hit[ip][wire] + hit[ip][wire]);
	      eff_err = TMath::Sqrt( hit[ip][wire]*no_hit[ip][wire] / TMath::Power( (hit[ip][wire] + no_hit[ip][wire]), 3) );
	      ofile << wire+1 << "  " << eff << "  " << eff_err << endl;
	    }
	}
      
      TGraphErrors *graph = new TGraphErrors(wire_eff, "%lg %lg %lg");
      graph->Write("wire_eff" + plane_name[ip]);  
      ofile.close();
    }
}


