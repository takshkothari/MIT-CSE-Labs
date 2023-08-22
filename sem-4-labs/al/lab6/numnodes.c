#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node * l;
    struct node * r;
} node;

node* create(int x){
    node *new = (node*)malloc(sizeof(node));
    new->val = x;
    new->l = new->r = NULL;
    return new;
}

int count(node *root){
    if(root == NULL)
        return 0;
    int l = count(root->l);
    int r = count(root->r);

    return 1 + l + r;
}

void main(){
    node* root = create(1);
    root->l = create(2);
    root->r = create(3);
    root->l->l = create(4);
    root->l->r = create(5);
    root->r->l = create(9);
    root->r->r = create(8);
    root->l->l->l = create(6);
    root->l->l->r = create(7);
    printf("total number of nodes is %d\n", count(root));
}