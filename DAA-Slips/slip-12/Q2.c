// Selection sort
#include<stdio.h>

void selection(int a[], int n);

void main()
{
  int a[20], n;                      
  
  printf("\nEnter value of n: ");    
  scanf("%d", &n);                   
  
  printf("\nEnter array elements: "); 
  for(int i = 0; i < n; i++) {       // O(n) time - Loop executes n times
    scanf("%d", &a[i]);              
  }
  
  selection(a, n);                   // O(n²) time - Function call
  
  printf("\nSorted array elements:"); 
  
  for(int i = 0; i < n; i++) {       // O(n) time - Loop executes n times
    printf(" %d", a[i]);            
  }
}

void selection(int arr[], int n)
{
  int min, temp;                     
  for(int i = 0; i < n-1; i++)       // O(n) time - Outer loop executes (n-1) times
  {
    min = i;                         
    for(int j = i+1; j < n; j++)     // n(n-1) O(n-i) time per i - Inner loop executes (n-i-1) times
    {
      if(arr[j] < arr[min])          
        min = j;                     
    }
    // Swap the minimum element with the current element
    temp = arr[i];                   
    arr[i] = arr[min];               
    arr[min] = temp;                 
  }
}