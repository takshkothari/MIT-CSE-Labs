
`timescale 1ns/1ns
`include "q1.v"

module q1_tb();
reg [3:0]w;
reg [1:0]s;
wire f;

q1 q1(w,s,f);
initial 
begin 
    $dumpfile("q1_tb.vcd");
    $dumpvars(0,q1_tb);

    w = 4'b0001; s = 2'b00; #20;
    w = 4'b0001; s = 2'b01; #20;
    w = 4'b0100; s = 2'b10; #20;
    w = 4'b0100; s = 2'b01; #20;

    $display("Test Complete");

end
endmodule
