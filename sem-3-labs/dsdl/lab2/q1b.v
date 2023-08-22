module q1b(b, c, d, f);
	input b, c, d;
	output f;
	assign f = (~b & c) | (~b & d) | (b & ~c & ~d);
endmodule
