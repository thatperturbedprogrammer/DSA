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

// Insertion
int indInsertion(int arr[], int used_size, int capacity, int index, int element)
{
    // array is full
    if(used_size >= capacity)
    {
        return -1;
    }

    // used_size(end) se chalu hoega , index tak jaega
    for(int i = used_size-1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }

    arr[index] = element;

}

int main()
{
    int arr[10] = {1,2,3,4};
    int capacity = 10;
    int used_size = 4;

    display(arr, used_size);

    int element = 45;       // element to insert
    int index = 3;          // index to insert at

    if(indInsertion(arr, used_size, capacity, index, element) == -1)
    {
        printf("Insertion Failed\n");
    }
    else
    {
        printf("Insertion Successful\n");
        used_size +=1;
        display(arr, used_size);
    }

    return 0;
}