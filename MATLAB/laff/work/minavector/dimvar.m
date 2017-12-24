function[err_out,h_out,X,Y]= dimvar(n)

dimension=zeros(1,n);
mycond=zeros(1,n);
realcond=zeros(1,n);
relerr=zeros(1,n);
l2normv=zeros(1, n);
modi=zeros(1, n);
    for i=1:n
        dimension(1,i)= pow2(i);
        [c_out,r_out,l2norm]=my_single_vec_cond(pow2(i));
        mycond(1,i)=c_out;
        modi(1, i)= 1.23*mycond(1, i);
        realcond(1,i)=r_out;
        l2normv(1, i)=l2norm;
        relerr(1,i)=abs(modi(1, i)/realcond(1, i) -1);
    end
   
    X=l2normv;
    Y = [modi;realcond]';
    %Y=ones(1,n);
    Z=relerr;
    figure(2);
    err_out=semilogx(X,Z,'Marker','+','LineStyle','none');
    figure(1);
    h_out=loglog(X,Y);
    
return