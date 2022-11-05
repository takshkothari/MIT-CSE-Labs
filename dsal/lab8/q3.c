#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *queue;
    int f, r, size;
} Queue;
void enqueueF(Queue *pq, char ch)
{
    if (pq->f == -1)
    {
        pq->r = pq->f = 0;
        pq->queue[pq->f] = ch;
    }
    else
    {
        pq->f = (pq->f - 1 + pq->size) % pq->size;
        pq->queue[pq->f] = ch;
    }
}
void enqueueR(Queue *pq, char ch)
{
    if (pq->f == -1)
        pq->f = 0;
    pq->r = (pq->r + 1) % pq->size;
    pq->queue[pq->r] = ch;
}
char dequeueF(Queue *pq)
{
    char ch;
    ch = pq->queue[pq->f];
    if (pq->f == pq->r)
        pq->f = pq->r = -1;
    else
        pq->f = (pq->f + 1) % pq->size;
    return ch;
}
char dequeueR(Queue *pq)
{
    char ch;
    ch = pq->queue[pq->r];
    if (pq->r == pq->f)
        pq->r = pq->f = -1;
    else
        pq->r = (pq->r - 1 + pq->size) % pq->size;
    return ch;
}
void display(Queue *pq)
{
    int i = pq->f;
    while (i != pq->r)
    {
        printf("%c ", pq->queue[i]);
        i = (i + 1) % pq->size;
    }
    printf("%c ", pq->queue[pq->r]);
}
int checkPalin(Queue *pq)
{
    if (pq->f == -1)
        return 1;
    if (dequeueF(pq) == dequeueR(pq))
        checkPalin(pq);
    else
        return 0;
    return 1;
}
int main()
{
    Queue *pq, q;
    pq = &q;
    char temp[20];
    printf("Enter the string: ");
    scanf("%s", temp);
    pq->size = strlen(temp);
    pq->f = pq->r = -1;
    pq->queue = (char *)malloc(pq->size * sizeof(char));
    for (int i = 0; temp[i] != '\0'; i++)
        enqueueR(pq, temp[i]);
    if (checkPalin(pq))
        printf("palindrome");
    else
        printf("not palindrome");
}