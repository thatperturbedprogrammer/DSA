// FIFO

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

// Making Global front and rear Nodes for LinkedList
struct Node * f = NULL;
struct Node * r = NULL;

// Traversal
void linkedListTraversal(struct Node *ptr)
{
    printf("\nPrinting the elements of this Linked List Queue:\n");

    while(ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;        // now point to next node
    }
}


// Enqueue
void enqueue(int val)
{
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n == NULL)
    {
        printf("Queue is Full\n");
    }
    else
    {
        
        printf("Enqueueing: %d\n", val);

        n->data = val;            
        n->next = NULL;
        
        // if Queue is empty, that is f and r both are pointing to NULL
        if(f==NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n; 
            r = n;      // now r is pointing to n
        }
    }

}


// Dequeue
int dequeue()
{
    struct Node * ptr = f;
    if(ptr == NULL)
    {
        printf("Unable to Dequeue, Queue is Empty\n\n");
        return -1;
    }

    printf("Dequeueing: %d\n", f->data);
    f = f->next; 

    int val = ptr->data;
    free(ptr);

    return val;
}


int main()
{
    linkedListTraversal(f);
    dequeue();

    // calling enqueue
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    linkedListTraversal(f);


    // calling dequeue
    dequeue();
    dequeue();
    linkedListTraversal(f);

    return 0;
}