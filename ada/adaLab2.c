
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
Node lowestCommonAncestor(Node root, int key1, int key2) {
    if (root == NULL)
        return NULL;
    if (root->key == key1 || root->key == key2)
        return;
    Node left = lowestCommonAncestor(root->left, key1, key2);
    Node right = lowestCommonAncestor(root->right, key1, key2);
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
//return abs(left_count - right_count) <= 1 && IsPerfectlyBalanced(root->left) && IsPerfectlyBalanced(root->right);

/*Helper function to print the paths with sum, the printing mainly happens here,
the PrintPathsWithSum function is used only for calling the helper one
 It recursively traverses the tree, adding each node's value to path and checking if
any prefixes of path sum to sum. If so, then we print the corresponding path. We then
recursively traverse the left and right subtrees of the current node,
 incrementing pathLength as we go.*/
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