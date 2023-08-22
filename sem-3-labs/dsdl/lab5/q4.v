module comp2bit(A, B, AeqB, AgtB, AltB);
	input [1:0]A;
	input [1:0]B;
	output AeqB,AgtB,AltB;
	wire [1:0]i;
	assign i = ~(A^B);
	assign AeqB = i[1]&i[0];
	assign AgtB = (A[1]&~B[1])|(i[1]&A[0]&~B[0]);
	assign AltB = ~(AeqB|AgtB);
endmodule

module comp4bit(a,b,aeqb,agtb,altb);
	input [3:0]a;
	input [3:0]b;
	output aeqb, agtb, altb;
	wire AeqB1, AgtB1, AltB1;
	comp2bit stage0(a[3:2], b[3:2], AeqB1, AgtB1, AltB1);
	comp2bit stage1(a[1:0], b[1:0], AeqB2, AgtB2, AltB2);
	assign aeqb = AeqB1 & AeqB2;
	assign agtb = AgtB1|(AeqB1 & AgtB2);
	assign altb = ~(aeqb|agtb);
endmodule
