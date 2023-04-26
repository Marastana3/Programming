#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int field[MAX_ROWS][MAX_COLS];
bool visited[MAX_ROWS][MAX_COLS];

void explore(int row, int col, int prev_height, int start_row, int start_col, int num_rows, int num_cols) {
    if (row < 0 || row >= num_rows || col < 0 || col >= num_cols) {
        // We've gone off the edge of the field, print the path
        printf("Path from (%d, %d) to edge: (%d, %d)", start_row, start_col, prev_height, row, col);
        return;
    }

    if (visited[row][col] || field[row][col] <= prev_height) {
        // We've already visited this cell or it's not a valid move, backtrack
        return;
    }

    visited[row][col] = true;

    // Explore all adjacent cells
    explore(row + 1, col, field[row][col], start_row, start_col, num_rows, num_cols);
    explore(row - 1, col, field[row][col], start_row, start_col, num_rows, num_cols);
    explore(row, col + 1, field[row][col], start_row, start_col, num_rows, num_cols);
    explore(row, col - 1, field[row][col], start_row, start_col, num_rows, num_cols);

    visited[row][col] = false;
}

int main() {
    int num_rows, num_cols, start_row, start_col;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &num_rows, &num_cols);

    printf("Enter the matrix: ");
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            scanf("%d", &field[i][j]);
            visited[i][j] = false;
        }
    }

    printf("Enter starting position: ");
    scanf("%d %d", &start_row, &start_col);

    // Start exploring from the starting position
    explore(start_row, start_col, -1, start_row, start_col, num_rows, num_cols);

    return 0;
}
