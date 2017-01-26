#include<stdio.h>
#include<stdlib.h>



void utyb(double* a, double* b,int m){
    int lda = m;
    int i, j;
    int t;
    int temp;
    double sum;    
    for(i = 0;i<m;i++){
	sum = 0;
	t = (i>>2)<<2;
     
	temp = i*lda;
	for(j = 0;j < t; j+=4){
		sum += a[temp+j]*b[j];
		sum += a[temp+j+1]*b[j+1];
		sum += a[temp+j+2]*b[j+2];
		sum += a[temp+j+3]*b[j+3];		
	}
	for(j = t; j < i; j++){
		sum += a[temp+j]*b[j];
	}
       /*
	for(j=0;j<i;j++){
		sum+= a[temp+j]*b[j];
	}*/
        b[i] = (b[i] - sum) / a[i*lda+i];       
    
    }
}

