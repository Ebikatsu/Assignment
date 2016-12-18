module testbench();
	//logic [3:0] data, [6:0] segments;
	logic  [0:3]data, [0:6]segments;
	sevenseg dut([0:3]data,[0:6]segments);
	initial begin
		data = '{0,0,0,0};	#10;
		data = '{0,0,0,1};	#10;
		data = '{0,0,1,0};	#10;
		data = '{0,0,1,1};	#10;
		data = '{0,1,0,0};	#10;
		data = '{0,1,0,1};	#10;
		data = '{0,1,1,0};	#10;
		data = '{0,1,1,1};	#10;
		data = '{1,0,0,0};	#10;
		data = '{1,0,0,1};	#10;
		data = '{1,0,1,0};	#10;
		data = '{1,0,1,1};	#10;
		data = '{1,1,0,0};	#10;
		data = '{1,1,0,1};	#10;
		data = '{1,1,1,0};	#10;
		data = '{1,1,1,1};	#10;
	end
	initial begin
		$dumpfile("dump.vcd");
		$dumpvars(0,sevenseg);
	end
endmodule
