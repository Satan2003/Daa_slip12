// Matrix Chain Multiplcation
#include <stdio.h>
#include <limits.h>

int matrixChainOrder(int p[], int n) {
    int m[n][n]; // DP table
    int j, q;

    // Cost is zero when multiplying one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    // L is the chain length (subproblems of increasing size)
    for (int L = 2; L < n; L++) { 
        for (int i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX; // Set to a large value

            for (int k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q; // Store the minimum cost
            }
        }
    }

    return m[1][n - 1]; // Minimum cost
}

int main() {
    int n;
    
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    
    int p[n + 1];

  
    printf("Enter the dimensions: ");
    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    printf("Minimum number of multiplications: %d\n", matrixChainOrder(p, n + 1));

    return 0;
}
