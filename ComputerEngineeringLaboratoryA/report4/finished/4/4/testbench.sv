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

module testbench();
	logic a,b,c,y;
	minority dut(a,b,c,y);
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
