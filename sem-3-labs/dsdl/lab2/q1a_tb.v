`timescale 1ns/1ns
`include "q1a.v"

module q1a_tb();
reg a, b, c, d;
wire f;

q1a q1(a, b, c, d, f);
initial
begin

       $dumpfile("q1a_tb.vcd");
       $dumpvars(0, q1a_tb);
       
       a=1'b0; b=1'b0; c=1'b0; d=1'b0;
       #20;
       
       a=1'b0; b=1'b0; c=1'b0; d=1'b1;
       #20;
       
       a=1'b0; b=1'b0; c=1'b1; d=1'b0;
       #20;
       
       a=1'b0; b=1'b0; c=1'b1; d=1'b1;
       #20;
       
       a=1'b0; b=1'b1; c=1'b0; d=1'b0;
       #20;
       
       a=1'b0; b=1'b1; c=1'b0; d=1'b1;
       #20;
       
       a=1'b0; b=1'b1; c=1'b1; d=1'b0;
       #20;
       
       a=1'b0; b=1'b1; c=1'b1; d=1'b1;
       #20;
       
       a=1'b1; b=1'b0; c=1'b0; d=1'b0;
       #20;
       
       a=1'b1; b=1'b0; c=1'b0; d=1'b1;
       #20;
       
       a=1'b1; b=1'b0; c=1'b1; d=1'b0;
       #20;
       
       a=1'b1; b=1'b0; c=1'b1; d=1'b1;
       #20;
       
       a=1'b1; b=1'b1; c=1'b0; d=1'b0;
       #20;
       
       a=1'b1; b=1'b1; c=1'b0; d=1'b1;
       #20;
       
       a=1'b1; b=1'b1; c=1'b1; d=1'b0;
       #20;
       
       a=1'b1; b=1'b1; c=1'b1; d=1'b1;
       #20;
       
       $display("Test complete");
end

endmodule
       
