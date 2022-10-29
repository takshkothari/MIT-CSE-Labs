#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char st[20][20];
    int tos;
} stack;
void push(stack *s, char *ch)
{
    int i = 0;
    while (ch[i] != '\0')
    {
        (s->st)[++(s->tos)][i] = ch[i];
    }
}
char *pop(stack *s)
{
    int i = 0;
    char *ch = s->st[(s->tos)--];
    char *ans;
    int len = (int)strlen(ch);
    ans = (char *)malloc(len * sizeof(char));
    while (ch[i] != '\0')
    {
        ans[i] = ch[i];
    }
    return ans;
}
int isop(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return 1;
    default:
        return 0;
    }
}
int main()
{
    int i, ind = 0;
    char expr[20], ch, *t;
    printf("enter the prefix\n ");
    scanf("%s", expr);
    stack s;
    s.tos = -1;
    char op1[20], op2[20];
    i = strlen(expr) - 1;
    do
    {
        if (expr[i] == ')')
        {
            continue;
        }
        else if (expr[i] == '(')
        {
            continue;
        }
        else if (isop(expr[i]))
        {
            strcpy(op1, pop(&s));
            strcpy(op2, pop(&s));
            int i2, i3 = 0, ind2 = 0;
            int len = strlen(op1) + strlen(op2) + 1;
            t = (char *)malloc(len * sizeof(char));
            for (i2 = 0; i2 < len; i2++)
            {
                if (i2 < (int)strlen(op1))
                    t[ind2++] = op1[i2];
                else if (i2 == len - 1)
                    t[ind2++] = expr[i];
                else
                    t[ind2++] = op2[i3++];
            }
            t[ind2] = '\0';
            push(&s, t);
        }
        else
        {
            t = (char *)malloc(2 * sizeof(char));
            t[0] = expr[i];
            t[1] = '\0';
            push(&s, t);
        }
        i--;
    } while (expr[i] != '\0');

    printf("postfix expression: ");
    printf("%s", s.st[0]);
}