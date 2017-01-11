/*
module clkgen1m(
	input logic reset,
	input logic clk50,
	output logic clk1,
	//output logic [5:0] prescaleoutput
	);
	
	reg[5:0] prescale;
	//assign prescaleoutput = prescale;
	always_ff @(posedge clk50, posedge reset)
	if(reset) begin
	 clk1<=0;
	prescale<=0;
	 end else if (prescale == 49) begin 
	  prescale <= 0;
	  clk1 <= ~clk1;
	 end else begin
	  prescale <= prescale + 1;
	  clk1 <= clk1;
	 end
endmodule	 
*/
	
module clkgen1m(
	input logic reset,
	input logic clk50,
	output logic clk1,
	//output logic [5:0] prescaleoutput
	);
	
	reg[5:0] prescale;

	//assign prescaleoutput = prescale;

	always_ff @(posedge reset)
	begin
	 	clk1<=0;
		prescale<=0;
	end

	always_ff @(posadge clk50)
	if (prescale == 49) begin 
		prescale <= 0;
		clk1 <= ~clk1;
	end else begin
		prescale <= prescale + 1;
		clk1 <= clk1;
	end

endmodule	 
	
