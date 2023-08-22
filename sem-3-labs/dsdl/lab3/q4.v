module q4(a, b, c, d, f);
   input a, b, c, d;
   output f;
   nor(g,a,a);
   nor(h,c,c);
   nor(i,d,d);
   nor(j,g,h);
   nor(f,i,j);
endmodule
