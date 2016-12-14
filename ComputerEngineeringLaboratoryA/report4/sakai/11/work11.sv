module jkflipflop	(
				input logic clk, J, K,
				output logic Q
			);
/*
	logic nextQ;
	always_ff @(posedge clk)
		Q <= nextQ;
*/
	always_comb
		if(J == 1 && K == 1)Q = ~Q;
		else if(J == K)Q = Q;
		else if(J == 1)Q = 1;
		else if(K == 1)Q = 0;
endmodule
