#include <stdio.h>
#include <stdlib.h>


struct node {
 int key;
 struct node* left;
 struct node* right;
 struct node *p;
};

typedef struct node* Node;

/* Create a new node */
Node newNode(int key) {
 Node node = (Node) malloc(sizeof(struct node));
 node->key = key;
 node->left = NULL;
 node->right = NULL;
 node->p=NULL;
 return(node);
}

/* Insert a new node into a BST */
void insert(Node* root, Node z) {
 Node x,y;
 y=NULL;
 x=*root;
 while (x!=NULL) {
    y=x;
    if (x->key < z->key)
                x=x->right;
    else
                x=x->left;
    }
 z->p=y;
 if (y==NULL) {
        *root=z;
        }
        else {
        if (z->key<=y->key)
            y->left=z;
        else
            y->right=z;
        }

}


void inorder(Node root) {
    if(root != NULL){
        inorder(root->left);
        printf("%d", root->key);
        inorder(root->right);
    }
}

int height(Node root, int h) {
    if(!root){
        return h;
    }
    else{
        int heightLeft = height(root->left, h+1);
        int heightRight = height(root->right, h+1);
    }

    return max(heightLeft, heightRight);

}


int search(Node root, int key) {
    while(root != NULL && key != root->key){
        if(key < root->key)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}


int main()
{
    Node tree=NULL;

    insert(&tree,newNode(7));
    insert(&tree,newNode(15));
    insert(&tree,newNode(3));
    insert(&tree,newNode(10));
    insert(&tree,newNode(5));

    inorder(tree);

    int h= height(tree);

    int found = search(tree, 10);

}