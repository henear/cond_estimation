#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "hager.h"
#include "oneNrm.h"
#include "infNrm.h"
#include "myrandom.h"
#include "mkl.h"

#define N 2;

int main(){
	
	
	double* a;
	
	double* invNorm;
	double* infNorm;
	double* oneNorm;
	double cond;
	int n = 256;
	int i,j;
	char on = '1';
	char in = 'I';	
	char type = on;

	a = malloc(n* n *sizeof(double));
	oneNorm = malloc(sizeof(double));
	invNorm = malloc(sizeof(double));
	infNorm = malloc(sizeof(double));
	int time =0;
	for(i=2;i<n;i<<=1){
		time+=i*i;
	}

	for(i=0;i<time;i++){
		rand();
	}
	
	random(a, n);
/*
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%f ",a[i+j*n]);
		}
		printf("\n");
	}
*/
	if(type == on){
		oneNrm(a, n, oneNorm);
	}else{
		infNrm(a, n, infNorm);
	}
	hager(a, n, invNorm, type);

	if(type==on){
	cond = (*oneNorm)*(*invNorm);
	}else{
	cond = (*infNorm)*(*invNorm);
	}
	if(type == on){
	printf("%f\n", cond);
	}else{
	printf("%f\n", cond);
	}
	free(a);
	free(infNorm);
	free(invNorm);
	free(oneNorm);
	
	return 0;
}



