`timescale 1ns/1ns
`include "q5.v"
module q5_tb();
reg i, clk, resetn;
wire o;
q5 q5(i,o,clk,res);
initial
begin
	$dumpfile("q5_tb.vcd");
	$dumpvars(0, q5_tb);
	clk=0;
	forever #20 clk = ~clk;
end
initial begin
	i=1'b1; resetn=1;
	#40;
	i=1'b0; resetn=1;
	#40;
	i=1'b1; resetn=1;
	#40;
	
	$display("Test complete");
end
endmodule
