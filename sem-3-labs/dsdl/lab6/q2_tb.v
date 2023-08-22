`timescale 1ns/1ns
`include "q2.v"

module q2_tb();
reg [15:0] w;
reg [3:0] s;
wire f;

q2 q2(w,s,f);
initial 
begin 
    $dumpfile("q2_tb.vcd");
    $dumpvars(0,q2_tb);

    w = 16'b0000000000000001; s = 4'b0000;#20;
    w = 16'b0000000000000001; s = 4'b0001;#20;
    w = 16'b0000000000000000; s = 4'b0010;#20;
    w = 16'b0000000000000000; s = 4'b0101;#20;

    $display("Test Complete");

end
endmodule
