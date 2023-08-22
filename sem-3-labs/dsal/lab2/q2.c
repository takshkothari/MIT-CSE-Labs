#include <stdio.h>
#include <stdlib.h>
int Smallest(int *arr, int l)
{
    int s = *arr;
    for (int i = 1; i < l; i++)
    {
        if (*(arr + i) < s)
            s = *(arr + i);
    }
    return s;
}
void main()
{
    int l;
    printf("enter length of array ");
    scanf("%d", &l);
    int *arr = (int *)malloc(l * sizeof(int));
    printf("enter numbers\n");
    for (int i = 0; i < l; i++)
        scanf("%d", &arr[i]);
    int s = Smallest(arr, l);
    printf("the smallest number is: %d", s);
}