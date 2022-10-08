#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 20

typedef struct
{
    char s[size];
    int top;
} STACK;

void push(STACK *s1, char x)
{
    s1->s[++(s1->top)] = x;
}

char pop(STACK *s1)
{
    return s1->s[s1->top--];
}

int pre(char x)
{
    switch (x)
    {
    case '#':
        return 0;
    case '(':
    case ')':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '$':
        return 4;
    }
}

void main()
{
    STACK s1;
    s1.top = -1;
    char infix[size], prefix[size], revinf[size], revpref[size], x, t, ch;
    int i = 0, k = 0;
    printf("enter infix expression\n");
    scanf("%s", infix);
    int l = strlen(infix);
    push(&s1, '#');
    for (i = l - 1; i >= 0; i--, k++)
        revinf[k] = infix[i];
    revinf[k] = '\0';
    i = k = 0;
    while ((ch = revinf[i++]) != '\0')
    {
        switch (ch)
        {
        case ')':
            push(&s1, ch);
            printf("PUSH %c\n", ch);
            break;
        case '(':
            while (s1.s[s1.top] != ')')
            {
                t = pop(&s1);
                prefix[k++] = t;
            }
            x = pop(&s1);
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while (pre(s1.s[s1.top]) > pre(ch))
            {
                t = pop(&s1);
                prefix[k++] = t;
                printf("POP and APPEND %c\n", t);
            }
            push(&s1, ch);
            printf("PUSH %c\n", ch);
            break;
        case '$':
            if (s1.s[s1.top] == '$')
            {
                t = pop(&s1);
                prefix[k++] = t;
                printf("POP and APPEND %c\n", t);
            }
            push(&s1, '$');
            break;
        default:
            prefix[k++] = ch;
            break;
        }
    }
    int m = 0;
    while (s1.s[s1.top] != '#')
    {
        t = pop(&s1);
        prefix[k++] = t;
    }
    prefix[k] = '\0';
    for (i = l - 1; i >= 0; i--)
        revpref[m++] = prefix[i];
    revpref[m] = '\0';
    printf("\ninfix expression: %s\nprefix expression: %s\n", infix, prefix);
}