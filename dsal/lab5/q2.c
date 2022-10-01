#include <stdio.h>

typedef struct
{
    int a[100];
    int tos;
} stack;

stack push(stack s, int x)
{
    s.tos++;
    s.a[s.tos] = x;
    return s;
}

long convert(stack s)
{
    long n = 0;
    for (int i = s.tos; i >= 0; i--)
        n = n * 10 + s.a[i];
    return n;
}

void convertDec(stack s, int str[100])
{
    int i;
    for (i = 0; i <= s.tos; i++)
        str[i] = s.a[i];
}

int main()
{
    stack s;
    s.tos = -1;
    int n, i;
    double num, dn;
    printf("Enter a decimal number ");
    scanf("%lf", &num);
    n = (int)num;
    while (n > 0)
    {
        s = push(s, (n % 2));
        n = n / 2;
    }
    stack s2;
    s2.tos = -1;
    dn = num - (int)num;

    if (dn != 0)
    {
        while (dn != 1)
        {
            dn = dn * 2;
            s2 = push(s2, (int)dn);
        }
    }

    long bin;
    bin = convert(s);
    int binDec[100];
    convertDec(s2, binDec);

    printf("The number in binary is: %ld.", bin);
    for (i = 0; i <= s2.tos; i++)
        printf("%d", binDec[i]);
    return 0;
}