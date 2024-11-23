/*1) Implement the function int isSorted(unsigned t[], unsigned n)which checks if the array 
has the elements in a monotonous order (either increasing or decreasing)returning a logical result;*/

#include<stdio.h>
#define LEN 11

int check(unsigned x, unsigned y) {
    if (x < y) {
        return 1;
      }
    else {
        return 0;
    }
}

int isSorted(unsigned t[]) {

    int ok = 1;
    int order = check(t[0], t[1]);
    for (int i = 0; i < LEN; i++) {
        if (check(t[1], t[i + 1]) != order) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    unsigned t[] = { 1,2,4,6,3 };
    printf("%u\n", isSorted(t));
    return 0;
}

