mosule exercise1(
	input logic a,b,c,
	output logic y,z);
assign y = a & (b | c);
assign z = ~(a ^ b);
endmodule
