#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX], n;
bool visited[MAX];
bool isENode[MAX]; 
bool isLive[MAX]; 
bool isDead[MAX];

// DFS function to mark reachable nodes
void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int e, u, v;
   
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    
    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
        isENode[i] = isLive[i] = isDead[i] = false;
    }
    
    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }
    
    // Step 1: Identify E-Nodes (Nodes that are expanded in traversal)
    for (int i = 0; i < n; i++) {
        bool hasOutgoing = false;
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                hasOutgoing = true;
                break;
            }
        }
        if (!hasOutgoing)
            isENode[i] = true;
    }

    // Step 2: Find which nodes can reach an E-Node using DFS
    for (int i = 0; i < n; i++) {
        if (isENode[i]) {
            for (int j = 0; j < n; j++)
                visited[j] = false;
            
            dfs(i);  // Run DFS from each E-Node
            
            for (int j = 0; j < n; j++) {
                if (visited[j])
                    isLive[j] = true;
            }
        }
    }

    // Step 3: Identify Dead Nodes (Nodes that can't reach E-Nodes)
    for (int i = 0; i < n; i++) {
        if (!isLive[i])
            isDead[i] = true;
    }

    printf("\nE-Nodes: ");
    for (int i = 0; i < n; i++)
        if (isENode[i])
            printf("%d ", i);

    printf("\nLive Nodes: ");
    for (int i = 0; i < n; i++)
        if (isLive[i])
            printf("%d ", i);

    printf("\nDead Nodes: ");
    for (int i = 0; i < n; i++)
        if (isDead[i])
            printf("%d ", i);
    
    printf("\n");

    return 0;
}
