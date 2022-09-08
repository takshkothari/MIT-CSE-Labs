module q1(a, b, c, d, f);
   input a, b, c, d;
   output f;
   nand(g,b,b);
   nand(h,d,d);
   nand(i,a,g);
   nand(j,c,h);
   nand(k,i,j);
   nand(f,k,k);
endmodule
