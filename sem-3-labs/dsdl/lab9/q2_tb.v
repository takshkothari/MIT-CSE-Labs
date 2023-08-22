`timescale 1ns/1ns
`include "q2.v"

module q2_tb();
reg [3:0] w;
wire f,g,h;
integer i;

q2 q2(w,f,g,h);
initial
begin
	$dumpfile("q2_tb.vcd");
	$dumpvars(0,q2_tb);
	
	for(i=0;i<16;i=i+1)
	begin 
		w=i; #20;
	end
	
	$display("Test Complete");
end 
endmodule
