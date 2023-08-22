`timescale 1ns/1ns
`include "q3.v"

module q3_tb();
reg [2:0] w;
reg En;
wire f;

q3 q3(w,En,f);
initial
begin
	$dumpfile("q3_tb.vcd");
	$dumpvars(0,q3_tb);
	
	En=1'b1;
	w=3'd0; #20;
	w=3'd1; #20;
	w=3'd2; #20;
	w=3'd3; #20;
	w=3'd4; #20;
	w=3'd5; #20;
	w=3'd6; #20;
	w=3'd7; #20;
	
	$display("Test Complete");
end 
endmodule
