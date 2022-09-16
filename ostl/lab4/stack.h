#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int top;
    int *arr;
} STACK;

int pop(STACK *);
void push(STACK *, int);
void display(STACK *);