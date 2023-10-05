#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexanal.h"

struct token token2;
FILE *fp;

void Program();
void declarations();
int data_type();
void identifier_list();
void identifier_listprime();
void assign_stat();
void assign_statprime();

void valid(){
	printf("\n-------SUCCESS!-------\n\n");
	exit(0);
}

void invalid(char *follow)
{
	printf("\n----------PARSER ERROR!----------\n\n");
	printf("Error reported at row no. %d column no. %d\n", token2.row, token2.col);
	printf("Expected %s\n", follow);
	exit(0);
}

void Program(){
	token2 = getNextToken(fp);
	if (strcmp(token2.lexeme, "main") == 0){
		token2 = getNextToken(fp);
		if (strcmp(token2.lexeme, "(") == 0){
			token2 = getNextToken(fp);
			if (strcmp(token2.lexeme, ")") == 0){
				token2 = getNextToken(fp);
				if (strcmp(token2.lexeme, "{") == 0){
					token2 = getNextToken(fp);
					declarations();
					assign_stat();
					if (strcmp(token2.lexeme, "}") == 0){
						token2 = getNextToken(fp);
					}
					else{
						invalid("}");
					}
				}
				else{
					invalid("{");				}
			}
			else{
				invalid(")");
			}
		}
		else{
			invalid("(");
		}
	}
	else{
		invalid("main");
	}
	valid();
}

void declarations(){
	if (data_type()){
		identifier_list();
		if (strcmp(token2.lexeme, ";") == 0){
			token2 = getNextToken(fp);
			declarations();
		}
		else{
			invalid(";");
		}
	}
}

int data_type(){
	if (strcmp(token2.lexeme, "int") == 0){
		token2 = getNextToken(fp);
		return 1;
	}
	else if (strcmp(token2.lexeme, "char") == 0){
		token2 = getNextToken(fp);
		return 1;
	}
	else{
		return 0;
	}
}

void identifier_list(){
	if (strcmp(token2.lexeme, "id") == 0){
		token2 = getNextToken(fp);
		identifier_listprime();
	}
	else{
		invalid("id");
	}
}

void identifier_listprime(){
	if (strcmp(token2.lexeme, ",") == 0){
		token2 = getNextToken(fp);
		identifier_list();
	}
}

void assign_stat(){
	if (strcmp(token2.lexeme, "id") == 0){
		token2 = getNextToken(fp);
		if (strcmp(token2.lexeme, "=") == 0){
			token2 = getNextToken(fp);
			assign_statprime();
		}
		else{
			invalid("=");
		}
	}
	else{
		invalid("id");
	}
}

void assign_statprime(){
	if (strcmp(token2.lexeme, "id") == 0){
		token2 = getNextToken(fp);
		if (strcmp(token2.lexeme, ";") == 0){
			token2 = getNextToken(fp);
		}
		else{
			invalid(";");
		}
	}
	else if (strcmp(token2.lexeme, "num") == 0){
		token2 = getNextToken(fp);
		if (strcmp(token2.lexeme, ";") == 0){
			token2 = getNextToken(fp);
		}
		else{
			invalid(";");
		}
	}
	else{
		invalid("id | num");
	}
}

int main(){
	char temp[100];
	FILE *fa;
	char filename[100],c;
	printf("Enter file name\n");
	scanf("%s",filename);
	fp = fopen(filename,"r");
	if (fp == NULL){
		printf("Cannot open file \n");
		exit(0);
	}
	Program();
	valid();
	
}