`timescale 1ns/1ns
`include "qd.v" 
module qd_tb();
reg clk,clear; 
wire [3:0] Q;
qd qd(clk,clear,Q);
initial
begin
	$dumpfile("qd_tb.vcd");
	$dumpvars(0, qd_tb);
	clk=0;
	forever #20 clk = ~clk;
end
initial begin
	clear = 0; #40;
	clear = 1; #520;
	$display("Test complete");
	$finish;
	
end
endmodule
