`timescale 1ns/1ns
`include "q3.v"

module q3_tb();
reg [3:0] w;
wire [3:0] x;

q3 q3(w,x);
initial
begin 
	$dumpfile("q3_tb.vcd");
	$dumpvars(0,q3_tb);

	w = 4'b0000; #20;
	w = 4'b0001; #20;
	w = 4'b0010; #20;
	w = 4'b0011; #20;
	w = 4'b0100; #20;
	w = 4'b0101; #20;
	w = 4'b0110; #20;
	w = 4'b0111; #20;
	w = 4'b1000; #20;
	w = 4'b1001; #20;

	$display("Test Complete");
end
endmodule
