#include <stdio.h>

void addTime(unsigned h, unsigned m, unsigned dMin);

int main()
{
    unsigned h, m, dMin;
    
    h = 7;
    m = 40; 
    dMin = 70;

    addTime(h, m, dMin);

    return 0;
    
}

void addTime(unsigned h, unsigned m, unsigned dMin)
{
    unsigned hAdd; 
    m += dMin;
    hAdd = m / 60;
    m = m % 60;
    h = h + hAdd;
    h = h % 24;

    printf("The time is %d : %d", h, m);
}