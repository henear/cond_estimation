#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void swap(double* v, int i, int j) {
  double vv;
  vv = v[i];
  v[i] = v[j];
  v[j] = vv;
}

void swapRows(double* A, int i, int j, int n,int lda) {
  // E_i <--> E_j
	double aa;
	int k;
	int temp;
  for(k=0; k<n; k++) {
    temp = k*lda;
    aa = A[i+temp];
    A[i+temp] = A[j+temp];
    A[j+temp] = aa;
  }
}

void rowReplacement(double* A, int i, int j,int n, int lda) {
  // E_j --> E_j - (a(j,i)/a(i,i))E_i
  double f;
  int k;
  int temp = i*lda;
  f = A[j+temp] / A[temp+i];
  A[j+temp] = f;
  for(k=i+1; k< n; k++) {
    A[j+k*lda] -= f*A[i+k*lda];
  }
}

void lufac(double* A, int n) {
	
	double* s;
	double pivot;
	double q;
	
  	int lda = n;
  	int i,j,k;  

	s = malloc(n*sizeof(double));
  
  // Determine scale factors for scaled partial pivoting
  
  for( i=0; i<n; i++) {
    s[i] = fabs( A[i] );
    for( j=1; j<n; j++) {
      if( s[i] < fabs (A[i + j*lda]) ) {
      	s[i] = fabs( A[i + j*lda] );
    }
  }

  // Loop on Columns
  for(j=0; j<n; j++) {

    // Get nonzero pivot (use scaled partial pivoting)
     pivot = fabs(A[j+j*lda]) / s[j];
    i = j;
    for(k=j+1; k<n; k++) {
      q = fabs(A[k+j*lda])/s[k];
      if(q > pivot) {
		pivot = q;
        i = k;
      }
    }
    
    if(i != j) {
      swapRows(A,i,j,n,lda);
      swap(s,i,j);
      
    }

    // Loop on rows
    for(i=j+1; i<n; i++){
      rowReplacement(A,j,i,n,lda);
    } 
  }
  }
}


