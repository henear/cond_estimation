#include<stdlib.h>

#include "norm1v.h"
#include "normiv.h"

void oneNrm(double* a, int n, double* oneNorm){
	int i;
	double* cand;	
	int* maxInd;

	cand = malloc(n*sizeof(double));
	maxInd = malloc(sizeof(int));

	for(i = 0; i < n;i++){
		norm1v(&a[i*n], &cand[i], n);
	}
		normiv(cand, oneNorm, n, maxInd);
		free(cand);
		free(maxInd);
}
