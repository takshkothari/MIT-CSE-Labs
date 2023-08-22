module q1(w,e,y);
	input [2:0] w;
	input e;
	output [0:7] y;
	wire t1,t2;
	assign t1 = ~w[2] & e;
	assign t2 = w[2] & e;

	d24 stage0(w[1:0],t1,y[0:3]);
	d24 stage1(w[1:0],t2,y[4:7]);

endmodule

module d24(w,e,y);
	input [1:0] w;
	input e;
	output reg [0:3] y;
	integer x;
	always @(w or e)
	for (x = 0; x <= 3; x=x+1)
		if ((w==x) && (e == 1))
			y[x] = 1;
		else
			y[x] = 0;
endmodule
