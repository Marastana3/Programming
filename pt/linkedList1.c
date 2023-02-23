#include <stdio.h>
#include <stdlib.h>

/*
1. Write a function to construct (and return) a double linked list
that is the reverse of a given original double linked list without
changing the original list provided as parameter.
*/
 
/* a node of the double linked list */
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;   
};
 
/* Function to reverse a double Linked List */
void reverse(struct Node **head_ref)
{
     struct Node *temp = NULL; 
     struct Node *current = *head_ref;
      
     /* swap next and prev for all nodes of
       double linked list */
     while (current !=  NULL)
     {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;             
        current = current->prev;
     }     
      
     if(temp != NULL ){
         *head_ref = temp->prev;
     }
}    
 
 
/* Function to insert a node at the beginning of the double linked list */
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    if (!new_node)
    {
      printf("Couldn't allocate memory!\n");
      exit(-1);
    }
    
    new_node->data  = new_data;
    new_node->prev = NULL;
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);   
 
    /* change prev of head node to new node */
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;   
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
/* Function to print nodes in a given double linked list */
void printList(struct Node *node)
{
    while(node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

void freeList(struct Node* head){
    struct Node* temp;

    while (head != NULL)
    {
      temp = head;
      head = head->next;
      free(temp);
    }
    
}

int main()
{
    //empty list
    struct Node* head = NULL;
  
    push(&head, 1);
    push(&head, 5);
    push(&head, 10);
    push(&head, 15);
  
    printf("\n Original Linked list ");
    printList(head);
  
    /* Reverse double linked list */
    reverse(&head);
  
    printf("\n Reversed Linked list ");
    printList(head);          

    freeList(head);
    return 0;
}