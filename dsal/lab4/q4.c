#include <stdio.h>

int tower(int n, char source, char dest, char aux)
{
    static int c = 0;
    if (n == 1)
    {
        printf("\nmove disk 1 from peg %c to peg %c", source, dest);
        c++;
    }
    else
    {
        tower(n - 1, source, aux, dest);
        printf("\nmove disk %d from peg %c to peg %c", n, source, dest);
        c++;
        tower(n - 1, aux, dest, source);
    }
    return c;
}

void main()
{
    int n;
    printf("enter number of discs: ");
    scanf("%d", &n);
    printf("moves are: \n");
    int x = tower(n, 'A', 'B', 'C');
    printf("\nnumber of moves = %d\n", x);
}
