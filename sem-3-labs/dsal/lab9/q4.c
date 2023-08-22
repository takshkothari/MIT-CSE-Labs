
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void deleteDuplicates(Node **list)
{
    Node *i1 = (Node *)malloc(sizeof(Node));
    Node *i2 = (Node *)malloc(sizeof(Node));
    i1 = *list;
    i2 = *list;
    while (i1->next != NULL)
    {
        int x = i1->val;
        i2 = i1->next;
        while (i2 != NULL)
        {
            if (i2->val != x)
                break;
            else
                i2 = i2->next;
        }
        if (i2 == NULL)
        {
            i1->next = NULL;
            break;
        }
        else if (i2 != i1->next)
            i1->next = i2;
        i1 = i1->next;
    }
}

int main()
{
    int n, x;
    Node *list = (Node *)malloc(sizeof(Node));
    printf("enter length of list ");
    scanf("%d", &n);
    printf("enter input for list:\n");
    input(list, n);
    printf("after removing duplicates: ");
    deleteDuplicates(&list);
    display(list);
}