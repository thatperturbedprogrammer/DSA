// FIFO -
// enqueueF
// enqueueR
// dequeueF
// dequeueR

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
    printf("\nf Queue: ");

    for(int i=q->f+1; i<used_size; i++)
    {
        printf("%d ", q->arr[i]);
    }

    printf("\nr Queue: ");
    for(int j=q->r+1; j<used_size; j++)
    {
        printf("%d ", q->arr[j]);
    }
    printf("\n");
}



// enqueueF
void enqueueF(struct queue *q, int val)
{
    if(q->arr[q->f] == -1)
    {
        printf("Cannot enqueue at front\n");
    }
    else
    {
        q->f++;
        q->arr[q->f] = val;

        printf("Enqueued element at front: %d\n", val);

    }
}

// enqueueR
void enqueueR(struct queue *q, int val)
{
    if(isFull(q))
    {
        printf("The queue is full. Cannot enqueue at front\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;

        printf("Enqueued element at rear: %d\n", val);

    }
}


// dequeueF
int dequeueF(struct queue *q)
{
    int a = -1;
    if(isEmpty(q))
    {
        printf("The queue is empty, Cannot dequeue at front\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
        printf("Dequeued at front: %d\n", a);
    }
    return a;
}

// dequeueR
int dequeueR(struct queue *q)
{
    int a = -1;
    if(q->r == -1)
    {
        printf("The queue is empty. Cannot dequeue at rear\n");
    }
    else
    {
        q->r;
        a = q->arr[q->r];
        printf("Dequeued at rear: %d\n", a);
        q->r--;
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

    // enqueueR
    enqueueR(&q, 1);
    enqueueR(&q, 2);
    enqueueR(&q, 3);
    enqueueR(&q, 4);
    display(&q, 10);
    
    // dequeueF
    dequeueF(&q);
    dequeueF(&q);
    display(&q, 10);

    // enqueueF
    enqueueF(&q, 11);
    enqueueF(&q, 22);
    display(&q, 10);

    // dequeueR
    dequeueR(&q);
    dequeueR(&q);
    dequeueR(&q);
    dequeueR(&q);
    dequeueR(&q);
    dequeueR(&q);
    display(&q, 10);

    return 0;
}