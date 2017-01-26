#include<stdio.h>
#include<stdlib.h>
#include "myrandom.h"
#include"mkl.h"

#define N 4

void myst(int k){
int j;
int n = k;
int i;
int info;
char on = '1';
char in = 'I';
char type = on;
double* A;
double* WOR;
int* iwork;
WOR = malloc(4*n*sizeof(double));
double* WORK;
double rcond;
double cond;
int *ipiv;
ipiv = malloc(n*sizeof(int));
iwork = malloc(n*sizeof(int));
A = malloc(n*n*sizeof(double));
//Create the random matrix
myrandom(A, n);
/*
for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		printf("%f ",A[i+j*n]);
	}
	printf("\n");
}*/
WORK = malloc(n*sizeof(double));
double anorm = dlange(&type,&n,&n,A,&n,WORK);

//dgetrf(&n, &n, A, &n, ipiv, &info);
double base = 1.0;

dgecon(&type,&n,A,&n,&anorm,&rcond,WOR,iwork,&info);
cond = 1.0 / rcond;
printf("%f\n",cond);

}

int main(){
	int i;
//	for(i=2;i<20;i+=2){
//	printf("%d ",i);
	myst(4);
//	}
	return 0;
}
