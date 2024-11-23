#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void display(unsigned n){

    for(int i = 31; i >=  0; --i){
        printf("%d", (n >> i) & 1);
    }
}

unsigned reversed_4bits(unsigned n){

    unsigned y = 0;
    unsigned aux = 0;

    for(int i = 0; i < 4; ++i){
        y = (n >> i) & 1;
        aux |= (y << 4 - i - 1);
    }

    return aux;
}


unsigned reverse_nibbles(unsigned n){

    unsigned y = 0;
    unsigned aux = 0;

    for(int i = 0; i < 32; i += 4){
        y = (n >> i) & 0b1111; // 0b1111 -> 15
        aux |= (reversed_4bits(y) << 32 - i - 4);
    }    

    return aux;
}


int main(){

    display(347);
    printf("\n");
    display(reverse_nibbles(347));

    return 0;
}