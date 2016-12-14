module minority(	input logic a,b,c,
			output logic y);
assign y=	~a&~c|
		      ~b&~c|
		      ~a&~b;	
endmodule
