#include <stdio.h>

void compare(int a, int b, int c);

int main()
{
    int a, b, c;
    scanf_s("%i %i %i", &a, &b, &c);
    compare(a, b, c);
    return 0;
}

void compare(int a, int b, int c)
{
    if (a != b && a != c && b != c)
        printf("All arguments are distinct");
    else if (a == b && a != c && b != c)
        printf("Arguments 1 and 2 are equal");
    else if (a == b && a == c && b == c)
        printf("All arguments are equal");
    else if (a != b && a == c && b != c)
        printf("Arguments 1 and 3 are equal");
    else if (a != b && a != c && b == c)
        printf("Arguments 2 and 3 are equal");
}
