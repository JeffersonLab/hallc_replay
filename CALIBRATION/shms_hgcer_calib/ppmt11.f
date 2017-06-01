      real function ppmt11(x)
C
C -- Function to fit the normalized signal amplitude distribution in Minuit
C    with the trinomial average of the three Discrete Compound Two-Stage Poisson
C    distributions (DC2SPs) convoluted with a Gaussian
C
C    11 fit parameters are: 
C      Scale  = Par(1)  - ADC channels per 1 photoelectron
C      Sigma  = Par(2)  - experimental resolution (in channels ADC)
C      Mu     = Par(3)  - average photoelectron multiplicity
C      Nu1    = Par(4)  - electron multiplicity at 2nd stage (1st dynode), 1-st component
C      Alpha2 = Par(5)  - portion of the 2-nd component at the second stage
C      Nu2    = Par(6)*Nu1 - electron multiplicity at the second stage, 2-nd component
C      Alpha3 = Par(7)*(1-Alpha2) - res. portion of the 3-rd component at the second stage 
C      Nu3    = Par(8)*Nu1 - electron multiplicity at the second stage, 3-rd component
C      Xi     = Par(9)  - average gain at the third stage (second dynode)
C      Beta   = Par(10)  - Portion of Exp. Modified Gaussian in the Resolution Function
C      Tau    = Par(11) - Exp. Modified Gaussian "Temperature" normalized to Sigma units
C    ----------------
C
C    The function requires the input vector idvec(4) which specifies the number of bins 
C    in the input histogram and the range in x from xmin to xmax to allow for proper 
C    normalization, the value of "mean" for the histogram
C
C      nbins  = idvec(1)
C      xmin   = idvec(2)
C      xmax   = idvec(3)
C      mean   = idvec(4)
C      x0     = <Calculated>
C
C      x0     = mean - Scale*Mu - Beta*Tau*Sigma
C
C     -- P.Degtiarenko, JLab, January 2015 --
C
      implicit NONE
      real x,x0
      real  Scale
      real  Mu, Nu1, Alpha2, Nu2, Alpha3, Nu3, Xi, Sigma, Beta, Tau
      real sScale
      real sMu,sNu1,sAlpha2,sNu2,sAlpha3,sNu3,sXi,sSigma,sBeta,sTau
      real cP2txG,f
      real idvec,Par,mean,xmin,xmax,nbins,TauSPE
      vector idvec(4)
      common/PAWPAR/Par(11)
      logical init,message,diagn
      common/reset/init,message,diagn
      integer m0,m1
      common/mlimits/m0,m1
      common/storpar/sScale,
     &     sMu,sNu1,sAlpha2,sNu2,sAlpha3,sNu3,sXi,sSigma,sBeta,sTau
      data init/.true./
      data message/.true./
      data diagn/.true./
c
      m0 = 0
      m1 = 12  ! Limits for m integration, for Few-Photoelectron studies
      f  = 0.
c
      Scale  = Par(1)
      Sigma  = Par(2)
      Mu     = Par(3)
      Nu1    = Par(4)
      Alpha2 = Par(5)
      Nu2    = Par(6)*Nu1
      Alpha3 = Par(7)*(1-Alpha2)
      Nu3    = Par(8)*Nu1
      Xi     = Par(9)
      Beta   = Par(10)
      Tau    = Par(11)
c
      nbins  = idvec(1)
      xmin   = idvec(2)
      xmax   = idvec(3)
      mean   = idvec(4)
c
      x0     = mean - Scale*Mu - Beta*Tau*Sigma
      TauSPE = Tau*Sigma/Scale
c
      if( sScale.ne.Scale.or.sSigma.ne.Sigma.or.sMu.ne.Mu.or.
     &    sNu1.ne.Nu1.or.sNu2.ne.Nu2.or.sNu3.ne.Nu3.or.
     &    sAlpha2.ne.Alpha2.or.sAlpha3.ne.Alpha3.or.sXi.ne.Xi.or.
     &    sBeta.ne.Beta.or.sTau.ne.Tau                           ) then
         init = .true.
         diagn = .true.
CCC         print *,  Par
      endif
c
      f = cP2txG(x/Scale,Mu,Nu1,Alpha2,Nu2,Alpha3,Nu3,Xi,Beta,TauSPE,
     &     Sigma/Scale,x0/Scale)/Scale*(xmax-xmin)/nbins
c
      sScale  = Scale 
      sSigma  = Sigma
      sMu     = Mu 
      sNu1    = Nu1
      sAlpha2 = Alpha2
      sNu2    = Nu2
      sAlpha3 = Alpha3
      sNu3    = Nu3
      sXi     = Xi
      sBeta   = Beta
      sTau    = Tau
c
 900  continue
      ppmt11 = f
      end
C
      real function 
     &     cP2txG(x,Mu,Nu1,Alpha2,Nu2,Alpha3,Nu3,Xi,Beta,Tau,s,x0)
