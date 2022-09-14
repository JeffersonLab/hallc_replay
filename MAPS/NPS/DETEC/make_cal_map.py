#!/usr/bin/python

# Python script to generate calorimeter map for testing NPS
# Author: C. Yero
# Date:   Jan 9, 2021
# email:  cyero@jlab.org

import numpy as np



#Choose which type of calorimeter map to create ('projection' or 'translation' or 'standard')
#where standard referes to the standard shms calorimeter map excluding the shms pre-shower

nps_map_type = "translation" 
#nps_map_type = "projection"
#nps_map_type = "standard"

#Set calorimter map name
caloMapName = 'pcal_nps_{}.map'.format(nps_map_type)


#SHMS Calorimeter Information
det_id = 26   #detector ID (for now, use SHMS calorimeter ID)
roc = 4       #Read-out controller crate (ROC) in which fADCs are located
slot = np.array([5, 6, 7, 8, 9, 10, 13, 14, 15, 16, 17, 18, 19, 20])   #fADC slot location

#1st shms calo block for each slot (originally it started at block 1 for SHMS, but for NPSApp, we have changed the software so it starts at block 0)
#shms_blk = np.array([0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208])


#1st shms calo block for each slot 
shms_blk = np.array([1, 17, 33, 49, 65, 81, 97, 113, 129, 145, 161, 177, 193, 209])


#--------------------------------------------------------------------
#1st NPS calo block mapped to each slot and the 1st shms calo block
#--------------------------------------------------------------------
#----NPS Blocks by projection (see shms_to_nps.key in current directory)-----
#get 1st nps block number per slot for PLANE=1 (central) (see shms_to_nps.key in current directory)
nps_block_proj1 = np.array([416, 384, 352, 320, 288, 256, 224, 192, 160, 128, 96, 64, 32, 0])
#get 1st nps block number per slot for PLANE=2 (left projection) (see map_projection.png)
nps_block_proj2 = np.array([448, 480, 512, 544, 576, 608, 640, 672, 704, 736, 768, 800, 832, 864])
#get 1st nps block number per slot for PLANE=3 (top projection) (see map_projection.png) : as chan 1 -> 16, nps chan 479 -> 464 so one needs to count opposite
nps_block_proj3 = np.array([479, 511, 543, 575, 607, 639, 671, 703, 735, 767, 799, 831, 863, 895])
#get 1st nps block number per slot for PLANE=4 (right projection) (see map_projection.png) : as chan 1 -> 16, nps chan 447 -> 432 so one needs to count opposite
nps_block_proj4 = np.array([447, 415, 383, 351, 319, 287, 255, 223, 197, 159, 127, 95, 63, 31])

#----NPS Blocks by translation (see shms_to_nps.key in current directory) -----
#get 1st nps block number per slot for PLANE=1 (central) 
nps_block_trans1 = np.array([416, 384, 352, 320, 288, 256, 224, 192, 160, 128, 96, 64, 32, 0])
#get 1st nps block number per slot for PLANE=2 (left translation) 
nps_block_trans2 = np.array([864, 832, 800, 768, 736, 704, 672, 640, 608, 576, 544, 512, 480, 448])
#get 1st nps block number per slot for PLANE=3 (top translation) 
nps_block_trans3 = np.array([880, 848, 816, 784, 752, 720, 688, 656, 624, 592, 560, 528, 496, 464])
#get 1st nps block number per slot for PLANE=4 (right translation) 
nps_block_trans4 = np.array([432, 400, 368, 336, 304, 272, 240, 208, 176, 144, 112, 80, 48, 16])


#Map information (to be written to file)
channel = 16                     #total number of channels per fADC module

if nps_map_type == "standard":
    plane   = np.array([1])
else:
    plane   = np.array([1,2,3,4])    #detector plane (since we only consider 4 copies of the shms shower counter to mimic NPS, then we need 4 planes, one plane for each projection or translation)
counter = 0                          #this variable will hold the actual detector element (block number for calorimeter)
signal  = 0                          #refers to which side of a plane one is referring to, since each copy of the shower has only one side (back-end) where signals are readout, then SIGNAL = 0.

#Reference Time Information
ref_roc  = 2    #create where ref. time is located
ref_slot = 14   #reference time slot
ref_idx  = 3    #reference time index
ref_ch   = 11   #reference time channel


#comments / header information
header_comment = """! SHMS Calorimeter Array ({}) signal Map 
! {} map for testing NPS software\n
 
! NPSCAL_ID=26  :: ADC

! general map format: (channel, plane, counter, signal)
! channel  ->  actual module channel being used (i.e., fADC chan 0,1,2,.. etc) 
! plane    ->  detector plane (since we only consider 4 copies of the shms shower array to mimic NPS, 4 planes are used)
! counter  ->  this variable will hold the actual detector element (block number for calorimeter)
! signal   ->  side of a plane: since each copy of the shower array has only one side (back-end) where signals are readout, then signal = 0 for each plane.

""".format(nps_map_type, nps_map_type)

