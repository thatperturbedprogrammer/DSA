// inOrder _'\'
// inOrder - Left Root Right

// Traversing using Recursion

// inOrder is :
// Bottom-Up approach

// HARD
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

// Check BST
int isBST(struct Node* root)
{
    // static variable ki value alag alag calls ke lie different nahi hogi
    static struct Node * prev = NULL;      // root
    if(root!=NULL)
    {
        // Checking if left subtree is Binary Search Tree
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev != NULL && root->data <= prev->data)
        {
            // kyuki root data bada hona chahie previous data se
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
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


    // Calling inOrder
    // inOrder(p);

    printf("%d ", isBST(p));


    return 0;
}





/*
Comment explaining BST
I was watched this video at least 8 times but it's worth . now i clearly understood this isBST function

First we clearing that 
1) 1 3 4 5 6 is ascending of tree
2) Prev is NULL for root->data 1, prev is 1 for root 3 ,prev is 3 for root  4 and so on.
3) return 1 means true 
4) return 0 means false
Note: draw tree and dry run

if isBST function return 1 ( true) means it is binary search tree and if isBST return 0 (False) means it is not BST

Now,  if(! isBST(root->left)){return 0} this function pushing us to the left on the tree and if(! isBST(root->left)) is execute and return 0 only if isBST return 0.

That set i thing am explained all functions except recursion

*/