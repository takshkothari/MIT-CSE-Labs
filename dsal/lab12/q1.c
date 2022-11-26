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
void insertBST(Node **, int);

Node *createNode(int x)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->val = x;
    new->left = NULL;
    new->right = NULL;
    return new;
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

void insertBST(Node **tree, int x)
{
    Node *iter = (Node *)malloc(sizeof(Node));
    Node *prev = (Node *)malloc(sizeof(Node));
    Node *root = (Node *)malloc(sizeof(Node));
    Node *temp = (Node *)malloc(sizeof(Node));

    temp = createNode(x);
    prev = NULL;
    root = *tree;
    iter = root;
    while (iter != NULL)
    {
        prev = iter;
        if (iter->val > x)
            iter = iter->left;
        else
            iter = iter->right;
    }
    if (prev == NULL)
        *tree = temp;
    else if (x < prev->val)
        if (prev->left != NULL)
        {
            temp->left = prev->left;
            prev->left = temp;
        }
        else
            prev->left = temp;
    else
    {
        if (prev->right != NULL)
        {
            temp->right = prev->right;
            prev->right = temp;
        }
        else
            prev->right = temp;
    }
}
void delAndReplace(Node **tree, int x)
{
    Node *iter = (Node *)malloc(sizeof(Node));
    Node *iter2 = (Node *)malloc(sizeof(Node));
    Node *root = (Node *)malloc(sizeof(Node));

    root = *tree;
    iter = root;
    while (iter->val != x)
    {
        if (iter->val > x)
            iter = iter->left;
        else
            iter = iter->right;
    }
    if ((iter->left != NULL) && (iter->right != NULL))
    {
        iter2 = iter->left;
        while (iter2->right != NULL)
            iter2 = iter2->right;
        iter->val = iter2->val;
    }
}

int main()
{
    int n, i, x;
    Node *tree = (Node *)malloc(sizeof(Node));
    tree = NULL;
    printf("Enter number of elements ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter element ");
        scanf("%d", &x);
        insertBST(&tree, x);
    }
    printf("Inorder traversal: ");
    inOrder(tree);
    printf("\nEnter element to delete ");
    scanf("%d", &x);
    delAndReplace(&tree, x);
    printf("Inorder traversal of new tree: ");
    inOrder(tree);
}