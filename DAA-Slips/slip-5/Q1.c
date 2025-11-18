#include <stdio.h>

int k, a, b, u, v, n, ne = 1;
int parent[9] = {0};  // Initialize parent array to 0
int min, mincost = 0, cost[9][9];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void main() {
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {  // Fix: Use 0-based indexing
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)  // Replace 0 with a large number (infinity)
                cost[i][j] = 999;
        }
    }

    printf("\nEdges of the Minimum Cost Spanning Tree:\n");

    while (ne < n) {
        min = 999;  // Reset min in each iteration

        for (int i = 0; i < n; i++) {  // Fix: Use 0-based indexing
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min) {  
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            printf("Edge %d: (%d, %d) = %d\n", ne++, a + 1, b + 1, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;  // Mark selected edge as used
    }

    printf("\nMinimum Cost = %d\n", mincost);
}