C
C -- Returns the value of the trinomial average of the three
C    Discrete Compound Two-Stage Poisson distributions (DC2SP)
C    with average second stage multiplicities (gains) Nu1, Nu2, and Nu3,
C    convoluted with normal Gaussian distribution with sigma s, 
C    properly scaled to the <x>, <x0>, and <s> parameters -- 
C    producing a continuous function of x.
C    average third stage multiplicity (gain) <Xi> is set to all DC3SPs
C -- The resulting distribution is shifted by <x0> to model 
C    conditions of amplitude measurements with pedestal 
C    readings at zero signal, spread by a Gaussian noise.
C -- The variables <x>, <x0>, and <s> are in units in which "1"
C    corresponds to the amplitude of the event with exact multiplicity of 
C    <Mu> at the first stage, 
C    and <Num> at the second stage
C -- Integral from -infinity to +infinity of cP2txG(x)*dx = 1.0
C
C     -- P.Degtiarenko, JLab, November 2013 --
C
      implicit NONE
      integer n,k,nmid,nmin,nmax,nmin1,nmax1
      real    x,Mu,Nu1,Alpha2,Nu2,Alpha3,Nu3,Xi,Beta,Tau,Zeta,s,x0
      real    dxs,ddxs,xmin,xmax,avrNuS,sn
      double precision f,df,sqr2pi,xn,dsn,flog,SdPn,GmxEMG
      double precision xk,dfk,logfac
      double precision 
     &       dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi,dBeta,dTau,dZeta
      data dxs/8.5/
      common/comdxs/dxs ! -- Equivalent of the SAVE statement -- !
C
      f = 0.0D0
      if(Mu.le.0..or.Nu1.le.0..or.s.le.0.) then
         goto 900
      else
         dMu     = Mu
         dNu1    = Nu1
         dAlpha2 = Alpha2
         dNu2    = Nu2
         dAlpha3 = Alpha3
         dNu3    = Nu3
         dXi     = Xi
         dBeta   = Beta
         dTau    = Tau
         Zeta    = Xi
         dZeta   = Zeta
c -- Avoid zeros in Alphas ---
         if(dAlpha2.lt.0.1D-12) dAlpha2 = 0.1D-12
         if(dAlpha3.lt.0.1D-12) dAlpha3 = 0.1D-12
c
         avrNuS = Nu1*(1.-Alpha2-Alpha3) + Alpha2*Nu2 + Alpha3*Nu3
         nmid = max(int(avrNuS*(x-x0)),1)
         sn   = sqrt(s**2+nmid/avrNuS/avrNuS/Xi) ! Sigma counts 3rd stage
         ddxs = max(dxs*sn,abs(Tau)*16.0)
         xmin = x - ddxs
         xmax = x + ddxs
         if(x.lt.xmin.or.x.gt.xmax) goto 900
         nmin = max(int(avrNuS*(xmin-x0)),0)
         nmax = max(int(avrNuS*(xmax-x0)),nmin+1) 
         do n = nmin, nmax
            df = 0.0D0
            if(n.eq.0) then
               dsn = s
               xn  = x - x0
               df= SdPn(n,dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi)*
     &              GmxEMG(xn,dbeta,dsn,dtau)
            elseif(n.gt.3) then
               dsn = sqrt(s**2+n/avrNuS/avrNuS/Xi)
               xn  = x - x0 - n/avrNuS
               df  = SdPn(n,dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi)*
     &              GmxEMG(xn,dbeta,dsn,dtau)
            else ! -- Convolution with 3rd stage Poissonian close to x0 --
               dsn = s
               xk  = x - x0
               dfk = dexp(-n*dXi)*GmxEMG(xk,dbeta,dsn,dtau)
               df = df + dfk
               k  = 1
 150           continue
               xk  = x - x0 - k/Xi/avrNuS
               dsn = sqrt(s**2+k/avrNuS/avrNuS/Xi/Xi/Zeta)
               dfk = dexp(k*dlog(n*dXi)-n*dXi-logfac(k))*
     &              GmxEMG(xk,dbeta,dsn,dtau)
               df = df + dfk
               k  =  k + 1
               if((k.le.int(n*Xi).or.dfk*1.e8.gt.df).and.k.lt.1000) 
     &              goto 150
               df = df*SdPn(n,dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi)
            endif
            f  = f + df
         enddo
      endif
 900  continue
      cP2txG = f
      end
C
      double precision function logfac(n)
