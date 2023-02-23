//Rat in a Maze - Backtracking
#include <stdio.h>

#define MAX_SIZE 4

void printSolution(int sol[MAX_SIZE][MAX_SIZE]){
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}

// A function to check if x, y is valid
int isValid(int maze[MAX_SIZE][MAX_SIZE], int x, int y){
	if (x >= 0 && x < MAX_SIZE && y >= 0 && y < MAX_SIZE && maze[x][y] == 1)
		return 1;
	return 0;
}

// A recursive function to solve Maze problem
int solveRecursive(int maze[MAX_SIZE][MAX_SIZE], int x, int y, int sol[MAX_SIZE][MAX_SIZE]){
	if (x == MAX_SIZE - 1 && y == MAX_SIZE - 1 && maze[x][y] == 1) {
		sol[x][y] = 1;
		return 1;
	}
	// Check if maze[x][y] is valid
	if (isValid(maze, x, y) == 1) {
		// Check if the current block is already part of solution path
		if (sol[x][y] == 1)
			return 0;
		// mark x, y as part of solution path
		sol[x][y] = 1;
		//Move forward in x direction
		if (solveRecursive(maze, x + 1, y, sol) == 1)
			return 1;
		// If moving in x direction doesn't give solution
		// then Move down in y direction
		if (solveRecursive(maze, x, y + 1, sol) == 1)
			return 1;
		// If none of the above movements work then
		// BACKTRACK: unmark x, y as part of solution path
		sol[x][y] = 0;
		return 0;
	}
	return 0;
}

int solveMaze(int maze[MAX_SIZE][MAX_SIZE]){
	int sol[MAX_SIZE][MAX_SIZE] = { { 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 } };
	if (solveRecursive(maze, 0, 0, sol) == 0) {
		printf("Solution doesn't exist");
		return 0;
	}
	printSolution(sol);
	return 1;
}


int main(void){
	int maze[MAX_SIZE][MAX_SIZE] = { { 1, 0, 0, 0 },
					{ 1, 1, 0, 1 },
					{ 0, 1, 0, 0 },
					{ 1, 1, 1, 1 } };
	solveMaze(maze);
	return 0;
}
