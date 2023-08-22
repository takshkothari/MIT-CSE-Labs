#include <stdio.h>

void copy(char a[], char b[], int c)
{
    b[c] = a[c];
    if (a[c++] == '\0')
        return;
    copy(a, b, c);
}
void main()
{
    char a[20], b[20];
    printf("enter string ");
    scanf("%s", a);
    copy(a, b, 0);
    printf("string is %s\n", a);
    printf("copied string is %s\n", b);
}