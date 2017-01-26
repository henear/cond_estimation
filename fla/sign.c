#include<stdio.h>
#include<stdlib.h>
double judge(int t){
        if( t > 0 ){
                return 1.0;
        }else if( t < 0){
                return -1.0;
        }else{
              	return 0.0;
        }
}

void sign(double* x, double* y, int m){
	int i;
	int a = m >> 2;
	int b = a << 2;	
	for(i = 0;i < b; i+=4){
		y[i] = judge(x[i]);
		y[i+1] = judge(x[i+1]);
		y[i+2] = judge(x[i+2]);
		y[i+3] = judge(x[i+3]);	
	}	

	for(i = b ; i< m; i++){
		y[i] = judge(x[i]);
	}
}

/*
int main(){
double* x;
double* y;
x = malloc(10*sizeof(double));
y = malloc(10*sizeof(double));
int i;
for(i=0;i<10;i++){
x[i] = 8-i;
}
sign(x,y,10);
for(i=0;i<10;i++){
printf("y[%d] is %f\n",i,y[i]);
}
}
*/
