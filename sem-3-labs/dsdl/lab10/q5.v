module q5(i, o, clk, resetn);
	input i;
	input clk, resetn;
	output o;
	wire [4:0] c;

	dff s0(i, clk, resetn, c[0]);
	dff s1(c[0], clk, resetn, c[1]);
	dff s2(c[1], clk, resetn, c[2]);
	dff s3(c[2], clk, resetn, c[3]);
	dff s4(c[3], clk, resetn, c[4]);
	dff s5(c[4], clk, resetn, o);
endmodule
module dff(d, clk, resetn, q);
	input d, clk, resetn;
	output reg q;
	always @(posedge clk)
	begin
		if(!resetn)
			q <= 0;
		else
			q <= d;
	end
endmodule
