#include<math.h>

void norm1v(double* x,double* vecNorm, int m){
	int i;
	int t = (m>>2)<<2;
	double temp = 0;
	for(i=0;i<t;i+=4){
		temp += fabs(x[i]);
		temp += fabs(x[i+1]);
		temp += fabs(x[i+2]);
		temp += fabs(x[i+3]);	
	}
	for(i=t;i<m;i++){
		temp += fabs(x[i]);
	}
	*vecNorm = temp;	
}
