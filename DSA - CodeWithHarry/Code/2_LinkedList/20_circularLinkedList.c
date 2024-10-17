#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;

};

void linkedListTraversal(struct Node  *head)
{
    struct Node *ptr = head;
    do{
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
}


// Case 1 - Insert at First
struct Node * insertAtFirst(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    // p for traversing to the end of linked list
    struct Node * p = head->next;
    
    while(p->next != head)
    {
        p = p->next;
    }

    // At this point p points to the last node of this Circular Linked List
    
    p->next = ptr;
    ptr->next = head;
    head = ptr;     // head points to new inserted node now

    return head;
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = head;

    linkedListTraversal(head);


    // Case 1 - Insert at First
    printf("\nBefore:\n"); 
    linkedListTraversal(head);

    head = insertAtFirst(head, 0);

    printf("\nAfter:\n");
    linkedListTraversal(head);

    return 0;
}