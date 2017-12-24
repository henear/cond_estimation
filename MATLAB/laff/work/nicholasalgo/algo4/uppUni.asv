function [U]=uppUni(n)
A = rand(n,n);
[L,U,P] = lu(A);
for i=1:n
    U(i)= U(:,i)/norm(U(:,i),2);
end

return