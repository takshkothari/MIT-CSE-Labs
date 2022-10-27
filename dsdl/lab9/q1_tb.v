`timescale 1ns/1ns
`include "q1.v"

module q1_tb();
reg [3:0] w;
wire f;
integer i;

q1 q1(w,f);
initial
begin
	$dumpfile("q1_tb.vcd");
	$dumpvars(0,q1_tb);
	
	for(i=0;i<16;i=i+1)
	begin 
		w=i; #20;
	end
	
	$display("Test Complete");
end 
endmodule
