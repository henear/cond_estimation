function [] = to()
for i=1:10
    size(1,i)=i*500;
end
mkl =[   1.194e-03;
 4.300e-03;
 9.197e-03;
 1.806e-02;
 3.086e-02;
 4.557e-02;
 6.226e-02;
 8.135e-02;
 1.026e-01;
 1.261e-01
];
fla =[ 5.069e-04;
 2.815e-03;
 6.836e-03;
 1.239e-02;
 2.001e-02;
 2.882e-02;
 3.944e-02;
 5.148e-02;
 6.525e-02;
 8.022e-02;

];
nai=[ 5.341e-04;
 7.361e-03;
 2.133e-02;
 4.386e-02;
 7.355e-02;
 1.166e-01;
 1.733e-01;
 2.323e-01;
 3.210e-01;
 3.935e-01
];
X = size;
Y=[mkl,fla,nai];
stem(X,Y,'LineStyle','none');
legend('mkl','fla','Clib');
title('Performance of Triangular Matrix, L_{1} norm')
xlabel('size');
ylabel('seconds')
return