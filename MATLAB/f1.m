function [] = f1()
for i=1:10
    size(1,i)=i*1000;
end
mkl =[ 4.071e-02;
 2.899e-01;
 9.349e-01;
 2.169e+00;
 4.107e+00;
 6.975e+00;
 1.088e+01;
 1.612e+01;
 2.284e+01;
 3.120e+01
];
fla =[ 5.246e-02;
 3.466e-01;
 1.085e+00;
 2.473e+00;
 4.721e+00;
 8.020e+00;
 1.256e+01;
 1.858e+01;
 2.633e+01;
 3.587e+01
];
X = size;
Y=[mkl,fla];
stem(X,Y,'LineStyle','none');
legend('mkl','fla');
title('Performance of Full Matrix, L_{1} norm')
xlabel('size');
ylabel('seconds')
return