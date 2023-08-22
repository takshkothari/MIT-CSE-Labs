#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
    struct node *prev;
} node;

node* create(node **, int);
node* insertStart(node *, int);
void insertEnd(node* , int);
void deleteStart(node *);
void deleteEnd(node *);
void display(node *);

node* create(node **head,int n){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->next=NULL;
    temp->prev=NULL;
    *head=temp;
    printf("enter elements\n");
    for(int i=0;i<n-1;i++){
        scanf("%d",&temp->val);
        temp->next=(node*)malloc(sizeof(node));
        temp->next->prev=temp;
        temp=temp->next;
        temp->next=NULL;
    }
    scanf("%d",&temp->val);
    printf("\n");
    return *head;
}
node* insertStart(node* front, int x){
    node *temp = front;
    node *newnode = (node *)malloc(sizeof(node));
    newnode->val=x;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(front == NULL){
        front = newnode;
        return front;
    }
    if(front->next == NULL){
        newnode->next=front;
        front->prev=newnode;
        front=newnode;
        return front;
    }
    while(temp->next!=NULL){
        if(temp->next == NULL){
            newnode->next=temp->next;
            temp->next->prev=newnode;
            temp->next=newnode;
            newnode->prev=temp;
            return front;
        }
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    return front;
}
void insertEnd(node* front, int x){
    node *newNode = (node*) malloc(sizeof(node));
    node *temp = front;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
    printf("%d inserted\n", x);
}
void deleteStart(node *front){
    node *temp;
    if(front == NULL){
        printf("underflow\n");
        return;
    }
    else if(front->next = NULL){
        printf("%d deleted\n", front->val);
        front = NULL;
        free(front);        
    }
    else{
        printf("%d deleted\n", front->val);
        temp = front;
        front = front->next;
        front->prev = NULL;
        free(temp);
    }
}
void deleteEnd(node *front){
    node *temp;
    if(front == NULL){
        printf("underflow\n");
        return;
    }
    else if(front->next = NULL){
        printf("%d deleted\n", front->val);
        front = NULL;
        free(front);        
    }
    else{
        temp = front;
        if(temp->next != NULL)
            temp = temp->next;
        printf("%d deleted\n", temp->val);
        temp->prev->next = NULL;
        free(temp);
    }
}
void display(node *front){
    node *temp = front;
    printf("Linked list:\n");
    while (temp != NULL){
        printf("%d\t", temp->val);
        temp = temp->next;
    }
    printf("\n");
}