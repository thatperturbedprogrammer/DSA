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

// Deletion
int indDeletion(int arr[], int used_size, int capacity, int index)
{
    // index more than used_size
    if(index >= used_size)
    {
        return -1;
    }

    // index se chalu hoega , used_size tak jaega
    for(int i = index; i < used_size-1; i++)
    {
        arr[i] = arr[i+1];
    }

}

int main()
{
    int arr[10] = {1,2,3,4};
    int capacity = 10;
    int used_size = 4;

    display(arr, used_size);

    int index = 3;

    if(indDeletion(arr, used_size, capacity, index) == -1)
    {
        printf("Deletion Failed\n");
    }
    else
    {
        printf("Deletion Successful\n");
        used_size -=1;
        display(arr, used_size);
    }

    return 0;
}