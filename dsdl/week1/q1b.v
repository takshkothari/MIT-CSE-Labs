module q1b(a, b, c, d, f);
   input a, b, c, d;
   output f;
   wire g,h;
   assign g = (a & b) | c;
   assign h = (a & b) | c;
   assign f = (~g & d) & (d | h);
endmodule
