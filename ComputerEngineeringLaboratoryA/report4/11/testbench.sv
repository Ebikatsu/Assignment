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
