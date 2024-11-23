/*Implement a function that receives an array together with its capacity and fills the array with all the negative
numbers read from the input until 0 is entered. Fill as many values as possible, without overflowing the array.*/
#include<stdio.h>

int ReturnArray(int arr[], unsigned n) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			arr[i] = arr[i--];
			break;
		}
		printf("%d", arr[i]);

			}
	return 0;
}

int main(void) {

	int arr[] = { -1, -2, -4, -5, -6, -7, -9, -3, -8, -2, -1, -4, -3, -5, 0};
	unsigned n = sizeof(arr) / sizeof(arr[0]);
	ReturnArray(arr, n);

	return 0;
}