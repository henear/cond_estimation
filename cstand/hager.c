#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include"upyb.h"
#include"utyb.h"
#include"ltyb.h"
#include"loyb.h"
#include"sign.h"
#include"norm1v.h"
#include"normiv.h"
#include"copy.h"
#include"lufac.h"
#include"print.h"
#include"mkl.h"

void sumIt(double* v,int m,double* psum){
	double temp = 0;
	int i;
	int bi = (m>>2)<<2;
	for(i=0;i<bi;i+=4){
		temp+=v[i];
		temp+=v[i+1];
		temp+=v[i+2];
		temp+=v[i+3];
	}
	for(i=bi;i<m;i++){
		temp+=v[i];
	}
	*psum = temp;
}

void hager(double* a, int m, double* invNorm, char type){
	int i;
	double* psum;
	double* x;
	double* v;
	double* maxVal;
	double* rho;
	double* temp;
	double* temp2;
	int* maxInd;
	int flag = 1;
	int* ipiv;
	x = malloc(m*sizeof(double));
	v = malloc(m*sizeof(double));
	maxVal = malloc(sizeof(double));
	maxInd = malloc(sizeof(int));
	rho = malloc(sizeof(double));
	temp = malloc(m* sizeof(double));
	temp2 = malloc(m* sizeof(double));
	psum = malloc(sizeof(double));
	ipiv = malloc(sizeof(int));
	//Initialize x
	int info;
	for(i = 0; i < m; i++){
		x[i] = 1.0/m;
	}

	
	//LU factorization of A
	dgetrf(&m, &m, a, &m, ipiv,&info);
//	lufac(a, m);

	double det = 1.0;
	for(i=0;i<m;i++){
		det = det * a[i*m+i];
	}
	
/*	if(det > 1e8){
		for(i=0;i<m*m;i++){
			a[i] /= 1e8;
		}
	}
*/	int count = 0;
	while(flag){		
		copy(x, temp, m);
		if(type == '1'){
		//Solve Lb = x
		loyb(a, x, m);

		//Solve Uy = b
		upyb(a, x, m);		
		}else{
		utyb(a, x, m);
		ltyb(a, x, m);
		}
		
		copy(x, temp2, m);
		//Sign function
		sign(x, v, m);	
		//Solve U'd=y
		if(type == '1'){
		utyb(a, v, m);		

		//Solve L'g = d
		ltyb(a, v, m);
		}else{
		loyb(a, v, m);
		upyb(a, v, m);			
		}
		//Find ||g||_inf
		normiv(v, maxVal, m, maxInd);
		
		//Find g*x
		if(count == 0){	
			sumIt(v,m,psum);
			*rho = *psum / m;	
		}else{
		*rho=v[*maxInd];
		}
		
		if(*maxVal <= *rho){
			norm1v(temp2, invNorm, m);
			flag = 0;
		}else{
                        x = malloc(m*sizeof(double));
                        x[*maxInd] = 1;
		}
		count++;			
	}
	free(psum);
	free(x);
	free(v);
	free(temp);
	free(temp2);
	free(rho);
	free(maxInd);
	free(ipiv);
	free(maxVal);
}



