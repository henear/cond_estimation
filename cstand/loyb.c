
#include<stdio.h>
#include<stdlib.h>
void loyb(double* L, double* b,int m){
    int ida = m;
    int i, j;
/*
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%f ",L[i+j*ida]);
		}
			printf("\n");
iy	}*/
    double sum;  
    double t = (i>>2)<<2;  
    for(i = 0; i < m; i++){
        sum = 0;
/*
        for(j=0;j<t;j+=4){
            sum += L[j*ida+i]*b[j];
	    sum += L[(j+1)*ida+i]*b[j+1];
            sum += L[(j+2)*ida+i]*b[j+2];
	    sum += L[(j+3)*ida+i]*b[j+3];

        }
	for(j=t;j<i;j++){
	    sum += L[j*ida+i]*b[j];
	}
*/	//dotv(&L[i], b, &sum, i, ida, 1);
	for(j=0;j<i;j++){
		sum += L[i+j*ida]*b[j];
	}	
        b[i] = b[i] - sum; 
	
    }
}


