// DFS

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX]; 
int visited[MAX];    
int n;              

void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1; 

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) { 
            DFS(i);
        }
    }
}


int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("Depth First Search (DFS) starting from vertex %d:\n", start);
    DFS(start);

    return 0;
}
