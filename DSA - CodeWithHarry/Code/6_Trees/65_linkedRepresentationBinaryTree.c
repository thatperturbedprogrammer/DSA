#include<stdio.h>
#include<stdlib.h>


struct Node{
    struct Node * left;
    int data;
    struct Node * right;
};

struct Node * createNode(int data)
{
    struct Node * n;    // Creating a node pointer
    n = (struct Node *) malloc(sizeof(struct Node));    // Allocating memory in the heap
    
    n->data = data;     // Setting the data
    n->left = NULL;     // Setting the left child to NULL
    n->right = NULL;    // Setting the left right to NULL

    return n;   // Finally returing the created node
}


int main()
{

    struct Node *p, *p1, *p2;

    // Constructing the root node - Using Function
    p = createNode(2);

    // Constructing other nodes
    p1 =createNode(4);
    p2 = createNode(1);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;

    return 0;
}