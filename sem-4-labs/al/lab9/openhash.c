#include<stdio.h>
#include<stdlib.h>


struct node {
  int data;
  struct node *next;
};
struct node *chain[10];

void init(){
    int i;
    for(i = 0; i < 10; i++)
        chain[i] = NULL;
}

void insert(int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    int key = value % 10;
    if(chain[key] == NULL)
        chain[key] = newNode;
    else {
        struct node *temp = chain[key];
        while(temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}
void print() {
    int i;  
    for(i = 0; i < 10; i++) {
        struct node *temp = chain[i];
        printf("chain[%d]->",i);
        while(temp) {
            printf("%d ->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main() {
    init();
    insert(7);
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);
    print();
    return 0;
}