%{
int poi = 0;
int nei = 0;
int pof = 0;
int nef = 0;
%}
%%
"-"[0-9]+\.[0-9]+ { nef++; }
"-"[0-9]+ { nei++; }
[+]?[0-9]+\.[0-9]+ { pof++; }
[+]?[0-9]+ { poi++; }
%%
int main(int argc, char **argv)
{
yylex();
printf("%d %d %d %d\n", poi, nei, pof, nef); }
int yywrap()
{
return 1;
}