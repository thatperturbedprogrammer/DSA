// Checking if Parenthesis in an Expression are balanced or not

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char popped_ch;
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
    return ptr->arr[ptr->top--];
}


// stackTop
char stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}


// isOperator
int isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// precedence
int precedence(char ch)
{
    if(ch == '*' || ch == '/')
    {
        return 3;
    }

    else if(ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }

}


// Infix to Postfix
char * infixToPostfix(struct stack *sp, char *infix)
{
    // empty postfix array
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));

    int i = 0;  // Track infix traversal (infix scanner)
    int j = 0;  // Track postfix append  (postfix fill)

    // until EoE
    while(infix[i] != '\0')
    {
        // if - not operator
        // agar operator nahi hai
        if(!isOperator(infix[i]))
        {
            // append to postfix
            postfix[j] = infix[i];
            j++;
            i++;
        }
        
        // else - operator
        // agar operator hai - toh check precedence
        else
        {
            // check precendence of operator
            // if - precedence more than stack's top element [push]
            if(precedence(infix[i]) > precedence(stackTop(sp)))
            {
                // agar precedence badi hai toh push
                push(sp, infix[i]);
                i++;
            }

            // else - precedence less than equal to stack's top element [pop]
            else
            {
                // agar precedence choti hai toh pop, and append stack's top element to postfix[]
                postfix[j] = pop(sp);
                j++;
            }

        }

    }
    // pop remaining elements in stack, which are arranged in the stack according to their precedence only
    while(!isEmpty(sp))
    {
        // jab tak stack empty nahi hai
        // pop and append to (i.e. fill) postfix[]
        postfix[j] = pop(sp);
        j++;
    }

    // last character of postfix[] should be '/0' to indicate EoE (like in a string)
    postfix[j] = '\0';

    return postfix;
}


int main()
{
    // Creating a character Stack
    struct stack *s;
    s->size = 100;
    s->top = -1;
    s->arr = (char *) malloc(s->size * sizeof(char));

    char * infix = "a-b+t/6";

    printf("Infix is: %s\n", infix);

    printf("Postfix is: %s\n", infixToPostfix(s, infix));

    infix = "x-y/z-k*d";
    
    printf("\nInfix is: %s\n", infix);

    printf("Postfix is: %s\n", infixToPostfix(s, infix));

    return 0;
}