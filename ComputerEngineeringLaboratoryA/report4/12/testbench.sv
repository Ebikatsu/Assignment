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
