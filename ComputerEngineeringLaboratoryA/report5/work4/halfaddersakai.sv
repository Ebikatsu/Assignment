module halfadder(
	input  logic a,
	input  logic b,
	output logic co,
	output logic s
);

assign  s=(a&~b)|(~a&b);
assign co=a&b;

endmodule