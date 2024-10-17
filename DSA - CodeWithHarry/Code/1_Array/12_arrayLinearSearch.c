// O(n)
// Unsorted Array

#include<stdio.h>
#include<stdlib.h>


// Traversal
void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

// Linear Search
int linearSearch(int arr[], int used_size, int element)
{

    // index se chalu hoega , used_size tak jaega
    for(int i = 0; i < used_size; i++)
    {
        if(arr[i] == element)
        {
            return i;
        }

    }

    // after checking every element in array, if still not found
    return -1;

}

int main()
{
    // Unsorted array for Linear Search
    int arr[20] = {1,2,3,4,51,6,12,7,28,39};
    int capacity = 20;
    int used_size = 10;

    display(arr, used_size);

    int element = 12;
    int searchIndex = linearSearch(arr, used_size, element);
    if(searchIndex == -1)
    {
        printf("Element not found\n");
    }

    else
    {
       printf("Element found at index: %d\n", searchIndex);
    }

    return 0;
}