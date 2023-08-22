#include <stdio.h>
#include <string.h>

void check(char word[], int i)
{
    int l = strlen(word) - (i + 1);
    if (word[i] == word[l])
    {
        if (i + 1 == l || i == l)
        {
            printf("palindrome\n");
            return;
        }
        check(word, i + 1);
    }
    else
        printf("not a palindrome\n");
}
void main()
{
    char word[20];
    printf("enter word ");
    scanf("%s", word);
    check(word, 0);
}