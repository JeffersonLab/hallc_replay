#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

#define NPLANES 12
#define GROUP 7

void get_tzero_param()
{


  
  //TString c[12] = {"1u1","1u2","1x1","1x2","1v1","1v2","2u1","2u2","2x1","2x2","2v1","2v2"}; 
  TString planes[NPLANES] = {"1u1","1u2","1x1","1x2","1v1","1v2","2u1","2u2","2x1","2x2","2v1","2v2"};
  
  int fNWires[NPLANES] = {107, 107, 79, 79, 107, 107, 107, 107, 79, 79, 107, 107};
  int group_size[NPLANES] = {7, 7, 5, 5, 7, 7, 7, 7, 5, 5, 7, 7};
  
  int group;
  int sw;
  int ip;
  
  
    Double_t *sum_NUM; 
    Double_t *sum_DEN; 
    Double_t *weighted_AVG;
    Double_t *weighted_AVG_err;
   

  //Initialize variables to calculates weighted avg by group
    Double_t sum_NUM[NPLANES][GROUP]={0.0}; 
    Double_t sum_DEN[NPLANES][GROUP]={0.0}; 
    Double_t weighted_AVG[NPLANES][GROUP]={0.0};
    Double_t weighted_AVG_err[NPLANES][GROUP]={0.0};
   
    
    Int_t *wire;
    Double_t *t0;
    Double_t *t0_err;
    Int_t *entries;
  
  //first sense wire in a given group of a given plane
  Int_t dc_group_min[NPLANES][GROUP] = {
    {1, 16, 32, 48, 64, 80, 96},           //plane 0 (1u1)
    {1, 13, 29, 45, 61, 77, 93},           //pane 1 (1u2)
    {1, 17, 33, 49, 65},   //plane 2(1x1)
    {},   //plane 3(1x2)
    {},   //plane 4(1v1)
    {},   //plane 5(1v2)
    {},   //plane 6(2u1)
    {},   //plane 7(2u2)
    {},   //plane 8(2x1)
    {},   //plane 9(2x2)
    {},   //plane 10(2v1)
    {}   //plane 11(2v2)

  };
  
  //last sense wire in a given group of a given plane
  Int_t dc_group_max[NPLANES][GROUP] = {
    {15, 31, 47, 63, 79, 95, 107},           //plane 0 (1u1)
    {12, 28, 44, 60, 76, 92, 107},           //pane 1 (1u2)
    {},   //plane 2(1x1)
    {},   //plane 3(1x2)
    {},   //plane 4(1v1)
    {},   //plane 5(1v2)
    {},   //plane 6(2u1)
    {},   //plane 7(2u2)
    {},   //plane 8(2x1)
    {},   //plane 9(2x2)
    {},   //plane 10(2v1)
    {}   //plane 11(2v2)




  };

  
  
  //Loop oer each plane
  for(ip=0; ip<NPLANES; ip++) {
    



    wire = new Int_t[fNWires[ip]];
    t0 = new Double_t[fNWires[ip]];
    t0_err = new Double_t[fNWires[ip]];
    entries = new Int_t[fNWires[ip]];

    cout << "******PLANE " << planes[ip] << "*******" << endl;
    
    //open and read each wire tzero file
    ifstream ifs;
    ifs.open("../data_files/run488/hdc_"+planes[ip]+"tzero_run488_updated.txt");
    


    
    
    if (ifs.is_open()) {
      cout << "File opened!" << endl;
      ifs.ignore(50000, '\n');    //ignore the first line 
      
      for (sw=0; sw<107; ++sw) {
	ifs >> wire[sw] >> t0[sw] >> t0_err[sw] >> entries[sw];
	//	cout
	//  << "wire: " << wire[iw] << "  "
	//  << "t0: " << t0[iw] << "  "
	//  << "t0_err: " << t0_err[iw] << "  "
	//  << "entries: " << entries[iw] << endl;
      } 
      ifs.close();
    }  // ifstream condition
    else {
      cout << "File not opened!" << endl;
    }



    
    //Loop over each ribbon cable group of wires
    for (group =0; group<GROUP; group++) {
      
      //  cout << "****GROUP***" << group << endl;


      for (sw = 1; sw<=107; sw++) {
	
	// cout << "min: " << dc_group_min[ip][group] << endl;
	if (sw >= dc_group_min[ip][group] && sw <= dc_group_max[ip][group] && t0[sw-1]!=0) {
	  
	  //calculate numerator and denominator of weighted average for each group
	 
	  sum_NUM[ip][group] = sum_NUM[ip][group] + t0[sw-1]/(t0_err[sw-1]*t0_err[sw-1]);
	  sum_DEN[ip][group] = sum_DEN[ip][group] + 1.0/(t0_err[sw-1]*t0_err[sw-1]);  
	}
	
      } // end loop over sensewires
     
      if (sum_NUM[ip][group]!=0 && sum_DEN[ip][group]!=0) {
	weighted_AVG[ip][group] = sum_NUM[ip][group] / sum_DEN[ip][group] ;
	weighted_AVG_err[ip][group] = sqrt( 1.0 / sum_DEN[ip][group] );
      }
      else {weighted_AVG[ip][group] = 0.0;}

      //  cout << "W_AVG_group: " << ": " << weighted_AVG[ip][group] << endl;

    } //end loop over groups
    
  } //end loop over planes

 


  //Write tzero values to a paramete file
  
  //Create an output file to store lookup values 
  ofstream ofs;
  TString wire_tzero = "./wire_tzero.param";
  ofs.open (wire_tzero);

  

  //loop over planes
  for (ip = 0; ip < NPLANES; ip++) 
    {
      //write plane headers
      ofs << "plane_"+planes[ip] << "=";
      
      cout << "****plane:**** " << ip << endl;
      //loop over group
      for (group = 0; group < GROUP; group++)
	{
	  cout << "****group:**** " << group << endl;
	  //loop over sensewires
	  for (sw = 1; sw<=107; sw++) {
	    
	    if (sw >= dc_group_min[ip][group] && sw <= dc_group_max[ip][group]) 
	      {
		
	
		if (sw<fNWires[ip])
		  {
		    ofs << setprecision(7) << weighted_AVG[ip][group] << ((sw+1) % 15 ? ", " : "\n") << fixed;
		  }
		else {ofs << setprecision(7) << weighted_AVG[ip][group] << fixed << endl;}
	
	    
		  
	     
	      }
	  } // end loop over sensewires
	  
	  
	} 
      

    }


}

      
   
      
    
 

    
    
   

  