C     -- Returns logarithm of factorial of the integer argument n(>=0)
C        Stores results into the COMMON/lfact/lf(10000) block upon initialization
C        Outside the array uses Srinivasa Ramanujan's formula for factorial:
C        https://en.wikipedia.org/wiki/Stirling's_approximation
C        Section "Versions suitable for calculators"
C     -- P.Degtiarenko, JLab,  July 2016 --
C
      implicit NONE
      integer n,i,nf
      logical initlf
      data initlf/.TRUE./
      parameter (nf=10000)
      double precision lf(nf),di,factlg,pi,z
      common/lfact/lf
      data pi/3.1415926536D0/
      common/freset/initlf
      if(initlf) then
         lf(1) = 0.0D0
         lf(2) = 0.0D0
         do i = 3, nf
            di = i - 1.0D0
            lf(i) = lf(i-1) + log(di)
         enddo
         initlf = .FALSE.
      endif
      if(n.lt.nf) then
         factlg = lf(n+1)
      else
         z = n
         factlg = z*log(z)-z+(log(z*(1+4*z*(1+2*z))))/6+log(pi)/2
      endif
      logfac = factlg
      end
C
      double precision function 
     &     SdPn(n,dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi)
C     -- Returns value of the dPn(n) calculated once
C        Stores results into the COMMON/pnstore/StoredPn upon the
C        first call with this n and retrieves the value if called again
C        Outside the array length (=nspn) calculates dPn every time and
C        prints warning once
C        The logical variable init may be reset from outside using 
C        COMMON/reset/init -- the reset is needed every time parameters change
C
C     -- P.Degtiarenko, JLab,  November 2013 --
C
      implicit NONE
      integer n,i,nspn
      parameter (nspn=20000)
      double precision f,dPn,
     &            dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi
      double precision StoredPn(nspn)
      common/pnstore/StoredPn
      logical init,message,diagn
      common/reset/init,message,diagn
c      logical init,message
c      data message/.true./
c      common/reset/init
c
      if(init) then
         do i = 1, nspn
            StoredPn(i) = -1.0D0
         enddo
         init = .FALSE.
      endif
      if(n.ge.0.and.n.lt.nspn) then ! ******** Try not to go above nspn ******* !
         if(n.lt.nspn) then
            f = StoredPn(n+1)
            if(f.lt.0.D0) then
               f = dPn(n,dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi)
               StoredPn(n+1) = f
            endif
         else
            f = dPn(n,dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi)
            if(message) then
               print *, '%%%SdPn: n was outside the range: n=',n
               print *, '   ---   The calcs may take long time...'
               message = .FALSE.
               print *, dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi
            endif
         endif
      else
         f = 0.D0
      endif
      SdPn = f
      end
C
      double precision function 
     &     dPn(n,dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi)
C
C     -- Returns the value of the integral over the first stage "m" of the
C        Compound Two-Stage Poisson function Pmn(m,n)
C        function of n, the cascade multiplicities on second stage, starting at 0
C
C        dMu, dNu: average cascade multiplicities on first and second stages
C
C     -- P.Degtiarenko, JLab, November 21, 2013 --
C
      implicit NONE
      integer n,m,minm,maxm,it,jt,kt
      double precision f,dPmn,df,dfl,pNu,logfac
      double precision dMu,dNu1,dAlpha1,dAlpha2,dNu2,dAlpha3,dNu3,dXi
      integer m0,m1
      common/mlimits/m0,m1
C
      f = 0.0D0
      minm = max(m0,1)
      maxm = m1
      dAlpha1 = 1.d0 - dAlpha2 - dAlpha3
      if(dAlpha1.lt.0) goto 900  ! -- dAlpha1 negative not physical
c
      do m = maxm, minm, -1
         df = 0.D0
         do it = 0, m            ! -- Trinomial sum of multiplicities
            do jt = 0, m-it
               kt = m - it - jt
               if(kt.ge.0) then
                  pNu = dNu3*kt + dNu2*jt + dNu1*it
                  dfl = kt*log(dAlpha3)+jt*log(dAlpha2)+it*log(dAlpha1)
                  df = df + 
     &              exp(dfl+logfac(m)-logfac(it)-logfac(jt)-logfac(kt))*
     &              dPmn(m,n,dMu,pNu)
               endif
            enddo
         enddo
         f  = f + df
      enddo
 500  continue
      if(m0.eq.0) then
         f  = f + dPmn(0,n,dMu,dNu1)
      endif
 900  continue
      dPn = f
      end
C
      double precision function dPmn(m,n,dMu,pNu)
C
C     -- Returns element (m,n) for the Compound Two-Stage Poisson function
C        Pmn = (dMu)^m*exp(-dMu)/m! * (m*pNu)^n*exp(-m*pNu)/n!
C        m, n: variable cascade multiplicities on first and second stages
C        dMu, pNu: average cascade multiplicity on the first, 
C                       and gain on the second stage
C        For (m.eq.0.and.n.gt.0) Pmn=0
C        For n=0 Pmn=(dMu)^m*exp(-dMu)/m! * exp(-m*pNu)
C
C     -- P.Degtiarenko, JLab,  November 2013 --
C
      implicit NONE
      integer m,n
      double precision funlog,f,logfac
      double precision dMu,pNu
