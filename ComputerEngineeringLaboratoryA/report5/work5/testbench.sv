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
		iSW[2:0]=3'b000;iSW[5:3]=3'b000;#10;
		iSW[2:0]=3'b001;iSW[5:3]=3'b001;#10;
		iSW[2:0]=3'b010;iSW[5:3]=3'b010;#10;
		iSW[2:0]=3'b011;iSW[5:3]=3'b011;#10;
		iSW[2:0]=3'b100;iSW[5:3]=3'b100;#10;
		iSW[2:0]=3'b101;iSW[5:3]=3'b101;#10;
		iSW[2:0]=3'b110;iSW[5:3]=3'b110;#10;
		iSW[2:0]=3'b111;iSW[5:3]=3'b111;#10;
	end
endmodule
