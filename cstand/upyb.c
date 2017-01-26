#include<stdlib.h>
#include<stdio.h>
void upyb(double* U, double* b,int m){
    int lda = m;
    int i, j;
    int t;
    double sum;
    
    for(i = m-1 ; i >= 0 ; i--){
        sum = 0;
	t = m -i -1;
	t = (t>>2)<<2;
		
        for(j=m-1;j>m-t-1;j-=4){
            sum += U[j*lda+i]*b[j];
	    sum += U[j*lda+i-lda]*b[j-1];
            sum += U[j*lda+i-(lda<<1)]*b[j-2];
	    sum += U[j*lda+i-(lda+lda<<1)]*b[j-3];
        }
	
	for(j= m-t-1;j>i;j--){
	    sum += U[j*lda+i]*b[j];
	}
	
        b[i] = (b[i] - sum)*1.0/U[i*lda+i];
	
    }
}



