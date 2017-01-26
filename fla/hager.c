#include<stdlib.h>
#include<math.h>
#include<inttypes.h>

#include "blis.h"

#include "print.h"
//#include"mkl.h"

#define dcopy dcopy_
#define dtrsv dtrsv_
#define idamax idamax_
#define dasum dasum_
#define ddot ddot_
//void hager(uplo_t uploa, trans_t transa, diag_t diaga, double* a, dim_t m, double invNorm){
/*
double judg(int t){
        if( t > 0 ){
                return 1.0;
        }else if( t < 0){
                return -1.0;
        }else{
              	return 0.0;
        }
}


void mysign(double* x, double* v, int m){
	int i;
	int temp = (m >>2)<<2;
	for(i=0;i<temp;i+=4){
		v[i]=judg(x[i]);
		v[i+1]=judg(x[i+1]);
		v[i+2]=judg(x[i+2]);
		v[i+3]=judg(x[i+3]);		
	}
	for(i=temp;i<m;i++){
		v[i]=judg(x[i]);
	}


}*/
void hager(double* a, int m, double* invNorm,char* type){
	int i, j;
	int count = 0;
	double* x;
	double* v;
	double* maxVal;
	double rho;
	double* temp;
	double* temp2;
	int64_t* maxInd;
		
	int flag = 1;
	int inc = 1;
	double* alpha;
	char lo = 'L';
	char up = 'U';
	char nt = 'N';
	char yt = 'T';
	char yd = 'U';
	char nd = 'N';	

	x = malloc(m*sizeof(double));
	v = malloc(m*sizeof(double));
	maxVal = malloc(sizeof(double));
	alpha = malloc(sizeof(double));
	temp = malloc(m* sizeof(double));
	temp2 = malloc(m* sizeof(double));
	maxInd = malloc(2*sizeof(int));

	//Initialize x
	*alpha = 1.0;
	for(i = 0; i < m; i++){
		x[i] = 1.0/m;
	}
	
	
	while(flag){
		bli_dcopyv(BLIS_NO_CONJUGATE, m, x, 1,temp,1, NULL);		

		//Solve Lb = x
		//dtrsv(&lo, &nt, &nd, &m, l, &m, x, &inc);
		if(*type == '1'){
		bli_dtrsv(BLIS_LOWER, BLIS_NO_TRANSPOSE, BLIS_UNIT_DIAG, m, alpha, a, 1, m , x,1, NULL);		
		//Solve Uy = b
		//dtrsv(&up, &nt, &nd, &m, u, &m, x, &inc);
		
		//bli_dtrsv(BLIS_UPPER, BLIS_NO_TRANSPOSE, BLIS_NONUNIT_DIAG, m, alpha, a, 1, m , x,1, NULL);		
		}
		else{
                //bli_dtrsv(BLIS_UPPER, BLIS_TRANSPOSE, BLIS_NONUNIT_DIAG, m, alpha, a, 1, m , x,1, NULL);
                //Solve Uy = b
                //dtrsv(&up, &nt, &nd, &m, u, &m, x, &inc);

                bli_dtrsv(BLIS_LOWER, BLIS_TRANSPOSE, BLIS_UNIT_DIAG, m, alpha, a, 1, m , x,1, NULL);

		}
		//dcopy(&m, x, &inc, temp2, &inc);
		bli_dcopyv(BLIS_NO_CONJUGATE, m, x, 1, temp2, 1, NULL);
		//Sign function
//		mysign(x, v, m);
		for(i=0;i<m;i++){
			if(x[i]<0){
				v[i]=-1;
			}else if(x[i]>0){
				v[i]=1;
			}else{
				v[i]=0;
			}
		}


		//Solve U'd=y
		if(*type == '1'){
		//bli_dtrsv(BLIS_UPPER, BLIS_TRANSPOSE, BLIS_NONUNIT_DIAG, m, alpha, a, 1, m , v,1, NULL);		
		//dtrsv(&up, &yt, &nd, &m, u, &m, v, &inc);
		//Solve L'g = d
		bli_dtrsv(BLIS_LOWER, BLIS_TRANSPOSE, BLIS_UNIT_DIAG, m, alpha, a, 1, m , v ,1, NULL);		
                //dtrsv(&lo, &yt, &yd, &m, l, &m, v, &inc);		
		}
		else{
		 bli_dtrsv(BLIS_LOWER, BLIS_NO_TRANSPOSE, BLIS_UNIT_DIAG, m, alpha, a, 1, m , v,1, NULL);
                //Solve Uy = b
                //dtrsv(&up, &nt, &nd, &m, u, &m, x, &inc);

                //bli_dtrsv(BLIS_UPPER, BLIS_NO_TRANSPOSE, BLIS_NONUNIT_DIAG, m, alpha, a, 1, m , v,1, NULL);

		}
		//Find ||g||_inf		
		bli_damaxv(m, v, 1, maxInd, NULL);

		//Find g*x		
		if( count == 0){
		bli_ddotv(BLIS_NO_CONJUGATE, BLIS_NO_CONJUGATE, m, v, 1, temp, 1, &rho, NULL);		
		}else{
		rho = v[ *maxInd ];
		}
		if(fabs(v[ *maxInd ]) <= rho){
			bli_dasumv(m, temp2,1,invNorm,NULL);
			flag = 0;
		}else{
			x = malloc(m*sizeof(double));
			x[*maxInd] = 1;
		}
		count++;		
	}	
		free(x);
		free(v);
		free(maxVal);
		free(temp);
		free(temp2);
}


