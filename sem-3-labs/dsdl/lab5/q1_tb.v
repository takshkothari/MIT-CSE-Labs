`timescale 1ns/1ns
`include "q1.v"
 
module q1_tb;
reg [4:0]x;
reg [4:0]y;
wire xeqy,xgty,xlty;
 
q1 q1(x, y, xeqy, xgty, xlty);
initial 
begin
 
	$dumpfile("q1_tb.vcd");
	$dumpvars(0,q1_tb);
 
	x=5'b10110; y=5'b01100;
	#20;
	x=5'b10101; y=5'b00010;
	#20;
	x=5'b10010; y=5'b11000;
	#20;
	x=5'b00001; y=5'b00001;
	#20;
 
	$display("Test complete");
 
end
endmodule	
