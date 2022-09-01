`timescale 1ns/1ns
`include "q3.v"

module q3_tb();
reg a, b, c, d;
wire f;

q3 q3(a, b, c, d, f);
initial
begin

       $dumpfile("q3_tb.vcd");
       $dumpvars(0, q3_tb);
       
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
       
