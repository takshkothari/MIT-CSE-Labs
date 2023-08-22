module q3(a, b, c, d, f);
	input a, b, c, d;
	output f;
	assign f = (a & b & c) | (a & b & d) | (a & c & d) | (b & c & d);
endmodule
