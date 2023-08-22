module q2a(b, c, d, f);
	input b, c, d;
	output f;
	assign f = (b | c) & (~b | d);
endmodule