c
      f = 0.0D0
      if( m.eq.0.and.n.gt.0 ) goto 900
c
      if(n.eq.0) then
         if(m.eq.0) then
            funlog  = -dMu
         else
            funlog  = m*log(dMu) - logfac(m) - dMu - pNu
         endif
         goto 800
      endif
c
      funlog = n*log(pNu)   - logfac(n) - pNu +
     &         m*log(dMu)   - logfac(m) - dMu
c
 800  continue
      if(ABS(funlog).lt.700.) f = exp(funlog)
 900  continue
      dPmn = f
      end
C
      real function fplot(x,mlim0,mlim1) 
C
C -- Same as ppmt11(x) but for interactive use
C
C     -- P.Degtiarenko, JLab, September 2014 --
C
      implicit NONE
      real x,x0
      real  Scale
      real  Mu, Nu1, Alpha2, Nu2, Alpha3, Nu3, Xi, Sigma, Beta, Tau
      real sScale
      real sMu,sNu1,sAlpha2,sNu2,sAlpha3,sNu3,sXi,sSigma,sBeta,sTau
      real cP2txG,f
      real idvec,Par,mean,xmin,xmax,nbins,TauSPE
      vector idvec(4)
      vector Par(11)
      logical init,message,diagn
      common/reset/init,message,diagn
      integer m0,m1,mlim0,mlim1,sm0,sm1,i
      common/mlimits/m0,m1
      common/storppr/sScale,
     & sMu,sNu1,sAlpha2,sNu2,sAlpha3,sNu3,sXi,sSigma,sBeta,sTau,sm0,sm1
c
      m0 = mlim0  ! Limits for m integration
      m1 = mlim1
      f  = 0.
c
      Scale  = Par(1)
      Sigma  = Par(2)
      Mu     = Par(3)
      Nu1    = Par(4)
      Alpha2 = Par(5)
      Nu2    = Par(6)*Nu1
      Alpha3 = Par(7)*(1-Alpha2)
      Nu3    = Par(8)*Nu1
      Xi     = Par(9)
      Beta   = Par(10)
      Tau    = Par(11)
c
      nbins  = idvec(1)
      xmin   = idvec(2)
      xmax   = idvec(3)
      mean   = idvec(4)
c
      x0     = mean - Scale*Mu - Beta*Tau*Sigma
      TauSPE = Tau*Sigma/Scale
c
      if( sScale.ne.Scale.or.sSigma.ne.Sigma.or.sMu.ne.Mu.or.
     &    sNu1.ne.Nu1.or.sNu2.ne.Nu2.or.sNu3.ne.Nu3.or.
     &    sAlpha2.ne.Alpha2.or.sAlpha3.ne.Alpha3.or.sXi.ne.Xi.or.
     &    sBeta.ne.Beta.or.sTau.ne.Tau.or.
     &    sm0.ne.m0.or.sm1.ne.m1                                 ) then
         init = .true.
         if(message) then
            print *,  Par
            message = .false.
         endif
      endif
c
      f = cP2txG(x/Scale,Mu,Nu1,Alpha2,Nu2,Alpha3,Nu3,Xi,Beta,TauSPE,
     &     Sigma/Scale,x0/Scale)/Scale*(xmax-xmin)/nbins
c
      sScale  = Scale 
      sSigma  = Sigma
      sMu     = Mu 
      sNu1    = Nu1
      sAlpha2 = Alpha2
      sNu2    = Nu2
      sAlpha3 = Alpha3
      sNu3    = Nu3
      sXi     = Xi
      sBeta   = Beta
      sTau    = Tau
      sm0     = m0
      sm1     = m1
c
 900  continue
      fplot = f
      end
*
C
      real function fpres(x,mlim0,mlim1) 
C
C -- Same as fplot(x) but for interactive use with Scale=1 and x0=0
C    Sigma needs to be normalized to the original scale value before first call 
C
C    In this subroutine x0=0, Scale=1, and mean=Mu
C    ================================================
C
C     -- P.Degtiarenko, JLab, November 2013 --
C
      implicit NONE
      real x,x0
      real  Scale
      real  Mu, Nu1, Alpha2, Nu2, Alpha3, Nu3, Xi, Sigma, Beta, Tau
      real sScale
      real sMu,sNu1,sAlpha2,sNu2,sAlpha3,sNu3,sXi,sSigma,sBeta,sTau
      real cP2txG,f
      real idvec,Par,mean,xmin,xmax,nbins,TauSPE
      vector idvec(5)
      vector par(11)
      logical init,message,diagn
      common/reset/init,message,diagn
      integer m0,m1,mlim0,mlim1,sm0,sm1
      common/mlimits/m0,m1
      common/storppr/sScale,
     & sMu,sNu1,sAlpha2,sNu2,sAlpha3,sNu3,sXi,sSigma,sBeta,sTau,sm0,sm1
