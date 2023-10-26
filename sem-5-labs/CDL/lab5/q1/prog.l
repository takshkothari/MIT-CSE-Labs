%{
#include<stdio.h>
int vow = 0;
int conso = 0;
%}
%%
[aeiouAEIOU] { vow++; }
[a-zA-Z] { conso++; }
%%
int main()
{
yylex();
printf("%d %d", vow, conso);
}
int yywrap()
{
return 1;
}