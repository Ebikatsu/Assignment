module sillyfunction(input  logic a, b,
                     output logic y3,y2,y1,y0);

  assign y3 = a & b ;
  assign y2 = a & ~b ;
  assign y1 = ~a & b ;
  assign y0 = ~a & ~b ;

endmodule
