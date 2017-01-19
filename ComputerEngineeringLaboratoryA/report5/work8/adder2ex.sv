module adder2ex(
	input logic [1:0] a,b,
	input logic ci,
	output logic [1:0] s,
	output logic co
);
	wire cu0;
	fulladder a0(a[0],b[0],ci,cu0,s[0]);
	fulladder a1(a[1],b[1],cu0,co,s[1]);
endmodule
