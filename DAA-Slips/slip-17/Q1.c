// N Queen Problem

#include <stdio.h>

#define MAX 10

int board[MAX][MAX]; 
int N;  


void printSolution() {
    static int solutionCount = 1;
    printf("\nSolution %d:\n", solutionCount++);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%c ", board[i][j] ? 'Q' : '.');
        printf("\n");
    }
}


int isSafe(int row, int col) {
    for (int i = 0; i < row; i++)  // Check the column above
        if (board[i][col])
            return 0;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)  // Check upper-left diagonal
        if (board[i][j])
            return 0;

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)  // Check upper-right diagonal
        if (board[i][j])
            return 0;

    return 1;
}


void solveNQueens(int row) {
    if (row == N) {  // All queens placed
        printSolution();
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;  // Place the queen
            solveNQueens(row + 1);  // Recur for next row
            board[row][col] = 0;  // Backtrack
        }
    }
}

int main() {
    printf("Enter the value of N: ");
    scanf("%d", &N);

    if (N < 1 || N > MAX) {
        printf("Invalid value! Enter N between 1 and %d.\n", MAX);
        return 1;
    }

    printf("\nSolutions for %d-Queens:\n", N);
    solveNQueens(0);  // Start solving from row 0

    return 0;
}
