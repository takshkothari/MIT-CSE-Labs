`timescale 1ns/1ns
`include "q4.v"

module q4_tb();
reg [3:0]a,b;
wire aeqb,agtb,altb;

comp4bit comp4bit(a,b,aeqb,agtb,altb);
initial
begin
	$dumpfile("q4_tb.vcd");
	$dumpvars(0,q4_tb);
	a=4'b1010; b=4'b1001; #20;
	a=4'b1010; b=4'b1010; #20;
	a=4'b1001; b=4'b1010; #20;
	$display("Test Complete");
end
endmodule
