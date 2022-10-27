module q4(w,f);
	input [3:0] w;
	output reg [2:0] f;
	always @(w)
	begin
		casex(w)
		4'b0000: f=3'bzz0;
		4'b0001: f=3'b001;
		4'b001x: f=3'b011;
		4'b01xx: f=3'b101;
		4'b1xxx: f=3'b111;
		endcase
	end
endmodule
