function[lo,err]=dimvar(n)
X= zeros(1,n);
real=zeros(1,n);
lowbound=zeros(1, n);
relerr=zeros(1, n);
for j=1:n
    X(1,j)=2^j;
    [lowbound(1, j),real(1, j)]=algo41(2^j);
    relerr(1, j)=  abs(1 - lowbound(1, j)/real(1, j));
    
end
figure(1);
Y= [lowbound;real]';
lo =loglog(X, Y);
figure(2);
Z = relerr;
err = semilogx(X, Z,'Marker','+','LineStyle','none');
return