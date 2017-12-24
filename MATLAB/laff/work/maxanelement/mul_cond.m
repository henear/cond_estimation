
function [c_out,r_out,l2cond]=mul_cond(n)

Singular=eye(n);
Singular(1,1) = 5;
A=rand(n,n);
B=rand(n,n);
C= A*B;
[Usvd,Ssvd,Vsvd]=svd(C);
l2cond = Singular(1,1)/Singular(n,n);
for i= 2:n-1
    Singular(i,i) = 4*rand()+1; 
end
T=Usvd*Singular*Vsvd;

[L,U,P]=lu(T);
[y,b]=trsv_ut(U);
z=trsv_lt(L,y);
d=trsv_lo(L,z);
x=trsv_up(U,d);
c_out=norm(x,2)/norm(z,2);
r_out=norm(inv(T),2);

return