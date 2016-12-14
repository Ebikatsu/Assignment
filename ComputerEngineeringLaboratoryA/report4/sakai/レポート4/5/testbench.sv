module testbench();
	logic data[0:3],segments[0:6] ;
	sevenseg dut(data[0:3], segments[0:6]);
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
