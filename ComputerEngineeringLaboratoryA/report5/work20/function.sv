module deg7dec
(
	input	logic	[3:0]	bdc,
	output	logic	[6:0]	seg
);
	assign	seg=b7s(bdc);
	function	[6:0]	b7s;
		input	[3:0]	bdc;
		case(bdc)
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
	endfunction
endmodule
