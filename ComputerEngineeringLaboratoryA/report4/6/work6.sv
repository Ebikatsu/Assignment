module work6(	input	logic	a,b,c,
		output	logic	y);
	mux8 muxinst({a,b,c},1,1,1,1,1,1,1,0,y);
endmodule
