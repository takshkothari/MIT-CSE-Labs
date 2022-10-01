#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *a;
    int tos;
} stack;

stack push(stack s, int x)
{
    s.tos++;
    s.a[s.tos] = x;
    return s;
}

stack delete (stack s, int ind)
{
    int i;
    for (i = ind; i < s.tos; i++)
        s.a[i] = s.a[i + 1];
    s.tos--;
    return s;
}

int main()
{
    stack s;
    int n, k;
    printf("Enter number of elements ");
    scanf("%d", &n);
    s.a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter element no. %d ", (i + 1));
        scanf("%d", &s.a[i]);
    }
    s.tos = n - 1;
    printf("Enter the number of elements that must be deleted ");
    scanf("%d", &k);
    while (k > 0)
    {
        for (int i = 0; i <= s.tos - 1; i++)
        {
            if (s.a[i] < s.a[i + 1])
            {
                s = delete (s, i);
                k--;
                break;
            }
        }
    }
    printf("The final array is:\n");
    for (int i = 0; i <= s.tos; i++)
        printf("%d ", s.a[i]);
    return 0;
}