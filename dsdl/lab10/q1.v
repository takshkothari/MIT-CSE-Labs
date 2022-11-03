module q1(d, res, clk, q);
	input d, res, clk;
	output reg q;
	always@(posedge clk or posedge res)
		if(res)
			q <= 0;
		else
			q <=d;
endmodule
