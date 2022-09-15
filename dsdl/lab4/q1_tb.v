`timescale 1ns/1ns
`include "q1.v"

module q1_tb();

reg a, b;
wire s, c;

ha ha(a, b, s, c);
initial
begin

	$dumpfile("q1_tb.vcd");
	$dumpvars(0, q1_tb);
	
	a=1'b0; b=1'b0; #20
	
	a=1'b0; b=1'b1; #20
	
	a=1'b1; b=1'b0; #20
	
	a=1'b1; b=1'b1;	#20
	
	$display("Test complete");
end

reg x, y, cin;
wire sum, cout;

fa fa(x, y, cin, sum, cout);
initial
begin

	$dumpfile("q1_tb.vcd");
	$dumpvars(0, q1_tb);
	
	x=1'b0; y=1'b0; cin=1'b0; #20;
	
	x=1'b0; y=1'b0; cin=1'b1; #20;
	
	x=1'b0; y=1'b1; cin=1'b0; #20;
	
	x=1'b0; y=1'b1; cin=1'b1; #20;
	
	x=1'b1; y=1'b0; cin=1'b0; #20;
	
	x=1'b1; y=1'b0; cin=1'b1; #20;
	
	x=1'b1; y=1'b1; cin=1'b0; #20;
	
	x=1'b1; y=1'b1; cin=1'b1; #20;
	
	$display("Test complete");
end

reg x1, y1, Cin;
wire Sum, Cout;

dfa dfa(x1, y1, Cin, Sum, Carry);
initial
begin

	$dumpfile("q1_tb.vcd");
	$dumpvars(0, q1_tb);
	
	x1=1'b0; y1=1'b0; Cin=1'b0; #20;
	
	x1=1'b0; y1=1'b0; Cin=1'b1; #20;
	
	x1=1'b0; y1=1'b1; Cin=1'b0; #20;
	
	x1=1'b0; y1=1'b1; Cin=1'b1; #20;
	
	x1=1'b1; y1=1'b0; Cin=1'b0; #20;
	
	x1=1'b1; y1=1'b0; Cin=1'b1; #20;
	
	x1=1'b1; y1=1'b1; Cin=1'b0; #20;
	
	x1=1'b1; y1=1'b1; Cin=1'b1; #20;
	
	$display("Test complete");
end

endmodule
