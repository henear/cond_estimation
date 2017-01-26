
void ltyb(double* L, double* b,int m){
    int lda = m;
    int i, j;
    int t;
    int temp;
    double sum;    
    for(i = m-1;i>=0;i--){
        sum = 0;
	temp = i * lda;
	t = m -i -1;
	t = (t>>2)<<2;
        for(j=m-1;j>m-t-1;j-=4){
            sum += L[temp+j]*b[j];
	    sum += L[temp+j-1]*b[j-1];
            sum += L[temp+j-2]*b[j-2];
	    sum += L[temp+j-3]*b[j-3];
        }
	for(j= m-t-1;j>i;j--){
	    sum += L[temp+j]*b[j];
	}
	//dotv(&L[i*lda+m-1],&b[m-1],&sum,m-1-i,-1,-1);
        b[i] = b[i] - sum;           
	}
}

