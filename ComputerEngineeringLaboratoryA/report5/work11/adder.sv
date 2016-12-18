module adder
(
	input	logic	[7:0]x,	[7:0]y,
	output	logic	[7:0]z
);
	assign	z[7:0]	=	x[7:0]	+	y[7:0];
endmodule
