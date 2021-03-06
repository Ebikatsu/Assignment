module xor4(	input logic a[0:3],
		output logic y);
assign y=~a[0]& a[1]&~a[2]&~a[3]|
          a[0]&~a[1]&~a[2]&~a[3]|
         ~a[0]&~a[1]&~a[2]& a[3]|
          a[0]& a[1]&~a[2]& a[3]|
         ~a[0]& a[1]& a[2]& a[3]|
          a[0]&~a[1]& a[2]& a[3]|
         ~a[0]&~a[1]& a[2]&~a[3]|
          a[0]& a[1]& a[2]&~a[3];
endmodule