`timescale 1ns/1ns
`include "q3.v"

module q3_tb();
reg [3:0] w;
reg e;
wire [0:15] y;

q3 q3(w,e,y);
initial
begin
	$dumpfile("q3_tb.vcd");
	$dumpvars(0,q3_tb);

	w = 4'b0000; e = 1; #20;
	w = 4'b0010; e = 1; #20;
	w = 4'b1001; e = 1; #20;
	w = 4'b1111; e = 1; #20;

	$display("Test Complete");
end
endmodule
