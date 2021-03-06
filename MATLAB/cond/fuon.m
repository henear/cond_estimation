function[CC,DD] = fuon()
    A = zeros(1,12);
    
for i=1:12
    A(1,i)=2^i;    
end
    B=[6.091995;
140.914945;
72.749478;
195.567656;
664.242216;
33531.788588;
28538.332563;
24390.871687;
108001.138867;
374794.723595;
424193.516294;
18293639.294890
];
C=[7.091995
121.226779;
89.785865;
197.255892;
852.056556;
15248.716947;
29219.043060;
22723.199051;
262917.161343;
503495.606841;
449493.258127;
17516639.220390;
];
D=[7.091995;
140.914945;
72.749478;
224.402698;
664.242216;
1898.208824;
172564.315919;
20930.833933;
687933.042657;
374794.723595;
3356420.761346;
18293639.295415;
];
Y=[B,C,D];

for i=1:12
    
    CC(i, 1)= C(i,1) / B(i,1);
    DD(i, 1)= D(i,1) / B(i,1);
   
end
Z = [ CC, DD];
figure(1);
loglog(A, Y, 'LineStyle', 'none', 'Marker','+');
figure(2);
semilogx(A,Z,'LineStyle', 'none', 'Marker','+');
return