module m41(c, d, s, f);
	input c,d;
	input [0:1]s;
	output f;
	reg f;
	always @(c or d or s)
		f = s[0]? (s[1]? 0: 0) : (s[1]? d: (c + ~d));
endmodule

module q1b(a,b,c,d,F);
	input a,b,c,d;
	output F;
	m41 s0(c, d, {a, b}, F);
endmodule
