module q4(w,s,f);
	input [7:0] w;
	input [2:0] s;
	output reg f;
	integer i;
	wire [7:0] c;
	d38 s0(s,1'b1,c);
	always@(c)
	begin
		f=1'b0;
		for(i=0;i<8;i=i+1)
		begin
			if(s==i)
				f= f | w[i]&c[i];
		end
	end
endmodule

module d38(w,En,f);
	input [2:0] w;
	input En;
	output reg [7:0] f;
	integer i;
	always@(w,En)
	begin
		for(i=0;i<=8;i=i+1)
		begin
			if((w == i) && (En == 1))
				f[i] = 1;
			else
				f[i] = 0;
		end
	end		
endmodule
