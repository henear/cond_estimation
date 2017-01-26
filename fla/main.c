#include "hager.h"
#include "FLAME.h"
#include "blis.h"
#include "myrandom.h"

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 4;
#define repeat 3;
#define M 10;

int main(){
//Specify the type of the norm
	char on = '1';
	char in = 'I';
	char type = in;

//Other variables
	double* cand;
	double* B;
	double* LU;
	int i;
	int ri;
	int size;
	int maxn = M;
	int nrepeat = repeat;
	double* buffer;
	double* oneNorm;
	int* bufp;
	int m ; 
	int rs= 1;
	int cs=m;
	FLA_Obj p;
	FLA_Obj A;
	double norm;
	double cond;	
	double gflop;
	double time_beginer;
	double duration_time;
	double rectime;
	double* conds;
// Initialize libflame.
	

	for(size = 0 , ri = 1; size < maxn; size++, ri++){
		m = (size + 1)*500 ;
		cs = m;

		FLA_Init();
		bli_init();
		//FLA_Queue_set_num_threads(4);
		LU = malloc(m*m*sizeof(double));
		B = malloc(m*m*sizeof(double));
		bufp = malloc(m*sizeof(int));
		buffer= malloc(m*m*sizeof(double));
		oneNorm = malloc(sizeof(double));
		cand = malloc(m * m* sizeof(double));
	

// Initialize random matrix
		myrandom(cand, m);	
	
// Get the matrix buffer address, size, and row and column strides.
// Create an m x m double-precision libflame object without a buffer,
// and then attach the matrix buffer to the object.
	
		FLA_Obj_create_without_buffer( FLA_DOUBLE, m, m, &A );
		FLA_Obj_attach_buffer( buffer, rs, cs, &A );
		FLA_Copy_buffer_to_object(FLA_NO_TRANSPOSE, m, m, cand, rs, cs, 0, 0, A);
		FLA_Obj_create_without_buffer(FLA_INT, m, 1,  &p);
		FLA_Obj_attach_buffer(bufp, 1, 1, &p);	
// Compute the l1 norm of the matrix
		for (i = 0; i< nrepeat;i++){
			time_beginer = omp_get_wtime();
		
			if( type == on ){
				bli_dnorm1m(m-1, 0, BLIS_DENSE, m, m, cand, 1, m, &norm, NULL);
			}else{
				bli_dnormim(m-1, 0, BLIS_DENSE, m, m, cand, 1, m, &norm, NULL);
			}

// Compute the LU factorization, storing to the lower triangle.

//	FLA_LU_piv(  A, p );
//	FLA_Obj_show("LU: ", A, "%f","\n");
			FLA_Copy_object_to_buffer(FLA_NO_TRANSPOSE, 0, 0, A, m, m, LU, rs, cs);

// Compute the inverse norm of a matrix
			hager(LU, m, oneNorm, &type);	
 			duration_time = omp_get_wtime() - time_beginer;

// Compute the condition number
			if(i == 0){
				cond = (*oneNorm) * norm;
				rectime = duration_time;
                	}else{
                 	       rectime = duration_time < rectime ? duration_time:rectime;
         	       }
		}

		gflop = ( 4.0*m*m + 7.0*m)/ (rectime * 1.0e9);
//        	printf("data_matrix ( %1lu, 1:4 ) = [ %4lu %10.3e %10.3e %10.7f ];\n", ri,ri*500, cond, rectime,gflop );
		printf("%10.3e\n", rectime);

// Free the object without freeing the matrix buffer.
		FLA_Obj_free_without_buffer( &A );
		FLA_Obj_free_without_buffer( &p );
	
// Free the matrix buffer.
		free( oneNorm );
		free( buffer );
		free( bufp );
		free( cand );
		free( LU );
		free( B );

// Finalize libflame.
		bli_finalize();
		FLA_Finalize();
	}
	return 0;
}
