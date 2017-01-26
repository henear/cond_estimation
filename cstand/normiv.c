#include<math.h>

void normiv(double* x, double* maxVal, int m, int* maxInd){
	int i;
	
	double maxv = x[0];
	int maxi = 0;
	for(i = 1; i < m; i++){
		if(fabs(x[i]) > maxv){
			maxv = fabs(x[i]);
			maxi = i;
		}
	}

	*maxVal = maxv;
	*maxInd = maxi;
}
