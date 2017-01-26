#include "FLAME.h"
#include "blis.h"
#include "hager.h"
#include<omp.h>
#include "myrandom.h"

#define M 11000;
#define repeat 3;

//Specify 1 norm or inf norm
void myflash(int n){
	char on = '1';
	char in = 'I';
	char type = in;

//Other variables
	void* bufoa;
	void* LU;
	double norm;
	double invNorm;
	double cond;
	double time_beginer;
	double duration_time;
	double rectime;
	double gflop;
	int ri = n;
	int nrepeat = repeat;
	int i;
	dim_t m = n;
	dim_t rs = 1;
	dim_t cs = n;
	dim_t b = 192;
	FLA_Obj A;
	FLA_Obj p;
	bufoa = malloc(m*m*sizeof(double));
	LU = malloc(m* m* sizeof(double));
	
// Initialize libflame.
	FLA_Init();
	bli_init();
	
//Create A and p
	FLASH_Obj_create( FLA_INT, m, 1, 1, &b, &p ); 
	FLASH_Obj_create( FLA_DOUBLE, m, m, 1, &b, &A );

//Set number of threads
	FLASH_Queue_set_num_threads( 1 );

//Initialize the matrix
//	FLASH_Random_matrix(A);	
	myrandom(bufoa, m);
	FLASH_Copy_buffer_to_hier(m, m, bufoa, rs, cs, 0, 0, A);
//	FLASH_Obj_show("A:", A,"%f","\n");
	
//Compute the 1 norm of matrix A
	FLASH_Copy_hier_to_buffer(0, 0, A, m, m, bufoa, rs, cs);

	for(i=0; i<nrepeat; i++){
		
		time_beginer = omp_get_wtime();

		if(type == on){
			bli_dnorm1m(m-1, 0, BLIS_DENSE, m, m, bufoa, 1, m, &norm, NULL);
 		}else{
                	bli_dnormim(m-1, 0, BLIS_DENSE, m, m, bufoa, 1, m, &norm, NULL);
		}
	//	printf("norm is %f", norm);
// Compute the LU factorization of matrix
	
 //		FLASH_LU_piv(A, p);
//	FLASH_Obj_show("A':", A,"%f","\n");
		FLASH_Copy_hier_to_buffer(0, 0, A, m, m, LU, rs, cs);

// Compute the inverse norm
		hager(LU, m, &invNorm, &type);
		duration_time = omp_get_wtime() - time_beginer;

 		if ( i == 0){
                  cond = norm * invNorm;
                  rectime = duration_time;
                }else{
                  rectime = duration_time < rectime ? duration_time:rectime;
		}
	}
// Compute and output the result
//	cond = norm * invNorm;
/*	if( type == 'I' ){
		printf("Condition number under linf norm is %f\n",cond);
	}else{
		printf("Condition number under lone norm is %f\n",cond);
	}
*/	
	gflop = (4.0*m*m +7.0*m)/(rectime * 1.0e9);
//	printf("rectime is %lf\n",rectime);
	printf("data_matrix (%2lu, 1:4) =[ %4lu %10.3e %10.3e %6.3f ];\n", ri/500,ri, cond, rectime, gflop);
// Free the object
	FLASH_Obj_free( &A );
	FLASH_Obj_free( &p );
       
// Free the matrix buffer.
 	free( bufoa );
	free( LU);
// Finalize libflame.
	FLA_Finalize();
	bli_finalize();
	

}

int main( void ){
	int i;
	int maxn = 5500;
	for (i = 500; i < maxn; i+=500){
        	myflash(i);
	}
        return 0;
}
