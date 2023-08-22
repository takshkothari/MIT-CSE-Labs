`timescale 1ns/1ns
`include "q2.v"
module q2_tb();
reg t, clk, res;
wire q;
q2 q2(t, clk, res, q);

initial
begin
	clk=0;
	forever #20 clk = ~clk;
end

initial
begin
	$dumpfile("q2_tb.vcd");
	$dumpvars(0, q2_tb);

	t <= 0; res <=0; #20;
	t <= 0; res <=1; #20;
	t <= 1; res <=0; #20;
	t <= 1; res <=0; #20;
	t <= 1; res <=1; #20;

	$display("Test complete");
end
endmodule
