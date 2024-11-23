/*2. Ints in string Write a function that prints out all numbers (strings of digits with optional sign) from 
a string given as parameter. Consider only standalone numbers, i.e. numbers that do not have any non-
whitespace characters adjacent to them.*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

void PrintNumbers(char* str) {

	for (int i = 0; i < strlen(str); i++) {
		if (isdigit(str[i])) {
			printf("%c", str[i]);
		}
	 }
}
int main(void) {

	char str[] = "ana are 14 mere si 12 pere";
	PrintNumbers(str);

	return 0;
}