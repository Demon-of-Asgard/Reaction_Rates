double fac(int n){
    double facto = 1.0;
    int i = 1;
    if(n==0){
        return(1.0);
    }
    else{
        while(i<=n){
            facto = facto*i;
            ++i;
        }
    }
    return(facto);
}