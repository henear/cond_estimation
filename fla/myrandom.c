#include<stdlib.h>

void myrandom(double* A, int n){
	int i, j;
	for(i = 0; i < n ; i++){
		for(j = 0;j < i;j++){
			A[i + j * n] =  (double)rand() / (double)RAND_MAX ;
		}
			A[i + i * n] = 1;
	}
}
