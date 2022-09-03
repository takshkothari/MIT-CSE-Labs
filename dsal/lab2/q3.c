#include <stdio.h>
#include <stdlib.h>
void inp(int *a, int l)
{
    printf("enter values:\n");
    for (int i = 0; i < l; i++)
        scanf("%d", &a[i]);
}

void printarr(int *a, int l)
{
    printf("the array is:\n");
    int *p = a;
    for (int i = 0; i < l; i++)
        printf("\t%d", *(p + i));
}

void *smallest(int *a, int l)
{
    int *tr = a, *s = a;
    for (int i = 0; i < l; i++)
    {
        if ((*s) > *(tr + 1))
        {
            tr++;
            s = tr;
            continue;
        }
        tr++;
    }
    return s;
}
void main()
{
    int *a, l;
    printf("enter size of array\n");
    scanf("%d", &l);
    a = (int *)malloc(l * sizeof(int));
    inp(a, l);
    printarr(a, l);
    int *small = smallest(a, l);
    int **psml;
    psml = &small;
    printf("the smallest element is: %d", *(small));
    printf("the smallest element using pointer to pointer is: %d", **psml);
}