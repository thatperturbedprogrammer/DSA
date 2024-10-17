// previous 
// data
// next

// Doubly Linked List Traversal - O(n)
// Linked List Insertion & Deletion - 
// NULL = start or head of Doubly LinkedList
// NULL = start end of Doubly LinkedList

#include<stdio.h>
#include<stdlib.h>

// Creation
struct Node{
    struct Node *prev;
    int data;
    struct Node * next;  
};

// Traversal
void linkedListTraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;        // now point to next node
    }

}

// Reverse Traversal
void linkedReverseListTraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->prev;        // now point to previous node
    }
}


int main()
{
    // Creation
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;


    // Allocate memory for nodes in the Linked List in Heap -  using malloc()
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    // using arrow operator
    head->prev = NULL;
    head->data = 1;
    head->next = second;

    second->prev = head;
    second->data = 2;
    second->next = third;

    third->prev = second;
    third->data = 3;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 4;
    fourth->next = NULL;
    

    // Traversal
    printf("Doubly Linked List Traversal:\n");
    linkedListTraversal(head);

    printf("\nDoubly Linked List Reverse Traversal:\n");
    linkedReverseListTraversal(fourth);

    return 0;
}