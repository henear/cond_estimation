function [] = ti()
for i=1:10
    size(1,i)=i*500;
end
mkl =[    1.084e-03;
 3.885e-03;
 8.318e-03;
 1.602e-02;
 2.743e-02;
 4.075e-02;
 5.629e-02;
 7.396e-02;
 9.347e-02;
 1.153e-01

];
fla =[ 
 5.710e-04
 1.089e-02
 2.566e-02
 5.111e-02
 8.161e-02
 1.271e-01
 1.870e-01
 2.517e-01
 3.282e-01
 4.113e-01


];
nai=[ 4.790e-04; 7.566e-03; 2.133e-02; 4.275e-02; 7.049e-02; 1.142e-01; 1.696e-01; 2.295e-01; 3.100e-01; 3.985e-01;
];
X = size;
Y=[mkl,fla,nai];
stem(X,Y,'LineStyle','none');
legend('mkl','fla','Clib');
title('Performance of Triangular Matrix, L_{\infty} norm')
xlabel('size');
ylabel('seconds')

return