function[C]=mul(n)
A = rand(n, n);
B = rand(n, n);
C = rand(n, n);
nc=4;
kc=4;
mc=4;
nr=2;
mr=2;
for jc=1:nc:n
    Jc = jc:jc+nc-1;
    for pc=1:kc:n
        Pc = pc:pc+kc-1;
        Bc = B(Pc,Jc);
        for ic=1:mc:n
            Ic = ic:ic+mc-1;
            Ac = A(Ic, Pc);
            for jr=1:nr:nc
                Jr = jr:jr+nr-1;
                for ir=1:mr:mc
                    Ir = ir:ir+mr-1;
                    for kr=0:kc-1
                        C(Ir,Jr)=C(Ir,Jr)+Ac(Ir, kr)*Bc(kr, Jr);
                    end
                end
            end
        end
    end
end
return