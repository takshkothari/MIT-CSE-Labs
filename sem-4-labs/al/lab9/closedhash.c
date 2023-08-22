#include <stdio.h>
#include<stdlib.h>

int h[10]={NULL};

void insert() {
    int key, index, i, flag=0, hkey;
    printf("enter value to insert: \n");
    scanf("%d", &key);
    hkey = key % 10;
    for(i = 0 ; i < 10 ; i++) {
        index = (hkey + i) % 10;
        if(h[index] == NULL) {
            h[index] = key;
            break;
        }
    }
    if(i == 10)
        printf("cannot be inserted\n");
}

void search() {
    int key, index, i, flag=0, hkey;
    printf("enter key: \n");
    scanf("%d", &key);
    hkey = key % 10;
    for(i = 0 ; i < 10 ; i++) {
        index = (hkey + i) % 10;
        if(h[index] == key) {
            printf("value found at index %d\n", index);
            break;
        }
    }
    if(i == 10)
        printf("value not found\n");
}
void display() {
    int i;
    printf("elements in hash table: ");
    for(i = 0 ; i < 10 ; i++)
        printf("\nat index %d  value =  %d",i,h[i]);
}

int main()
{
    int opt, i;
    while(1) {
        printf("menu\n1. insert\n2. display\n3. search\n4. exit\nenter choice");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4: 
                exit(0);
        }
    }
    return 0;
}