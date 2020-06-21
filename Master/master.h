int master(char in_traj_PATH[], char out_traj_PATH[]){

    FILE *fr1, *fr2, *fw1,*fw2;

    dimf dim = shape_of_file(in_traj_PATH);
    int nrows = dim.rows;
    int ncols = dim.cols;
    //printf("nrows: %d  ncols: %d\n",nrows, ncols);

    double Tnu, Tanu;
    double time[nrows],r[nrows],theta[nrows],x[nrows],z[nrows],rho[nrows],P[nrows],Ye[nrows],v[nrows],T[nrows],mue[nrows];
    double mup[nrows], mun[nrows],binNnu[nrows], binEnu[nrows], binNanu[nrows],binEanu[nrows];
    double rayNnu[nrows],rayEnu[nrows],rayNanu[nrows],rayEanu[nrows],rayNxnu[nrows],rayExnu[nrows];

    cross_section _binsigma;
    cross_section _raysigma;

    double E2T_fermi_fac = fac(3)*gsl_sf_fermi_dirac_int(3,0.0)/(fac(2)*gsl_sf_fermi_dirac_int(2,0.0));

    fr1 = fopen(in_traj_PATH, "r");
    fw1 = fopen(out_traj_PATH, "w");
    int count = 0;

    //---------------------------------------------------------------------------------------------------------------------------------------------

    while(fscanf(fr1,"%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",\
    &time[count],&r[count],&theta[count],&x[count],&z[count],&rho[count],&P[count],&Ye[count],&v[count],&T[count],&mue[count],\
    &mup[count], &mun[count],&binNnu[count],&binEnu[count],&binNanu[count],&binEanu[count],\
    &rayNnu[count],&rayEnu[count],&rayNanu[count],&rayEanu[count],&rayNxnu[count],&rayExnu[count])!=EOF){


        Tnu  = binEnu[count]/E2T_fermi_fac;
        Tanu = binEanu[count]/E2T_fermi_fac;
        _binsigma = crs_section(Tnu,Tanu,T[count],mue[count]);

        react_rate _binrate = rates(T[count], mue[count], _binsigma, binNnu[count], binNanu[count]);

        Tnu = rayEnu[count]/E2T_fermi_fac;
        Tanu = rayEanu[count]/E2T_fermi_fac;
        _raysigma = crs_section(Tnu,Tanu,T[count],mue[count]);

        react_rate _rayrate = rates(T[count], mue[count], _raysigma, rayNnu[count], rayNanu[count]);

        //-------------------------------------------------------------------------------------------------------------------------------------------

        fprintf(fw1, "%le\t%le\t%le\t%le\t%le\t%le\t%le\t%le\t%le\t%le\t%le\t%le\t%le\t%le\t%le\t%le\t%le\t%le\t%le\t%le\t%le\t",
        time[count],r[count],theta[count],rho[count],P[count],Ye[count],v[count],T[count],mue[count],\
        mup[count],mun[count],binNnu[count],binEnu[count],binNanu[count],binEanu[count],\
        rayNnu[count],rayEnu[count],rayNanu[count],rayEanu[count],rayNxnu[count],rayExnu[count]); //trajectory data---> 21-entries

        fprintf(fw1, "%le\t%le\t%le\t%le\t", _binsigma.sigma1, _binsigma.sigma2, _binsigma.sigma3, _binsigma.sigma4); //22-25 bin-cross-sections---> 4-entries
        fprintf(fw1, "%le\t%le\t%le\t%le\t", _binrate.rate1, _binrate.rate2, _binrate.rate3, _binrate.rate4);   // 26-29 bin-reaction rates---> 4-entries
        fprintf(fw1, "%le\t%le\t%le\t%le\t", _raysigma.sigma1, _raysigma.sigma2, _raysigma.sigma3, _raysigma.sigma4); //30-33 ray-cross-sections---> 4-entries
        fprintf(fw1, "%le\t%le\t%le\t%le\n", _rayrate.rate1, _rayrate.rate2, _rayrate.rate3, _rayrate.rate4);   // 34-37 ray-reaction rates---> 4-entries

        ++count;
    }

    //-------------------------------------------------------------------------------------------------------------------------------------------

    fclose(fr1);
    fclose(fw1);
    return(0);
}
