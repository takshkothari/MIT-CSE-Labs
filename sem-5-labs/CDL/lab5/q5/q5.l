%{
    #include<stdio.h>
    int num;
%}

%%
[0-9]+ { num = atoi(yytext); }
%%

int main(){
    yylex();
    printf("Hexadecimal number is %X",num);
}

int yywrap(){
    return 1;
}