// Not adaptive
// Not stable

// Minimum ko 
// select karke aage lao (at first index)

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

void selectionSort(int *A, int used_size)
{
    int indexOfMin;
    int temp = 0;

    for(int i=0; i<used_size-1; i++)
    {
        indexOfMin = i;  // assuming i is the most minimum

        for(int j=i+1; j<used_size; j++)
        {
            if(A[j] < A[indexOfMin])
            {

                // agar element at index j chota hai, to naya indexOfMin = j
                indexOfMin = j;
            }
        }
        // swap that smallest element with i, then repeat
        // swap A[i] with A[indexOfMin]
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}


int main()
{
    int A[] = {3, 5, 2, 13, 12};
    int used_size = sizeof(A)/sizeof(A[0]);

    printArray(A, used_size);
    selectionSort(A, used_size);
    printArray(A, used_size);


    return 0;
}


// DRY RUN
 // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13
