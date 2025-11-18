#include <stdio.h>
#include <stdlib.h>

void heapify(int a[], int n, int i) {
    int temp;
    int max = i;
    int lindex = 2 * i + 1;
    int rindex = 2 * i + 2;

    if (lindex < n && a[lindex] > a[max])
        max = lindex;

    if (rindex < n && a[rindex] > a[max])
        max = rindex;

    if (max != i) {
        temp = a[i];
        a[i] = a[max];
        a[max] = temp;
        heapify(a, n, max);
    }
}

void heapSort(int a[], int n) {
    int temp;

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // Heap sort
    for (int i = n - 1; i > 0; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}

int main() {
    int a[20];
    int n;

    printf("\nEnter no. of elements: ");
    scanf("%d", &n);

    // printf("\nEnter the Elements: ");
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &a[i]);
    // }

    // Randomly Generated Elements
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }

    printf("\nArray before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    heapSort(a, n);

    printf("\nAfter Heap-Sort: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
