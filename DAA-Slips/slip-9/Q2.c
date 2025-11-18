#include <stdio.h>

#define MAX 100

int n, targetSum;
int set[MAX], subset[MAX];

void printSubset(int subset[], int subsetSize) {
    printf("{ ");
    for (int i = 0; i < subsetSize; i++)
        printf("%d ", subset[i]);
    printf("}\n");
}

void sumOfSubset(int index, int currentSum, int subsetSize) {
    if (currentSum == targetSum) {
        printSubset(subset, subsetSize);
        return;
    }
    
    if (index >= n || currentSum > targetSum)
        return;

    // Include the current element
    subset[subsetSize] = set[index];
    sumOfSubset(index + 1, currentSum + set[index], subsetSize + 1);

    // Exclude the current element (Backtrack)
    sumOfSubset(index + 1, currentSum, subsetSize);
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("Subsets with sum %d are:\n", targetSum);
    sumOfSubset(0, 0, 0);

    return 0;
}
