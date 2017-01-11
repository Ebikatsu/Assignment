module deg7dec
(
	input	logic	[3:0]	bdc,
	output	logic	[6:0]	seg
);
	always_comb
		case(bdc)
/*
			4'b0000:seg=7'b0000001;
			4'b0001:seg=7'b1001111;
			4'b0010:seg=7'b0010010;
			4'b0011:seg=7'b0000110;
			4'b0100:seg=7'b1001100;
			4'b0101:seg=7'b0100100;
			4'b0110:seg=7'b0100000;
			4'b0111:seg=7'b0001101;
			4'b1000:seg=7'b0000000;
			4'b1001:seg=7'b0000100;
			default:seg=7'b1111111;
*/
			4'b0000:b7s=7'b1000000;
			4'b0001:b7s=7'b1111001;
			4'b0010:b7s=7'b0100100;
			4'b0011:b7s=7'b0110000;
			4'b0100:b7s=7'b0011001;
			4'b0101:b7s=7'b0010010;
			4'b0110:b7s=7'b0000010;
			4'b0111:b7s=7'b1011000;
			4'b1000:b7s=7'b0000000;
			4'b1001:b7s=7'b0010000;
			default:b7s=7'b1111111;

		endcase
endmodule
