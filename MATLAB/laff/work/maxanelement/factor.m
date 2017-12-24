function [a,b,c]=factor()
a=0;
b=0;
c=0;

for i= 1:800
    an=difcond();
    if an==1
        a=a+1;
    elseif an==2
        b=b+1;
    else c=c+1;
    end
end
return