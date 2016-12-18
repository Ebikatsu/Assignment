module testbench2();
  logic  a, b, y3,y2,y1,y0;

  // instantiate device under test
  sillyfunction dut(a, b,y3,y2,y1,y0);

  initial begin
    a = 1; b = 1; #10;
    assert (y3 === 1) else $error("000 failed.");
    a = 1; b = 0; #10;
    assert (y3 === 0) else $error("001 failed.");
    a = 0; b = 1; #10;
    assert (y3 === 0) else $error("010 failed.");
    a = 0; b = 0; #10;
    assert (y3 === 0) else $error("011 failed.");
    a = 1; b = 1; #10;
    assert (y2 === 0) else $error("100 failed.");
    a = 1; b = 0; #10;
    assert (y2 === 1) else $error("101 failed.");
    a = 0; b = 1; #10;
    assert (y2 === 0) else $error("110 failed.");
    a = 0; b = 0; #10;
    assert (y2 === 0) else $error("111 failed.");
    a = 1; b = 1; #10;
    assert (y1 === 0) else $error("000 failed.");
    a = 1;b = 0; #10;
    assert (y1 === 0) else $error("001 failed.");
    a = 0; b = 1; #10;
    assert (y1 === 1) else $error("010 failed.");
    a = 0; b = 0; #10;
    assert (y1 === 0) else $error("011 failed.");
    a = 1; b = 1; #10;
    assert (y0 === 0) else $error("000 failed.");
    a = 1;b = 0; #10;
    assert (y0 === 0) else $error("001 failed.");
    a = 0; b = 1; #10;
    assert (y0 === 1) else $error("010 failed.");
    a = 0; b = 0; #10;
    assert (y0 === 1) else $error("011 failed.");

  end
endmodule
