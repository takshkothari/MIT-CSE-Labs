module m41(w, s, f);
	input [3:0]w;
	input [1:0]s;
	output f;
	reg f;
	always @(w or s)
		f = s[0]? (s[1]? w[3]: w[2]) : (s[1]? w[1]: w[0]);
endmodule

module q2(w, s, f);
	input [15:0] w;
	input [3:0] s;
	output f;
	wire [3:0] x;
	
	m41 stage01(w[3:0], s[1:0], x[0]);
	m41 stage02(w[7:4], s[1:0], x[1]);
	m41 stage03(w[11:8], s[1:0], x[2]);
	m41 stage04(w[15:12], s[1:0], x[3]);
	m41 stage1(x, s[3:2], f);
endmodule
