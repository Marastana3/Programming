#include <stdio.h>
#include <stdint.h>

void display(uint32_t a){
    for(int i = 0; i < 32; ++i){
        printf("%d", (a >> i) & 1);
    }
}

void swap_nibbles(uint32_t *a, uint32_t *b){

    uint32_t result1 = 0;
    uint32_t result2 = 0;

    uint32_t nibble1 = 0;
    uint32_t nibble2 = 0;

    for(int i = 0; i < 32; i +=4){

        nibble1 = (*a >> i) & 0b1111;
        nibble2 = (*b >> i) & 0b1111;

        result1 |= nibble2 << i;
        result2 |= nibble1 << i;
    }

    *a = result1;
    *b = result2;
}

int main(){

    uint32_t a = 0x12345678; 
    uint32_t b = 0xABCDEF12;

    printf("Before nibbles swap:\n");
    display(a);
    printf("\n");
    display(b);
    printf("\n");
    swap_nibbles(&a, &b);
    printf("After nibbles swap:\n");
    display(a);
    printf("\n");
    display(b);

    return 0;
}