c
      m0 = mlim0  ! Limits for m integration
      m1 = mlim1
      f  = 0.
c
      Scale  = Par(1)
      Sigma  = Par(2)
      Mu     = Par(3)
      Nu1    = Par(4)
      Alpha2 = Par(5)
      Nu2    = Par(6)*Nu1
      Alpha3 = Par(7)*(1-Alpha2)
      Nu3    = Par(8)*Nu1
      Xi     = Par(9)
      Beta   = Par(10)
      Tau    = Par(11)
c
      nbins  = idvec(1)
      xmin   = idvec(2)
      xmax   = idvec(3)
c
      TauSPE = Tau*Sigma/Scale
      x0     = 0.0
      Scale  = 1.0
c
      if( sScale.ne.Scale.or.sSigma.ne.Sigma.or.sMu.ne.Mu.or.
     &    sNu1.ne.Nu1.or.sNu2.ne.Nu2.or.sNu3.ne.Nu3.or.
     &    sAlpha2.ne.Alpha2.or.sAlpha3.ne.Alpha3.or.sXi.ne.Xi.or.
     &    sBeta.ne.Beta.or.sTau.ne.Tau.or.
     &    sm0.ne.m0.or.sm1.ne.m1                                 ) then
         init = .true.
         if(message) then
            print *,  Par
            message = .false.
         endif
      endif
c
      f = cP2txG(x,Mu,Nu1,Alpha2,Nu2,Alpha3,Nu3,Xi,Beta,TauSPE,
     &     Sigma,x0)*(xmax-xmin)/nbins
c
      if(f.lt.1.E-16) then ! -- helps with PAW plots...
         f = 0.
      endif
c
      sScale  = Scale 
      sSigma  = Sigma
      sMu     = Mu 
      sNu1    = Nu1
      sAlpha2 = Alpha2
      sNu2    = Nu2
      sAlpha3 = Alpha3
      sNu3    = Nu3
      sXi     = Xi
      sBeta   = Beta
      sTau    = Tau
      sm0     = m0
      sm1     = m1
c
 900  continue
      fpres = f
      end
C
      real function 
     &     pcP2txG(x,Mu,Nu1,Alpha2,Nu2,Alpha3,Nu3,Xi,Beta,Tau,s,x0)
C
C -- Returns the value of the trinomial average of the three
C    Discrete Compound Two-Stage Poisson distributions (DC2SP)
C    with average second stage multiplicities (gains) Nu1, Nu2, and Nu3,
C    convoluted with normal Gaussian distribution with sigma s, 
C    properly scaled to the <x>, <x0>, and <s> parameters -- 
C    producing a continuous function of x.
C    average third stage multiplicity (gain) <Xi> is set to all DC3SPs
C -- The resulting distribution is shifted by <x0> to model 
C    conditions of amplitude measurements with pedestal 
C    readings at zero signal, spread by a Gaussian noise.
C -- The variables <x>, <x0>, and <s> are in units in which "1"
C    corresponds to the amplitude of the event with exact multiplicity of 
C    <Mu> at the first stage, 
C    and <Num> at the second stage
C -- Integral from -infinity to +infinity of cP2txG(x)*dx = 1.0
C
C     -- P.Degtiarenko, JLab, November 2013 --
C
      implicit NONE
      integer n,k,nmid,nmin,nmax,nmin1,nmax1
      real    x,Mu,Nu1,Alpha2,Nu2,Alpha3,Nu3,Xi,Beta,Tau,Zeta,s,x0
      real    dxs,ddxs,xmin,xmax,avrNuS,sn
      double precision f,df,sqr2pi,xn,dsn,flog,pSdPn
      double precision xk,dfk,logfac,GmxEMG
      double precision 
     &       dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi,dBeta,dTau,dZeta
      data dxs/8.5/
      common/comdxs/dxs ! -- Equivalent of the SAVE statement -- !
C
      f = 0.0D0
      if(Mu.le.0..or.Nu1.le.0..or.s.le.0.) then
         goto 900
      else
         dMu     = Mu
         dNu1    = Nu1
         dAlpha2 = Alpha2
         dNu2    = Nu2
         dAlpha3 = Alpha3
         dNu3    = Nu3
         dXi     = Xi
         dBeta   = Beta
         dTau    = Tau
         Zeta    = Xi
         dZeta   = Zeta
c -- Avoid zeros in Alphas ---
         if(dAlpha2.lt.0.1D-12) dAlpha2 = 0.1D-12
         if(dAlpha3.lt.0.1D-12) dAlpha3 = 0.1D-12
