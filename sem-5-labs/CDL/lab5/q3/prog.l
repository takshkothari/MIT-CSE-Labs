%{
int poi = 0;
int nei = 0;
int pof = 0;
int nef = 0;
%}
%%
[a-zA-Z]+ { words++; chars += strlen(yytext); }
" " { chars++; blank++; }
\n { lines++; }
. { chars++; }
%%
int main(int argc, char **argv)
{
yylex();
printf("%d %d %d %d\n", poi, nei, pof, nef); }
int yywrap()
{
return 1;
}