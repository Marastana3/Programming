/*2.Implement a function that receives as arguments a string, an array of integers and its capacity, and fills the array 
with all the positions from the string where a digit or a consonant is found, without overflowing the array.Return the 
number of elements copied into the array. Also, provide an adequate main() function.*/
#include<stdio.h>
#include<string.h>

int StringToArray(int arr[], unsigned n) {
	
	char str[] = "abdjgerfilokj245";
	char digits[] = "0123456789";
	char consonant[] = "bcdfghjklmnpqrstvwxyz";
	int poz = 0;
	int j = 0;
	for (int i = 0; i < strlen(str); i++) {
		poz = i;
		if (strcmp(str[i], digits) != NULL || strcmp(str[i], consonant) != NULL) {
			arr[++j] = poz;
		}
	}
	for (j = 0; j < n; j++) {
		printf("%u", arr[j]);
		printf("\n");
	}
	 
}

int main(void) {
	int arr[] ={0};
	unsigned n = sizeof(arr) / sizeof(arr[0]);
	StringToArray(arr, n);

	return 0;
}