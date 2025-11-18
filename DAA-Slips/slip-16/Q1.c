// 0/1 Knapsack Problem using Dynamic Programming
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];

    // Build the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0; // Base case: no items or zero capacity
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity]; // Maximum value that can be obtained
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    printf("Enter the values and weights of items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &values[i], &weights[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int max_value = knapsack(capacity, weights, values, n);

    printf("Maximum value that can be obtained: %d\n", max_value);

    return 0;
}

/*
Enter number of items: 3
Enter the values and weights of items:
Item 1: 3 7
Item 2: 5 10
Item 3: 4 6
Enter the capacity of the knapsack: 15
Maximum value that can be obtained: 7
*/