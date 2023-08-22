`timescale 1ns/1ns
`include "q3.v"

module q3_tb;
reg [3:0]a;
wire [3:0]b;


q3 q3(a,b);
initial
begin

	$dumpfile("q3_tb.vcd");
	$dumpvars(0,q3_tb);

	a=4'b1001;#20;

	a=4'b1101;#20;

	$display("Test Complete");

end
endmodule
