

#include <stdio.h>

unsigned swapLMD(unsigned nr){

    unsigned a, b, c;
    a = nr / 100;
    b = (nr / 10) % 10;
    c = nr % 10;
    nr = c * 100 + b * 10 + a;

    return nr;
}

int main(){

    unsigned nr = 123;
    unsigned n = swapLMD(nr);
    printf("The result of swapping the most significant digit with the least significant one of the number %d is %d", nr, n);
    return 0;
}

