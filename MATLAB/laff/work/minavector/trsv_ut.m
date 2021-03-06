% Copyright 2016 The University of Texas at Austin
%
% For licensing information see
%                http://www.cs.utexas.edu/users/flame/license.html 
%                                                                                 
% Programmed by: Name of author
%                Email of author

function [ y_out,b_out ] = trsv_ut( U )
   y=zeros(size(U,1),1);
   b=ones(size(U,1),1);
  [ UTL, UTR, ...
    UBL, UBR ] = FLA_Part_2x2( U, ...
                               0, 0, 'FLA_TL' );

  [ yT, ...
    yB ] = FLA_Part_2x1( y, ...
                         0, 'FLA_TOP' );

  [ bT, ...
    bB ] = FLA_Part_2x1( b, ...
                         0, 'FLA_TOP' );

  while ( size( UTL, 1 ) < size( U, 1 ) )

    [ U00,  u01,       U02,  ...
      u10t, upsilon11, u12t, ...
      U20,  u21,       U22  ] = FLA_Repart_2x2_to_3x3( UTL, UTR, ...
                                                     UBL, UBR, ...
                                                     1, 1, 'FLA_BR' );

    [ y0, ...
      psi1, ...
      y2 ] = FLA_Repart_2x1_to_3x1( yT, ...
                                    yB, ...
                                    1, 'FLA_BOTTOM' );                         
    [ b0, ...
      beta1, ...
      b2 ] = FLA_Repart_2x1_to_3x1( bT, ...
                                    bB, ...
                                    1, 'FLA_BOTTOM' );

   

    %------------------------------------------------------------%

    psi1=(1-transpose(u01)*yT)/upsilon11;
    tempvec1=psi1*transpose(u12t)-b2;
    temp=(-1-transpose(u01)*yT)/upsilon11;
    tempvec2=temp*transpose(u12t)-b2;
    if(norm(tempvec2,1)>norm(tempvec1,1))
        beta1=-1;
        psi1=temp;
    end
    
    %------------------------------------------------------------%
    
   
    [ UTL, UTR, ...
      UBL, UBR ] = FLA_Cont_with_3x3_to_2x2( U00,  u01,      U02,  ...
                                             u10t, upsilon11, u12t, ...
                                             U20,  u21,      U22, ...
                                             'FLA_TL' );

    [ yT, ...
      yB ] = FLA_Cont_with_3x1_to_2x1( y0, ...
                                       psi1, ...
                                       y2, ...
                                       'FLA_TOP' );
     [ bT, ...
       bB ] = FLA_Cont_with_3x1_to_2x1( b0, ...
                                       beta1, ...
                                       b2, ...
                                       'FLA_TOP' );

   
  
  end

 
  y_out = [ yT
            yB ];
   b_out = [ bT
             bB ];
  
return 