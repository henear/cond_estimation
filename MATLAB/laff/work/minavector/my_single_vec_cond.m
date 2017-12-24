
function[c_cond,r_cond,l2_norm] = my_single_vec_cond(n)
A= rand(3,3);
B= rand(3,3);
[Usvd, Ssvd, Vsvd]=svd(A*B);
Ssvd=eye(3);
Ssvd(3,3)=1/n;
Ssvd(2,2)=rand()*(1-1.0/n)+1.0/n;
test=Usvd*Ssvd*Vsvd;
[Lfac,Ufac,Pfac]=lu(test);
[y_out,b_out]=trsv_ut(Ufac);
[z_out]=trsv_lt(Lfac,y_out);
[d_out]=trsv_lo(Lfac,z_out);
[x_out]=trsv_up(Ufac,d_out);
r_cond=norm(inv(test),1);
c_cond=norm(x_out,1)/norm(z_out,1);
l2_norm= n;
return
