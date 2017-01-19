// --------------------------------------------------------------------
// Copyright (c) 2011 by Gian. 
// --------------------------------------------------------------------
//
// Permission:
//
//   Gian grants permission to use and modify this code for use
//   in synthesis for all educational purpose.
//
// Disclaimer:
//
//   This VHDL/Verilog or C/C++ source code is intended as a design reference
//   which illustrates how these types of functions can be implemented.
//   It is the user's responsibility to verify their design for
//   consistency and functionality through the use of formal
//   verification methods.  Gian provides no warranty regarding the use 
//   or functionality of this code.
//
// --------------------------------------------------------------------
//
// Major Functions:	DE2 TOP LEVEL 
//
// --------------------------------------------------------------------
//
// Revision History :
// --------------------------------------------------------------------
//   Ver  :| Author            :| Mod. Date :| Changes Made:
//   V1.0 :| Gian              :| 08/08/11  :| Initial Revision
//   V2.0 :| Gian              :| 16/10/15  :| Convert to SystemVerilog
// --------------------------------------------------------------------

module DE2_TOP (
////////////////////////	Clock Input	 	////////////////////////
  input logic	iCLK_50,				//	50 MHz
////////////////////////	Push Button		////////////////////////
  input logic [3:0] iKEY,				//	Pushbutton[3:0]
////////////////////////	DPDT Switch		////////////////////////
  input logic [17:0] iSW,				//	Toggle Switch[17:0]
////////////////////////	7-SEG Dispaly	////////////////////////
  output logic [6:0] oHEX0_D,				//	Seven Segment Digit 0
  output logic [6:0] oHEX1_D,				//	Seven Segment Digit 1
  output logic [6:0] oHEX2_D,				//	Seven Segment Digit 2
  output logic [6:0] oHEX3_D,				//	Seven Segment Digit 3
  output logic [6:0] oHEX4_D,				//	Seven Segment Digit 4
  output logic [6:0] oHEX5_D,				//	Seven Segment Digit 5
  output logic [6:0] oHEX6_D,				//	Seven Segment Digit 6
  output logic [6:0] oHEX7_D,				//	Seven Segment Digit 7
////////////////////////////	LED		////////////////////////////
  output logic [8:0] oLEDG,				//	LED Green[8:0]
  output logic [17:0] oLEDR,				//	LED Red[17:0]
////////////////////////////	UART	////////////////////////////
  output logic oUART_TXD,				//	UART Transmitter
  input logic iUART_RXD					//	UART Receiver
);

//===========================================================================
// PARAMETER declarations
//===========================================================================


///////////////////////////////////////////////////////////////////
//=============================================================================
// REG/WIRE declarations
//=============================================================================



//=============================================================================
// Structural coding
//=============================================================================
	logic		clk1;
	logic	[7:0]	co;
	logic	[31:0]	q;
	clkgen2500	clkgen2500(iCLK_50,clk1);
	count10	count4dre0(clk1,~iKEY[0],~iKEY[1],q[3:0],co[0]);
	count10	count4dre1(clk1,co[0],~iKEY[1],q[7:4],co[1]);
	count10	count4dre2(clk1,co[1],~iKEY[1],q[11:8],co[2]);
	count10	count4dre3(clk1,co[2],~iKEY[1],q[15:12],co[3]);
	count10	count4dre4(clk1,co[3],~iKEY[1],q[19:16],co[4]);
	count6	count4dre5(clk1,co[4],~iKEY[1],q[23:20],co[5]);
	count10	count4dre6(clk1,co[5],~iKEY[1],q[27:24],co[6]);
	count6	count4dre7(clk1,co[6],~iKEY[1],q[31:28],co[7]);
	deg7dec		deg7dec0(q[3:0],oHEX0_D[6:0]);
	deg7dec		deg7dec1(q[7:4],oHEX1_D[6:0]);
	deg7dec		deg7dec2(q[11:8],oHEX2_D[6:0]);
	deg7dec		deg7dec3(q[15:12],oHEX3_D[6:0]);
	deg7dec		deg7dec4(q[19:16],oHEX4_D[6:0]);
	deg7dec		deg7dec5(q[23:20],oHEX5_D[6:0]);
	deg7dec		deg7dec6(q[27:24],oHEX6_D[6:0]);
	deg7dec		deg7dec7(q[31:28],oHEX7_D[6:0]);
endmodule

