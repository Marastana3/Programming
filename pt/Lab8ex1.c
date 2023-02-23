//greedy

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 256

typedef struct object{

    double value;
    double weight;

} OBJECT;

OBJECT arr[MAX_LEN] = {0};

void swap(OBJECT *x, OBJECT *y){
    OBJECT temp = *x;
    *x = *y;
    *y = temp;
}

void sort_array(OBJECT *arr, double n){

    for(int i = 0; i < n - 1; ++i)
        for(int j = i + 1; j < n; ++j){
            if((arr[i].value / arr[i].weight) < (arr[j].value/arr[j].weight))
                swap(&arr[i], &arr[j]);
        }
}

void fill_bag(OBJECT *arr, double capacity, double n){

    double new_value = arr[0].value;
    double quantity = arr[0].weight;
    double rem_capacity = capacity;

    printf("value : %.f - quantity : %.f\n", new_value, quantity);
    rem_capacity = rem_capacity - arr[0].weight;

    for(int i = 1; i < n; ++i){
        if(arr[i].weight > rem_capacity){
            quantity = rem_capacity;
            new_value = (rem_capacity/arr[i].weight)*arr[i].value;
            printf("value : %.f - quantity : %.f\n", new_value, quantity);
        }
        else{
            quantity = arr[i].weight;
            new_value = arr[i].value;
            printf("value : %.f - quantity : %.f\n", new_value, quantity);
        }
        rem_capacity = rem_capacity - arr[i].weight;
    }

}

int main(void) {

    double capacity;
    printf("Please enter the capacity of the bag : ");
    scanf("%lf", &capacity);
    printf("\n");

    double n;
    printf("Please enter the number of available objects : ");
    scanf("%lf", &n);
    printf("\n");

    printf("Enter the value and the weight of the objects :\n");
    for(int i = 0; i < n; ++i){
        printf("%d. ", i+1);
        scanf("%lf %lf", &arr[i].value, &arr[i].weight);
    }

    sort_array(arr, n);
    fill_bag(arr, capacity, n);

    return 0;    
}