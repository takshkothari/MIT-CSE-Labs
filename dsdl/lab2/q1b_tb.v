`timescale 1ns/1ns
`include "q1b.v"

module q1b_tb();
reg b, c, d;
wire f;

q1b q1(b, c, d, f);
initial
begin

       $dumpfile("q1b_tb.vcd");
       $dumpvars(0, q1b_tb);
       
       b=1'b0; c=1'b0; d=1'b0;
       #20;
       
       b=1'b0; c=1'b0; d=1'b1;
       #20;
       
       b=1'b0; c=1'b1; d=1'b0;
       #20;
       
       b=1'b0; c=1'b1; d=1'b1;
       #20;
       
       b=1'b1; c=1'b0; d=1'b0;
       #20;
       
       b=1'b1; c=1'b0; d=1'b1;
       #20;
       
       b=1'b1; c=1'b1; d=1'b0;
       #20;
       
       b=1'b1; c=1'b1; d=1'b1;
       #20;
       
       $display("Test complete");
end

endmodule
       
