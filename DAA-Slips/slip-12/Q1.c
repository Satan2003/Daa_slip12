// BFS

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX]; 
int visited[MAX];    
int n;              


void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    int visitedBFS[MAX] = {0};

    queue[rear++] = start;
    visitedBFS[start] = 1;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visitedBFS[i]) {
                queue[rear++] = i;
                visitedBFS[i] = 1;
            }
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

    printf("\nBreadth First Search (BFS) starting from vertex %d:\n", start);
    BFS(start);

    return 0;
}
