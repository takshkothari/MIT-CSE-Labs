#include <stdio.h>
#include "stack.h"

void display(STACK *a)
{
    for (int i = 0; i < a->top; i++)
    {
        printf("%d ", *(a->arr + i));
    }
}