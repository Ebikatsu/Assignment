module adder89(
	input logic  [7:0]x  , 
	input logic  [7:0]y,
	output logic  [8:0] z 
);
wire c[8:1];
fulladder fulladder_0(x[0],y[0],0,z[0],c[1]);
fulladder fulladder_1(x[1],y[1],c[1],z[1],c[2]);
fulladder fulladder_2(x[2],y[2],c[2],z[2],c[3]);
fulladder fulladder_3(x[3],y[3],c[3],z[3],c[4]);
fulladder fulladder_4(x[4],y[4],c[4],z[4],c[5]);
fulladder fulladder_5(x[5],y[5],c[5],z[5],c[6]);
fulladder fulladder_6(x[6],y[6],c[6],z[6],c[7]);
fulladder fulladder_7(x[7],y[7],c[7],z[7],c[8]);
fulladder fulladder_8(0,0,c[8],z[8],);

endmodule
