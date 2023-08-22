#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *qu;
    int front, rear, capacity;
} queue;

void insertcq(queue *q, int ele)
{
    if ((q->rear + 1) == q->capacity)
    {
        printf("Queue is Full!\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->qu[q->rear] = ele;
}

int deletecq(queue *q)
{
    if (q->front == -1)
    {
        return -1;
    }

    int ele = q->qu[q->front];
    q->front = (q->front + 1) % q->capacity;
    return ele;
}

void displaycq(queue *q)
{
    for (int i = q->front; i < q->rear + 1; i++)
    {
        printf("%d ", q->qu[i]);
    }
}

int find_ele(queue *q, int ele)
{
    for (int i = q->front; i < q->rear + 1; i++)
    {
        if (q->qu[i] == ele)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    queue *q, que;
    q = &que;
    printf("Enter the capacity of queue: ");
    scanf("%d", &q->capacity);
    q->qu = (int *)malloc(q->capacity * sizeof(int));
    q->front = q->rear = -1;
    insertcq(q, 1);
    insertcq(q, 2);
    insertcq(q, 3);
    if (find_ele(q, 2))
        printf("found\n");
    else
        printf("not found\n");
    displaycq(q);
    printf("\ndeleted element: %d", deletecq(q));
}