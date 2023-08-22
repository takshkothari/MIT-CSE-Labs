`timescale 1ns/1ns
`include "q2b.v"

module q2b_tb();
reg [2:0]i;
wire f;

q2b q2b(i,f);
initial 
begin 
    $dumpfile("q2b_tb.vcd");
    $dumpvars(0,q2b_tb);

    i=3'b000; #20;
    i=3'b010; #20;
    i=3'b101; #20;

    $display("Test Complete");

end
endmodule
