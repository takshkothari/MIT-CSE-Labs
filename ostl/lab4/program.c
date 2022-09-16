#include "stack.h"

void main()
{
    printf("Enter the size of the array: ");
    int n;
    scanf("%d", &n);

    STACK st;
    st.top = n;
    st.arr = (int *)calloc(n, sizeof(int));
    printf("Enter an array of %d elements: ", n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", (st.arr + i));
    }

    push(&st, 10);
    printf("Stack after pushing\n");
    display(&st);
    printf("\n");

    printf("Element popped : %d\n", pop(&st));

    printf("Stack after popping\n");
    display(&st);
    printf("\n");
}