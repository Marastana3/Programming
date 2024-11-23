#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void display(uint16_t x){

    for(int i = 15; i >= 0; --i){
        printf("%d", (x >> i) & 1);
    }
}

uint16_t number(uint32_t x){

    uint16_t aux = 0;
    uint16_t y = 0;

    for(int i = 0; i < 32; ++i){
        if(i % 2 == 0){
           y =  (x >> i) & 1;
           aux |= y >> (i / 2);
        }
    }

    return aux;

}

uint16_t reverse(uint16_t x){

    uint16_t aux = 0;
    uint16_t y = 0;

    for(int i = 0; i < 16; ++i){
        y = (x >> i) & 1;
        aux |= (y << 16 - i - 1);
    }
    return aux;
}

int main(){
    uint16_t numb;
    numb =  number(13);
    display(numb);
    printf("\n");
    display(reverse(numb));
    return 0;
}