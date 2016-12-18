module testbench();
	logic x[1:0],y[3:0];
	decoder dut(x[1:0],y[3:0]);
	initial begin
		x = '{0,0}; #10;
		x = '{0,1}; #10;
		x = '{1,0}; #10;
		x = '{1,1}; #10;
	end
	initial begin
		$dumpfile("dump.vcd");
		$dumpvars(0,testbench);
	end
endmodule
