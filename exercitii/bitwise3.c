#include <stdio.h>
#include <stdint.h>

void find_bits(uint16_t a, uint64_t b) {

    unsigned index = 0; 

    for (int i = 63; i >= 0; --i) {
       
        uint64_t bit_b = (b >> i) & 1;

        uint16_t bit_a = (a >> (15 - index)) & 1;

        if (bit_b == bit_a) {
            index++;
        }

        if (index == 16) {
            printf("Ordered bits from a are in b\n");
            return;
        }
    }

    printf("NO\n");
}

int main() {
    uint16_t a = 0xAB12;        
    uint64_t b = 0xAB32DFF1278; 

    find_bits(a, b);

    return 0;
}

