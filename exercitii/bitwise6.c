#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void display(uint32_t n){
    for(int i = 0; i < 32; ++i){
        printf("%d", (n >> i) & 1);
    }
}

uint32_t count_ones(uint32_t n){

    unsigned bit = 0;
    unsigned count = 0;

    for(int i = 0; i < 32; ++i){
        bit = (n >> i) & 1;
        if(bit == 1) count++;
    }

    return count;
}

uint32_t reverse(uint32_t n){

    uint32_t result = 0;
    uint32_t bit = 0;

    for(int i = 0; i < 32; ++i){
        bit = (n >> i) & 1;
        result |= bit << (32 - i - 1);
    }

    return result;
}

bool check_power_of2(uint32_t n){

    if(count_ones(n) == 1)  return true;

    else                    return false;
}

void swap(uint32_t *y, uint32_t *x){

    uint32_t aux = *y;
    *y = *x;
    *x = aux;
}

void swap_odd_even(uint32_t n){

    uint32_t array[32];

    for(int i = 0; i < 32; ++i){
        array[i] = (n >> i) & 1;
    }

    //before
    for(int i = 0; i < 32; ++i){
        printf("%d", array[i]);
    }

    printf("\n");

    for(int i = 0; i < 32; ++i){
        swap(&array[i], &array[i+1]);
        i++;
    }
    //after
    for(int i = 0; i < 32; ++i){
        printf("%d", array[i]);
    }
}

void isolate_right(uint32_t n){

    uint32_t array[32];

    for(int i = 31; i >= 0; --i){
        array[i] = (n >> i) & 1;
    }
    
}



int main(){

    //printf("There are %d ones\n", count_ones(7));
    display(13);
    printf("\n");
    uint32_t reversed = reverse(13);
    display(reversed);
    printf("\n");

    if(check_power_of2(512)) printf("True");
    else                   printf("False");

    printf("\n");
    swap_odd_even(13);

    return 0;
}