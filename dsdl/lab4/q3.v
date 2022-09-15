module mult(x0,x1,y0,y1,s0,s1,s2,s3);
	input x0,x1,y0,y1;
	output s0,s1,s2,s3;
	
	and (s0,x0,y0);
	and (i1,x0,y1);
	and (i2,x1,y0);
	and (i3,x1,y1);
	
	
	ha stage01(i1,i2,s1,c1);
	ha stage02(i3,c1,s2,s3);
	
endmodule

module ha(a, b, s, c);
	input a, b;
	output s, c;
	assign s = a^b;
	assign c = a&b;
endmodule
