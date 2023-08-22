module m21(a, b, c, f);
	input a,b,c;
	output f;
	reg f;
	always @(a)
	case(a)
		0: f = b & c;
		1: f = b | c;
	endcase
endmodule

module q2a(a, b, c , F);
	input a,b,c;
	output F;
	m21 s0(a,b,c,F);
endmodule

