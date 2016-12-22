module jkflipflop	(
				input logic clk, J, K,
				output logic Q
			);
	always_comb
		if(J == 1 && K == 1)Q = ~Q;
		else if(J ==0&& K==0)Q = Q;
		else if(J == 1)Q = 1;
		else if(K == 1)Q = 0;
endmodule
