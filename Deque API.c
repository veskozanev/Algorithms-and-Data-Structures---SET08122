#include <stdio.h>

#define MAX 10

void enqueue(int *, int, int *, int *);
void dequeueFront(int *, int *, int *);
void dequeueEnd(int *, int *, int *);
int empty(int *);

int main()
{
    int arr[MAX];
    int front = -1, rear = -1;

    enqueue(arr, 23, &front, &rear);
    enqueue(arr, 9, &front, &rear);
    enqueue(arr, 11, &front, &rear);
    enqueue(arr, -10, &front, &rear);
    enqueue(arr, 25, &front, &rear);
    enqueue(arr, 16, &front, &rear);
    enqueue(arr, 17, &front, &rear);
    enqueue(arr, 22, &front, &rear);
    enqueue(arr, 19, &front, &rear);
    enqueue(arr, 30, &front, &rear);
    enqueue(arr, 31, &front, &rear);
    enqueue(arr, 32, &front, &rear);

    for(int n = 0; n<MAX; n++)
    {
        printf("%d, ",arr[n]);
    }

    printf("\n");
    dequeueFront(arr, &front, &rear);
    dequeueFront(arr, &front, &rear);
    dequeueFront(arr, &front, &rear);

    for(int n = 0; n<MAX; n++)
    {
        printf("%d, ",arr[n]);
    }
    printf("\n");
    enqueue(arr, 32, &front, &rear);

    for(int n = 0; n<MAX; n++)
    {
        printf("%d, ",arr[n]);
    }
    printf("\n");
    dequeueEnd(arr, &front, &rear);
    dequeueEnd(arr, &front, &rear);

    for(int n = 0; n<MAX; n++)
    {
        printf("%d, ",arr[n]);
    }
    printf("\n");
    enqueue(arr, 32, &front, &rear);

    for(int n = 0; n<MAX; n++)
    {
        printf("%d, ",arr[n]);
    }
    return 0;
}

void enqueue(int *arr, int item, int *pfront, int *prear)
{
    if(*prear == MAX-1) {
        for (int i = 0; i < MAX - 1; i++)
        {
            arr[i] = arr[i+1];
        }
        arr[*prear] = item;
        printf("Enqueuing: %d\n", item);
    }
    else
    {
        printf("Enqueuing: %d\n", item);
        (*prear)++;
        arr[*prear] = item;

        if(*pfront == -1)
            *pfront = 0;
    }
}

int empty(int *pfront)
{
    if(*pfront == -1)
    {
        printf("Queue is empty\n");
        return 1;
    }
    else
        return 0;
}

void dequeueFront(int *arr, int *pfront, int *prear)
{
    if(!empty(&pfront))
    {
        for (int i = 0; i < MAX; i++)
        {
            arr[i] = arr[i+1];
        }
        (*prear)--;
    }
}

void dequeueEnd(int *arr, int *pfront, int *prear)
{
    if(!empty(&pfront))
    {
        arr[*prear]=0;
        (*prear)--;
    }
}