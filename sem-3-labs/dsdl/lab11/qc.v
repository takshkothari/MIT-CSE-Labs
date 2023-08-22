//4 bit asynchronous up counter
module qc(clk,clear,Q);
	input clk,clear;
	output [3:0] Q;
	dff s0(~Q[0],clk,clear,Q[0]);
	dff s1(~Q[1],~Q[0],clear,Q[1]);
	dff s2(~Q[2],~Q[1],clear,Q[2]);
	dff s3(~Q[3],~Q[2],clear,Q[3]);
endmodule

module dff(D,clk,clear,Q);
	input D,clk,clear;
	output reg Q;
	always @(posedge clk or negedge clear)
	begin
	if(!clear)
		Q <= 0;
	else
		Q <= D;
	end
endmodule

