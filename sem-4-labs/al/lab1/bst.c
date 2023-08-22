#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node* lchild;
	int data;
	struct node* rchild;
};

struct node* BST(struct node *p,int key)
{
	struct node* temp;
	if(p==NULL)
	{
		temp=malloc(sizeof(struct node ));
		temp->rchild=temp->lchild=NULL;
		temp->data=key;
		return temp;
	}
	else if(key<p->data)
		p->lchild=BST(p->lchild,key);
	else
		p->rchild=BST(p->rchild,key);
	return p;
}

void inorder(struct node *p)
{
	if(p == NULL)
		return;
	inorder(p->lchild);
	printf("%d \t",p->data);
	inorder(p->rchild);
}

void preorder(struct node *p)
{
	if(p)
	{
		printf("%d \t",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

void postorder(struct node *p)
{
	if(p)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		printf("%d \t",p->data);
	}
}

int main()
{
	int n, i, x;
	struct node *root = NULL;
	printf("enter number of elements ");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		printf("enter element ");
		scanf("%d", &x);
		root=BST(root, x);
	}
	printf("inorder:\n");
	inorder(root);
	printf("\npreorder:\n");
	preorder(root);
	printf("\npostorder:\n");
	postorder(root);
	return 0;
}