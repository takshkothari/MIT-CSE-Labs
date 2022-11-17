//4 bit synchronous counter
module qd(clk,clear,Q);
	input clk,clear;
	output [3:0] Q;
	tff s0(1'b1,clk,clear,Q[0]);
	tff s1(Q[0],clk,clear,Q[1]);
	tff s2(Q[1]&Q[0],clk,clear,Q[2]);
	tff s3(Q[0]&Q[1]&Q[2],clk,clear,Q[3]);
endmodule

module tff(t,clk,resetn,q);
	input t,resetn,clk;
	output reg q;
	always@(negedge clk)
	begin
		if(!resetn)
			q <= 0;
		else
		begin
			if(t)
				q <= ~q;
			else
				q <= q;
		end
	end
endmodule
