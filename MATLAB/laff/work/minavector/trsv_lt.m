
% Copyright 2016 The University of Texas at Austin
%
% For licensing information see
%                http://www.cs.utexas.edu/users/flame/license.html 
%                                                                                 
% Programmed by: Name of author
%                Email of author

function [ x_out ] = trsv_lt( L,  y )
  x=zeros(size(L,1),1);
  [ LTL, LTR, ...
    LBL, LBR ] = FLA_Part_2x2( L, ...
                               0, 0, 'FLA_BR' );

  [ xT, ...
    xB ] = FLA_Part_2x1( x, ...
                         0, 'FLA_BOTTOM' );

  [ yT, ...
    yB ] = FLA_Part_2x1( y, ...
                         0, 'FLA_BOTTOM' );

  while ( size( LBR, 1 ) < size( L, 1 ) )

    [ L00,  l01,       L02,  ...
      l10t, lambda11, l12t, ...
      L20,  l21,       L22 ] = FLA_Repart_2x2_to_3x3( LTL, LTR, ...
                                                      LBL, LBR, ...
                                                      1, 1, 'FLA_TL' );

    [ x0, ...
      chi1, ...
      x2 ] = FLA_Repart_2x1_to_3x1( xT, ...
                                    xB, ...
                                    1, 'FLA_TOP' );

    [ y0, ...
      psi1, ...
      y2 ] = FLA_Repart_2x1_to_3x1( yT, ...
                                    yB, ...
                                    1, 'FLA_TOP' );

    %------------------------------------------------------------%

    %                       update line 1                        %
    %                             :                              %
    %                       update line n                        %

    %------------------------------------------------------------%
    chi1=(psi1-transpose(l21)*x2)/lambda11;
    [ LTL, LTR, ...
      LBL, LBR ] = FLA_Cont_with_3x3_to_2x2( L00,  l01,       L02,  ...
                                             l10t, lambda11, l12t, ...
                                             L20,  l21,       L22, ...
                                             'FLA_BR' );

    [ xT, ...
      xB ] = FLA_Cont_with_3x1_to_2x1( x0, ...
                                       chi1, ...
                                       x2, ...
                                       'FLA_BOTTOM' );

    [ yT, ...
      yB ] = FLA_Cont_with_3x1_to_2x1( y0, ...
                                       psi1, ...
                                       y2, ...
                                       'FLA_BOTTOM' );

  end

  x_out = [ xT
            xB ];

return