`timescale 1ns/1ns
`include "q4.v"

module q4_tb();
reg [7:0] w;
reg [2:0] s;
wire f;
q4 q4(w,s,f);
initial
begin
	$dumpfile("q4_tb.vcd");
	$dumpvars(0,q4_tb);
	
	w=8'd1; 
	s=3'd0; #20;
	s=3'd1; #20;
	s=3'd2; #20;
	s=3'd3; #20;
	s=3'd4; #20;
	
	$display("Test Complete");
end 
endmodule
