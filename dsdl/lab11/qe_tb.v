`timescale 1ns/1ns
`include "qe.v" 
module qe_tb();
reg en,clk,clear; 
wire [3:0] Q;
qe qe(clk,clear,en,Q);
initial
begin
	$dumpfile("qe_tb.vcd");
	$dumpvars(0, qe_tb);
	clk=0;
	forever #10 clk = ~clk;
end
initial begin
	en = 0;
	clear = 0; #20;
	clear = 1; #300;
	en = 1;
	clear = 0; #20;
	clear = 1; #300;
	$display("Test complete");
	$finish;
	
end
endmodule
