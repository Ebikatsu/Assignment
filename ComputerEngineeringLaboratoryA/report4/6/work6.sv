module work6(	input logic a,b,c,
		output logic y);
	mux8 dut('{0,0,0,b},a | ~c,~a & c,0,0,0,0,0,0);
endmodule
