#include<stdlib.h>

void random(double* A, int n){
	int i, j;
	for(i = 0; i < n ; i++){
		for(j=0;j < n;j++){
			A[i + j * n] = (double)rand() / (double)RAND_MAX ;
		}
	}
	
}
