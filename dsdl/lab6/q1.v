module m21(w, s, f);
	input [1:0]w;
	input s;
	output f;
	reg f;
	always @(w or s)
	begin
		f=w[1];
		if(s==0)
			f=w[0];
	end
endmodule

module q1(w, s, f);
	input [3:0]w;
	input [1:0]s;
	output f;
	wire [1:0]x;
	
	m21 stage01(w[1:0], s[0], x[0]);
	m21 stage02(w[3:2], s[0], x[1]);
	m21 stage1(x, s[1], f);
endmodule
