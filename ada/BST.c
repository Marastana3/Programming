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

/* Postorder function, traverses the binary search tree as follows:
   the subtrees from LEFT --> subtrees from RIGHT --> ROOT  */
void postorder(Node root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
         printf("%d", root->key);
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
    return abs(left_count - right_count) <= 1 && IsPerfectlyBalanced(root->left) && IsPerfectlyBalanced(root->right);
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

/*CheckExistTwoNodesWithSum: function to check if there are 2 nodes whose 
sum is equal with s
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


Helper function to find the lowest common ancestor
Node *lowestCommonAncestor(Node root, int key1, int key2) {
    if (root == NULL)
        return NULL;
    if (root->key == key1 || root->key == key2)
        return;
    Node *left = lowestCommonAncestor(root->left, key1, key2);
    Node *right = lowestCommonAncestor(root->right, key1, key2);
    if (left != NULL && right != NULL)
        return root;
    return (left != NULL) ? left : right;
}

Helper function that prints the path
void PrintPath(Node root, Node node) {
    if (root == NULL || node == NULL) {
        return;
    }
    if (root->value == node->key) {
        printf("%d ", root->key);
        return;
    }
    if (node->value < root->key) {
        printf("%d ", root->key);
        PrintPath(root->left, node);
    } else {
        printf("%d ", root->key);
        PrintPath(root->right, node);
    }
}

Helper function to print the paths with sum, the printing mainly happens here,
the PrintPathsWithSum function is used only for calling the helper one
 It recursively traverses the tree, adding each node's value to path and checking if
any prefixes of path sum to sum. If so, then we print the corresponding path. We then
recursively traverse the left and right subtrees of the current node,
 incrementing pathLength as we go.
void PrintPathWithSumHelper(Node root, int* path, int pathLength, int sum) {
    if (root == NULL) {
        return;
    }
    path[pathLength] = root->key;
    int i, currentSum = 0;
    for (i = pathLength; i >= 0; i--) {
        currentSum += path[i];
        if (currentSum == sum) {
            int j;
            for (j = i; j <= pathLength; j++) {
                printf("%d ", path[j]);
            }
            printf("\n");
        }
    }
    PrintPathWithSumHelper(root->left, path, pathLength + 1, sum);
    PrintPathWithSumHelper(root->right, path, pathLength + 1, sum);
}

void PrintPathFromTo(Node node1, Node node2) {
    Node root = NULL;
    Node ancestor = lowestCommonAncestor(root, node1, node2);
    if (ancestor == NULL) {
        printf("Error: node1 and node2 are not in the same BST\n");
        return;
    }
    PrintPath(root, node1);
    PrintPath(ancestor, node2);
}

void PrintPathsWithSum(Node root, int s) {
    int path[1000];  // assume paths are at most 1000 nodes long
    PrintPathWithSumHelper(root, path, 0, s);
}

 We use a queue to hold the nodes to be processed. We initially add the root node
 to the queue and then process nodes in the queue until it is empty. For each node 
 in the queue, we print out its value and then add its children to the queue (if 
 they exist). We then move on to the next node in the queue until all nodes at 
 the current level have been processed. At this point, we print a newline 
 character to indicate the end of the current level.
void PrintLevels(Node root) {
    if (root == NULL) {
        return;
    }
    // create a queue to hold the nodes to be processed
    Node** queue = (Node**)malloc(sizeof(Node*) * 1000);
    int front = 0, rear = 0;
    queue[rear++] = root;
    // process nodes in the queue
    while (front < rear) {
        int count = rear - front;
        // process all nodes at the current level
        while (count > 0) {
            Node node = queue[front++];
            printf("%d ", node->key);
            // add the node's children to the queue
            if (node->left != NULL) {
                queue[rear++] = node->left;
            }
            if (node->right != NULL) {
                queue[rear++] = node->right;
            }
            count--;
        }
        printf("\n");
    }
    free(queue);
}*/

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

    printf("The post-order is: ");
    postorder(tree);
    printf("\n");

    int h= height(tree);

    int found = search(tree, 10);

    int success = successor(tree, 3);

    printf("height: %d, found: %d, success: %d\n", h, found, success);



   /*Node lca = lowestCommonAncestor(tree, tree->left, tree->right);
    printf("Lowest common ancestor of %d and %d: %d\n", tree->left->key, tree->right->key, lca->key);


    printf("Paths with sum 8:\n");
    PrintPathsWithSum(tree, 8);

    printf("Levels:\n");
    PrintLevels(tree);
    */


}