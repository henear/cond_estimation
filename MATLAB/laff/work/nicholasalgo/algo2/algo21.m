function[upbd,rcond]=algo21(n)
T = rand (n,n);
z = zeros(1,n);
[L, U, P] = lu(T);
for i= 1:n
z(1, i)=1 /(U(i,i));
end
for i=n-1:-1:1
s=1;
for j=i+1:n
    s=s+abs(U(i, j))*z(1,j);
end
disp(s);
    z(1,i)=s/U(i,i);
end
upbd=max(abs(z));
rcond=norm((inv(U)),'inf');
return