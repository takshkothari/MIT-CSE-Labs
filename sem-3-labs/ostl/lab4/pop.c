#include <stdio.h>
#include "stack.h"

int pop(STACK *a)
{
    int n = (a->top);
    int ele = *((a->arr) + n - 1);
    a->arr = (int *)realloc(a->arr, (n - 1) * sizeof(int));
    (a->top) = n - 1;
    return ele;
}