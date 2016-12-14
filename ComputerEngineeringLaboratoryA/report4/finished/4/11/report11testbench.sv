module testbench();
	logic clk,J,K,Q;
	jkflipflop dut(clk,J,K,Q);
	initial begin
		J = 0; K = 1; #10;
			J = 0; K = 0; #10;
		J = 0; K = 1; #10;
			J = 0; K = 1; #10;
		J = 0; K = 1; #10;
			J = 1; K = 0; #10;
		J = 0; K = 1; #10;
			J = 1; K = 1; #10;
		J = 1; K = 0; #10;
			J = 0; K = 0; #10;
		J = 1; K = 0; #10;
			J = 0; K = 1; #10;
		J = 1; K = 0; #10;
			J = 1; K = 0; #10;
		J = 1; K = 0; #10;
			J = 1; K = 1; #10;
	end
	initial begin
		$dumpfile("dump.vcd");
		$dumpvars(0,testbench);
	end
endmodule
