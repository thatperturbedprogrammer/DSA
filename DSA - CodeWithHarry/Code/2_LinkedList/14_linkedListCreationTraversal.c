// Linked List Traversal - O(n)
// Linked List Insertion & Deletion - O(1)
// NULL = end of LinkedList

#include<stdio.h>
#include<stdlib.h>

// Creation
struct Node{
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

int main()
{
    // Creation
    struct Node * head;
    struct Node * second;
    struct Node * third;

    // Allocate memory for nodes in the Linked List in Heap -  using malloc()
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    // using arrow operator
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;


    // Traversal
    linkedListTraversal(head);

    return 0;
}