#include <stdio.h>
#include <limits.h>

#define MAX 20  // Max cities
#define INF INT_MAX

int n;
int dist[MAX][MAX];  // Distance matrix
int dp[MAX][1 << MAX]; // DP table


int tsp(int pos, int mask) {
    if (mask == (1 << n) - 1)  // All cities visited, return to start
        return dist[pos][0] ? dist[pos][0] : INF;

    if (dp[pos][mask] != -1)  // If already computed
        return dp[pos][mask];

    int minCost = INF;

    for (int city = 0; city < n; city++) {
        if (!(mask & (1 << city)) && dist[pos][city] > 0) {  // If not visited and path exists
            int newCost = dist[pos][city] + tsp(city, mask | (1 << city));
            if (newCost < minCost)
                minCost = newCost;
        }
    }

    return dp[pos][mask] = minCost;  // Store and return the computed cost
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 for no direct path):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    // Initialize DP table with -1
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < (1 << MAX); j++)
            dp[i][j] = -1;

    int minCost = tsp(0, 1);  // Start from city 0 with only city 0 visited

    printf("Minimum Cost of TSP: %d\n", minCost);
    return 0;
}
