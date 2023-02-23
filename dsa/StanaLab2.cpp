#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N_MAX 18

typedef struct {
	int age;
	int year;
}DATA ;

void print_array(DATA* arr) {

	for(int i = 0; i < N_MAX; ++i)
		printf("Age : %d , Year: %d\n", arr[i].age, arr[i].year);
}

//randomly generates the elements of the array.
void generate_array(DATA* arr) {
	
	int r1 = rand() % 100;
	int r2 = rand() % 1000;

	for (int i = 0; i < N_MAX; ++i) {

		arr[i].age = i * 100 + r1;
		arr[i].year = i * 100 + r2;
	}

}

// x is the element we want to search.
void interpolation_search(DATA* arr, int x) {

	long mid1, left1, right1, left2, right2, mid2;
	left1 = left2 = 0;
	right1 = right2 = N_MAX - 1;
	bool found = false;

//searches the element by the "age" criteria;
	do {
		mid1 = left1 + ((x - arr[left1].age) * (right1 - left1)) / (arr[right1].age - arr[left1].age);
		if(x > arr[mid1].age) left1 = mid1 + 1;
		else right1 = mid1 - 1;
	}
	while((left1 <= right1) && (arr[mid1].age != x) && (arr[right1].age != arr[left1].age) && (x >= arr[left1].age) && (x <= arr[right1].age) && (found == false));
	
	if(arr[mid1].age == x){
		found = true;
		printf("The element %d was found on position %ld .\n", x, mid1);
	}
	//if the elements is not found, it is searched by the "year" criteria;
	else{
		do {
		mid2 = left2 + ((x - arr[left2].year) * (right2 - left2)) / (arr[right2].year - arr[left2].year);
		if(x > arr[mid2].year) left2 = mid2 + 1;
		else right2 = mid2 - 1;
	}
	while((left2 <= right2) && (arr[mid2].year != x) && (arr[right2].year != arr[left2].year) && (x >= arr[left2].year) && (x <= arr[right2].year) && (found == false));
	
	if(arr[mid2].year == x){
		found = true;
		printf("The element %d was found on position %ld .\n", x, mid1);
	}
	//if the elements is not found by now, it means it is not present in our array.
	else printf("The element was not found.\n");
	}
}

int main(void) {

	int x = 1783;

	DATA* arr;
	arr = (DATA*)malloc(N_MAX * sizeof(int));

	if (arr == NULL) {
		free(arr);
		exit(1);
	}
	generate_array(arr);
	print_array(arr);
	interpolation_search(arr, x);
	free(arr);
	return 0;
}
