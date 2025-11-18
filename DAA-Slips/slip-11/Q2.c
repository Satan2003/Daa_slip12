// Dijkstra’s algorithm

#include <stdio.h>
#include <limits.h>

#define MAX 10


int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] < min) {  // Pick the smallest unvisited vertex
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}


void printSolution(int dist[], int n) {
    printf("\nVertex   Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\n", i, (dist[i] == INT_MAX) ? -1 : dist[i]);  // Show -1 for unreachable nodes
}


void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];         // Stores the shortest distances
    int visited[MAX] = {0}; // Array to track visited nodes

    // Initialize distances with INT_MAX and source with 0
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Loop for all vertices
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break; // If no vertex is reachable, exit

        visited[u] = 1; // Mark vertex as processed/visited

        // Update adjacent vertex distances
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] > 0 && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, n);
}

int main() {
    int n, src;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 0 for no direct path):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, n, src);

    return 0;
}
