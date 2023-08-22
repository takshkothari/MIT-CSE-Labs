#include <stdio.h>
#include "maths1.h"
void main()
{
    int x, y;
    printf("enter 2 numbers: ");
    scanf("%d %d", &x, &y);
    int z = add(x, y);
    printf(" %d\n", z);
    z = sub(y, x);
    printf(" %d\n", z);
}