c
         avrNuS = Nu1*(1.-Alpha2-Alpha3) + Alpha2*Nu2 + Alpha3*Nu3
         nmid = max(int(avrNuS*(x-x0)),1)
         sn   = sqrt(s**2+nmid/avrNuS/avrNuS/Xi) ! Sigma counts 3rd stage
         ddxs = max(dxs*sn,abs(Tau)*16.0)
         xmin = x - ddxs
         xmax = x + ddxs
         if(x.lt.xmin.or.x.gt.xmax) goto 900
         nmin = max(int(avrNuS*(xmin-x0)),0)
         nmax = max(int(avrNuS*(xmax-x0)),nmin+1) 
         do n = nmin, nmax
            df = 0.0D0
            if(n.eq.0) then
               dsn = s
               xn  = x - x0
               df= pSdPn(n,dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi)*
     &              GmxEMG(xn,dbeta,dsn,dtau)
            elseif(n.gt.3) then
               dsn = sqrt(s**2+n/avrNuS/avrNuS/Xi)
               xn  = x - x0 - n/avrNuS
               df  = pSdPn(n,dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi)*
     &              GmxEMG(xn,dbeta,dsn,dtau)
            else ! -- Convolution with 3rd stage Poissonian close to x0 --
               dsn = s
               xk  = x - x0
               dfk = dexp(-n*dXi)*GmxEMG(xk,dbeta,dsn,dtau)
               df = df + dfk
               k  = 1
 150           continue
               xk  = x - x0 - k/Xi/avrNuS
               dsn = sqrt(s**2+k/avrNuS/avrNuS/Xi/Xi/Zeta)
               dfk = dexp(k*dlog(n*dXi)-n*dXi-logfac(k))*
     &              GmxEMG(xk,dbeta,dsn,dtau)
               df = df + dfk
               k  =  k + 1
               if((k.le.int(n*Xi).or.dfk*1.e8.gt.df).and.k.lt.1000) 
     &              goto 150
               df = df*pSdPn(n,dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi)
            endif
            f  = f + df
         enddo
      endif
 900  continue
      pcP2txG = f
      end
C
      double precision function 
     &     pSdPn(n,dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi)
C     -- Returns value of the dPn(n) calculated once
C        Stores results into the COMMON/pnstore/StoredPn upon the
C        first call with this n and retrieves the value if called again
C        Outside the array length (=nspn) calculates dPn every time and
C        prints warning once
C        The logical variable init may be reset from outside using 
C        COMMON/reset/init -- the reset is needed every time parameters change
C
C     -- P.Degtiarenko, JLab,  November 2013 --
C
      implicit NONE
      integer n,i,nspn
c      logical init,message
c      data message/.true./
      parameter (nspn=20000)
      double precision f,pdPn,
     &            dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi
      double precision StoredPn(nspn)
      common/pnstore/StoredPn
      logical init,message,diagn
      common/reset/init,message,diagn
c      common/reset/init
c
      if(init) then
         do i = 1, nspn
            StoredPn(i) = -1.0D0
         enddo
         init = .FALSE.
      endif
      if(n.ge.0.and.n.lt.nspn) then ! ******** Try not to go above nspn ******* !
         if(n.lt.nspn) then
            f = StoredPn(n+1)
            if(f.lt.0.D0) then
               f = pdPn(n,dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi)
               StoredPn(n+1) = f
            endif
         else
            f = pdPn(n,dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi)
            if(message) then
               print *, '%%%SdPn: n was outside the range: n=',n
               print *, '   ---   The calcs may take long time...'
               message = .FALSE.
               print *, dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi
            endif
         endif
      else
         f = 0.D0
      endif
      pSdPn = f
      end
C
      double precision function 
     &     pdPn(n,dMu,dNu1,dAlpha2,dNu2,dAlpha3,dNu3,dXi)
C
C     -- Returns the value of the integral over the first stage "m" of the
C        Compound Two-Stage Poisson function Pmn(m,n)
C        function of n, the cascade multiplicities on second stage, starting at 0
C
C        dMu, dNu: average cascade multiplicities on first and second stages
C
C     -- P.Degtiarenko, JLab, November 21, 2013 --
C
      implicit NONE
      integer n,m,minm,maxm,it,jt,kt
      double precision f,dPmn,df,pNu,logfac
      double precision dMu,dNu1,dAlpha1,dAlpha2,dNu2,dAlpha3,dNu3,dXi
      integer m0,m1,ntc
      common/mlimits/m0,m1
      common/trincom/ntc
C
      f = 0.0D0
      minm = max(m0,1)
      maxm = m1
      dAlpha1 = 1.d0 - dAlpha2 - dAlpha3
      if(dAlpha1.lt.0) goto 900  ! -- dAlpha1 negative not physical
