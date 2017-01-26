#include<stdio.h>
#include<stdlib.h>

void print(double* x, int m){
	int i;
	for(i=0;i<m;i++){
		printf("[%d]: %f\n",i, x[i]);
	}
}
