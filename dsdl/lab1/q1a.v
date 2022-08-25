module q1a(a, b, c, d, f);
   input a, b, c, d;
   output f;
   and (g, a, b);
   and (h, a, b);
   or (i, g, c);
   or (j, c, h);
   not (k, i);
   and (l, k, d);
   or (m, d, j);
   and (f, l, m);
endmodule   
