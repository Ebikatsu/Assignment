module testbench3();
	logic a[0:3],y;
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
		$dumpvars(0,testbench3);
	end
endmodule