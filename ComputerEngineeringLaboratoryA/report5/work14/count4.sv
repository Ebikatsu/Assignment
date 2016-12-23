module count4dre
(
	input	logic		clk,
	input	logic		en,
	input	logic		clr,
	output	logic	[3:0]	q,
	output	logic		co
);
	assign	co=(q==9)&en;
	always_ff @ (posedge clk)
	begin
		if	(clr)	q<=4'b0000;
		else if	(co)	q<=4'b0000;
		else if	(en)	q<=q+1;
	end
endmodule
