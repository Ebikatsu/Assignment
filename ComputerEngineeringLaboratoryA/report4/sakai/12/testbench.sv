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
	logic clk, reset, out[0:2];
	work12 dut(clk, reset, out[0:2]);
	initial begin
		reset = 0; #10;
		reset = 1; #10;
		reset = 0; #10;
		clk = 0; #10;
		clk = 1; #10;
		clk = 0; #10;
		clk = 1; #10;
		clk = 0; #10;
		clk = 1; #10;
		clk = 0; #10;
		clk = 1; #10;
		clk = 0; #10;
		clk = 1; #10;
		clk = 0; #10;
		clk = 1; #10;
		clk = 0; #10;
		clk = 1; #10;
		clk = 0; #10;
		clk = 1; #10;
	end
	initial begin
		$dumpfile("dump.vcd");
		$dumpvars(0,testbench);
	end
endmodule
