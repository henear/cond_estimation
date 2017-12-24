function [ratio]=dimvar(n)
estcond=zeros(1,9);
realcond=zeros(1,9);

ratio=zeros(1,9);

for a=1:50
for i= 1:9
    A = rand(n, n);
    [Usvd, Ssvd, Vsvd]=svd(A);
    Ssvd(1,1)= 1;
    Ssvd(n,n)=10^(-i);
    
    for j= 2:n-1
    Ssvd(j, j)= rand()*(1-Ssvd(n, n))+Ssvd(n,n);
    end
    T =Usvd*Ssvd*Vsvd';
    [Q, R] = qr(T);
    [estcond(1,i),realcond(1,i)]=convex(n,R);
    ratio(1,i)=ratio(1,i)+estcond(1,i)/realcond(1,i);
end
end
for i=1:9
ratio(1,i)=ratio(1,i)*.02;
end
return