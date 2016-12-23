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
		//assign	oLEDR[1]	=	~iSW[0];
		iSW[0]=0;#10;
		iSW[0]=1;#10;
		//assign	oLEDR[4]	=	iSW[1]	&	iSW[2];
		iSW[2]=0;iSW[1]=0;#10;
		iSW[2]=0;iSW[1]=1;#10;
		iSW[2]=1;iSW[1]=0;#10;
		iSW[2]=1;iSW[1]=1;#10;
		//assign	oLEDR[7]	=	iSW[3]	|	iSW[4];
		iSW[4]=0;iSW[3]=0;#10;
		iSW[4]=0;iSW[3]=1;#10;
		iSW[4]=1;iSW[3]=0;#10;
		iSW[4]=1;iSW[3]=1;#10;
		//assign	oLEDR[10]	=	iSW[5]	^	iSW[6];
		iSW[6]=0;iSW[5]=0;#10;
		iSW[6]=0;iSW[5]=1;#10;
		iSW[6]=1;iSW[5]=0;#10;
		iSW[6]=1;iSW[5]=1;#10;
	end
endmodule
