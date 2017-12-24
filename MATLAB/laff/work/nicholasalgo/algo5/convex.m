function[rho, real]=convex(n,T)

b = zeros(n, 1);
real = norm(inv(T), 1);
%set b
cand = zeros(n,1);
for i = 1:n
    b(i, 1)= 1/n;
end
%rho = 0;
%for do loop
for c = 1:n

%solve Ax=b
[L, U, P] =lu(T);
bt = P*b;
temp= trsv_lo(L, bt);
x   = trsv_up(U, temp);
cand(i,1)=norm(x,1);
% if norm(x,1) <= rho
%     break
% else
%     %rho = norm(x,1);
% end 
y = sign(x);
% Solve A^{T}z=y
[L2,U2,P2]=lu(T');
yt= P2*y;
temp2 = trsv_lo(L2, yt);
z = trsv_up(U2, temp2);
[maxval, index]=max(abs(z));
if maxval < dot(z,b)
    break
else
    b=zeros(i,1);
    b(index,1) = 1;
end% end if
end% end for
    rho = max(cand);
return % end procedure