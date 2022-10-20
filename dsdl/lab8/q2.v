module q2(w,e,y);
	input [3:0] w;
	input e;
	output [0:15] y;

	wire t1,t2;
	assign t1 = ~w[3] & e;
	assign t2 = w[3] & e;

	d38 stage0(w[2:0],t1,y[0:7]);
	d38 stage1(w[2:0],t2,y[8:15]);

endmodule

module d38(w,e,y);
	input [2:0] w;
	input e;
	output reg [0:7] y;
	integer k;

	always @(w or e)
		for(k = 0; k <= 7; k=k+1)
		if ((w == k) && (e == 1))
			y[k] = 1;
		else 
			y[k] = 0;
endmodule
