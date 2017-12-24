function [c]=multiple(m)
c = zeros(1,9);
for i=1:50
    c = c+ difcond(9,m);
end
c=c/50;
return