module q3(w,En,f);
	input [2:0] w;
	input En;
	output f;
	wire [7:0] c;
	d24 s0(w[1:0],~w[2]&En,c[3:0]);
	d24 s1(w[1:0],w[2]&En,c[7:4]);
	assign f = c[3] | c[5] | c[6] | c[7];
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
