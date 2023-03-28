#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverseList(struct Node* head) {
    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    // Traverse the list and print the data element of each node
    printf("List elements: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deleteFromPosition(struct Node** headRef, int position) {
    // Check if the list is empty
    if (*headRef == NULL) {
        printf("Error: list is empty\n");
        return;
    }
    
    // If position is 0, delete the first node
    if (position == 0) {
        struct Node* temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
        return;
    }
    
    // Traverse the list until the node before the specified position
    struct Node* current = *headRef;
    for (int i = 0; i < position - 1; i++) {
        if (current->next == NULL) {
            printf("Error: position out of range\n");
            return;
        }
        current = current->next;
    }
    
    // Check if the specified position is valid
    if (current->next == NULL) {
        printf("Error: position out of range\n");
        return;
    }
    
    // Delete the node at the specified position
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

int main() {
    // Test the deleteFromPosition function
    struct Node* head = NULL;
    struct Node* node1 = (struct Node*) malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*) malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*) malloc(sizeof(struct Node));
    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    head = node1;
    traverseList(head);
    deleteFromPosition(&head, 1); // delete node2
    printf("List after deleting node at position 1: ");
    traverseList(head);
    printf("\n");
    return 0;
}
