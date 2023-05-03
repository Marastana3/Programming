#include <stdio.h>
#include <stdbool.h>

#define N 4 

// Returns true if a knows b, false otherwise
bool knows(int a, int b) {
    
   int matrix[N][N] = {
    {0, 1, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0}
};
    return matrix[a][b];
}

// Returns the id of the celebrity if there is one, -1 otherwise
int findCelebrity() {
    for (int i = 0; i < N; ++i) {
        bool isCelebrity = true;
        for (int j = 0; j < N; ++j) {
            // If i knows j or j doesn't know i, i can't be a celebrity
            if (i != j && (knows(i, j) || !knows(j, i))) {
                isCelebrity = false;
                break;
            }
        }
        if (isCelebrity) {
            return i;
        }
    }
    return -1;
}

int main() {
    int celebrity = findCelebrity();
    if (celebrity == -1) {
        printf("There is no celebrity.\n");
    } else {
        printf("The celebrity is person number %d.\n", celebrity);
    }
    return 0;
}
