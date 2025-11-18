#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int graph[MAX][MAX];
int color[MAX];
int n;

bool isSafe(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && color[i] == c)  // If adjacent vertex has the same color
            return false;
    }
    return true;
}


bool graphColoringUtil(int v, int m) {
    if (v == n)  // If all vertices are colored, return true
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;  // Assign color to the vertex

            if (graphColoringUtil(v + 1, m))  // Recur for the next vertex
                return true;

            color[v] = 0;  // Backtrack
        }
    }

    return false; 
}

void graphColoring(int m) {
    for (int i = 0; i < n; i++)
        color[i] = 0;  // Initialize all vertices as uncolored

    if (!graphColoringUtil(0, m)) {
        printf("Solution does not exist for %d colors.\n", m);
        return;
    }

    printf("Solution exists. Vertex colors:\n");
    for (int i = 0; i < n; i++)
        printf("Vertex %d -> Color %d\n", i, color[i]);
}

int main() {
    int e, u, v, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;  // Since it's an undirected graph
    }

    
    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(m);

    return 0;
}
