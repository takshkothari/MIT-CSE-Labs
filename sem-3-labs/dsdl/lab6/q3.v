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

module m81(w, s, f);
	input [7:0] w;
	input [2:0] s;
	output f;
	reg f;
	always @(w or s)
	case(s)
		0: f = w[0];
		1: f = w[1];
		2: f = w[2];
		3: f = w[3];
		4: f = w[4];
		5: f = w[5];
		6: f = w[6];
		7: f = w[7];
	endcase
endmodule

module q3(w, s, f);
	input [15:0] w;
	input [3:0] s;
	output f;
	wire [1:0] x;
	
	m81 s1(w[7:0], s[2:0], x[0]);
	m81 s2(w[15:8], s[2:0], x[1]);
	m21 s3(x, s[3], f);
endmodule