c
      do m = maxm, minm, -1
         df = 0.D0
         do it = 0, m           ! -- Trinomial sum of multiplicities
            do jt = 0, m-it
               kt = m - it - jt
               if(kt.ge.0.and.kt.le.m) then
	        if(ntc.eq.0.and.kt.eq.1.and.jt.eq.0.and.it.eq.0 .or.
     &             ntc.eq.1.and.kt.eq.0.and.jt.eq.1.and.it.eq.0 .or.
     &             ntc.eq.2.and.kt.eq.0.and.jt.eq.0.and.it.eq.1) then
                  pNu = dNu1*kt + dNu2*jt + dNu3*it
                  df = df + 
     &                 exp(logfac(m)-logfac(it)-logfac(jt)-logfac(kt))*
     &                 dAlpha1**kt*dAlpha2**jt*dAlpha3**it*
     &                 dPmn(m,n,dMu,pNu)
                endif
               endif
            enddo
         enddo
         f  = f + df
      enddo
 500  continue
      if(m0.eq.0) then
         f  = f + dPmn(0,n,dMu,dNu1)
      endif
 900  continue
      pdPn = f
      end
C
      real function pfplot(x,mlim0,mlim1,nt) 
C
C -- Same as ppmt11(x) but for interactive use
C
C     -- P.Degtiarenko, JLab, November 2015 --
C
      implicit NONE
      real x,x0
      real  Scale
      real  Mu, Nu1, Alpha2, Nu2, Alpha3, Nu3, Xi, Sigma, Beta, Tau
      real sScale
      real sMu,sNu1,sAlpha2,sNu2,sAlpha3,sNu3,sXi,sSigma,sBeta,sTau
      real pcP2txG,f
      real idvec,Par,mean,xmin,xmax,nbins,TauSPE
      vector idvec(4)
      vector par(11)
      logical init,message,diagn
      common/reset/init,message,diagn
      integer m0,m1,nt,ntc,mlim0,mlim1,sm0,sm1,snt
      common/mlimits/m0,m1
      common/trincom/ntc
      common/storppp/sScale,sMu,sNu1,
     &     sAlpha2,sNu2,sAlpha3,sNu3,sXi,sSigma,sBeta,sTau,sm0,sm1,snt
c
      m0 = mlim0  ! Limits for m integration
      m1 = mlim1
      ntc = nt
      f  = 0.
c
      Scale  = Par(1)
      Sigma  = Par(2)
      Mu     = Par(3)
      Nu1    = Par(4)
      Alpha2 = Par(5)
      Nu2    = Par(6)*Nu1
      Alpha3 = Par(7)*(1-Alpha2)
      Nu3    = Par(8)*Nu1
      Xi     = Par(9)
      Beta   = Par(10)
      Tau    = Par(11)
c
      nbins  = idvec(1)
      xmin   = idvec(2)
      xmax   = idvec(3)
      mean   = idvec(4)
c
      x0     = mean - Scale*Mu - Beta*Tau*Sigma
      TauSPE = Tau*Sigma/scale
c
      if( sScale.ne.Scale.or.sSigma.ne.Sigma.or.sMu.ne.Mu.or.
     &    sNu1.ne.Nu1.or.sNu2.ne.Nu2.or.sNu3.ne.Nu3.or.
     &    sAlpha2.ne.Alpha2.or.sAlpha3.ne.Alpha3.or.sXi.ne.Xi.or.
     &    sBeta.ne.Beta.or.sTau.ne.Tau.or.
     &      sm0.ne.m0.or.sm1.ne.m1.or.snt.ne.nt) then
         init = .true.
         if(message) then
            print *,  Par
            message = .false.
         endif
      endif
c
      f = pcP2txG(x/Scale,Mu,Nu1,Alpha2,Nu2,Alpha3,Nu3,Xi,Beta,TauSPE,
     &     Sigma/Scale,x0/Scale)/Scale*(xmax-xmin)/nbins
c
      if(f.lt.1.E-16) then ! -- helps with PAW plots...
         f = 0.
      endif
c
      sScale  = Scale 
      sSigma  = Sigma
      sMu     = Mu 
      sNu1    = Nu1
      sAlpha2 = Alpha2
      sNu2    = Nu2
      sAlpha3 = Alpha3
      sNu3    = Nu3
      sXi     = Xi
      sBeta   = Beta
      sTau    = Tau
      sm0     = m0
      sm1     = m1
      snt     = nt
c
 900  continue
      pfplot = f
      end
*
C
      real function pfpres(x,mlim0,mlim1,nt) 
C
C -- Same as ppmt11(x) but for interactive use with scale=1 and x0=0
C
C    In this subroutine x0=0, scale=1, and mean=Mu
C    ================================================
C
C     -- P.Degtiarenko, JLab, November 2015 --
C
      implicit NONE
      real x,x0
      real  Scale
      real  Mu, Nu1, Alpha2, Nu2, Alpha3, Nu3, Xi, Sigma, Beta, Tau
      real sScale
      real sMu,sNu1,sAlpha2,sNu2,sAlpha3,sNu3,sXi,sSigma,sBeta,sTau
      real pcP2txG,f
      real idvec,Par,mean,xmin,xmax,nbins,TauSPE
      vector idvec(4)
      vector par(11)
      logical init,message,diagn
      common/reset/init,message,diagn
      integer m0,m1,nt,ntc,mlim0,mlim1,sm0,sm1,snt
      common/mlimits/m0,m1
      common/trincom/ntc
      common/storppp/sScale,sMu,sNu1,
     &     sAlpha2,sNu2,sAlpha3,sNu3,sXi,sSigma,sBeta,sTau,sm0,sm1,snt
