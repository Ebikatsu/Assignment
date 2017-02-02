module df(
	input  logic CLK,
	input  logic D,
	output logic Q
);
	always_ff@(posedge CLK) begin
		Q<=D;
	end
endmodule