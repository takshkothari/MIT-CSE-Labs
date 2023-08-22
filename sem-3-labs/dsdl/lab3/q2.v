module q2(a, b, c, d, f);
   input a, b, c, d;
   output f;
   nor(g,d,d);
   nor(h,b,d);
   nor(i,b,c);
   nor(j,a,c,g);
   nor(k,h,i,j);
   nor(f,k,k);
endmodule
