#include<stdio.h>
#include<stdlib.h>

// struct myArray is an ADT - it is itself a DataType (user defined datatype)
struct myArray
{
    int total_size; // kitna size reserve karna hai
    int used_size; // kitna size use karna hai
    
    // pointer
    int *ptr;

};

void createArray(struct myArray *a, int tSize, int uSize)
{
    // dereferencing
    (*a).total_size = tSize;
    (*a).used_size = uSize;

    // taking or requesting memory dynamically from heap
    // This expression dereferences the pointer a and accesses the member variable ptr
    (*a).ptr = (int *) malloc(tSize * sizeof(int));

// The result of malloc is a pointer to the allocated memory block. By casting it to (int *), we explicitly specify that it’s a pointer to an int.
    

    // Using arrow operator
    /*
    a->total_size = tSize;
    a->used_size = uSize;

    // taking memory dynamically from heap
    a->ptr = (int *) malloc(tSize * sizeof(int));

    */

}

void show(struct myArray *a)
{
    for(int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

void setVal(struct myArray *a)
{
    int n;
    for(int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &n);

        (a->ptr)[i] = n;
    }
}
int main()
{

    // making instance of struct myArray
    struct myArray marks;

    // passing address of marks - sirf address ke madat se content update kar sakta hu
    createArray(&marks, 10, 2);

    printf("We are running setVal now\n");
    setVal(&marks);

    printf("We are running show() now\n");
    show(&marks);

    return 0;
}








// * = value at operator
// & = address of operator
// (*) = dereferencing operator


// Dereferencing a pointer means:
// getting the value that is stored in the memory location, pointed to by the pointer.