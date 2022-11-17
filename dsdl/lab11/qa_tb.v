`timescale 1ns/1ns
`include "qa.v" 
module qa_tb();
reg clk, set,clear; 
wire [3:0] Q;
qa qa(clk, clear,set, Q);
initial
begin
	$dumpfile("qa_tb.vcd");
	$dumpvars(0, qa_tb);
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
