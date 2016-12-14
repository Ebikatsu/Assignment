module decoder(	input	logic	a,b,
		output	logic	c,d,e,f);
	assign	c	=	~a&~b;
	assign	d	=	~a&b;
	assign	e	=	a&~b;
	assign	f	=	a&b;
endmodule
