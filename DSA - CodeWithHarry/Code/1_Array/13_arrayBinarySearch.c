// O(logn)
// Sorted Array

#include<stdio.h>
#include<stdlib.h>


int low, high, mid;

// Traversal
void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Binary Search
int binarySearch(int arr[], int used_size, int element)
{

    low=0;
    high=used_size-1;
    mid=(low+high)/2;

    // Search until low and high converge
    while(low<=high)
    {
        if(arr[mid] == element)
        {
            return mid;
        }

        if(element > arr[mid])
        {
            // new low = mid
            low = mid+1;
            mid=(low+high)/2;
        }

        else
        {
            // element < arr[mid];
            // new high = mid
            high = mid-1;
            mid=(low+high)/2;
        }

    }

    return -1;

}

int main()
{
    // Sorted array for Binary Search
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    // int capacity = 20;
    int used_size = sizeof(arr)/sizeof(int);

    display(arr, used_size);

    int element = 6;
    int searchIndex = binarySearch(arr, used_size, element);
    if(searchIndex == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index: %d", searchIndex);
    }

    return 0;
}