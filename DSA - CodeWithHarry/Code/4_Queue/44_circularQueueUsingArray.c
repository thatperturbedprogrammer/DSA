#include<stdio.h>
#include<stdlib.h>

struct circularQueue{
    int size;
    int f;
    int r;
    int *arr;
};

// isEmpty
int isEmpty(struct circularQueue * q)
{
    if(q->f == q->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

// isFull
int isFull(struct circularQueue *q)
{
    if((q->r+1)%q->size == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// Traversal - not working
void display(struct circularQueue * q, int used_size)
{
    printf("circularQueue: ");

    for(int i=1; i<used_size; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}


// enqueue
void enqueue(struct circularQueue *q, int val)
{
    if(isFull(q))
    {
        printf("The circularQueue is full\n");
    }
    else
    {
        // Circular increment
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;

        printf("Enqueued element: %d\n", val);

    }
}

// dequeue
int dequeue(struct circularQueue *q)
{
    int a = -1;
    if(isEmpty(q))
    {
        printf("The circularQueue is empty\n");
    }
    else
    {
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}


int main()
{
    struct circularQueue q;
    q.size = 4;

    // initially q, r = 0
    q.f = 0;
    q.r = 0;
    q.arr = (int *) malloc(q.size * sizeof(int));

    // arr[0] is reserved for empty space
    // Can only add size - 1 elements
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    display(&q, 4);

    printf("DeQueueing element: %d\n", dequeue(&q));
    printf("DeQueueing element: %d\n", dequeue(&q));
    printf("DeQueueing element: %d\n", dequeue(&q));

    // Checking circularQueue isFull & isEmpty

    if(isFull(&q))
    {
        printf("The circularQueue is full\n");
    }

    if(isEmpty(&q))
    {
        printf("The circularQueue is empty\n");
    }

    // display(&q, 5);

    return 0;
}