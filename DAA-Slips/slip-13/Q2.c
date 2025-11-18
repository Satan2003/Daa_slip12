// optimal binary search tree

#include <stdio.h>
#include <limits.h>

int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}


int optimalBST(int keys[], int freq[], int n) {
    int cost[n][n]; // Cost table

    // Initialize cost matrix for single keys
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // Compute cost for chains of increasing length
    for (int L = 2; L <= n; L++) { // L is chain length
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX; // Set to maximum initially

            // Try making each key the root
            for (int r = i; r <= j; r++) {
                int leftCost = (r > i) ? cost[i][r - 1] : 0;
                int rightCost = (r < j) ? cost[r + 1][j] : 0;
                int totalCost = leftCost + rightCost + sum(freq, i, j);

                if (totalCost < cost[i][j])
                    cost[i][j] = totalCost;
            }
        }
    }

    return cost[0][n - 1]; // Return the minimum cost
}

int main() {
    int n;
    printf("Enter number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];

    printf("Enter the keys: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &keys[i]);

    printf("Enter their respective frequencies: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &freq[i]);

    int minCost = optimalBST(keys, freq, n);
    printf("Minimum cost of Optimal BST: %d\n", minCost);

    return 0;
}
