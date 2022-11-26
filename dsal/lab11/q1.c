#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    Node *tree = (Node *)malloc(sizeof(Node));
    createBT(&tree);
    printf("Inorder:\n");
    inOrder(tree);
    printf("\nPre Order:\n");
    preOrder(tree);
    printf("\nPost Order:\n");
    postOrder(tree);
    printf("\n");
}