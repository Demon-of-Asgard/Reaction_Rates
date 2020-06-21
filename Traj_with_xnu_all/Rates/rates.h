react_rate rates(double T, double mue,cross_section _sigma, double nnu, double nanu){

    double Delta = 1.293; //[MeV]
    react_rate _rate;

    //-----------------------------------------------------------------------------------------------------------

    double sigma_nu = _sigma.sigma1;
    double sigma_anu = _sigma.sigma2;
    double rate1 = nnu * c * sigma_nu;
    double rate2 = nanu * c * sigma_anu;

    //-----------------------------------------------------------------------------------------------------------

    double sigma_e = _sigma.sigma3;
    double sigma_ae = _sigma.sigma4;
    double barmue = (mue-Delta)/T;
    double barmuae = -mue / T;

    double ne = (1.3e32) * (pow(T, 3.0) * fac(2) / (M_PI * M_PI)) * gsl_sf_fermi_dirac_2(barmue); //[1/cm^3]
    double nae = (1.3e32) * (pow(T, 3.0) / (M_PI * M_PI)) * fac(2) * gsl_sf_fermi_dirac_2(barmuae); //[1/cm^3]
    double rate3 = ne * c * sigma_e;
    double rate4 = nae * c * sigma_ae;  

    //-----------------------------------------------------------------------------------------------------------

    _rate.rate1 = rate1;
    _rate.rate2 = rate2;
    _rate.rate3 = rate3;
    _rate.rate4 = rate4;

    //-----------------------------------------------------------------------------------------------------------

    return(_rate);
}