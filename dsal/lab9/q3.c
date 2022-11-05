#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void inputCirc(Node *node, int n)
{
    int i, temp;
    Node *head = (Node *)malloc(sizeof(Node));
    head = node;
    for (i = 0; i < n; i++)
    {
        printf("enter value ");
        scanf("%d", &temp);
        if (i == 0)
        {
            node->val = temp;
            node->next = node;
        }
        else
        {
            insertNode(node, temp);
            node = node->next;
        }
    }
}
void displayCirc(Node *node)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head = node;
    while (node->next != head)
    {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("%d\n", node->val);
}
int isTraversed(Node *node, Node *head)
{
    if (node == head)
        return 1;
    return 0;
}
void merge(Node *l1, Node *l2, Node *mergedList)
{
    Node *l1Head = (Node *)malloc(sizeof(Node));
    Node *l2Head = (Node *)malloc(sizeof(Node));
    Node *mergedListHead = (Node *)malloc(sizeof(Node));
    l1Head = l1;
    l2Head = l2;
    int l1Trav = 0, l2Trav = 0;
    mergedListHead = mergedList;
    int i = 0;
    while (!(l1Trav && l2Trav))
    {
        if (l1Trav && !l2Trav)
        {
            insertNode(mergedList, l2->val);
            mergedList = mergedList->next;
            l2 = l2->next;
            if (isTraversed(l2, l2Head))
                l2Trav = 1;
        }
        else if (l2Trav && !l1Trav)
        {
            insertNode(mergedList, l1->val);
            mergedList = mergedList->next;
            l1 = l1->next;
            if (isTraversed(l1, l1Head))
                l1Trav = 1;
        }
        else
        {
            if (l1->val < l2->val)
            {
                if (i == 0)
                {
                    mergedList->val = l1->val;
                    mergedList->next = mergedList;
                }
                else
                {
                    insertNode(mergedList, l1->val);
                    mergedList = mergedList->next;
                }
                l1 = l1->next;
                if (isTraversed(l1, l1Head))
                    l1Trav = 1;
            }
            else if (l1->val == l2->val)
            {
                if (i == 0)
                {
                    mergedList->val = l1->val;
                    mergedList->next = mergedList;
                }
                else
                {
                    insertNode(mergedList, l1->val);
                    mergedList = mergedList->next;
                }
                l1 = l1->next;
                l2 = l2->next;
                if (isTraversed(l1, l1Head))
                    l1Trav = 1;
                if (isTraversed(l2, l2Head))
                    l2Trav = 1;
            }
            else
            {
                if (i == 0)
                {
                    mergedList->val = l2->val;
                    mergedList->next = mergedList;
                }
                else
                {
                    insertNode(mergedList, l2->val);
                    mergedList = mergedList->next;
                }
                l2 = l2->next;
                if (isTraversed(l2, l2Head))
                    l2Trav = 1;
            }
        }
        i += 1;
    }
}
int main()
{
    int n1, n2;
    printf("enter number of elements in list 1: ");
    scanf("%d", &n1);
    printf("enter number of elements in list 2: ");
    scanf("%d", &n2);
    Node *l1 = (Node *)malloc(sizeof(Node));
    Node *l2 = (Node *)malloc(sizeof(Node));
    Node *mergedList = (Node *)malloc(sizeof(Node));
    printf("enter elements of list 1:\n");
    inputCirc(l1, n1);
    printf("list 1: ");
    displayCirc(l1);
    printf("enter elements of list 2:\n");
    inputCirc(l2, n2);
    printf("list 2: ");
    displayCirc(l2);
    printf("merged list: ");
    merge(l1, l2, mergedList);
    displayCirc(mergedList);
}