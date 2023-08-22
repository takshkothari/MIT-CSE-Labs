#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char **queue;
    int f, r, size;
} Queue;

void enqueueF(Queue *pq, char str[])
{
    if (pq->f == -1)
    {
        pq->r = pq->f = 0;
        strcpy(pq->queue[pq->f], str);
    }
    else
    {
        pq->f = (pq->f - 1 + pq->size) % pq->size;
        strcpy(pq->queue[pq->f], str);
    }
}

void enqueueR(Queue *pq, char str[])
{
    if (pq->f == -1)
    {
        pq->f = 0;
    }
    pq->r = (pq->r + 1) % pq->size;
    strcpy(pq->queue[pq->r], str);
}

char *dequeueF(Queue *pq)
{
    if ((pq->f == pq->r) && (pq->r == pq->size - 1))
    {
        return "EMPTY";
    }
    char *str = (char *)malloc((strlen(pq->queue[pq->f]) + 1) * sizeof(char));
    strcpy(str, pq->queue[pq->f]);
    pq->f = (pq->f + 1) % pq->size;
    return str;
}

void display(Queue *pq)
{
    int i = pq->f;
    while (i != pq->r)
    {
        printf("%s ", pq->queue[i]);
        i = (i + 1) % pq->size;
    }
    printf("%s ", pq->queue[pq->r]);
}

int main()
{
    Queue *pq, q;
    pq = &q;
    printf("Enter the size: ");
    scanf("%d", &pq->size);
    pq->f = pq->r = -1;
    pq->queue = (char **)malloc(pq->size * sizeof(char *));
    for (int i = 0; i < pq->size; i++)
        pq->queue[i] = (char *)malloc(20 * sizeof(char));
    enqueueF(pq, "how");
    enqueueF(pq, "what");
    enqueueR(pq, "who");
    enqueueR(pq, "why");
    dequeueF(pq);
    display(pq);
}