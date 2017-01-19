module clkgen2500
(
	input	logic clk2500,
	output	logic	clk1
);
	reg	[11:0]	prescale;
	always_ff @(posedge clk2500)
		if(prescale == 2499)
		begin
			prescale	<=	0;
			clk1		<=	~clk1;
		end
		else
		begin
			prescale	<=	prescale+1;
			clk1		<=	clk1;
		end
endmodule
