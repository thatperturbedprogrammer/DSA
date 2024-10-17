// Intermediate Result - Sabse Bhaari (Biggest) element at the end
// n(n+1)/2

// O(n^2)

#include<stdio.h>
#include<stdlib.h>

void printArray(int *A, int used_size)
{
    for(int i=0; i<used_size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}


// adaptive bubbleSort 
void bubbleSortAdaptive(int *A, int used_size)
{
    int isSorted = 0;
    for(int i=0; i<used_size-1; i++)    // For number of passes
    {

        isSorted = 1;   // assuming Array is already sorted in first pass
        
        printf("Working on pass no. %d\n", i+1);
        for(int j=0; j<used_size-1-i; j++)  // For comparison in each pass
        {
            // swap
            if(A[j] > A[j+1])
            {
                int temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
                isSorted = 0;   // agar is if ke andar enter hua to array already sorted nhi hai
            }
        }

        if(isSorted)
        {
            return;
        }

    }
    
}

// bubble sort
void bubbleSort(int *A, int used_size)
{
    for(int i=0; i<used_size-1; i++)    // For number of passes
    {
        printf("Working on pass no. %d\n", i+1);
        for(int j=0; j<used_size-1-i; j++)  // For comparison in each pass
        {
            // swap
            if(A[j] > A[j+1])   // A[j] bada hai uske agle vale se toh usko aage bhejo{bubble up}
            {
                int temp = A[j+1];
                A[j+1] = A[j];
                A[j] = temp;
            }
        }

    }
    
}


int main()
{
    int A[] = {12, 222, 34, 54};
    int used_size = sizeof(A)/sizeof(A[0]);         // sizeof(whole Array / sizeof(1st element of Array)

    // printf("array size: %d\n\n\n", sizeof(A)/sizeof(A[0]));
    printArray(A, used_size);   // Before sorting

    bubbleSortAdaptive(A, used_size);   // calling bubbleSort

    printArray(A, used_size);   // After sorting

    return 0;
}