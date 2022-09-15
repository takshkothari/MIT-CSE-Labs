module bcd(x0,x1,x2,x3,y0,y1,y2,y3,cin,s0,s1,s2,s3);
	input x0,x1,x2,x3,y0,y1,y2,y3,cin;
	output s0,s1,s2,s3;
	
	fbAdd stage0(x0,x1,x2,x3,y0,y1,y2,y3,cin,st0,st1,st2,st3,cout);
	and (t1,st3,st2);
	and (t2,st3,st1);
	or (co,cout,t1,t2);
	//assign k={1'b0,co,co,1'b0};
	fbAdd stage1(st0,st1,st2,st3,1'b0,co,co,1'b0,1'b0,s0,s1,s2,s3,c);	
	
endmodule

module fbAdd(x0,x1,x2,x3,y0,y1,y2,y3,cin,s0,s1,s2,s3,cout);
	input x0,x1,x2,x3,y0,y1,y2,y3,cin;
	output s0,s1,s2,s3,cout;
	
	fa stage0(x0,y0,cin,s0,c1);
	fa stage1(x1,y1,c1,s1,c2);
	fa stage2(x2,y2,c2,s2,c3);
	fa stage3(x3,y3,c3,s3,cout);
	
endmodule

module fa(a,b,cin,s,cout);
	input a,b,cin;
	output s,cout;
	
	assign s = a ^ b ^ cin;
	assign cout = (a & b) | (a & cin) | (b & cin);

endmodule
