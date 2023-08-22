#include<stdio.h>
#include<stdlib.h>
#include"functions.h"

void main()
{
    node *ll=NULL;
    int ch, x;
    printf("enter size of linked list\n");
    scanf("%d", &x);
    create(&ll, x);
    printf("Menu\n1. insert start\n2. insert end\n3. delete start\n4. delete end\n5. display\n6. exit\n");
    do{
        printf("enter choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter element to insert: ");
            scanf("%d", &x);
            ll=insertStart(&ll, x);
            break;
        case 2:
            printf("enter element to insert: ");
            scanf("%d", &x);
            insertEnd(ll, x);
            break;
        case 3:
            deleteStart(ll);
            break;
        case 4:
            deleteEnd(ll);
            break;
        case 5:
            display(ll);
            break;
        case 6:
            printf("bye bye\n");
            break;
        }
    }while(ch!=6);
}