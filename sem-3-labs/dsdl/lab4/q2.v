module fa(a,b,cin,s,cout);
	input a,b,cin;
	output s,cout;
	
	assign s = a ^ b ^ cin;
	assign cout = (a & b) | (a & cin) | (b & cin);

endmodule

module addsub(x0,x1,x2,x3,y0,y1,y2,y3,k,s0,s1,s2,s3,cout);
	input x0,x1,x2,x3,y0,y1,y2,y3,k;
	output s0,s1,s2,s3,cout;
	
	xor (yk0,y0,k);
	xor (yk1,y1,k);
	xor (yk2,y2,k);
	xor (yk3,y3,k);
	
	fa stage0(x0,yk0,k,s0,c1);
	fa stage1(x1,yk1,c1,s1,c2);
	fa stage2(x2,yk2,c2,s2,c3);
	fa stage3(x3,yk3,c3,s3,cout);
	
	
endmodule 
/*
module FBAddSub(x [3:0], y [3:0], k,s [3:0], cout);
	input x [3:0], y [3:0], k;
	output [3:0] s, cout;
	
	assign yk = {(y[0]^k),(y[1]^k),(y[2]^k),(y[3]^k)};
	
	fa stage0(x[0],yk[0],k,s[0],c1);
	fa stage1(x[1],yk[1],c1,s[1],c2);
	fa stage2(x[2],yk[2],c2,s[2],c3);
	fa stage3(x[3],yk[3],c3,s[3],cout);
	

endmodule */
