%{
#include<stdio.h>
%}
%%
[a-zA-Z_][a-zA-Z0-9_]* { printf(" Identifier"); }
%%
int main()
{
yylex();
}
int yywrap()
{
return 1;
}