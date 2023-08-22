module dff(d, res, clk, q);
	input d, res, clk;
	output reg q;
	always@(posedge clk or posedge res)
		if(res==0)
			q <= 0;
		else
			q <=d;
endmodule
module q4(i, out, clk, res);
	input [4:0]i;
	output [4:0]out;
	input clk,res;
	dff s0(i[0],clk,res,out[0]);
	dff s1(i[1],clk,res,out[1]);
	dff s2(i[2],clk,res,out[2]);
	dff s3(i[3],clk,res,out[3]);
	dff s4(i[4],clk,res,out[4]);
endmodule
