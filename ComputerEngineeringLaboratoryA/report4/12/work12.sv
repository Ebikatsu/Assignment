module	work12
	(
		input	logic	clk,	reset,
		output	logic	out[0:2]
	);
	always_ff @(posadge	clk,	posadge	reset)
		if(reset)out = '{0,0,0}
		else
			case(out)
				'{0,0,0}:out = '{0,0,1};
				'{0,0,1}:out = '{0,1,1};
				'{0,1,1}:out = '{0,1,0};
				'{0,1,0}:out = '{1,1,0};
				'{1,1,0}:out = '{1,1,1};
				'{1,1,1}:out = '{1,0,1};
				'{1,0,1}:out = '{1,0,0};
				'{1,0,0}:out = '{0,0,0};
			endcase
endmodule
