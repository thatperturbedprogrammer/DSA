// inOrder _'\'
// inOrder - Left Root Right

// Traversing using Recursion

// inOrder is :
// Bottom-Up approach

// HARD

// 3 ways to delete
// 1 - Delete leaf Node
// 2 - Delete Node in between
// 3 - Delete root Node


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

// inOrder traversal
void inOrder(struct Node* root)
{
    if(root != NULL)     // jab tak root != NULL hai tab tak recursively call hota rhega
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}


// ---------------------------------------------------------------------------------------------------

// inOrder Predecessor
struct Node *inOrderPredecessor(struct Node *root)
{
    // inOrder Predecessor - left subtree ka right-most child, 
    // bcoz it has to be greater than: left subtree ke root ka left child

    root = root->left;
    while(root->right != NULL)
    {
        root = root->right;
    }
    // return onOrder predecessor/successor
    return root;

}
// delete
struct Node *deleteNode(struct Node *root, int value)
{
    struct Node *iPre;      // declaring inOrder Pre Node

    if(root == NULL)
    {
        return NULL;
    }

    // base condition
    // We have reached leaf node
    if(root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // Go to left subtree
    if(value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }

    // Go to right subtree
    else if(value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }

    // Deletion strategy when the Node is found [inOrder Predecessor & inOrder Successor]
    else
    {
        // inOrder Predecessor
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;        // chaning root->data to predecessor ka data pre->data
        root->left = deleteNode(root->left, iPre->data);        // root left bcoz we replaced root ke left ka data with predecessor ka data

    }
    return root;
}
int main()
{

    struct Node *p, *p1, *p2, *p3, *p4;

    // root node
    p = createNode(5);

    // Constructing other nodes
    p1 =createNode(3);
    p2 = createNode(6);
    p3 = createNode(1);
    p4 = createNode(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    // Finally the tree looks like this:
    //        5
    //      /  '\'
    //    3      6
    //   / \      
    //  1   4

    inOrder(p);

    deleteNode(p, 3);

    printf("\n");
    inOrder(p);

    printf("\n");
    printf("|Data is %d |", p->data);
    inOrder(p);

    return 0;
}
