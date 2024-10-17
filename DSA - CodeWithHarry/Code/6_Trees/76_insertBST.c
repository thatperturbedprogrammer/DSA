// inOrder _'\'
// inOrder - Left Root Right

// Traversing using Recursion

// inOrder is :
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

// insert
void insert(struct Node *root, int key)
{
    struct Node *prev = NULL;

    // loop until leaf node is NULL
    while(root != NULL)
    {
        prev = root;
        if(key == root->data)
        {
            printf("Cannot insert %d, already exists in BST", key);
            return;
        }

        else if(key < root->data)
        {
            root = root->left;
        }
        
        else
        {
            root = root->right;
        }

    }

    // Creating a new Node to insert
    struct Node *new = createNode(key);

    // Linking - agar key previous root ke data se chota hai to insert left mein karo, varna right mein karo
    if(key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
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

    insert(p, 7);
    printf("%d ", p->right->right->data);
    return 0;
}
