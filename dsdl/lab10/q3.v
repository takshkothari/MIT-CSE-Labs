module q3(j, k, clk, res, q);
	input j, k, clk, res;
	output reg q;
	always @(posedge clk)
	begin
		if(res)
			q<=0;
		else
			case({j, k})
				0: q<=q;
				1: q<=0;
				2: q<=1;
				3: q<=~q;
			endcase
	end
endmodule
