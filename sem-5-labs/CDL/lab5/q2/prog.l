%{
int chars = 0;
int words = 0;
int lines = 0;
int blank = 0;
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
printf("%d %d %d %d\n", lines, blank, words, chars); }
int yywrap()
{
return 1;
}