module fulladder
(
	input	logic	a,b,ci,
	output	logic	co,s
);
	wire	p,g;

	assign	p	=	a	^	b;
	assign	g	=	a	&	b;
	assign	s	=	p	^	ci;
	assign	cout	=	g	|	(p	&	ci);
endmodule

