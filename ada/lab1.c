#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//comparison function used by the qsort to sort the array in ascending order
int cmpfunc(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) {
        return -1;
    } else if (x > y) {
        return 1;
    } else {
        return 0;
    }
}

// Efficient version of CountTripletsSum
int countTripletsSumEfficient(int arr[], int n, int sum) {
    int count = 0;
    qsort(arr, n, sizeof(int), cmpfunc);
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            int tripletSum = arr[i] + arr[left] + arr[right];
            if (tripletSum == sum) {
                count++;
                left++;
                right--;
            } else if (tripletSum < sum) {
                left++;
            } else {
                right--;
            }
        }
    }
    return count;
}

// Brute force version of CountTripletsSum
int countTripletsSumBruteForce(int arr[], int n, int V) {
    int count = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == V) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    FILE *file;
    //file = fopen("10int_1.txt", "r");
    //file = fopen("1Kint_1.txt", "r");
    //file = fopen("2Kint_1.txt", "r");
    //file = fopen("4Kint_1.txt", "r");
    //file = fopen("10Kint_1.txt", "r");
    //file = fopen("15Kint_1.txt", "r");
    file = fopen("30Kint_1.txt", "r");
    //file = fopen("50Kint_1.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(-1);
    }
    int n;
    fscanf(file, "%d", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
    int sum = 0;
    clock_t start, end;
    double cpu_time_used;

    // Measure time for efficient version
    start = clock();
    int countEfficient = countTripletsSumEfficient(arr, n, sum);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Efficient count: %d\n", countEfficient);
    printf("Time taken (efficient): %f seconds\n", cpu_time_used);

    // Measure time for brute-force version
    start = clock();
    int countBruteForce = countTripletsSumBruteForce(arr, n, sum);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Brute force count: %d\n", countBruteForce);
    printf("Time taken (brute force): %f seconds\n", cpu_time_used);

    free(arr);
    return 0;
}
