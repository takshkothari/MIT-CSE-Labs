module m81(d, s, f);
	input d;
	input [2:0] s;
	output f;
	reg f;
	always @(d or s)
	case(s)
		0: f = 0;
		1: f = 0;
		2: f = 1;
		3: f = 1;
		4: f = 1;
		5: f = 0;
		6: f = 1;
		7: f = ~d;
	endcase
endmodule

module q1a(a,b,c,d,F);
	input a,b,c,d;
	output F;
	m81 s0(d, {a, b, c}, F);
endmodule
