module d24(w,e,y);
	input [1:0] w;
	input e;
	output reg [0:3] y;
	always @(w or e)
	begin
		y=4'b1111;
		if (e == 1)
		begin
			case(w)
				0:  y[0] = 0;
				1:  y[1] = 0;
				2:  y[2] = 0;
				3:  y[3] = 0; 
			endcase
		end
	end
endmodule

module q3(w,e,y);
	input [3:0] w;
	input e;
	output [0:15] y;
	wire [0:3] y2;
    
	d24 stage0(w[3:2],e,y2);
	d24 stage1(w[1:0],~y2[0],y[0:3]);
	d24 stage2(w[1:0],~y2[1],y[4:7]);
	d24 stage3(w[1:0],~y2[2],y[8:11]);
	d24 stage4(w[1:0],~y2[3],y[12:15]);

endmodule
