#include<math.h>

double judge(double a){
	if(a >= 0){
		return 1.0;
	}else{
		return -1.0;
	}
}

void sign(double* x, double* y, int m){
	int i;
	int t = (m>>2)<<2;
	for(i=0;i<t;i+=4){
		y[i]=judge(x[i]);
		y[i+1]= judge(x[i+1]);
		y[i+2]=judge(x[i+2]);
		y[i+3]= judge(x[i+3]);
	}
	for(i=t;i<m;i++){
		y[i]=judge(x[i]);
	}
}


