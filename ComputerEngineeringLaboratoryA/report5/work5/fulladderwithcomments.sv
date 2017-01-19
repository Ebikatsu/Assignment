module fulladder
(
	input	logic	a,b,ci,
	output	logic	co,s
);
	assign co =
		(~a &  b &  ci) |//a=0,b=1,ci=1の項に対応
		( a & ~b &  ci) |//a=1,b=0,ci=1の項に対応
		( a &  b & ~ci) |//a=1,b=1,ci=0の項に対応
		( a &  b &  ci) ;//a=1,b=1,ci=1の項に対応
	assign s =
		( a & ~b & ~ci) |//a=1,b=0,ci=0の項に対応
		(~a &  b & ~ci) |//a=0,b=1,ci=0の項に対応
		(~a & ~b &  ci) |//a=0,b=0,ci=1の項に対応
		( a &  b &  ci) ;//a=1,b=1,ci=1の項に対応
endmodule

module fulladderUsingHalfadder
(
	input	logic	a,b,ci,
	output	logic	co,s
);
	wire co0,co1,s0;
	halfadder ha0(a,b,co0,s0);
	halfadder ha1(s0,ci,co1,s);
	assign co = co0 | co1;
endmodule
