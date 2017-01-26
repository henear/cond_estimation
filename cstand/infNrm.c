#include <stdlib.h>

#include "normiv.h"

void infNrm(double* a, int n, double* infNorm){
	int i, j;
	double* cand;
	int* maxInd;

	cand = malloc(n*sizeof(double));
	maxInd = malloc(sizeof(int));

	for(i = 0; i < n;i++){
		for(j=0; j<n; j++){
			cand[i]+=a[i+j*n];
		}
	}
		normiv(cand, infNorm, n, maxInd);
		free(cand);
		free(maxInd);

}

