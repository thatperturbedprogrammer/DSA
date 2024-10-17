// Checking if Parenthesis in an Expression are balanced or not

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

// isFull
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

// isEmpty
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
void push(struct stack *ptr, char val)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow, Cannot push %c to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }

}

// Pop
char pop(struct stack *ptr)
{
    ptr->arr[ptr->top--];
}


// Parenthesis matching
int parenthesisMatch(struct stack *sp, char *exp)
{
    for(int i=0; exp[i]!='\0'; i++)
    {
        if(exp[i] == '(')
        {
            push(sp, exp[i]);

        }
        else if(exp[i] == ')')
        {
            if(isEmpty(sp))
            {
                return 0;
            }
            else
            {
                pop(sp);
            }
       
        }
    }

    // check if stack is empty
    if(isEmpty(sp))
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
    struct stack *s;
    s->size = 100;
    s->top = -1;
    s->arr = (char *) malloc(s->size * sizeof(char));

    char * exp= "(8*(9)";

    if(parenthesisMatch(s, exp))
    {
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }
    
    return 0;
}