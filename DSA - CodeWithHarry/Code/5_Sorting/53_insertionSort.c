// key me save karo
// shift karo
// key ko insert karo


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

// insertion sort
// sorted 
// array | unsorted array
// 12    | 54   65   7   30   9   {eg: 1st pass}

void insertionSort(int *A, int used_size)
{
    // key is A[i]
    int key;

    // j , is i ke pehle ka index
    int j;

    // Loop for passes
    for(int i=1; i<=used_size-1; i++)
    {
        key = A[i];

        j = i-1;        // i ke pehle ka(previous) element

        // Loop for each pass

        // kya A[j] bada hai key se     [for Ascending order]
        // i.e A[j=i-1] > A[i]?             - agar hai to shift kardo aage
        while(j>=0 && A[j] > key)
        {
            // swap
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;   // key ki value jo stored ki thi use apne sahi jagah pe dal dia
    }
}


int main()
{
    // -1  0    1    2    3   4    5
    //     12   54   65   7   30   9
    int A[] = {12, 54, 65, 7, 30, 9};
    int used_size = sizeof(A)/sizeof(A[0]);

    printArray(A, used_size);   //Before sorting

    insertionSort(A, used_size);     // calling insertion sort

    printArray(A, used_size);   // After sorting


    return 0;
}


// -------------------------------------------------------------------------------------------------


// DRY RUN

 // -1   0    1   2   3   4   5
   //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
   //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

   //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
   //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

   //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
   //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
   //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
   //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
   //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

   // Fast forwarding and 4th and 5th pass will give:
   //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
   //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

   //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
   //      07, 09, 12, 23, 54, 65| --> After the 5th pass 
// 
