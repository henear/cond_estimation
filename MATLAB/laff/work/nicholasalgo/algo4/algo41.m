function [esti_inv_norm, real_inv_norm] = algo41(n,m)
%Get a random vector x, random matrix A and factoriza it into form LU
A = rand(n,n);
B = rand(n,n);
[Usvd, Ssvd, Vsvd]=svd(A*B);
Singular = eye(n);
Singular(1,1)=10^m;
for i = 2:n-1
    Singular(i, i)=(Singular(1,1)-1)*rand()+1;
end
T = Usvd*Singular*Vsvd';
gamma=zeros(5,1);
[L, U, P]=lu(T);
 x = rand(n,1);
 x = x/norm(x,2);
 
     for j = 1:5
        x = inv(U*U')*x;
        
         %t = trsv_lo(L, x);
         %x = trsv_lt(L, t);
         exp = 1/(2*j);
         gamma(j) = (norm(x, 2))^(exp);
         if j >= 3
             if gamma(j)<=gamma(j-2)
                 esti_inv_norm=max(gamma(1:j));
                     break
             end 
         end
         gammatemp=gamma(1:5);
         esti_inv_norm=max(gammatemp);         
     end
      real_inv_norm=norm(inv(U),2);
return