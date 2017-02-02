module adder8(
	input  logic [7:0]a,b,
	output logic [8:0]s
);
	wire cu[6:0];
	halfadder ado(a[0],b[0],cu[0],s[0]);
	fulladder ad1(a[1],b[1],cu[0],cu[1],s[1]);
	fulladder ad2(a[2],b[2],cu[1],cu[2],s[2]);
	fulladder ad3(a[3],b[3],cu[2],cu[3],s[3]);
	fulladder ad4(a[4],b[4],cu[3],cu[4],s[4]);
	fulladder ad5(a[5],b[5],cu[4],cu[5],s[5]);
	fulladder ad6(a[6],b[6],cu[5],cu[6],s[6]);
	fulladder ad7(a[7],b[7],cu[6],s[8],s[7]);

endmodule
