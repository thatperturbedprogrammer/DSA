#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;

};

// Is Empty
int isEmpty(struct stack *ptr)
{
    if(ptr->top == -1)
    { 
        return 1;
    }
    else
    {
        return 0;   // 0 means false
    }
}


// Is Full
int isFull(struct stack *ptr)
{
    if(ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // Dynamically bharenge array
    // s.arr = (int *) malloc(s.size * sizeof(int));

    // Using arrow operator
    // Arrow operator - Derefencing karo fir, dot laga ke access karo
    struct stack *s;
    s->size = 5;
    s->top = -1;
    // Dynamically bharenge array
    s->arr = (int *) malloc(s->size * sizeof(int)); 

    // Pushing elements manually
    s->arr[0] = 0;
    s->top++;
    s->arr[1] = 1;
    s->top++;
    s->arr[2] = 2;
    s->top++;
    s->arr[3] = 3;
    s->top++;
    // s->arr[4] = 4;
    // s->top++;

    // Check is stack is empty, full or has space to push elements
    if(isEmpty(s))
    {
        printf("Stack is empty\n");
    }
    else if(isFull(s))
    {
        printf("Stack is Full\n");
    }
    else
    {
        printf("Stack has space to push elements");
    }
    return 0;
}