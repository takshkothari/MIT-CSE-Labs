`timescale 1ns/1ns
`include "qb.v" 
module qb_tb();
reg clk, set,clear; 
wire [4:0] Q;
qb qb(clk, clear,set, Q);
initial
begin
	$dumpfile("qb_tb.vcd");
	$dumpvars(0, qb_tb);
	clk=0;
	forever #20 clk = ~clk;
end
initial begin
	clear = 0; 
	set = 1; #40;
	set = 0;
	clear = 1;
	#320;
	$display("Test complete");
	$finish;
	
end
endmodule
