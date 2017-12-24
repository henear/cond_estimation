function [X] = dimvar(n)
dimension=zeros(1,n);
mycond=zeros(1,n);
realcond=zeros(1,n);
relerr=zeros(1,n);
    for i=1:n     
        
        [c_out,r_out,l2cond]=mul_cond(2^i);
        dimension(1,i)=2^i;
        mycond(1,i)=c_out;
        realcond(1,i)=r_out;
        relerr(1,i)=(r_out-c_out)/r_out;
    end
    X=dimension;
    Y = [mycond;realcond]';
    Z=relerr;
    figure(1);
    semilogx(X,Z,'LineStyle','none');
    figure(2);
    semilogx(X,Y);
return