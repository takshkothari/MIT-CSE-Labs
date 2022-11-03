`timescale 1ns/1ns
`include "q1.v"

module q1_tb();
reg d, res, clk;
wire q;

q1 q1(d, res, clk, q);
initial 
begin
	clk = 0;
	forever #20 clk = ~clk;
end
initial begin
	$dumpfile("q1_tb.vcd");
	$dumpvars(0,q1_tb);
	res=1; d=0; #20;
	d=1;#20;
	d=0;#20;
	d=1;
	$display("Test Complete");
end
endmodule
