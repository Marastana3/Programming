#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct passenger{ //the list for passengers
    int index;
    struct passenger *next;
}passenger_t;

typedef struct flight{ //the list for flights
    char name[10];
    struct flight *next;
    struct passenger *first;
}flight_t;

flight_t *head_flight = NULL;


int main(void){

    return 0;
}