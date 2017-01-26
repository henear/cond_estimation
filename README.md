# cond_estimation
This is my code for estimating the condition number of a given matrix.
Condition number of a matrix is defined as its norm and the inverse norm of the matrix.
The matrix has to be square matrix and column  - major stored in an 1d array.
BLAS represents building our estimation code on the top of BLAS library(Basic Linear Algebra Subprograms), 
the standard linear algebra computing library.
Cstand folder represents building the algorithm on top of the C standard library.
FLA The code build on top of the blis library.
FLASH The code build on the top of blis and flash library
Thanks to the high performance computing group in the University of Texas at Austin for giving me permissions
using the BLIS and FLASH library and their help during the development of codes here during 2016 Summer.
