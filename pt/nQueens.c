// N Queens-Backtraking
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// the size of the chessboard
#define MAX_SIZE 8
 
// Function to check if two queens threaten each other or not
int isSafe(char mat[][MAX_SIZE], int r, int c)
{
    // return 0 if two queens share the same column
    for (int i = 0; i < r; i++)
    {
        if (mat[i][c] == 'Q') {
            return 0;
        }
    }
 
    // return 0 if two queens share the same `\` diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (mat[i][j] == 'Q') {
            return 0;
        }
    }
 
    // return 0 if two queens share the same `/` diagonal
    for (int i = r, j = c; i >= 0 && j < MAX_SIZE; i--, j++)
    {
        if (mat[i][j] == 'Q') {
            return 0;
        }
    }
 
    return 1;
}
 
void printSolution(char mat[][MAX_SIZE])
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
 
void nQueen(char mat[][MAX_SIZE], int r)
{
    if (r == MAX_SIZE)
    {
        printSolution(mat);
        return;
    }
 
    // place queen at every square in the current row `r`
    for (int i = 0; i < MAX_SIZE; i++)
    {
        // if no two queens threaten each other
        if (isSafe(mat, r, i))
        {
            // place queen on the current square
            mat[r][i] = 'Q';
 
            // recursion for the next row
            nQueen(mat, r + 1);
 
            // backtrack and remove the queen from the current square
            mat[r][i] = '-';
        }
    }
}
 
int main()
{
    char mat[MAX_SIZE][MAX_SIZE];
    memset(mat, '-', sizeof mat);
 
    nQueen(mat, 0);
 
    return 0;
}