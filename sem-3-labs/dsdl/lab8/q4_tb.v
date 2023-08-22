`timescale 1ns/1ns
`include "q4.v"

module q4_tb();
reg [3:0] w;
wire [2:0] f;

q4 q4(w,f);
initial
begin
	$dumpfile("q4_tb.vcd");
	$dumpvars(0,q4_tb);
	
	w=4'd1; #20;
	w=4'd5; #20;
	w=4'd7; #20;
	w=4'd13; #20;
	
	$display("Test Complete");
end 
endmodule
