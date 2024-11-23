#include <stddef.h>
#include <stdio.h>

void display(int x) {
    int size = sizeof(int) * 8;
    for (int i = size; i > 0; --i) {
        printf("%d", (x >> (i - 1)) & 1);
        if (i % 4 == 1) {
            printf( "_");
        }
    }
    printf("%s", "\n");
}

void switch_nibble(char nibble, int *first, int *second) {
    if (nibble > sizeof(int) - 1 || nibble < 0) {
        printf("Provide nibble as 0, 1, 2, 3");
        return;
    }

    int identity = 0xFF << (nibble * 8); // a byte of only 1
    int firstNumberNibble = *first & identity;
    int secondNumberNibble = *second & identity;

    // set corresponding nibble to 0000_0000
    *first = *first & ~identity;
    *second = *second & ~identity;
    // set nibble to the other's nibble
    *first = *first | secondNumberNibble;
    *second = *second | firstNumberNibble;
}

int main() {
    int x = 152, y = 763;
    display(x);
    display(y);
    switch_nibble(0, &x, &y);
    display(x);
    display(y);
    return 0;
}
