module dffsclr2(
	input  logic CLK,
	input  logic D,
	input  logic CLRN,
	input  logic PRN,
	output logic Q
);
	always_ff@(posedge CLK,negedge CLRN,negedge PRN) begin
		if     (~CLRN) Q<=0;
		else if(~PRN) 	Q<=1;
		else				Q<=D;
	end
endmodule