module q2b(i,f);
	input [2:0]i;
	output f;
	m21 stage0({i[0],1'b0},i[1],g);
	m21 stage1({1'b1,i[0]},i[1],h);
	m21 stage2({h,g},i[2],f);
endmodule

module m21(a,s,f);
	input [1:0]a;
	input s;
	output f;
	reg f;
	always @ (a,s)
	case(s)
		0:f=a[0];
		1:f=a[1];
	endcase
endmodule
