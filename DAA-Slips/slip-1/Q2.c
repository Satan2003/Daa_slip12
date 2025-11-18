 // Quick sort method

#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int low, int high) {
    int key = a[low]; 
    int i = low + 1;
    int j = high;
    int temp;

    while (1) {
        
        while (i <= high && a[i] <= key)
            i++;

        
        while (a[j] > key)
            j--;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int j = partition(a, low, high);
        quickSort(a, low, j - 1);  // left sub-array
        quickSort(a, j + 1, high); // right sub-array
    }
}

int main() {
    int a[100], n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("\nThe elements are: ");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;  
        printf("%d ", a[i]);
    }

    quickSort(a, 0, n - 1); 
    
    printf("\nSorted elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

