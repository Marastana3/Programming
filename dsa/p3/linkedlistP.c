#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    char name[20];
    struct student *next;
}student_t;

typedef struct zoom{
    int ID;
    char passw[];
    struct zoom *next;
    struct student *first;
}zoom_t;

zoom_t *headRef = NULL;

void addZoom(zoom_t **headRef, zoom_t *node){
    if((*headRef) == NULL){
        *headRef = node;
        return;
    }

    zoom_t *temp = *headRef;

    while(temp->next == NULL){
        temp = temp->next;
    }
    temp = temp->next;
}

int main(void){

}