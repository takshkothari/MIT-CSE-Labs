%{
int rd = 0;
int wr = 0;
%}

%%
scanf { rd++; fwrite("read", 1, 4, yyout); }
printf { wr++; fwrite("write", 1, 5, yyout); }
%%

int main(int argc, char **argv) {
yyin = fopen("inp.txt", "r");
yyout = fopen("op.txt", "w+");
yylex();
printf("%d %d\n", rd, wr); 
}
int yywrap() {
	return 1;
}