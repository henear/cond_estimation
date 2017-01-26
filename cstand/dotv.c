#include <stdio.h>
#include <stdlib.h>
void dotv(double* x, double* y,double* rho, int m,int gapx, int gapy){
	double sum = 0;
	int i, j;
	j = 0;
	int bound = ((m*m)>>2)<<2;
	printf("bound is %d\n",bound);
	if( gapx > 0 ) {
		for(i = 0; i < bound;i+=4*gapx){
			sum += x[i] * y[j];
			sum += x[i + gapx] * y[j + gapy];
			sum += x[i + 2 * gapx] * y[j + 2 * gapy];
			sum += x[i + 3 * gapx] * y[j + 3 * gapy];
			j   += 4 * gapy;
 	    }
		for(i = bound; i< m*m; i+= gapx){
			sum += x[i] * y[j];
			j   += gapy;
	    }   
	*rho = sum;
	}/*
	else{
		//gapx<0
		int temp = m%4;
		for( i = m-1; i>=temp;i-=4*gapx){
			sum += x[i]*y[i];
			sum += x[i+gapx]*y[i+gapy];
			sum += x[i+2*gapx]*y[i+2*gapy];
			sum += x[i+3*gapx]*y[i+3*gapy];
		}
		for(i = temp-1; i>= m; i-= gapx){
			sum += x[i]*y[i];
	    }
	*rho = sum;
	}*/
}


