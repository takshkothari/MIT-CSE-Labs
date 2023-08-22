`timescale 1ns/1ns
`include "q2.v"

module q2_tb();
reg [3:0] w;
reg e;
wire [0:15] y;

q2 q2(w,e,y);
initial
begin
    $dumpfile("q2_tb.vcd");
    $dumpvars(0,q2_tb);

    w = 4'b0000; e = 1; #20;
    w = 4'b0001; e = 1; #20;
    w = 4'b1101; e = 1; #20;
    w = 4'b1111; e = 1; #20;

    $display("Test Complete");

end
endmodule
