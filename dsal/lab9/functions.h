#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

typedef struct node Node;
void insertNode(Node *, int);
void display(Node *);
void input(Node *, int);
void deleteNode(Node **, Node *);

void insertNode(Node *prev, int x)
{
    Node *t = (Node *)malloc(sizeof(Node));
    t->val = x;
    t->next = prev->next;
    prev->next = t;
}

void display(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

void input(Node *node, int n)
{
    int i, temp;
    for (i = 0; i < n; i++)
    {
        printf("\nenter value ");
        scanf("%d", &temp);
        if (i == 0)
        {
            node->val = temp;
            node->next = NULL;
            continue;
        }
        insertNode(node, temp);
        node = node->next;
    }
}

void deleteNode(Node **list, Node *tbd)
{
    if (*list == tbd)
        *list = (*list)->next;
    else
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp = *list;
        while (temp->next != NULL)
        {
            if (temp->next == tbd)
            {
                temp->next = tbd->next;
                break;
            }
            temp = temp->next;
        }
    }
    free(tbd);
}