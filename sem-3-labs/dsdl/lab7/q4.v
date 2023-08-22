module q4(b,g);
	input [3:0]b;
	output [3:0]g;
	wire c;
	assign c = b[1] ^ b[0];
	m41 s0({1'b1,1'b1,1'b0,1'b0},b[3:2],g[3]);
	m41 s1({1'b0,1'b1,1'b1,1'b0},b[3:2],g[2]);
	m41 s2({~b[1],b[1],~b[1],b[1]},b[3:2],g[1]);
	m41 s3({h,h,h,h},b[3:2],g[0]);
endmodule
	
module m41(w, s, f);
	input [3:0]w;
	input [1:0]s;
	output f;
	reg f;
	always @(w or s)
		f = s[0]? (s[1]? w[3]: w[2]) : (s[1]? w[1]: w[0]);
endmodule
