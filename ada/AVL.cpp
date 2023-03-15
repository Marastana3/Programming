#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// AVL tree node
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

// Function to get the height of a node
int height(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

// Function to get the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to create a new node with a given key
struct node *newNode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially added at leaf
    return node;
}

// Function to right rotate subtree rooted with y
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Function to left rotate subtree rooted with x
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get the balance factor of a node
int getBalance(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return height(n->left) - height(n->right);
}

// Recursive function to insert a key in the subtree rooted with node and returns the new root of the subtree
struct node *insert(struct node *node, int key)
{
    // Perform the normal BST insertion
    if (node == NULL)
    {
        return (newNode(key));
    }

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    { // Equal keys are not allowed in BST
        return node;
    }

    // Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases
    // Left Left Case
    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // return the (unchanged) node pointer
    return node;
}

// Function to print the peorder traversal of the AVL tree
void preorder(struct node *root){
    if(root != NULL){
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
         
    }
}

int main(void)
{   
    //clock_t start, end;
    //double cpu_time_used;
    struct node *root = NULL;

     root = insert(root, 3);
     root = insert(root, 6);
     root = insert(root, 18);
     root = insert(root, 2);
     root = insert(root, 1);
     root = insert(root, 13);
     root = insert(root, 16);
     root = insert(root, 4);

    preorder(root);
    printf("\n");
/*
    // Seed the random number generator with the current time
    srand(time(NULL));

    //start timer
    start = clock();
    // Insert 1000000 random keys between 1 and 1000000
    for (int i = 0; i < 1000000; ++i) {
        int key = rand() % 1000000 + 1;
        root = insert(root, key);
    }
    end = clock();
    int height1 = height(root);

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time used for Insertion of 1000000 random keys for constructed AVL tree is: %f seconds, and height is : %d\n", cpu_time_used, height1);

    // Insert 1000000 increasing keys between 1 and 1000000
    start = clock();
    for (int i = 0; i < 1000000; ++i) {
        int key = i;
        root = insert(root, key);
    }
    end = clock();
    int height2 = height(root);

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time used for Insertion of 1000000 increasing keys for constructed AVL tree is: %f seconds and height is: %d\n", cpu_time_used, height2);
   */

    return 0;
}
