#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct passenger {
    int index;
    struct passenger *next;
} passenger_t;

typedef struct flight {
    char name[10];
    struct flight *next;
    struct passenger *first;
} flight_t;

flight_t *head_flight = NULL;

void add_flight_list(flight_t **head_flight, flight_t *node) {
    if((*head_flight)==NULL) {
        (*head_flight) = node;
        return;
    }

    flight_t *temp;
    temp = (*head_flight);

    while(temp->next!=NULL) 
        temp = temp->next;
    
    temp->next = node;
}

void add_passenger_list(passenger_t **root, passenger_t *node) {
    if((*root)==NULL || node->index<(*root)->index) {
        node->next = (*root);
        (*root) = node;
        return;
    }

    passenger_t *temp;
    temp = (*root);

    while(temp->next!=NULL && temp->next->index<node->index)
        temp = temp->next;
    
    node->next = temp->next;
    temp->next = node;
}

void delete(passenger_t **root, passenger_t *node) {
    if(node == (*root)) {
        (*root) = (*root)->next;
        free(node);
        return;
    }

    passenger_t *temp;
    temp = (*root);

    while(temp->next!=node)
        temp = temp->next;

    temp->next = temp->next->next;
    free(node);
}

void removePassenger(flight_t *head_flight, int index) {
    flight_t *temp;
    temp = head_flight;

    while(temp) {
        passenger_t *aux;
        aux = temp->first;

        while(aux) {
            if(aux->index == index) {
                passenger_t *to_delete;
                to_delete = aux;
                aux = aux->next;
                delete(&temp->first, to_delete);
            }
            else
                aux = aux->next;
        }

        temp = temp->next;
    }
}

void print_list(flight_t *head_flight) {
    flight_t *temp;
    temp = head_flight;

    while(temp) {
        printf("%s ", temp->name);
        printf("Passengers: ");
        passenger_t *aux;
        aux = temp->first;
        while(aux) {
            printf("%d ", aux->index);
            aux = aux->next;
        }
        printf("\n");
        temp = temp->next;
    }
}

int main() {
    FILE *f = fopen("flights_doc.txt", "r");
    if(!f) {
        printf("error at opening file");
        exit(1);
    }

    int no_flights;
    fscanf(f,"%d", &no_flights);

    for(int i=1;i<=no_flights;i++) {
        flight_t *node;
        node = (flight_t*) malloc(sizeof(flight_t));
        if(node==NULL) {
            printf("error at malloc");
            exit(1);
        }

        fscanf(f,"%s",node->name);
        node->first = NULL;
        node->next = NULL;

        add_flight_list(&head_flight, node);
    }

    int no_passengers;
    flight_t *fl;
    fl = head_flight;
    for(int i=1;i<=no_flights;i++) {
        fscanf(f,"%d", &no_passengers);

        for(int j=1;j<=no_passengers;j++) {
            passenger_t *node;
            node = (passenger_t*) malloc(sizeof(passenger_t));
            if(node==NULL) {
                printf("error at malloc");
                exit(1);
            }

            fscanf(f,"%d",&node->index);
            node->next = NULL;

            add_passenger_list(&(fl->first), node);
        }

        fl = fl->next;
    }

    print_list(head_flight);

    int delete_index;
    fscanf(f,"%d", &delete_index);
    printf("%d\n", delete_index);

    removePassenger(head_flight, delete_index);

    print_list(head_flight);

    return 0;
}