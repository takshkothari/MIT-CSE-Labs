#include <stdio.h>

int fibo(int n, int *opc)
{
    (*opc)++;
    if (n == 0 || n == 1)
        return n;
    else
        return (fibo(n - 1, opc) + fibo(n - 2, opc));
}
void main()
{
    int n, opc = 0;
    printf("enter n: ");
    scanf("%d", &n);
    printf("fibo no. is %d", fibo(n-1, &opc));
    printf("\nopcount is %d",opc);
}