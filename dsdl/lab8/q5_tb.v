`timescale 1ns/1ns
`include "q5.v"

module q5_tb();
reg [15:0] w;
wire [3:0] f;

q5 q5(w,f);
initial
begin
	$dumpfile("q5_tb.vcd");
	$dumpvars(0,q5_tb);
	
	w=16'd4; #20;
	w=16'd19; #20;
	w=16'd67; #20;
	w=16'd2048; #20;
	
	$display("Test Complete");
end 
endmodule
