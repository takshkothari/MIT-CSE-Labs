`timescale 1ns/1ns
`include "q1.v"

module q1_tb();
reg [2:0] w;
reg e;
wire [0:7] y;

q1 q1(w,e,y);
initial
begin
    $dumpfile("q1_tb.vcd");
    $dumpvars(0,q1_tb);
    e = 1;
    w = 3'b000;#20;
    w = 3'b001;#20;
    w = 3'b010;#20;
    w = 3'b011;#20;
    w = 3'b100;#20;
    w = 3'b101;#20;
    w = 3'b110;#20;
    w = 3'b111;#20;

    $display("Test Complete");

end
endmodule
