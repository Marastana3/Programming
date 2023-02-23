#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}node;
node *start = NULL;

//Basic functions for LINKED LISTS:
void create_list(){  //create a linked list
    node *temp, *ptr;
    temp = (node *)malloc(sixeof(node));
    if(temp == NULL){
        printf("ERROR: MALLOC!");
        exit(1);
    }
    printf("Enter the data value for the node:");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if(start == NULL)
        start = temp;
    else{
        ptr = start;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
} 

void display(){ //Displays the elements of the list
    node *ptr;
    if(start == NULL){
        printf("The list is empty!");
        return;
    }
    else{
        ptr = start;
        printf("The list elements are:");
        while(ptr != NULL){
            printf("%d", ptr->info);
            ptr = ptr->next;
        }
    }
}

void delete_pos(){ //Delete element from a given position

    int i, pos;
    node *temp, *ptr;
    if(start == NULL){
        printf("The list is empty!");
        exit(1);
    }
    else{
        printf("Enter pos");
        scanf("%d", &pos);
        if(pos == 0){
            ptr = start;
            start = start->next;
            printf("The deleted element is:%d", ptr->info);
            free(ptr);
        }
        else{
            ptr = start;
            for(i = 0; i < pos; ++i){
                temp = ptr;
                ptr = ptr->next;
                if(ptr = NULL){
                    printf("Pos not found");
                    return;
                }
            }
            temp->next = ptr->next;
            printf("The deleted elem is: %d", ptr->info);
            free(ptr);
        }
    }

}

void insert_pos(){//insert element on position
    node *temp, *ptr;
    int i, pos;
    temp = (node *)malloc(sizeof(node));
    if(temp == NULL){
        printf("error malloc");
        exit(1);
    }
    printf("enter pos to insert:");
    scanf("%d", temp->info);

    temp->next = NULL;
    if(pos == 0){
        temp->next = start;
        start = temp;
    }
    else{
        for(i = 0; i < pos-1; ++i){
            ptr = ptr->next;
            if(ptr == NULL){
                printf("Pos not found");
                return;
            }
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}



int main(void){

    return 0;
}