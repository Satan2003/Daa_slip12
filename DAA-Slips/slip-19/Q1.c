// Hamiltonian Cycle

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int graph[MAX][MAX], path[MAX], n;
bool foundCycle = false; 

bool isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0) // No edge exists
        return false;

    for (int i = 0; i < pos; i++)  // Check if vertex is already in the path
        if (path[i] == v)
            return false;

    return true;
}

void printCycle() {
    foundCycle = true;
    printf("Hamiltonian Cycle: ");
    for (int i = 0; i < n; i++)
        printf("%d -> ", path[i]);
    printf("%d\n", path[0]); // Complete the cycle
}


void hamiltonianCycleUtil(int pos) {
    if (pos == n) { 
        if (graph[path[pos - 1]][path[0]] == 1) // Check if last connects to first
            printCycle();
        return;
    }

    for (int v = 1; v < n; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            hamiltonianCycleUtil(pos + 1);
            path[pos] = -1; // Backtrack
        }
    }
}

void findHamiltonianCycles() {
    for (int i = 0; i < n; i++) 
        path[i] = -1; // Initialize path
    
    path[0] = 0; // Start from first vertex

    hamiltonianCycleUtil(1);

    if (!foundCycle)
        printf("No Hamiltonian Cycle found.\n");
}

int main() {
    int i, j;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){ 
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nAll Hamiltonian Cycles in the given graph:\n");
    findHamiltonianCycles();

    return 0;
}
