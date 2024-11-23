/*4. Definitions in strings Write a function that takes a string, prints all definitions of the form name=value from the string, one per line,
and returns their number. name must be an identifier (like in C: starts with letter or underscore, may contain letters, underscore and digits).
value may contain arbitrary non-whitespace. Definitions must be separated by whitespace from other parts of the string.*/

#include<stdio.h>
#include<string.h>

int PrintDef(char* str) {

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '=') {
			unsigned n = strlen(str) - i;
			char buff1[25];
			strncpy(buff1, str, n);
		}
	}

	for (int i = strlen(str) - 1; i = 0; i--) {
		if (str[i] == '=') {
			unsigned m = strlen(str) - i;
			char buff2[25];
			strncpy(buff2, str, m);
		}
	}

	for (int i = ; i < 25; i++)
		printf("%s = %s", buff1[i], buff2[i]);

}

int main(void) {


	return 0;
}
