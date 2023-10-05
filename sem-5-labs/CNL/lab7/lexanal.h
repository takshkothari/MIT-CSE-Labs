#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 

struct token
{
    char lexeme[64] ;

    int row,col;
};
 
static int row=1,col=1;
char buf[2048];
 
const char specialsymbols[]={'?',';',':',','};
const char *keywords[] = {"const", "char", "int","return","for", "while", "do",
                            "switch", "if", "else","unsigned", "case", "break","float"};
 
const char arithmeticsymbols[]={'*'};
 
int isKeyword(const char *str)
{   
    for(int i=0;i<sizeof(keywords)/sizeof(char*);i++)
    {
    if(strcmp(str,keywords[i])==0)
      {
      return 1;
      }
    }
    return 0;
}
 
int charBelongsTo(int c,const char *arr) {
    int len;
     
    if(arr==specialsymbols)
        len=sizeof(specialsymbols)/sizeof(char);
     
    else if(arr==arithmeticsymbols)
        len=sizeof(arithmeticsymbols)/sizeof(char);
     
    for(int i=0;i<len;i++) {
        if(c==arr[i])
            return 1;
    }
      return 0;
}
 
void fillToken(struct token *tkn,char c,int row,int col) {
    tkn->row=row;
    tkn->col=col;
    tkn->lexeme[0]=c;
    tkn->lexeme[1]='\0';
}
 
void newLine() {
    ++row;
    col=1;
}
 
struct token getNextToken(FILE *f1) {
    int c;
    struct token tkn;
    tkn.row=-1;
 
    int gotToken=0;
    if (c == EOF)
        strcpy(tkn.lexeme,"eof");
      
    while(!gotToken && (c=fgetc(f1))!=EOF){
        if(charBelongsTo(c,specialsymbols)) {
            fillToken(&tkn,c,row,col);
            gotToken=1;
            ++col;
        }
 
        else if(charBelongsTo(c,arithmeticsymbols)) {
            fillToken(&tkn,c,row,col);
            gotToken=1;
            ++col;
            }
     
        else if(c=='(')
            {
              fillToken(&tkn,c,row,col);
                 gotToken=1;
              ++col;
            }
     
        else if(c==')')
          {
              fillToken(&tkn,c,row,col);
                 gotToken=1;
              ++col;
        }
     
        else if(c=='{') {
            fillToken(&tkn,c,row,col);
            gotToken=1;
            ++col;
        }
     
        else if(c=='}') {
        fillToken(&tkn,c,row,col);
        gotToken=1;
        ++col;
        }
     
        else if(c=='+') {
            int d=fgetc(f1);
            if(d!='+') {
                fillToken(&tkn,c,row,col);
                gotToken=1;
                ++col;
                fseek(f1,-1,SEEK_CUR);
            }

            else {
                fillToken(&tkn,c,row,col);
                strcpy(tkn.lexeme,"++");
                gotToken=1;
                col+=2;
            }
        }
     
        else if(c=='-') {
            int d=fgetc(f1);
     
            if(d!='-') {
                fillToken(&tkn,c,row,col);
                gotToken=1;
                ++col;
                fseek(f1,-1,SEEK_CUR);
            }
     
            else {
                fillToken(&tkn,c,row,col);
                strcpy(tkn.lexeme,"--");
                gotToken=1;
                col+=2;
            }
        }
     
        else if(c=='=') {
            int d=fgetc(f1);
     
            if(d!='=') {
                fillToken(&tkn,c,row,col);
                gotToken=1;
                ++col;
                fseek(f1,-1,SEEK_CUR);
            }
     
            else {
                fillToken(&tkn,c,row,col);
                strcpy(tkn.lexeme,"==");
                gotToken=1;
                col+=2;
            }
        }
     
        else if(isdigit(c)) {
            tkn.row=row;
            tkn.col=col++;
            tkn.lexeme[0]=c;
     
            int k=1;
     
            while((c=fgetc(f1))!=EOF && isdigit(c)) {
                tkn.lexeme[k++]=c;
                col++;
            }
     
            tkn.lexeme[k]='\0';
            strcpy(tkn.lexeme,"num");
            gotToken=1;
            fseek(f1,-1,SEEK_CUR);
        }
     
        else if(c == '#') {
            while((c = fgetc(f1)) != EOF && c != '\n');
            newLine();
        }
     
        else if(c=='\n') {
            newLine();
            c = fgetc(f1);

            if(c == '#') {
                while((c = fgetc(f1)) != EOF && c != '\n');
                    newLine();
            }
     
            else if(c != EOF)
                fseek(f1, -1, SEEK_CUR);
        }
     
        else if(isspace(c))
            ++col;
     
        else if(isalpha(c)||c=='_') {
            tkn.row=row;
            tkn.col=col++;
            tkn.lexeme[0]=c;
            int k=1;
     
            while((c=fgetc(f1))!= EOF && isalnum(c)) {
                tkn.lexeme[k++]=c;
                ++col;
            }
     
            tkn.lexeme[k]='\0';
     
          	if(!isKeyword(tkn.lexeme))
          		strcpy(tkn.lexeme,"id");
     
            gotToken=1;
            fseek(f1,-1,SEEK_CUR);
        }
     
        else if(c=='/') {
            int d=fgetc(f1);
            ++col;
     
            if(d=='/') {
                while((c=fgetc(f1))!= EOF && c!='\n')
                    ++col;
     
                if(c=='\n')
                    newLine();
            }
     
            else if(d=='*') {
                do {
                    if(d=='\n')
                        newLine();
     
                    while((c==fgetc(f1))!= EOF && c!='*') {
                        ++col;
                        if(c=='\n')
                            newLine();
                    }
     
                    ++col;
                } while((d==fgetc(f1))!= EOF && d!='/' && (++col));
                ++col;
            }
     
            else {
                fillToken(&tkn,c,row,--col);
                gotToken=1;
                fseek(f1,-1,SEEK_CUR);
            }
        }
     
        else if(c == '"') {
            tkn.row = row;
            tkn.col = col;
            int k = 1;
            tkn.lexeme[0] = '"';
            while((c = fgetc(f1)) != EOF && c != '"') {
                tkn.lexeme[k++] = c;
                ++col;
            }
     
            tkn.lexeme[k++] = '"';
           	tkn.lexeme[k]='\0';
            gotToken = 1;
        }
     
        else if(c == '<' || c == '>' || c == '!') {
            fillToken(&tkn, c, row, col);
            ++col;
            int d = fgetc(f1);
            if(d == '=') {
                ++col;
                strcat(tkn.lexeme, "=");
            }
            else
            	fseek(f1, -1, SEEK_CUR);
     
            gotToken = 1;
        }
     
        else if(c == '&' || c == '|') {
            int d = fgetc(f1);
            if(c == d) {
                tkn.lexeme[0] = tkn.lexeme[1] = c;
                tkn.lexeme[2] = '\0';
                tkn.row = row;
                tkn.col = col;
                ++col;
                gotToken = 1;
            }
            else
                fseek(f1, -1, SEEK_CUR);
            ++col;
        }
     
        else
            ++col;
    }
    if (c == EOF){
    strcpy(tkn.lexeme,"eof");}
    return tkn;
}