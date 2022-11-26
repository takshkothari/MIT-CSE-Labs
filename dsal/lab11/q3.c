#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char val;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(char x)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->val = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}

double eval(char op, double x, double y)
{
    if (op == '+')
        return x + y;
    if (op == '-')
        return x - y;
    if (op == '*')
        return x * y;
    if (op == '/')
        return x / y;
}

double evaluate(Node *node)
{
    if (node == NULL)
        return 0;
    if (node->right == NULL && node->left == NULL)
        return (double)(node->val - '0');

    double x = evaluate(node->left);
    double y = evaluate(node->right);

    return eval(node->val, x, y);
}

int main()
{
    Node *root = createNode('*');
    root->left = createNode('+');
    root->right = createNode('/');
    root->left->left = createNode('1');
    root->left->right = createNode('6');
    root->right->left = createNode('9');
    root->right->right = createNode('4');

    printf("Ans :  %lf\n", evaluate(root));
}