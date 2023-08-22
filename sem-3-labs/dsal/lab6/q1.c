#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 20
#define EXPR_SIZE 20

typedef enum
{
    lparan,
    rparan,
    plus,
    minus,
    multiply,
    divide,
    mod,
    eos,
    operand
} PRECEDENCE;

int stack[STACK_SIZE];
char expr[EXPR_SIZE];

void push(int *top, int x)
{
    stack[++(*top)] = x;
}

int pop(int *top)
{
    return stack[(*top)--];
}

PRECEDENCE getToken(char *symbol, int *n)
{
    *symbol = expr[(*n)++];
    switch (*symbol)
    {
    case '+':
        return plus;
    case '-':
        return minus;
    case '*':
        return multiply;
    case '/':
        return divide;
    case '%':
        return mod;
    case '(':
        return lparan;
    case ')':
        return rparan;
    case '\0':
        return eos;
    default:
        return operand;
    }
}

int eval()
{
    PRECEDENCE token;
    char symbol;
    int n = 0, c, op1, op2, top = -1;
    token = getToken(&symbol, &n);
    while (token != eos)
    {
        if (token == operand)
        {
            c = symbol - '0';
            push(&top, c);
        }
        else
        {
            op2 = pop(&top);
            op1 = pop(&top);
            if (token == plus)
                push(&top, op2 + op1);
            else if (token == minus)
                push(&top, op2 - op1);
            else if (token == multiply)
                push(&top, op2 * op1);
            else if (token == divide)
                push(&top, op2 / op1);
            else if (token == mod)
                push(&top, op2 % op1);
        }
        token = getToken(&symbol, &n);
        // printf("%d\n", stack[top]);
    }
    return pop(&top);
}

void main()
{
    char ex[EXPR_SIZE];
    int i, j = 0;
    printf("enter prefix expression\n");
    scanf("%s", ex);
    for (i = strlen(ex) - 1; i >= 0; i--, j++)
        expr[j] = ex[i];
    printf("\nAnswer: %d\n", eval());
}