c
      m0 = mlim0  ! Limits for m integration
      m1 = mlim1
      ntc = nt
      f  = 0.
c
      Scale  = Par(1)
      Sigma  = Par(2)
      Mu     = Par(3)
      Nu1    = Par(4)
      Alpha2 = Par(5)
      Nu2    = Par(6)*Nu1
      Alpha3 = Par(7)*(1-Alpha2)
      Nu3    = Par(8)*Nu1
      Xi     = Par(9)
      Beta   = Par(10)
      Tau    = Par(11)
c
      nbins  = idvec(1)
      xmin   = idvec(2)
      xmax   = idvec(3)
      mean   = idvec(4)
c
      x0     = 0.0
      scale  = 1.0
      TauSPE = Tau*Sigma/scale
c
      if( sScale.ne.Scale.or.sSigma.ne.Sigma.or.sMu.ne.Mu.or.
     &    sNu1.ne.Nu1.or.sNu2.ne.Nu2.or.sNu3.ne.Nu3.or.
     &    sAlpha2.ne.Alpha2.or.sAlpha3.ne.Alpha3.or.sXi.ne.Xi.or.
     &    sBeta.ne.Beta.or.sTau.ne.Tau.or.
     &      sm0.ne.m0.or.sm1.ne.m1.or.snt.ne.nt) then
         init = .true.
         if(message) then
            print *,  Par
            message = .false.
         endif
      endif
c
      f = pcP2txG(x/Scale,Mu,Nu1,Alpha2,Nu2,Alpha3,Nu3,Xi,Beta,TauSPE,
     &     Sigma/Scale,x0/Scale)/Scale*(xmax-xmin)/nbins
c
      if(f.lt.1.E-16) then ! -- helps with PAW plots...
         f = 0.
      endif
c
      sScale  = Scale 
      sSigma  = Sigma
      sMu     = Mu 
      sNu1    = Nu1
      sAlpha2 = Alpha2
      sNu2    = Nu2
      sAlpha3 = Alpha3
      sNu3    = Nu3
      sXi     = Xi
      sBeta   = Beta
      sTau    = Tau
      sm0     = m0
      sm1     = m1
      snt     = nt
c
 900  continue
      pfpres = f
      end
*
      double precision function GmxEMG(ddr,dbeta,dsigma,ddtau)
C
C     -- Returns weighted sum of a Gaussian and the Exponentially 
C        Modified Gaussian distributions, function of real r:
C        GmxEMG = (1-beta)*G(r;sigma) + beta*EMG(r;sigma,tau), with
C        EMG = 1/(2*tau)*exp(mu/tau+sigma**2/(2*tau**2)-r/tau)*
C             (1 - erf((mu+sigma**2/tau-r)/(sqrt(2*sigma**2))))
C        Gaussian (and EMG) mu = 0
C        Gaussian (and EMG) sigma = sigma
C        Exponential "temperature" = tau
C        Portion of EMG function in the sum = beta
C        The function represents a p.d.f. normalized to unit area
C        ln(sqrt(pi))  = 0.57236494292469997D0
C        sqrt(2)   = 1.4142135623730950D0
C        sqrt(2Pi) = 2.5066282746310005D0
C
C     -- P.Degtiarenko, JLab, January 2015 --
C
      implicit NONE
      double precision ddr,dr,dbeta,dsigma,ddtau,dtau
      double precision gausslog,funlog,z,lff,fe,fg,sigma2
      double precision erf
c
      if(ddtau.lt.0.) then
         dr = -ddr
         dtau = -ddtau
      else
         dr =  ddr
         dtau =  ddtau
      endif
c -- Tau/Sigma can't be too small --
      if(dtau.lt.0.05D0*dsigma) dtau = 0.05D0*dsigma
      fg = 0.0D0
      fe = 0.0D0
      sigma2 = dsigma*dsigma
      z = (sigma2/dtau-dr)/(1.4142135623730950D0*dsigma)
      if(z.lt.5.0D0) then
         lff = log(1.0D0-erf(z))
      else
         lff = -z*z - log(z) - 0.57236494292469997D0
      endif
      gausslog = -dr*dr/2.0D0/sigma2
      if(gausslog.gt.-700.0D0) fg = (1.0D0-dbeta)*exp(gausslog)/
     &                              dsigma/2.5066282746310005D0
      funlog = sigma2/(2.0D0*dtau*dtau) - dr/dtau + lff
      if(funlog.lt.700.0D0) fe = dbeta*0.5D0*exp(funlog)/dtau
c
      GmxEMG = fg + fe
      end
