module q2a(a, b, c, d, f, g);
   input a, b, c, d;
   output f, g;
   nand (x, a, b);
   xor (f, d, x, c);
   nor (g, b, c, d);
endmodule   
