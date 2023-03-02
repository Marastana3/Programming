#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int countBruteForce(int arr[], int n, int V) {
    int count = 0;
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            for (int k = j+1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == V) {
                    count++;
                }
            }
        }
    }
    return count;
}

int countEfficient(int arr[], int n, int V) {
    int count = 0;
    // Sort the array
    qsort(arr, n, sizeof(int), cmpfunc);
    // Use two pointers to find pairs that sum to V-x
    for (int i = 0; i < n-2; i++) {
        int j = i+1;
        int k = n-1;
        while (j < k) {
            if (arr[i] + arr[j] + arr[k] == V) {
                count++;
                j++;
                k--;
            } else if (arr[i] + arr[j] + arr[k] < V) {
                j++;
            } else {
                k--;
            }
        }
    }
    return count;
}

int main() {
    // Read input from file
    FILE *fp;
    int n, V;
    fp = fopen("1Kint_1.txt", "r");
    fscanf(fp, "%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    // Measure time taken by efficient version
    clock_t start_efficient = clock();
    int count_efficient = countEfficient(arr, n, 0);
    clock_t end_efficient = clock();
    double time_efficient = (double)(end_efficient - start_efficient) / CLOCKS_PER_SEC;

    // Measure time taken by brute-force version
    clock_t start_brute_force = clock();
    int count_brute_force = countBruteForce(arr, n, 0);
    clock_t end_brute_force = clock();
    double time_brute_force = (double)(end_brute_force - start_brute_force) / CLOCKS_PER_SEC;

    printf("Efficient count: %d\n", count_efficient);
    printf("Time taken (efficient version): %f seconds\n", time_efficient);

    printf("Brute-force count: %d\n", count_brute_force);
    printf("Time taken (brute-force version): %f seconds\n", time_brute_force);

    return 0;
}
