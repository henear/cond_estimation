function [result]=factor(n)
a=0;
b=0;
for i=1:n
count=dimvar(40);
a=a+count(1,1);
b=b+count(1,2);
end
result=zeros(1,2);
result(1,1)=a;
result(1,2)=b;
return