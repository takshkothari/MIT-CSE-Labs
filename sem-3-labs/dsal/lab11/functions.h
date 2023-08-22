#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
} node;

typedef struct node Node;

Node *createNode(int);
void inOrder(Node *);
void postOrder(Node *);
void preOrder(Node *);
void createBT(Node **);

Node *createNode(int x)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->val = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void inOrder(Node *tree)
{
    if (tree != NULL)
    {
        inOrder(tree->left);
        printf("%d ", tree->val);
        inOrder(tree->right);
    }
}

void postOrder(Node *tree)
{
    if (tree != NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        printf("%d ", tree->val);
    }
}

void preOrder(Node *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->val);
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void createBT(Node **tree)
{
    Node *iter = (Node *)malloc(sizeof(Node));
    Node *prev = (Node *)malloc(sizeof(Node));
    Node *root = (Node *)malloc(sizeof(Node));
    iter = NULL;
    int x;
    int inp = 0;
    printf("enter value of root ");
    scanf("%d", &x);
    iter = createNode(x);
    root = iter;
    *tree = iter;
    prev = iter;

    printf("\n1.enter left\n2.enter right\n3.move up\n4.exit");

    do
    {
        printf("\nenter choice ");
        scanf("%d", &inp);
        if (inp == 1)
        {
            printf("enter value to insert ");
            scanf("%d", &x);
            Node *temp = createNode(x);
            prev = iter;
            iter->left = temp;
            iter = iter->left;
            printf("moved left");
        }
        else if (inp == 2)
        {
            printf("enter value to insert ");
            scanf("%d", &x);
            Node *temp = createNode(x);
            prev = iter;
            iter->right = temp;
            iter = iter->right;
            printf("moved right");
        }
        else if (inp == 3)
        {
            if (iter == root)
                printf("already at root");
            else
            {
                iter = prev;
                printf("moved up");
            }
        }
    } while (inp != 4);
}