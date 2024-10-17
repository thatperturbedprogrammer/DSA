// Worst Case! - O(n^2)
// Already Sorted Elements

// Best Case - O(nlogn)
// Pivot beecho beech (in the middle hoga)


// Ms. Quick Sort Madam
// Mr. Partition PT Teacher

// ------------Recursively calling quickSort function to sort subarrays----------------

// pivot is first element
// i = low
// j = high



// [ 0, 1, 2, 3, 4, 5]
// i = left to right --> i++                             // j = right to left <--
// i++     until A[i] >= pivot                                // j--       until A[j] <= pivot

// i sidhee disha me chalta jaega tab tak               // j ulti disha me chalta jaega tab tak
// jab tak use pivot se bade element na mil jae         // jab tak use pivot se chota ya barabar(equal) element na mil jae

                            // fir i aur j interchange (swap ho jaenge)

                            // This process (loop) will repeat till j<i


// partition function first element ko, array ke, jagah pe laa deta hai

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


// partition function
int partition(int *A, int low, int high)
{
    int pivot = A[low];

    int i = low+1;
    int j = high;

    int temp;

    do{
        while(A[i] <= pivot)
        {
            i++;
        }

        while(A[j] > pivot)
        {
            j--;
        }

        if(i<j)
        {
            // swap
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while(i<j);

     // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void quickSort(int *A, int low, int high)
{
    int partitionIndex;     // Index of pivot after partition

    if(low < high)
    {
        partitionIndex = partition(A, low, high);

        quickSort(A, low, partitionIndex-1);        // sort left subarray
        quickSort(A, partitionIndex+1, high);       // sort right subarray
    }
}

int main()
{
    int A[] = {3, 5, 2, 13, 12};
    int used_size = sizeof(A)/sizeof(A[0]);

    printf("size: %d \n", sizeof(A)/sizeof(A[0]));
    printArray(A, used_size);
    quickSort(A, 0, used_size-1);
    printArray(A, used_size);


    return 0;
}


// ----------------------------------------------------------------------------------------------------------------


// DRY RUN
    // 3, 5, 2, 13, 12, 3, 2, 13, 45
    // 3, 2, 2, 13i, 12, 3j, 5, 13, 45
    // 3, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to partition returns 3