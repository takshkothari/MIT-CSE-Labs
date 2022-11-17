`timescale 1ns/1ns
`include "qc.v" 
module qc_tb();
reg clk,clear; 
wire [3:0] Q;
qc qc(clk,clear,Q);
initial
begin
	$dumpfile("qc_tb.vcd");
	$dumpvars(0, qc_tb);
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