header_info = """
DETECTOR={}

!reference time info
ROC={}
SLOT={}
REFINDEX={}
{}, 1000, 0, 3 ! pFADC_TREF_ROC2\n
ROC={}
""".format(det_id, ref_roc, ref_slot, ref_idx, ref_ch, roc)


# helper function to map the SHMS calorimeter blocks to those of NPS for testing
def get_NPS_block(iplane=0, slot_idx=0, map_type=""):

    if map_type=="projection":
        #central (actual calorimeter, not a projection) 
        if iplane==1:
            #check the slot number index so that the initial nps block can be assigned for that slot
            inps_blk = nps_block_proj1[slot_idx]
            return (inps_blk)
    
        #calorimeter LEFT projection 
        elif iplane==2:
            inps_blk = nps_block_proj2[slot_idx]
            return inps_blk
    
        #calorimeter TOP projection 
        elif iplane==3:
            inps_blk = nps_block_proj3[slot_idx]
            return inps_blk        

        #calorimeter RIGHT projection 
        elif iplane==4:
            inps_blk = nps_block_proj4[slot_idx]
            return inps_blk
    
    elif map_type=="translation":
        #central (actual calorimeter) 
        if iplane==1:
            #check the slot number index so that the initial nps block can be assigned for that slot
            inps_blk = nps_block_trans1[slot_idx]
            return inps_blk
    
        #calorimeter LEFT translation
        elif iplane==2:
            inps_blk = nps_block_trans2[slot_idx]
            return inps_blk
    
        #calorimeter TOP translation
        elif iplane==3:
            inps_blk = nps_block_trans3[slot_idx]
            return inps_blk        

        #calorimeter RIGHT translation 
        elif iplane==4:
            inps_blk = nps_block_trans4[slot_idx]
            return inps_blk        
    
# main function to create calorimter map
def make_cal_map():
    
    #open file in write mode
    f = open(caloMapName, "w")
    
    f.write(header_comment)
    f.write(header_info)
    
    #loop over each calorimeter projection (central, left, top, right)
    for ipl in plane:
        print("--------> PLANE = ", ipl)
        print("plane = ", len(plane))
        
        if nps_map_type == "standard":
            f.write("\n")
            f.write("!=====================================\n")
            f.write("!SHMS Standard Shower (fly's eye) Map\n")
            f.write("!(excluding pre-shower)\n")
            f.write("!=====================================\n")
        else:
            f.write("\n")
            f.write("!===============================\n")
            if (ipl==1):
                f.write("!Quadrant 0 (bottom right. {}) \n".format(nps_map_type))
            elif (ipl==2):
                f.write("!Quadrant 1 (bottom left. {}) \n".format(nps_map_type))
            elif (ipl==3):
                f.write("!Quadrant 3 (top left. {}) \n".format(nps_map_type))
            elif (ipl==4):
                f.write("!Quadrant 2 (top right. {}) \n".format(nps_map_type))
            f.write("!================================\n")

           
        #start loop over slots of Calorimeter ROC for each plane (projection) 
        for slot_idx, islot in enumerate(slot):

            f.write("\n")
            f.write("SLOT={}\n".format(islot))
            f.write("REFINDEX={}\n".format(ref_idx))

            #call function to get 1st nps block number given the projection and slot index
            nps_blk_proj = get_NPS_block(ipl, slot_idx, "projection")

            #call function to get 1st nps block number given the translation and slot index
            nps_blk_trans = get_NPS_block(ipl, slot_idx, "translation")

            if nps_map_type == "projection":
                counter = nps_blk_proj  #rename block with generic name counter
            elif nps_map_type == "translation":
                counter = nps_blk_trans  #rename block with generic name counter
            elif nps_map_type == "standard":
                counter = shms_blk[slot_idx]
                
            #loop over each of the 16 channels per adc slot
            for ichan in range(channel):
                
                #write the info per channel to map file
                f.write("{}, {}, {}, {}\n".format(ichan, ipl, counter, signal ))
                
                if nps_map_type == "projection":            
                    if(ipl==1 or ipl==2):
                        print('slot_idx=', slot_idx, 'islot=',islot, 'nps_blk_proj=',counter)
                        counter  += 1     #increment nps block number counter
                    elif(ipl==3 or ipl==4):
                        counter -= 1     #decrease nps block number counter
                        print('slot_idx=', slot_idx, 'islot=',islot, 'nps_blk_proj=',counter)
                if nps_map_type == "translation" or "standard":            
                        counter  += 1   #increment nps block number counter

                        
                
if __name__ == "__main__":
    make_cal_map()




