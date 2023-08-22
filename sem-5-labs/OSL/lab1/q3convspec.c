#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main()
{
    int a = 42;
    float b = 6.9;
    char c = 'x';
    char s[] = "tako";
    
    printf("int = %d\nfloat = %f\nchar = %c\nstring = %s\nhex for int = %x\nexp for float = %e\n", a, b, c, s, a, b);
        
    return 0;
}