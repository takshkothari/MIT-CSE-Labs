module q5(w,f);
	input [15:0] w;
	output reg [3:0] f;
	integer i;
	always @(w)
	begin
		for(i=0;i<16;i=i+1)
		begin
			if(w[i] == 1)
				f=i;
		end
	end
endmodule
