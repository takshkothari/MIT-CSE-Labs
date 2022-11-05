#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *queue;
    int f, r, cap;
} QUEUE;

void pqinsert(QUEUE *apq, int x)
{
    if (apq->f == -1)
        apq->f = 0;
    apq->r = (apq->r + 1) % apq->cap;
    apq->queue[apq->r] = x;
}

int pqmindelete(QUEUE *apq)
{
    int small = apq->queue[apq->f];
    int index = 0;
    for (int i = apq->f + 1; i <= apq->r; i++)
    {
        if (small > apq->queue[i])
        {
            small = apq->queue[i];
            index = i;
        }
    }
    for (int i = index + 1; i <= apq->r; i++)
        apq->queue[i - 1] = apq->queue[i];
    apq->r--;
    return small;
}

void display(QUEUE *apq)
{
    for (int i = apq->f; i <= apq->r; i++)
        printf("%d ", apq->queue[i]);
    printf("\n");
}

int main()
{
    QUEUE *apq, pq;
    apq = &pq;
    apq->f = -1;
    apq->r = -1;
    printf("enter size of queue: ");
    scanf("%d", &apq->cap);
    apq->queue = (int *)malloc(apq->cap * sizeof(int));
    pqinsert(apq, 2);
    pqinsert(apq, 4);
    pqinsert(apq, 9);
    printf("%d\n", pqmindelete(apq));
    display(apq);
}