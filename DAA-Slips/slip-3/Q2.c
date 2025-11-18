// Prims Algorthim

#include <stdio.h>

int a, b, u, v, n, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

void main() {
  printf("\nEnter the number of nodes: ");
  scanf("%d", &n);

  printf("Enter the adjacency matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &cost[i][j]);
      if (cost[i][j] == 0)
        cost[i][j] = 999;  
    }
  }

  visited[0] = 1; 

  while (ne < n) {
    min = 999;  

    for (int i = 0; i < n; i++) {
      if (visited[i]) {  
        for (int j = 0; j < n; j++) {
          if (!visited[j] && cost[i][j] < min) {  
            min = cost[i][j];
            a = u = i;
            b = v = j;
          }
        }
      }
    }
    
    visited[v] = 1;
    printf("\nEdge %d: (%d %d) cost: %d", ne++, a, b, min);
    mincost += min;
    
    cost[a][b] = cost[b][a] = 999;
  }
  printf("\nMinimum cost = %d\n", mincost);
}

