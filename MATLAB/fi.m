function [] = fi()
for i=1:10
    size(1,i)=i*1000;
end
mkl =[  3.999e-02;
 2.876e-01;
 9.266e-01;
 2.133e+00;
 4.156e+00;
 6.940e+00;
 1.084e+01;
 1.603e+01;
 2.279e+01;
 3.110e+01;

];
fla =[ 6.052e-02;
 3.850e-01;
 1.186e+00;
 2.675e+00;
 5.054e+00;
 8.504e+00;
 1.324e+01;
 1.952e+01;
 2.758e+01;
 3.750e+01;
];

X = size;
Y=[mkl,fla];

stem(X,Y,'LineStyle','none');
legend('mkl','fla');
title('Performance of Full Matrix, L_{\infty} norm')
xlabel('size');
ylabel('seconds')
return