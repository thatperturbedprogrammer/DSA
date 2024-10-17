// Cases
/*
Case 1: Delete the First Node (update head Node)                        -  [O(1)]           { ptr = head;  head = head->next;  free(ptr); }
Case 2: Delete a Node in between                                        -  [O(n)]           { *p = head; *q = head->next; for(i = 0; i < index-1; i++){p = p->next; q = q->next;} p->next = q->next; free(q); } where p & q is used to traverse linked list index-wise (index-wise as in an array)
Case 3: Delete the Last Node                                            -  [O(n)]           { *p = head; *q = head->next; while(q->next !- NULL){p = p->next; q = q->next;} p->next = NULL; free(q); } where p & q is used to traverse linked list index-wise (index-wise as in an array)
Case 4: Delete a Node with a given value  (Node data (value) is given)  -  [O(1)]           { *p = head; *q = head->next; while(q->data != value && q->next != NULL){p = p->next; q = q->next;} if(q->data == value){p->next = q->next; free(q);} }
*/



#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}


// Case 1 - Delete the First Node
struct Node * deleteAtFirst(struct Node * head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}


// Case 2 - Delete a Node in between when index given
struct Node * deleteAtIndex(struct Node *head, int index)
{
    // dynamically allocate in heap, just like in second
    struct Node *p = head;
    struct Node *q = head->next;

    for(int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return head;
}


// // Case 3 - Delete the Last Node
struct Node * deleteAtEnd(struct Node *head)
{
    // dynamically allocate in heap, just like in second
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);            // just for freeing we need q to point to last node, which is to be freed

    return head;
}


// Case 4 - Delete a Node with given value
struct Node * deleteGivenValue(struct Node *head, int value)
{
    // dynamically allocate in heap, just like in second
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    // checking if data exists in the linked list to delete it
    if(q->data == value)
    {
        p->next = q->next;    // p pehle q ko point kar rha tha, ab vo use point karega jise q point kar rha tha (before deleting q, we need address of next node which is stored in q)
        free(q);
    }

    return head;
}


int main()
{
    struct Node *head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;


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
    
    fourth->data = 2;
    fourth->next = NULL;


    // Case 1
    // Delete the First Node
    printf("\nBefore:\n");
    linkedListTraversal(head);

    printf("\nAfter:\n");

    // head = newnode   {head points to new node now which is inserted at beginning of linked list}
    head = deleteAtFirst(head);
    linkedListTraversal(head);


    // Case 2
    // Delete a Node in between when index given
    printf("\nBefore:\n");
    linkedListTraversal(head);

    printf("\nAfter:\n");

    head = deleteAtIndex(head, 1);
    linkedListTraversal(head);


    // Case 3
    // Delete the Last Noe
    printf("\nBefore:\n");
    linkedListTraversal(head);

    printf("\nAfter:\n");

    head = deleteAtEnd(head);
    linkedListTraversal(head);


    // Case 4
    // Delete a Node with given value
    printf("\nBefore:\n");
    linkedListTraversal(head);

    printf("\nAfter:\n");

    head = deleteGivenValue(head, 22);
    linkedListTraversal(head);

    return 0;
}