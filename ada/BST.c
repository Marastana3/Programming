#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node{
 int key;
 struct node* left;
 struct node* right;
 struct node *p;
};

typedef struct node* Node;

/* Create a new node */
Node newNode(int key){
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

/* Inorder function, prints the binary search tree as follows: 
   ROOT --> LEFT --> RIGHT*/
void inorder(Node root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

/* Preorder function, traverses the binary search tree as follows:
   ROOT --> the subtrees from LEFT --> subtrees from RIGHT */
void preorder(Node root){
    if(root != NULL){
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
         
    }
}

/*The height of a BST is represented by the longest path from ROOT --> LEAF NODE*/
int height(Node root){
    if(root == NULL)
        return 0;
    else{

        int heightLeft = height(root->left);
        int heightRight = height(root->right);

        if (heightLeft > heightRight)
            return (heightLeft + 1);
        else
            return (heightRight + 1);
    }
}

/* Returns the node containing the key or NULL if the key is not present*/
int search(Node root, int key){
    while(root != NULL && key != root->key){
        if(key < root->key)
            root = root->left;
        else
            root = root->right;
    }
    return root->key;
}

/*Helper function (find minimum) for the successor function*/
int treeMinimum(Node root){
    while(root->left != NULL){
        root = root->left;
    }
    return root->key;
}

/*Returns the node containing the sucessor of node or NULL if there is no 
successor of node*/
int successor(Node root, int key){
    Node y;
    if(root->right != NULL){
        return treeMinimum(root->right);
   }
   y = root->p;
   while(y != NULL && root == y->right){
        root = y;
        y = y->p;
   }
   return y->key;
}

/*Helper function for the IsPerfectlyBalanced function*/
int countNodes(Node root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

/*IsPerfectlyBalanced returns true if BST is perfectly balanced*/
bool IsPerfectlyBalanced(Node root) {
    if (root == NULL) {
        return true;
    }
    int left_count = countNodes(root->left);
    int right_count = countNodes(root->right);
    if(left_count - right_count == 0)
        return true;
    else return false;
}

/*SearchClosest function that finds the node containing the key 
with the value closest to k*/
Node SearchClosest(Node root, int k) {
    Node closest = root;
    while (root != NULL) {
        if (abs(root->key - k) < abs(closest->key - k)) {
            closest = root;
        }
        if (root->key == k) {
            return root;
        }
        else if (root->key < k) {
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return closest;
}

//do not work!! :(
/*The last 3 functions*/

bool CheckExistTwoNodesWithSum(Node root, int s) {
    int arr[1000];
    int len = 0;
    bool flag = false;

    void Inorder(Node root) {
        if (root == NULL) {
            return;
        }
        Inorder(root->left);
        arr[len++] = root->key;
        Inorder(root->right);
    }
    Inorder(root);
    int i = 0;
    int j = len - 1;
    while (i < j) {
        if (arr[i] + arr[j] == s) {
            flag = true;
            break;
        }
        else if (arr[i] + arr[j] < s) {
            i++;
        }
        else {
            j--;
        }
    }
    return flag;
}

int main(void){
    Node tree=NULL;

    insert(&tree,newNode(8));
    insert(&tree,newNode(15));
    insert(&tree,newNode(2));
    insert(&tree,newNode(5));
    insert(&tree,newNode(4));
    insert(&tree,newNode(10));
    insert(&tree,newNode(3));
    insert(&tree,newNode(1));
    insert(&tree,newNode(20));
    insert(&tree,newNode(18));
    insert(&tree,newNode(7));
    insert(&tree,newNode(22));

    printf("The order is: ");
    inorder(tree);
    printf("\n");

    printf("The pre-order is: ");
    preorder(tree);
    printf("\n");

    int h= height(tree);

    int found = search(tree, 10);

    int success = successor(tree, 4);

    printf("height: %d, found: %d, success: %d\n", h, found, success);

    if(IsPerfectlyBalanced(tree))
        printf("The tree is perfectly balanced\n");
    else printf("The tree is not perfectly balanced!\n");

    int k = 16;
    Node closest = SearchClosest(tree, k);
    printf("The closest value to %d is : %d\n", k, closest->key);

    if(CheckExistTwoNodesWithSum(tree, 12))
        printf("TRUE\n");
    else printf("FALSE\n");

    return 0;

}