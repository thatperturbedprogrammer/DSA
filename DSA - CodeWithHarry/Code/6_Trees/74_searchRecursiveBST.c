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

struct Node* searchBST(struct Node* root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }

    // if key is root (i.e. key found), return root
    if(key == root->data)
    {
        return root;
    }

    // if key less than root, Search left subtree
    else if(key < root->data)
    {
        return searchBST(root->left, key);
    }
    // if key more than root, Search right subtree
    else
    {
        return searchBST(root->right, key);
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

    struct Node* n = searchBST(p, 3);
    if(n!=NULL)
    {
        printf("Found: %d", n->data);
    }
    else
    {
        printf("Element not found");

    }
    return 0;
}
