module q1(w,f);
	input [3:0] w;
	output f;
	wire [15:0] k;
	d416 s0(w, k);
	assign f = k[1] | k[3] | k[6] | k[7] | k[9] | k[14] | k[15];	
endmodule

module d416(w,f);
	input [3:0] w;
	output reg [15:0] f;
	integer i;
	always@(w)
	begin
		for(i=0;i<16;i=i+1)
		begin
			if(w == i)
				f[i] = 1;
			else
				f[i] = 0;
		end
	end
endmodule
