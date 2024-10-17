// FIFO

#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

// isEmpty
int isEmpty(struct queue * q)
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
int isFull(struct queue *q)
{
    if(q->r == q->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// Traversal - not working
void display(struct queue * q, int used_size)
{
    printf("Queue: ");

    for(int i=0; i<used_size; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}


// enqueue
void enqueue(struct queue *q, int val)
{
    if(isFull(q))
    {
        printf("The queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;

        printf("Enqueued element: %d\n", val);

    }
}

// dequeue
int dequeue(struct queue *q)
{
    int a = -1;
    if(isEmpty(q))
    {
        printf("The queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
int main()
{
    struct queue q;
    q.size = 100;

    // initially q, r = -1
    q.f = -1;
    q.r = -1;
    q.arr = (int *) malloc(q.size * sizeof(int));

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
        
    display(&q, 5);

    printf("Dequeueing element: %d\n", dequeue(&q));
    printf("Dequeueing element: %d\n", dequeue(&q));
    printf("Dequeueing element: %d\n", dequeue(&q));
    printf("Dequeueing element: %d\n", dequeue(&q));
    printf("Dequeueing element: %d\n", dequeue(&q));


    // Checking Queue isFull & isEmpty

    if(isFull(&q))
    {
        printf("The queue is full\n");
    }

    if(isEmpty(&q))
    {
        printf("The queue is empty\n");
    }

    // display(&q, 5);

    return 0;
}