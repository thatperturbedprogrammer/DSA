// Cases
/*
Case 1: Insert at the beginning (update head Node)              -  [O(1)]           { newhead->next = head;  head=newhead;  return head }
Case 2: Insert in between                                       -  [O(n)]           { newnode->next = p->next;  p->next = newnode; } where p is used to traverse linked list index-wise (index-wise as in an array)
Case 3: Insert at the end                                       -  [O(n)]           { p->next = newnode;  newnode->next = NULL}  when / if(p->next == NULL)
Case 4: Insert after a Node  (Node {pointer} q is given)        -  [O(1)]           { newnode->next = q->next;  q->next = newnode }
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


// Case 1 - Insert at First
struct Node * insertAtFirst(struct Node *head, int data)
{
    // dynamically allocate in heap, just like in second
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = head;

    // return new head i.e newnode (newnode is first element/node in linked list)
    return newnode;
}


// Case 2 - Insert in Between
struct Node * insertAtIndex(struct Node *head, int data, int index)
{
    // dynamically allocate in heap, just like in second
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;

    // p is a pointer that points to head node, so we can traverse the whole linked list using it
    struct Node *p = head;

    int i = 0;

    // jis index me mujhe ana hai vo minus me aa jao mai
    // p ko vaha khada karna hai
    while(i != index-1)
    {
        p = p->next;
        i++;
    }

    // p->next agla vala Node hai

    // link ko todke jodna
    newnode->next = p->next;
    
    // link jodna
    p->next = newnode;

    return head;
}


// Case 3 - Insert at End
struct Node * insertAtEnd(struct Node *head, int data)
{
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;

    // p is a pointer that points to head node, so we can traverse the whole linked list using it
    struct Node *p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }

    // p now points to new inserted node
    p->next = newnode;

    // newnode is the last node in the linked list
    newnode->next = NULL;

    return head;
}


// Case 4 - Insert after Node
struct Node * insertAfterNode(struct Node *head, struct Node *prevnode, int data)
{
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = data;

    newnode->next = prevnode->next;
    prevnode->next = newnode; 

    return head;
}


int main()
{
    struct Node *head;
    struct Node * second;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = NULL;


    // Insert at First or Insert at Head
    printf("\nBefore:\n");
    linkedListTraversal(head);

    printf("\nAfter:\n");

    // head = newnode   {head points to new node now which is inserted at beginning of linked list}
    head = insertAtFirst(head, 56);
    linkedListTraversal(head);


    // Insert in Between
    printf("\nBefore:\n");
    linkedListTraversal(head);

    printf("\nAfter:\n");

    head = insertAtIndex(head, 3, 3);
    linkedListTraversal(head);


    // Insert at End
    printf("\nBefore:\n");
    linkedListTraversal(head);

    printf("\nAfter:\n");

    head = insertAtEnd(head, 4);
    linkedListTraversal(head);


    // Insert after a Node
    printf("\nBefore:\n");
    linkedListTraversal(head);

    printf("\nAfter:\n");

    head = insertAfterNode(head, second, 22);
    linkedListTraversal(head);

    return 0;
}