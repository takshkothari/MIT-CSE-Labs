module ha(a, b, s, c);
	input a, b;
	output s, c;
	assign s = a^b;
	assign c = a&b;
endmodule

module fa(x, y, cin, sum, cout);
	input x, y, cin;
	output sum, cout;
	assign sum = x^y^cin;
	assign cout = (x & y)|(y & cin)|(cin & x);
endmodule

module dfa(x1, y1, Cin, Sum, Cout);
	input x1, y1, Cin;
	output Sum, Cout;
	ha stage0(x1, y1, s1, c1);
	ha stage1(s1, Cin, Sum, c2);
	assign Cout = c1|c2;
endmodule
