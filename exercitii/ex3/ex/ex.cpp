#include <stdio.h>

int median(int a, int b, int c);

int main()
{
    int a, b, c, m;
    a = 6;
    b = 5;
    c = 8;

    m = median(a, b, c);
    printf("The median is %d.\n\n",m);
    return 0;
}

int median(int a, int b, int c)
{
    if ((a < b && b < c) || (c < b && b < a))
        return b;
    else if ((b < a && a < c) || (c < a && a < b))
        return a;
    else if ((b < c && c < a) || (a < c && c < b))
        return c;
}