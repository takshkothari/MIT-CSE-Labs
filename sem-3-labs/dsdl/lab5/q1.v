module q1(x, y, xeqy, xgty, xlty);
 
	input [4:0]x;
	input [4:0]y;
	output xeqy;
	output xgty;
	output xlty;
	wire [4:0]k;
 
	assign k=~(x^y);
	assign xeqy=(k[4]&k[3]&k[2]&k[1]&k[0]);
	assign xgty=(x[4]&~y[4])|(k[4]&x[3]&~y[3])|(k[4]&k[3]&x[2]&~y[2])|(k[4]&k[3]&k[2]&x[1]&~y[1])|(k[4]&k[3]&k[2]&k[1]&x[0]&~y[0]);
	assign xlty=~(xeqy|xgty);
 
endmodule
