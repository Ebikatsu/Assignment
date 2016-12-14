module testbenchver2();
	logic	a,b,c,d,e,f;
	decoder dut(a,b,c,d,e,f);
	initial begin
		a=0;b=0;#10;
		a=0;b=1;#10;
		a=1;b=0;#10;
		a=1;b=1;#10;
	end
	initial begin
		$dumpfile("dump.vcd");
		$dumpvars(0,testbenchver2);
	end
endmodule
