/*A function that takes an unsigned number and returns a number formed
by the even digits of n*/

#include <stdio.h>

unsigned MakeNumber(unsigned n) {

	if (n == 0) {
		return 0;
	}
	else {
		    n = n / 10;
			return (n % 10) * 10 + MakeNumber(n / 10);
		}
}

int main(void) {

	printf("%d\n", MakeNumber(176));

	return 0;
}