/*
module sevenseg(input logic [0:3] data,
		output logic [0:6] segments);
	always_comb
	case(data)
		0: segments = 7'b111_1110;
		1: segments = 7'b011_0000;
		2: segments = 7'b110_1101;
		3: segments = 7'b111_1001;
		4: segments = 7'b011_0011;
		5: segments = 7'b101_1011;
		6: segments = 7'b101_1111;
		7: segments = 7'b111_0000;
		8: segments = 7'b111_1111;
		9: segments = 7'b111_0011;
		10: segments = 7'b111_0111;
		11: segments = 7'b001_1111;
		12: segments = 7'b100_1110;
		13: segments = 7'b011_1101;
		14: segments = 7'b100_1111;
		15: segments = 7'b100_0111;
		default: segments = 7'b000_0000;
	endcase
endmodule
*/
module sevenseg(	input	logic	[3:0]	data,
			output	logic	[6:0]	segments);
	always_comb
		case(data)
			4'h0:sevenseg=7'b111_1110;
			4'h1:sevenseg=7'b000_0000;
			4'h2:sevenseg=7'b000_0000;
			4'h3:sevenseg=7'b000_0000;
			4'h4:sevenseg=7'b000_0000;
			4'h5:sevenseg=7'b000_0000;
			4'h6:sevenseg=7'b000_0000;
			4'h7:sevenseg=7'b000_0000;
			4'h8:sevenseg=7'b000_0000;
			4'h9:sevenseg=7'b000_0000;
			4'ha:sevenseg=7'b000_0000;
			4'hb:sevenseg=7'b000_0000;
			4'hc:sevenseg=7'b000_0000;
			4'hd:sevenseg=7'b000_0000;
			4'he:sevenseg=7'b000_0000;
			4'hf:sevenseg=7'b000_0000;
		endcase
endmodule
