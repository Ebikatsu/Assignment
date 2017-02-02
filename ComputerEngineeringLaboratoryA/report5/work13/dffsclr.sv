module dffsclr(
	input  logic CLK,
	input  logic D,
	input  logic SCLR,
	output logic Q
);
	always_ff@(posedge CLK) begin
		if (SCLR) Q<=0;
		else 		 Q<=D;
	end
endmodule