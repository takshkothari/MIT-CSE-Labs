#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int *queue;
    int f, r, size;
} Queue;

void enqueue(Queue *pq, int ele)
{
    if (pq->r == pq->size - 1)
        printf("queue full\n");
    else
    {
        if (pq->f == -1)
            pq->f = 0;
        pq->r = (pq->r + 1) % pq->size;
        pq->queue[pq->r] = ele;
    }
}

int dequeue(Queue *pq)
{
    int ele;
    if (pq->f == -1)
        return 0;
    else
    {
        ele = pq->queue[pq->f];
        pq->f = (pq->f + 1) % pq->size;
        return ele;
    }
}

void display(Queue *pq)
{
    for (int i = pq->f; i < pq->r + 1; i++)
        printf("%d ", pq->queue[i]);
}

void reverse(Queue *pq)
{
    int temp;
    int end = pq->r + 1;
    int start = pq->f;
    for (int i = start; i < end / 2; i++)
    {
        temp = dequeue(pq);
        pq->queue[i] = pq->queue[end - i - 1];
        pq->queue[end - i - 1] = temp;
    }
    pq->f = start;
}

int main()
{
    Queue *pq, q;
    pq = &q;
    pq->f = pq->r = -1;
    printf("enter size:\n");
    scanf("%d", &pq->size);
    pq->queue = (int *)malloc(pq->size * sizeof(int));
    enqueue(pq, 2);
    enqueue(pq, 4);
    enqueue(pq, 6);
    display(pq);
    printf("\n");
    reverse(pq);
    display(pq);
    return 0;
}