/*
  The function cP2txG returns the value of the trinomial average of the three Discrete Compound Two-Stage Poisson distributions (DC2SP) with average second stage multiplicities (gains) Nu1, Nu2, and Nu3, convoluted with a normal Gaussian distribution with sigma s,
properly scaled to the <x>, <x0>, and <s> parameters producing a continuous function of x.
 */
Double_t cP2txG



void ppmt11(Double_t *x, Double_t *par)
{
  /*
    Function to fit NORMALIZED signal amplitude using Degtiarenko trinomial average of the three Discrete Compound Two-Stage Poisson distributions (DC2SPs) convoluted with a Gaussian

    11 fit parameters:
    Scale  = Par(1)            - ADC channels per 1 photoelectron
    Sigma  = Par(2)            - experimental resolution (in channels ADC)
    Mu     = Par(3)            - average photoelectron multiplicity
    Nu1    = Par(4)            - electron multiplicity at 2nd stage (1st dynode), 1-st component
    Alpha2 = Par(5)            - portion of the 2-nd component at the second stage
    Nu2    = Par(6)*Nu1        - electron multiplicity at the second stage, 2-nd component
    Alpha3 = Par(7)*(1-Alpha2) - res. portion of the 3-rd component at the second stage
    Nu3    = Par(8)*Nu1        - electron multiplicity at the second stage, 3-rd component
    Xi     = Par(9)            - average gain at the third stage (second dynode)
    Beta   = Par(10)           - Portion of Exp. Modified Gaussian in the Resolution Function
    Tau    = Par(11)           - Exp. Modified Gaussian "Temperature" normalized to Sigma units
    ****************
    The function required the input vector idvec(4) hich specifies the number of bins in input histogram and the range in x from xmin to xmax to allow proper normalization, the value of "mean" for the histogram
    
    nbins  = idvec(1)
    xmin   = idvec(2)
    xmax   = idvec(3)
    mean   = idvec(4)
    x0     = <Calculated>

    x0 = mean - Scale*Mu - Beta*Tau*Sigma
   */

  Float_t x,x0;
  Float_t Scale;
  Float_t Mu, Nu1, Alpha2, Nu2, Alpha3, Nu3, Xi, Sigma, Beta, Tau;
  Float_t sScale;
  Float_t sMu, sNu1, sAlpha2, sNu2, sAlpha3, sNu3, sXi, sSigma, sBeta, sTau;
  Float_t cP2txG, f;
  Float_t idvec, Par, mean, xmin, xmax, nbins, TauSPE;
  std::vector<ROOT::Math::XYZTVector> idvec(4);
  Int_t m0, m1;

  m0 = 0;
  m1 = 12; //Limits for m integration, for Few-Photoelectron studies
  f = 0;

  


}
