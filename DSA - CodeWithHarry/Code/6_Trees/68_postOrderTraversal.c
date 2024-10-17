// postOrder _'\'
// postOrder - Left Right Root

// Traversing using Recursion

// postOrder is :
// Bottom-Up approach

#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node * left;
    int data;
    struct Node * right;
};

struct Node* createNode(int data)
{
    struct Node *n;
    n = (struct Node*) malloc(sizeof(struct Node));

    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n; 
}


// postOrder traversal
void postOrder(struct Node* root)
{
    if(root != NULL)     // jab tak root != NULL hai tab tak recursively call hota rhega
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);

    }
}
int main()
{

    struct Node *p, *p1, *p2, *p3, *p4;

    // root node
    p = createNode(4);

    // Constructing other nodes
    p1 =createNode(1);
    p2 = createNode(6);
    p3 = createNode(5);
    p4 = createNode(2);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    // Finally the tree looks like this:
    //        4
    //      /  '\'
    //    1      6
    //   / \      
    //  5   2


    // Calling postOrder
    postOrder(p);

    return 0;
}