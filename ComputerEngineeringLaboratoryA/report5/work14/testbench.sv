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
		iCLK_50=0;iSW[0]=0;iKEY[0]=0;
		iCLK_50=0;#10;iCLK_50=1;#10;
		iKEY[0]=1;
		iCLK_50=0;#10;iCLK_50=1;#10;
		iKEY[0]=0;
		iCLK_50=0;#10;iCLK_50=1;#10;
		iSW[0]=1;
		iCLK_50=0;#10;iCLK_50=1;#10;//q==1;
		iCLK_50=0;#10;iCLK_50=1;#10;//q==2;
		iCLK_50=0;#10;iCLK_50=1;#10;//q==3;
		iCLK_50=0;#10;iCLK_50=1;#10;//q==4;
		iCLK_50=0;#10;iCLK_50=1;#10;//q==5;
		iCLK_50=0;#10;iCLK_50=1;#10;//q==6;
		iCLK_50=0;#10;iCLK_50=1;#10;//q==7;
		iCLK_50=0;#10;iCLK_50=1;#10;//q==8;
		iCLK_50=0;#10;iCLK_50=1;#10;//q==9;
		iCLK_50=0;#10;iCLK_50=1;#10;//q==0;
	end
endmodule
