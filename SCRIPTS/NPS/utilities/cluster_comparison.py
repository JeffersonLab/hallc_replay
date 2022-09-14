import numpy as np
import LT.box as B
import csv
import matplotlib.pyplot as plt



def get_ncluster(run=-1, detec='', clust_method=''):

    evNum     = []
    Nclusters = []
    
    prev_ev = -1
    
    with open('./run_%d_grid/%s_%s_Cal_Grid.csv'%(run, detec, clust_method), 'r') as file:

        reader = csv.reader(file)
        #loop over data
        for col in reader:
            #skip commented lines
            if col[0][0]=='#': continue

            #check if previous event is NOT equal to current event
            if(col[0]!=prev_ev):
                evNum.append(int(col[0].strip())) 
                Nclusters.append(int(col[1].strip()))
                
            #store current event as prev event
            prev_ev = col[0]


    
    return (evNum, Nclusters)




def cluster_comparison():

    run = 10398
    
    print("Hello World!")

    evNum_SHMS_CA, Nclust_SHMS_CA = get_ncluster(run, "SHMS", "CellularAutomata")
    evNum_SHMS_St, Nclust_SHMS_St = get_ncluster(run, "SHMS", "Standard")

    evNum_NPS_CA, Nclust_NPS_CA = get_ncluster(run, "NPS", "CellularAutomata")
    evNum_NPS_St, Nclust_NPS_St = get_ncluster(run, "NPS", "Standard")
    

    

    #difference between number of clusters formed from each algorithm of a given calorimeter geometry
    #For SHMS: clusters are formed within 224 block boundary (16 col x 14 row)
    #For NPS: clusters are formed within 896 block boundary (32 col x 28 row)
    
    diff_SHMS = ( [i - j for (i, j) in zip(Nclust_SHMS_CA, Nclust_SHMS_St)] )
    diff_NPS = ( [i - j for (i, j) in zip(Nclust_NPS_CA, Nclust_NPS_St)] )

    fig = plt.figure(figsize=(8,6))
    plt.hist(diff_SHMS, 100, (-10,10), align='left', ec='black', color='green', alpha = 0.5, label=r'(SHMS Geometry)')
    plt.hist(diff_NPS, 100, (-10,10), align='left', ec='black', color='blue', alpha = 0.5, label=r'(NPS Geometry)')

   
    plt.title('Number of Clusters Difference (Run %d)' % (run))
    plt.xlabel(r'$\Delta N = N_{Cellular Automata} -N_{HCANA}$')
    plt.ylabel('Number of Events')
    plt.xticks(np.arange(-10,12,2))
    plt.legend(loc='upper left')
    
    plt.xlim(xmin=-10, xmax = 10)
    plt.yscale('log')
    plt.savefig('Overlay_NClustDiff_%d.pdf'%(run))
    plt.show('same')

    #-------------------------------------------------------------------

    fig = plt.figure(figsize=(8,6))
    plt.hist(Nclust_NPS_CA, 100, (0,10), align='left', ec='black', color='green', alpha = 0.5, label=r'Cellular Automata')
    plt.hist(Nclust_NPS_St, 100, (0,10), align='left', ec='black', color='blue', alpha = 0.5, label=r'HCANA')

   
    plt.title('Number of Clusters (NPS Geometry): Run %d' % (run))
    plt.xlabel(r'Number of Clusters, $N$')
    plt.ylabel('Number of Events')
    plt.xticks(np.arange(0,12,2))
    plt.legend(loc='upper right')
    
    plt.xlim(xmin=0, xmax = 10)
    plt.yscale('log')
    plt.savefig('Overlay_NClusters_%d.pdf'%(run))
    plt.show('same')




    
if __name__ == "__main__":
    cluster_comparison()

