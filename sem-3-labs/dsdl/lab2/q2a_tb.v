`timescale 1ns/1ns
`include "q2a.v"

module q2a_tb();
reg b, c, d;
wire f;

q2a q1(b, c, d, f);
initial
begin

       $dumpfile("q2a_tb.vcd");
       $dumpvars(0, q2a_tb);
       
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
       
