#include <stdio.h>

int main() {
    // Declaring arrays with extra space to allow 1-based indexing
    int A[3][3], B[3][3], C[3][3];
    int P, Q, R, S, T, U, V;

    printf("Enter the elements of the first matrix:\n");
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    printf("\nThe first matrix is:\n");
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    printf("\nThe second matrix is:\n");
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }

    // Strassen'S formulas with 1-based indexing
    P = (A[1][1] + A[2][2]) * (B[1][1] + B[2][2]);
    Q = (A[2][1] + A[2][2]) * B[1][1];
    R = A[1][1] * (B[1][2] - B[2][2]);
    S = A[2][2] * (B[2][1] - B[1][1]);
    T = (A[1][1] + A[1][2]) * B[2][2];
    U = (A[2][1] - A[1][1]) * (B[1][1] + B[1][2]);
    V = (A[1][2] - A[2][2]) * (B[2][1] + B[2][2]);

    // Computing the resulting matrix elements
    C[1][1] = P + S - T + V;
    C[1][2] = R + T;
    C[2][1] = Q + S;
    C[2][2] = P + R - Q + U;

    printf("\nAfter multiplication, the resulting matrix is:\n");
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}