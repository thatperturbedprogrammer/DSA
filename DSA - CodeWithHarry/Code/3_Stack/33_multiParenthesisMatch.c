// Checking if Parenthesis in an Expression are balanced or not

#include<stdio.h>
#include<stdlib.h>

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


// match - (), {}, []
int match(char a, char b)
{
    if(a=='(' && b==')')
    {
        return 1;
    }
    if(a=='{' && b=='}')
    {
        return 1;
    }
    if(a=='[' && b==']')
    {
        return 1;
    }

    return 0;

}


// Parenthesis matching
int parenthesisMatch(struct stack *sp, char *exp)
{
    for(int i=0; exp[i]!='\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);

        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(isEmpty(sp))
            {
                // opening '(', '{', '[' without closing ')', '}', ']'
                return 0;
            }

            // else pop
            popped_ch = pop(sp);
            if(!(match(popped_ch, exp[i])))
            {
                return 0;
            }
       
        }
    }

    // sab parenthesis checking hone ke baad
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

    char * exp= "[8*(9-1)]{}";

    if(parenthesisMatch(s, exp))
    {
        printf("The parenthesis is balanced");
    }
    else
    {
        printf("The parenthesis is not balanced");
    }
    
    return 0;
}