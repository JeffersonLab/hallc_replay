#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

void get_tzero_param()
{


  ofstream ofs;
  TString tzero = "../data_files/run488/test_tzero_out_488.dat";
  ofs.open (tzero);
  
  //TString c[12] = {"1u1","1u2","1x1","1x2","1v1","1v2","2u1","2u2","2x1","2x2","2v1","2v2"}; 
  TString planes[2] = {"1u1", "1u2"};
  
  
  int group;
  int sw;
  int ip;

  //Loop oer each plane
  for(ip=0; ip<2; ip++) {

    cout << "******PLANE " << planes[ip] << "*******" << endl;

    //open and read each wire tzero file
    ifstream ifs;
    ifs.open("../data_files/run488/hdc_"+planes[ip]+"tzero_run488_updated.txt");



    Int_t wire[107]={0};
    Double_t t0[107]={0.0};
    Double_t t0_err[107]={0.0};
    Double_t entries[107]={0};
 
    
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



    //Initialize variables to calculates weighted avg by group
    Double_t sum_NUM[7]={0.0}; 
    Double_t sum_DEN[7]={0.0}; 
    Double_t weighted_AVG[7]={0.0};
    Double_t weighted_AVG_err[7]={0.0};


 //Loop over each ribbon cable group of wires
   for (group =1; group <=7; group++) {

     cout << "****GROUP***" << group << endl;

      for (sw = 1; sw<=107; sw++) {

	//Define boolean operations for ribbon cable groups
    	Bool_t dc1u1_g1 = ip==0 && group==1 && sw>0 && sw <=15;
	Bool_t dc1u1_g2 = ip==0 && group==2 && sw>=16 && sw <=31;
	Bool_t dc1u1_g3 = ip==0 && group==3 && sw>=32 && sw <=47;
	Bool_t dc1u1_g4 = ip==0 && group==4 && sw>=48 && sw <=63;
	Bool_t dc1u1_g5 = ip==0 && group==5 && sw>=64 && sw <=79;
	Bool_t dc1u1_g6 = ip==0 && group==6 && sw>=80 && sw <=95;
	Bool_t dc1u1_g7 = ip==0 && group==7 && sw>=96 && sw <=107;
            
 	

	//Define boolean operations for ribbon cable groups
    	Bool_t dc1u2_g1 = ip==1 && group==1 && sw>0 && sw <=12;
	Bool_t dc1u2_g2 = ip==1 && group==2 && sw>=13 && sw <=28;
	Bool_t dc1u2_g3 = ip==1 && group==3 && sw>=29 && sw <=44;
	Bool_t dc1u2_g4 = ip==1 && group==4 && sw>=45 && sw <=60;
	Bool_t dc1u2_g5 = ip==1 && group==5 && sw>=61 && sw <=76;
	Bool_t dc1u2_g6 = ip==1 && group==6 && sw>=77 && sw <=92;
	Bool_t dc1u2_g7 = ip==1 && group==7 && sw>=93 && sw <=107;
         

	if(dc1u1_g1) {
	  cout << "wire: " << wire[sw-1] <<endl;
	  cout << "t0: " << t0[sw-1] << endl;
	}
	else if(dc1u1_g2){
	  cout << "wire: " << wire[sw-1] <<endl;
	  cout << "t0: " << t0[sw-1] << endl;
	}
		else if(dc1u1_g3){
	  cout << "wire: " << wire[sw-1] <<endl;
	  cout << "t0: " << t0[sw-1] << endl;
	}
		else if(dc1u1_g4){
	  cout << "wire: " << wire[sw-1] <<endl;
	  cout << "t0: " << t0[sw-1] << endl;
	}
		else if(dc1u1_g5){
	  cout << "wire: " << wire[sw-1] <<endl;
	  cout << "t0: " << t0[sw-1] << endl;
	}
		else if(dc1u1_g6){
	  cout << "wire: " << wire[sw-1] <<endl;
	  cout << "t0: " << t0[sw-1] << endl;
	}
		else if(dc1u1_g7){
	  cout << "wire: " << wire[sw-1] <<endl;
	  cout << "t0: " << t0[sw-1] << endl;
	}

	//***********PLANE DC1 U2*************
	
	if(dc1u2_g1) {
	  cout << "wire: " << wire[sw-1] <<endl;
	  cout << "t0: " << t0[sw-1] << endl;
	}
	else if(dc1u2_g2){
	  cout << "wire: " << wire[sw-1] <<endl;
	  cout << "t0: " << t0[sw-1] << endl;
	}
		else if(dc1u2_g3){
	  cout << "wire: " << wire[sw-1] <<endl;
	  cout << "t0: " << t0[sw-1] << endl;
	}
		else if(dc1u2_g4){
	  cout << "wire: " << wire[sw-1] <<endl;
	  cout << "t0: " << t0[sw-1] << endl;
	}
		else if(dc1u2_g5){
	  cout << "wire: " << wire[sw-1] <<endl;
	  cout << "t0: " << t0[sw-1] << endl;
	}
		else if(dc1u2_g6){
	  cout << "wire: " << wire[sw-1] <<endl;
	  cout << "t0: " << t0[sw-1] << endl;
	}
		else if(dc1u2_g7){
	  cout << "wire: " << wire[sw-1] <<endl;
	  cout << "t0: " << t0[sw-1] << endl;
	}
	
   

   } //end loop over groups
      
   
      
    
 } //end loop over sense wires
 


  } // end loop over planes
    /*
    static const Int_t a = 0; 
  
    
    for (Int_t l=0; l<107; l++){

      
      // if (t0_err[l] == 0.0) return -1;

      //      cout << wire[l]<< endl;    
      if ((l>=a) && (l<=(a+b[k])) && (entries[l]>300)){
    
	t0_sum[0] = t0_sum[0] + ( t0[l] / (t0_err[l] * t0_err[l]));
	sigma_sum[0] = sigma_sum[0] + (1/(t0_err[l] * t0_err[l]));
	cout << wire[l]<< endl;
      }


      if (( l>=(a+b[k]+1)) && (l<=(a+b[k]+16)) && (entries[l]>300)){
    
	t0_sum[1] = t0_sum[1] + ( t0[l] / (t0_err[l] * t0_err[l]));
	sigma_sum[1] = sigma_sum[1] + (1/(t0_err[l] * t0_err[l]));
	cout << wire[l]<< endl;
      }

      if (( l>=(a+b[k]+17)) && (l<=(a+b[k]+32)) && (entries[l]>300)){
    
	t0_sum[2] = t0_sum[2] + ( t0[l] / (t0_err[l] * t0_err[l]));
	sigma_sum[2] = sigma_sum[2] + (1/(t0_err[l] * t0_err[l]));
	cout << wire[l]<< endl;
      }

      if (( l>=(a+b[k]+33)) && (l<=(a+b[k]+48)) && (entries[l]>300)){
    
	t0_sum[3] = t0_sum[3] + ( t0[l] / (t0_err[l] * t0_err[l]));
	sigma_sum[3] = sigma_sum[3] + (1/(t0_err[l] * t0_err[l]));
	cout << wire[l]<< endl;
      }

      if (( l>=(a+b[k]+49)) && (l<=(a+b[k]+64)) && (entries[l]>300)){
    
	t0_sum[4] = t0_sum[4] + ( t0[l] / (t0_err[l] * t0_err[l]));
	sigma_sum[4] = sigma_sum[4] + (1/(t0_err[l] * t0_err[l]));
	cout << wire[l]<< endl;
      }

      if (( l>=(a+b[k]+65)) && (l<=(a+b[k]+80)) && (entries[l]>300)){
    
	t0_sum[5] = t0_sum[5] + ( t0[l] / (t0_err[l] * t0_err[l]));
	sigma_sum[5] = sigma_sum[5] + (1/(t0_err[l] * t0_err[l]));
	cout << wire[l]<< endl;
      }

    
      if (( l>=(a+b[k]+81)) && (l<=(a+b[k]+93)) && (entries[l]>300)){
	//	cout << wire[l]<< endl;
	//	if (t0_err[l] == 0.0 || t0_err[l] == 0.0)
	  t0_sum[6] = t0_sum[6] + ( t0[l] / (t0_err[l] * t0_err[l]));
	  //	cout<<"to_sum[6]" << t0_sum[6] << endl;

	  //	if (t0_err[l] == 0.0 || t0_err[l] == 0.0)
	  sigma_sum[6] = sigma_sum[6] + (1/(t0_err[l] * t0_err[l]));
      	cout <<"sigma_sum[6]" <<sigma_sum[6]<< endl;
      }
      
    }  // wire loop

    
    t0_average[0] = (t0_sum[0] / sigma_sum[0]) ;
  
 
    cout << "t0_sum[0] : " << t0_sum[0] << endl;
    cout << "sigma_sum[0] : " << sigma_sum[0] << endl;
    cout << " t0_average [0] : " << t0_average[0] << endl;

    t0_average[1] = (t0_sum[1] / sigma_sum[1]) ;
  
 
    cout << "t0_sum[1] : " << t0_sum[1] << endl;
    cout << "sigma_sum[1] : " << sigma_sum[1] << endl;
    cout << " t0_average [1] : " << t0_average[1] << endl;

    t0_average[2] = (t0_sum[2] / sigma_sum[2]) ;

    t0_average[3] = (t0_sum[3] / sigma_sum[3]) ;

    t0_average[4] = (t0_sum[4] / sigma_sum[4]) ;

    t0_average[5] = (t0_sum[5] / sigma_sum[5]) ;

    t0_average[6] = (t0_sum[6] / sigma_sum[6]) ;
    cout << "t0_average[6] : " << t0_average[6] << endl;
    
    

    

    //put new values to t0
    
    for (Int_t l=0; l<107; l++){
          
      if ((l>=0) && (l<=14)){
    
	t0[l] = t0_average[0];
      
	cout << " new t0 : " << t0[l] << endl;
       
      }
      if ((l>=15) && (l<=30)){
    
	t0[l] = t0_average[1];
      
	cout << " new t0 : " << t0[l] << endl;
       
      }
     
      if ((l>=31) && (l<=46)){
    
	t0[l] = t0_average[2];
      
	cout << " new t0 : " << t0[l] << endl;
       
      }
     
      if ((l>=47) && (l<=62)){
    
	t0[l] = t0_average[3];
      
	cout << " new t0 : " << t0[l] << endl;
       
      }   
      if ((l>=63) && (l<=78)){
    
	t0[l] = t0_average[4];
      
	cout << " new t0 : " << t0[l] << endl;
       
      }   

      if ((l>=79) && (l<=94)){
    
	t0[l] = t0_average[5];
      
	cout << " new t0 : " << t0[l] << endl;
       
      }   

      if ((l>=95) && (l<107)){
    
	t0[l] = t0_average[6];
      
	cout << " new t0 : " << t0[l] << endl;

      } 


     
    } // wire loop

    cout << "ok "  << "for k = " << k << endl;





    //create a output file stream to write t0 for each wire for all planes 

    //ofstream ofs;
    //TString tzero = "../data_files/run464/test_tzero_out_464.dat";
    // ofs.open (tzero);

    cout << "PLANE = " << c[k] << endl;
    ofs << "PLANE = " << c[k] << endl;
 
    
    
    for (int ip=0; ip<107; ip++){
             
      //cout << "t_average_weighted: " << t0[ip] << endl; 
      if (wire[ip]>0)  ofs << t0[ip] << ", ";
    }
     

    ofs << "GOT HERE IN PLANE = " << c[k] << endl;
    
  

    //just testing 

    // Int_t number[2]={2,5,1};
    // TString number_1[2]={"1u1","b","c"};
    // for(Int_t j=0; j<3 ;j++) 
    //   cout << "number : " << number[j] << " number_1 : " << number_1[j] << endl;
    
} // ending for loop for planes

  ofs.close();
    */
   
}
  

