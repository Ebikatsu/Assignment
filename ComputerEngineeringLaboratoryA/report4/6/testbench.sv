/*
module testbench();
	logic a[0,3],y;
	xor4 dut(a[0:3],y);
	initial begin
		a = '{0,0,0,0};	#10;
		a = '{0,0,0,1};	#10;
		a = '{0,0,1,0};	#10;
		a = '{0,0,1,1};	#10;
		a = '{0,1,0,0};	#10;
		a = '{0,1,0,1};	#10;
		a = '{0,1,1,0};	#10;
		a = '{0,1,1,1};	#10;
		a = '{1,0,0,0};	#10;
		a = '{1,0,0,1};	#10;
		a = '{1,0,1,0};	#10;
		a = '{1,0,1,1};	#10;
		a = '{1,1,0,0};	#10;
		a = '{1,1,0,1};	#10;
		a = '{1,1,1,0};	#10;
		a = '{1,1,1,1};	#10;
	end
	initial begin
		$dumpfile("dump.vcd");
		$dumpvars(0,testbench);
	end
endmodule
*/
/*
module testbench();
	logic s[2:0],d0,d1,d2,d3,d4,d5,d6,d7,y;
	xor4 dut(s[2:0],d0,d1,d2,d3,d4,d5,d6,d7,y);
	initial begin
		s[2:0] = 
	end
	initial begin
		$dumpfile("dump.vcd");
		$dumpvars(0,testbench);
	end
endmodule
*/
module testbench();
	logic a,b,c,y;
	work6 dut(a,b,c,y);
	initial begin
		a = 0; b = 0; c = 0; #10;
		a = 0; b = 0; c = 1; #10;
		a = 0; b = 1; c = 0; #10;
		a = 0; b = 1; c = 1; #10;
		a = 1; b = 0; c = 0; #10;
		a = 1; b = 0; c = 1; #10;
		a = 1; b = 1; c = 0; #10;
		a = 1; b = 1; c = 1; #10;
	end
	initial begin
		$dumpfile("dump.vcd");
		$dumpvars(0,testbench);
	end
endmodule
