#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TableLength 30

enum tokenType { EOFILE=-1, LESS_THAN, LESS_THAN_OR_EQUAL, GREATER_THAN, GREATER_THAN_OR_EQUAL, EQUAL,NOT_EQUAL};

struct token {
	char *lexeme;
	int index;
	unsigned int rowno,colno; //row number, column number.
	enum tokenType type;
};

struct ListElement {
	struct token tok;
	struct ListElement *next;
};

struct ListElement *TABLE[TableLength];

void Initialize() {
	for(int i=0;i<TableLength;i++)
		TABLE[i] = NULL;
}
void Display() {
	//iterate through the linked list and display
}
int HASH(char *str) {
	//Develop an OpenHash function on a string.
}
int SEARCH(char *str) {
//Write a search routine to check whether a lexeme exists in the Symbol table.
//Returns 1, if lexeme is found
//else returns 0
}
void INSERT(struct token tk) {
	if(SEARCH(tk.lexeme)==1) {
		return; // Before inserting we check if the element is present already.
	}
	int val = HASH(tk.lexeme);
	struct ListElement* cur = (struct ListElement*)malloc(sizeof(struct ListElement));
	cur->tok = tk;
	cur->next = NULL;
	if(TABLE[val]==NULL) 
		TABLE[val] = cur; // No collision.
	else {
		struct ListElement * ele= TABLE[val];
		while(ele->next!=NULL) 
			ele = ele->next; // Add the element at the End in the case of a collision.
		ele->next = cur;
	}
}