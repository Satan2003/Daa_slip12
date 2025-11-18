// 0/1 knapsack problem using LCBB

#include <stdio.h>
#include <stdlib.h>

// Structure for items
typedef struct {
    int weight;
    int value;
    float ratio;  // value/weight ratio
} Item;

// Structure for nodes in the search tree
typedef struct {
    int level;     // Level of the item being considered
    int profit;    // Profit so far
    int weight;    // Weight so far
    float bound;   // Upper bound of profit
} Node;

// Compare function for sorting items by value/weight ratio
int compare(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;
    return (item2->ratio > item1->ratio) ? 1 : -1;
}

// Calculate upper bound at a node
float bound(Node node, int capacity, Item items[], int n) {
    // If weight exceeds capacity, return 0
    if (node.weight > capacity)
        return 0;

    // Initialize bound to current profit
    float profit_bound = node.profit;
    int weight = node.weight;
    int level = node.level;
    
    // Add items until capacity is reached
    while (level < n && weight + items[level].weight <= capacity) {
        weight += items[level].weight;
        profit_bound += items[level].value;
        level++;
    }
    
    // Add fraction of the next item if possible
    if (level < n) {
        profit_bound += (capacity - weight) * items[level].ratio;
    }
    
    return profit_bound;
}

int knapsackLCBB(int capacity, int weights[], int values[], int n) {
    // Create and initialize items
    Item* items = (Item*)malloc(n * sizeof(Item));
    for (int i = 0; i < n; i++) {
        items[i].weight = weights[i];
        items[i].value = values[i];
        items[i].ratio = (float)values[i] / weights[i];
    }
    
    // Sort items by value/weight ratio (non-increasing)
    qsort(items, n, sizeof(Item), compare);
    
    // Initialize queue for BFS
    // Queue size is potentially 2^n but we use a reasonable size
    int queueSize = 1000;
    Node* queue = (Node*)malloc(queueSize * sizeof(Node));
    int front = 0, rear = 0;
    
    // Create a dummy node
    Node u = {0, 0, 0, 0};
    u.bound = bound(u, capacity, items, n);
    queue[rear++] = u;
    
    int maxProfit = 0;
    
    // Branch and bound loop
    while (front < rear) {
        // Extract node
        Node current = queue[front++];
        
        // Skip if bound is not promising
        if (current.bound <= maxProfit)
            continue;
        
        // If it's a leaf node
        if (current.level == n)
            continue;
        
        // Try including the current item
        Node withItem;
        withItem.level = current.level + 1;
        withItem.profit = current.profit + items[current.level].value;
        withItem.weight = current.weight + items[current.level].weight;
        
        // Update best solution if better
        if (withItem.weight <= capacity && withItem.profit > maxProfit)
            maxProfit = withItem.profit;
        
        // Calculate bound and add to queue if promising
        withItem.bound = bound(withItem, capacity, items, n);
        if (withItem.bound > maxProfit && withItem.weight <= capacity) {
            if (rear >= queueSize) {
                queueSize *= 2;
                queue = (Node*)realloc(queue, queueSize * sizeof(Node));
            }
            queue[rear++] = withItem;
        }
        
        // Try excluding the current item
        Node withoutItem;
        withoutItem.level = current.level + 1;
        withoutItem.profit = current.profit;
        withoutItem.weight = current.weight;
        withoutItem.bound = bound(withoutItem, capacity, items, n);
        
        if (withoutItem.bound > maxProfit) {
            if (rear >= queueSize) {
                queueSize *= 2;
                queue = (Node*)realloc(queue, queueSize * sizeof(Node));
            }
            queue[rear++] = withoutItem;
        }
    }
    
    free(items);
    free(queue);
    return maxProfit;
}

int main() {
    int n, capacity;
    
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    int weights[n], values[n];
    
    printf("Enter the values and weights of items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &values[i], &weights[i]);
    }
    
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    
    int max_value = knapsackLCBB(capacity, weights, values, n);
    
    printf("Maximum value that can be obtained: %d\n", max_value);
    
    return 0;
}