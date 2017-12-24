function [e3]=difcond (n,m)
%m is the size of the matrix
%n is the condition number controller
X = zeros(1, n);
c = zeros(1, n);

r = zeros(1, n);
e3= zeros(1, n);
for j=1:50
for i= 1:n
    X(1, i)= 10^i;
    [c(1, i), r(1, i)] = my_cond(10^i,m);   
    
    e3(1, i) = e3(1,i)+ c(1, i)/r(1, i);
end
end
    e3= 0.02*e3;
% Y=[c3;r]';
% figure(1);
% loglog(X,Y');
%  figure(2);
%  semilogx(X,e3');    
return