#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;

};

int isFull(struct stack *ptr)
{
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
    {
    return 0;
    }

}

int isEmpty(struct stack *ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Push
void push(struct stack *ptr, int val)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow, Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("Pushed %d\n", val);
    }
}


// Peek
// i = position
int peek(struct stack *ptr, int i)
{
    int arrayInd = ptr->top-i+1;
    if((ptr->top-i+1) < 0)
    {
        printf("Not a valid position\n");
        return -1;
    }
    else
    {
        return ptr->arr[arrayInd];
    }
}

int main()
{

    struct stack *sp = (struct stack*) malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;

    sp->arr = (int *) malloc(sp->size * sizeof(int));

    push(sp, 1);
    push(sp, 2);
    push(sp, 3);
    push(sp, 4);
    push(sp, 5);
    // push(sp, 6);

    printf("\n");
    printf("\n");
    
    // Peek - Printing values from the stack
    for(int j=1; j<=sp->size; j++)
    {
        printf("The value at position %d is: %d\n", j, peek(sp, j));
    }

    return 0;
}