//script to write out individual wire tzero values, after being averaged out by groups of ribbon cables.

#define NPLANES 1

using namespace std;

void get_tzero_param () 
{

 
  int run_NUM;
  TString f0 = "input_RUN.txt";
  ifstream infile(f0);
  infile >> run_NUM;   
  
  TString run = Form("run%d", run_NUM);
  
  //Declare plane names to loop over
  TString plane_names[NPLANES]={"1u1"};
  
  
  //Loop over all planes
  for (int ip = 0; ip < NPLANES; ip++){
    
    
   

      //Loop over each ribbon cable group of wires
      
      for(int group = 1; group<=7; group++) {
	
	//open updated t0 dat file
    ifstream ifs;
    TString t_zero_file = "../data_files/" + run + "/hdc_"+plane_names[ip]+Form("tzero_run%d_updated.txt", run_NUM);
    ifs.open (t_zero_file);
    string line;
    
    int sensewire;
    int t_zero;
    int entries;
    double t_zero_err;
    
   
    
    //read line by line the t_zero_file
    while(getline(ifs, line)) {
      if(!line.length()|| line[0] == '#')
	continue;
      
      sscanf(line.c_str(), "%d %d %lf %d", &sensewire, &t_zero, &t_zero_err, &entries); //assign each of the variables above a data in the t_zero_file
        


	//boolean operator to define specific ribbon cable groups
	Bool_t dc1u1_g1 = ip==0 && group==1 && sensewire>0 && sensewire <=15;
	Bool_t dc1u1_g2 = ip==0 && group==2 && sensewire>=16 && sensewire <=31;
	Bool_t dc1u1_g3 = ip==0 && group==3 && sensewire>=32 && sensewire <=47;
	Bool_t dc1u1_g4 = ip==0 && group==4 && sensewire>=48 && sensewire <=63;
	Bool_t dc1u1_g5 = ip==0 && group==5 && sensewire>=64 && sensewire <=79;
	Bool_t dc1u1_g6 = ip==0 && group==6 && sensewire>=80 && sensewire <=95;
	Bool_t dc1u1_g7 = ip==0 && group==7 && sensewire>=96 && sensewire <=107;


	//Initialize variables to calculate weighted average
	double sum_NUM;  //numerator of weighted avg
	double sum_DEN;   //denominator of weighted avg
	double weighted_AVG;
	double weighted_AVG_err; 
	
	
	//set them to zero to start sum inside while loop 
	sum_NUM = 0.0;
	sum_DEN = 0.0;
	
	weighted_AVG = 0.0;
	weighted_AVG_err = 0.0;
	
	
	//calculate weighted average and write it out.
	
	if (dc1u1_g1) 
	  {
	    
	    cout << "group: " << group << " sensewire: " << sensewire << endl; 
	    
	  }
	
        else if (dc1u1_g2) 
	  {
	    cout << "group: " << group << " sensewire: " << sensewire << endl; 
	    //    else (cout << "there are no sensewires present " << endl;)
          }
	  
	 else if (dc1u1_g3) 
	  {
	    cout << "group: " << group << "  sensewire: " << sensewire << endl; 
	    //    else (cout << "there are no sensewires present " << endl;)
          }
	
         else if (dc1u1_g4) 
	  {
	    cout << "group: " << group << "  sensewire: " << sensewire << endl; 
	  }
	
	 else if (dc1u1_g5) 
	  {
	    cout << "group: " << group << "sensewire: " << sensewire << endl; 
          }
	 else if (dc1u1_g6) 
	  {
	    cout << "group: " << group << "sensewire: " << sensewire << endl; 
	  }
	 else if (dc1u1_g7) 
	  {
	    cout << "group: " << group << "sensewire: " << sensewire << endl; 
	  }
	
	
      } //end loop over group
      
    }  //end while loop over data file 
    
  }  // end loop over planes

}

