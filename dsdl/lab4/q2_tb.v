`timescale 1ns/1ns
`include "q2.v"

module q2_tb();

reg x0,x1,x2,x3,y0,y1,y2,y3,k;
wire s0,s1,s2,s3,cout;
/*
reg [3:0] x, [3:0] y, k;
wire [3:0] s, cout; */

addsub fbas(x0,x1,x2,x3,y0,y1,y2,y3,k,s0,s1,s2,s3,cout);
initial 
begin 
	$dumpfile("q2_tb.vcd");
	$dumpvars(0,q2_tb);
	
	//Addition tests: 
	
	k=0;x0=0;x1=1;x2=1;x3=1;y0=0;y1=0;y2=1;y3=1;#20;
	k=0;x0=1;x1=0;x2=1;x3=1;y0=0;y1=1;y2=0;y3=0;#20;
	//k=0;x=4'b1110;y=4'b1100;#20;
	
	//Subtraction tests: 
	
	k=1;x0=1;x1=0;x2=1;x3=1;y0=0;y1=1;y2=0;y3=0;#20;
	k=1;x0=1;x1=0;x2=1;x3=1;y0=0;y1=1;y2=1;y3=0;#20;
	
	$display("Test Complete");
	
end 
endmodule
