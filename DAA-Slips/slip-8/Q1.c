// Knapsack using Greedy Method

#include <stdio.h>

typedef struct {
    int weight;
    int value;
    double ratio;
} Item;

void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

// sort in descending order
void sortItemsByRatio(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}


double knapsack(Item items[], int n, int capacity) {
    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take the full item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take fraction of the item
            totalValue += items[i].ratio * capacity;
            break; 
        }
    }
    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter weight and value for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    sortItemsByRatio(items, n);

    double maxValue = knapsack(items, n, capacity);

    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
