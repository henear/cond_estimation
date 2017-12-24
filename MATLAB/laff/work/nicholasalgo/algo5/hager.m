function [mynorm,realnorm,A]=hager(n)
A = eye(n);
realnorm=norm(inv(A),1);
b = zeros(n,1);
rho = 0;
mynorm =0;
for i=1:n
    b(i,1) = 1;
    x= A\b;
    if norm(x,1)<= rho
        mynorm = rho;
        break;
    else
        rho = norm(x,1);
    end
    y = sign(x);
    z = A'\y;
    imax = find(z == max(max(z)));
    if z(imax)< dot(z, b)
        mynorm = rho;
        break;
    else
        b = zeros(n,1);
    end
end
        
    