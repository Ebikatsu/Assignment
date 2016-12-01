module decoder(input logic x[1:0],
		output logic y[3:0]);
	always_comb
	begin
		y[0] =	~x[1]&	~x[0];
		y[1] =	~x[1]&	x[0];
		y[2] =	x[1]&	~x[0];
		y[3] =	x[1]&	x[0];
	end
endmodule
