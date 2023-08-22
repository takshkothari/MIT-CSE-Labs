#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *l;
    struct node *r;
} node;

node* create(int x) {
    node *new = (node*) malloc(sizeof(node));
    new->val = x;
    new->l = new->r = NULL;
    return new;
}

int dia(node *r, int *h) {
    if (r == NULL)
        return 0; 
    int lh = 0, rh = 0;
    int ld = dia(r->l, &lh);
    int rd = dia(r->r, &rh);
    *h = ((lh > rh)? lh : rh) + 1;
    int t = (ld > rd)? ld : rd;
    if((lh + rh + 1)>t)
        return (lh + rh + 1);
    else
        return t;
}

void main(){
    ;
}
