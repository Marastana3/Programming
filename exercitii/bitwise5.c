#include <stdio.h>
#include <stdint.h>
#include <math.h>

void display(unsigned n){

    for(int i = 0; i < sizeof(unsigned); ++i){
        printf("%d", ((n >> i) & 1));
    }
}

unsigned bit_segments(unsigned n){
    
    unsigned current_bit = -1;
    unsigned segments = 0;

    for(int i = 0; i < sizeof(unsigned); ++i){

        int bit = (n >> i) & 1;

        if(bit != current_bit) {
            segments++;         
            current_bit = bit; 
        }

    }
        
    return segments;
}

int main(){

    printf("There are :%d segments\n", bit_segments(13));
    printf("\n");

    return 0;
}