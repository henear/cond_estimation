function [c_out,r_out]=my_cond(n,m)
%function [T,P,x,z]=my_cond(n,m)
Singular=eye(m);
Singular(m, m) = 1/n;
A=rand(m,m);

[Usvd,Ssvd,Vsvd]=svd(A);

for i=2:m-1
Singular(i,i) = 1/n+(1-1/n)*rand();
end
T=Usvd*Singular*Vsvd';
%[Q, R] = qr(T);

[L,U,P]=lu(T);
[y,b]=trsv_ut(U);
z=trsv_lt(L,y);
d=trsv_lo(L,z);
x=trsv_up(U,d);
c_out=norm(x, 1)/norm(z, 1);
r_out=norm(inv(P*T), 1);

return