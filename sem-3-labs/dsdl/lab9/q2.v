module q2(w,f,g,h);
	input [3:0] w;
	output f,g,h;
	wire [15:0] z;
	d416 s0(w,1'b1,z);
	
	assign f = z[10] | z[11] | z[3] | z[7] | z[6] | z[14];
	assign g = z[10] | z[14] | z[2] | z[3];
	assign h = z[0] | z[1] | z[14] | z[15] | z[3] | z[7];
endmodule
	

module d416(w,En,f);
	input [3:0] w;
	input En;
	output [15:0] f;
	wire [3:0] c;
	d24 stage0(w[3:2],En,c);
	d24 stage1(w[1:0],c[0],f[3:0]);
	d24 stage2(w[1:0],c[1],f[7:4]);
	d24 stage3(w[1:0],c[2],f[11:8]);
	d24 stage4(w[1:0],c[3],f[15:12]);
endmodule

module d24(w,En,f);	
	input [1:0] w;
	input En;
	output reg [3:0] f;
	always@(w,En)
	begin
		case(En)
		  0: f = 4'b0000;
		  1:
		  begin
		  	case(w)
		  		0:f=4'b0001;
		  		1:f=4'b0010;
		  		2:f=4'b0100;
		  		3:f=4'b1000;
		  	endcase
		  end
		endcase
	end
endmodule	
