module q2(t, clk, res, q);
	input t, clk, res;
	output reg q;
	always@(negedge clk or negedge res)
	begin
		if(res == 0)
			q<=0;
		else
			if(t==1)
				q<=~q;
			else
				q<=q;
	end
endmodule
