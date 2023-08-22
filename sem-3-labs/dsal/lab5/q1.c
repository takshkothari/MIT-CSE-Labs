#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 5
typedef struct
{
    char arr[STACK_SIZE];
    int tos;
} STACK;

int isEmpty(STACK s)
{
    return s.tos == -1;
}

int isFull(STACK s)
{
    return s.tos == STACK_SIZE;
}

void push(STACK *s, char n)
{
    if (isFull(*s))
    {
        printf("Stack Overlfow, Terminating\n");
        return;
    }
    s->arr[++(s->tos)] = n;
}

char pop(STACK *s)
{
    if (isEmpty(*s))
    {
        printf("Stack Underflow, Terminating\n");
        return 1;
    }
    return s->arr[s->tos--];
}

char peak(STACK s)
{
    return s.arr[s.tos];
}

void display(STACK s)
{
    printf("[ ");
    for (int i = 0; i <= s.tos; i++)
        printf("%c ", s.arr[i]);
    printf("\n");
}

int main()
{

    int input;
    STACK *s;
    while (input != 3)
    {
        printf("Do you want to push, pop or exit? (1/2/3) ");
        scanf("%d", &input);
        char out;
        switch (input)
        {
        case 1:
            printf("Enter the character to push: ");
            char in;
            scanf("%c %c", &in, &in);
            push(s, in);
            display(*s);
            break;
        case 2:
            out = pop(s);
            printf("Popped %c \n", out);
            display(*s);
            break;

        case 3:
            printf("Bye Bye\n");
            break;
        default:
            break;
        }
    }
}