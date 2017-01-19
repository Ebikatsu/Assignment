module testbench();
	logic		iCLK_50;
	logic	[3:0]	iKEY;
	logic	[17:0]	iSW;
	logic	[6:0]	oHEX0_D;
	logic	[6:0]	oHEX1_D;
	logic	[6:0]	oHEX2_D;
	logic	[6:0]	oHEX3_D;
	logic	[6:0]	oHEX4_D;
	logic	[6:0]	oHEX5_D;
	logic	[6:0]	oHEX6_D;
	logic	[6:0]	oHEX7_D;
	logic	[8:0]	oLEDG;
	logic	[17:0]	oLEDR;
	logic		oUART_TXD;
	logic		iUART_RXD;
	DE2_TOP dut
	(
		iCLK_50,
		iKEY,     
		iSW,
		oHEX0_D,
		oHEX1_D,
		oHEX2_D,
		oHEX3_D,
		oHEX4_D,
		oHEX5_D,
		oHEX6_D,
		oHEX7_D,
		oLEDG,
		oLEDR,
		oUART_TXD,
		iUART_RXD
	);
	initial begin
		iSW[4:0]=5'b00000;#10;
		iSW[4:0]=5'b00001;#10;
		iSW[4:0]=5'b00010;#10;
		iSW[4:0]=5'b00011;#10;
		iSW[4:0]=5'b00100;#10;
		iSW[4:0]=5'b00101;#10;
		iSW[4:0]=5'b00110;#10;
		iSW[4:0]=5'b00111;#10;
		iSW[4:0]=5'b01000;#10;
		iSW[4:0]=5'b01001;#10;
		iSW[4:0]=5'b01010;#10;
		iSW[4:0]=5'b01011;#10;
		iSW[4:0]=5'b01100;#10;
		iSW[4:0]=5'b01101;#10;
		iSW[4:0]=5'b01110;#10;
		iSW[4:0]=5'b01111;#10;
		iSW[4:0]=5'b10000;#10;
		iSW[4:0]=5'b10001;#10;
		iSW[4:0]=5'b10010;#10;
		iSW[4:0]=5'b10011;#10;
		iSW[4:0]=5'b10100;#10;
		iSW[4:0]=5'b10101;#10;
		iSW[4:0]=5'b10110;#10;
		iSW[4:0]=5'b10111;#10;
		iSW[4:0]=5'b11000;#10;
		iSW[4:0]=5'b11001;#10;
		iSW[4:0]=5'b11010;#10;
		iSW[4:0]=5'b11011;#10;
		iSW[4:0]=5'b11100;#10;
		iSW[4:0]=5'b11101;#10;
		iSW[4:0]=5'b11110;#10;
		iSW[4:0]=5'b11111;#10;
	end
endmodule
