module fulladder
(
	input	logic	a,b,ci,
	output	logic	co,s
);
	wire	p,g;

	assign	p	=	a	^	b;
	assign	g	=	a	&	b;
	assign	s	=	p	^	ci;
	assign	co	=	g	|	(p	&	ci);
endmodule

