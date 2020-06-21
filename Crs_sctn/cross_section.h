cross_section crs_section(double Tnu, double Tanu, double T, double mue){

    double k = 9.3e-44; //[cm^2/MeV^2]
    double Delta = 1.293; //[MeV]
    double Mp = 938.27231; //[MeV]
    double Mn = 939.57; //[MeV] 
    
    double avE1nu, avE2nu, avE3nu;
    double avE1anu, avE2anu, avE3anu;

    //---------------------------------------------------------------------------------------------------------------------------------------------------------
    
    avE1nu = Tnu*(fac(3)*gsl_sf_fermi_dirac_int(3,0.0))/(fac(2)*gsl_sf_fermi_dirac_int(2,0.0));//[MeV]
    avE2nu = (Tnu*Tnu)*(fac(4)*gsl_sf_fermi_dirac_int(4,0.0))/(fac(2)*gsl_sf_fermi_dirac_int(2,0.0));//[MeV^2]
    avE3nu = (Tnu*Tnu*Tnu)*(fac(5)*gsl_sf_fermi_dirac_int(5,0.0))/(fac(2)*gsl_sf_fermi_dirac_int(2,0.0));//[MeV^3]

    avE1anu = Tanu*(fac(3)*gsl_sf_fermi_dirac_int(3,0.0))/(fac(2)*gsl_sf_fermi_dirac_int(2,0.0));//[MeV]
    avE2anu = (Tanu*Tanu)*(fac(4)*gsl_sf_fermi_dirac_int(4,0.0))/(fac(2)*gsl_sf_fermi_dirac_int(2,0.0));//[MeV2]
    avE3anu = (Tanu*Tanu*Tanu)*(fac(5)*gsl_sf_fermi_dirac_int(5,0.0))/(fac(2)*gsl_sf_fermi_dirac_int(2,0.0));//[MeV^3]

    double epsilon_nu = avE2nu/avE1nu;//[MeV]
    double epsilon_anu = avE2anu/avE1anu;//[MeV]
    double a_nu = avE2nu/(avE1nu*avE1nu);
    double a_anu = avE2anu/(avE1anu*avE1anu);

    double b_nu = (avE3nu*avE1nu)/(avE2nu*avE2nu);
    double b_anu = (avE3anu*avE1anu)/(avE2anu*avE2anu);

    double W_nu  = 1+(1.02*b_nu*epsilon_nu/Mn);
    double W_anu = 1-(7.22*b_anu*epsilon_anu/Mp);

    double sigma_nu  = k*avE1nu*epsilon_nu*(1+(2.0*Delta/epsilon_nu)+(a_nu*(Delta/epsilon_nu)*(Delta/epsilon_nu)))*W_nu;
    double sigma_anu = k*avE1anu*epsilon_anu*(1-(2.0*Delta/epsilon_anu)+ (a_anu*(Delta/epsilon_anu)*(Delta/epsilon_anu)))*W_anu; 
    //--------------------------------------------------------------------------------------------------------------------------------------------------------
    
    double barmue = (mue - Delta) / T;

    double ne = (1.3e32) * ( pow(T, 3.0) * fac(2) / (M_PI * M_PI) ) * gsl_sf_fermi_dirac_2(barmue); //[1/cm^3]
    double barE1e = T * fac(3) * gsl_sf_fermi_dirac_int(3, barmue) / (fac(2) * gsl_sf_fermi_dirac_int(2, barmue));
    double barE2e = pow(T, 2.0) * fac(4) * gsl_sf_fermi_dirac_int(4, barmue) / (fac(2) * gsl_sf_fermi_dirac_int(2, barmue));

    double epsilon_e = barE2e / barE1e;
    double a_e = barE2e/pow(barE1e,2.0);

    double sigma_e = ((1.0/2.0)*k*barE1e*epsilon_e)*(1 + (2.0*Delta/epsilon_e) + a_e*pow(Delta/epsilon_e, 2.0))*W_nu;

    //--------------------------------------------------------------------------------------------------------------------------------------------------------

    double barmuae = -mue / T;

    double nae = (1.3e32) * (pow(T, 3.0) / (M_PI * M_PI)) * fac(2) * gsl_sf_fermi_dirac_2(barmuae); //[1/cm^3]
    double barE1ae = T * fac(3) * gsl_sf_fermi_dirac_int(3, barmuae) / (fac(2) * gsl_sf_fermi_dirac_int(2, barmuae));
    double barE2ae = pow(T, 2.0) * fac(4) * gsl_sf_fermi_dirac_int(4, barmuae) / (fac(2) * gsl_sf_fermi_dirac_int(2, barmuae));

    double epsilon_ae = barE2ae / barE1ae;
    double a_ae = barE2ae / pow(barE1ae, 2.0);

    double sigma_ae = ((1.0/2.0)*k*barE1ae*epsilon_ae)*(1 + (2.0*Delta/epsilon_ae) + a_ae*pow(Delta/epsilon_ae,2.0))*W_anu;
    
    //--------------------------------------------------------------------------------------------------------------------------------------------------------
    
    //printf("sigma_nu: %le\tsigma_anu: %le\n",sigma_nu,sigma_anu);
    cross_section _sigma;
    
    _sigma.sigma1 = sigma_nu;
    _sigma.sigma2 = sigma_anu;
    _sigma.sigma3 = sigma_e;
    _sigma.sigma4 = sigma_ae;

    return(_sigma);
}