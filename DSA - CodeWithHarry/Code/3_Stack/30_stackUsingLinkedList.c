#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

// struct Node *top = NULL;     [making top as a global variable] (alternate way for pop)

// isEmpty
int isEmpty(struct Node *top)
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// isFull
int isFull(struct Node *top)
{
    struct Node *p = (struct Node *) malloc(sizeof(struct Node));
    if(p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Push
struct Node * push(struct Node *top, int data)
{
    if(isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n = (struct Node *) malloc(sizeof(struct Node));
        n->data = data;
        n->next = top;
        top = n;
        return top;

    }

}


// Pop
int pop(struct Node **top)   // ** matlab poiner ka poiner (poiner to a pointer)
{
    if(isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    else
    {

        // temp node banao
        struct Node * temp = *top;

        // top ko move karo
        *top = (*top)->next;

        // top ke data ko store karo
        int data = temp->data;

        // temp ko free karo
        free(temp);

        // data ko return karo
        return data;

    }
}

int peek(struct Node *top, int pos)
{
    struct Node * ptr = top;
    for(int i=0; (i<pos-1 && ptr!=NULL); i++)
    {
        // will not go into loop for positon 1 as ptr is already pointing to top(which is position 1)  [position 1 means index 0]
        ptr = ptr->next;
    }

    if(ptr!=NULL)
    {
        return ptr->data;
    }

    else
    {
        return -1;
    }
}


// Stack Top
int stackTop(struct Node *top)
{
    return top->data;
}

// Stack Bottom

int stackBottom(struct Node *top)
{
    struct Node * ptr = top;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }

    return ptr->data;

}

void linkedListTraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *top = NULL;

    // Push
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);    

    printf("Pushed\n");
    linkedListTraversal(top);

    
    // Pop
    int element = pop(&top);  // address bheja to reflect changes to top done in pop()
    printf("Popped: %d\n", element);
    linkedListTraversal(top);

    printf("\n");

    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);
    top = push(top, 6);
    linkedListTraversal(top);

    int peekedElement = peek(top, 1);
    printf("Peeked Element at position 1: %d\n", peekedElement);

    // peeking all elements
    for(int i=1; i<=5; i++)
    {
        printf("Value at position %d is: %d\n", i, peek(top, i));
    }

    printf("Stack Top: %d\n", stackTop(top));
    printf("Stack Bottom: %d\n", stackBottom(top));

    return 0;
}