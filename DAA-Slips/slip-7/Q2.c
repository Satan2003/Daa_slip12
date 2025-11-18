// Topological Sort

#include <stdio.h>
#include <stdlib.h>

#define MAX 100  

void topologicalSort(int graph[MAX][MAX], int n) {
    int inDegree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    // Calculate in-degree for each vertex
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {  // Edge exists
                inDegree[j]++;
            }
        }
    }

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Process vertices in the queue
    int count = 0;
    printf("Topological Order: ");
    while (front < rear) {
        int u = queue[front++]; // Dequeue a vertex
        printf("%d ", u);
        count++;

        // Reduce in-degree of all adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v]) {  // Edge exists
                inDegree[v]--;
                if (inDegree[v] == 0) { // If in-degree becomes zero, enqueue it
                    queue[rear++] = v;
                }
            }
        }
    }

    // If count != n, there is a cycle (not a DAG)
    if (count != n) {
        printf("\nError: The graph contains a cycle! Topological sorting is not possible.\n");
    } else {
        printf("\n");
    }
}

int main() {
    int n, graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 1 for an edge, 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort(graph, n);

    return 0;
}
