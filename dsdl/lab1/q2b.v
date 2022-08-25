module q2b(a, b, c, d, f, g);
   input a, b, c, d;
   output f, g;
   wire x, y;
   assign x = a&b;
   assign f = ~x^c^d;
   assign y = b|c|d;
   assign g = ~y;
endmodule
