module adder2(
	input  logic [1:0]a,b,
	output logic [1:0]s
);
	wire cu0;
	wire gbg;
	halfadder ado(a[0],b[0],cu0,s[0]);
	fulladder ad1(a[1],b[1],cu0,gbg,s[1]);

endmodule
