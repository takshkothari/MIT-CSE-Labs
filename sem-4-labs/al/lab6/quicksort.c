#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int l, int r){
    int p = a[r];
    int i = (l - 1);
    for (int j = l; j <= r - 1; j++){
        if (a[j] < p){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[r]);
    return (i + 1);
}

void quicksort(int arr[], int l, int h){
    if (l < h){
        int p = partition(arr, l, h);
        quicksort(arr, l, p - 1);
        quicksort(arr, p + 1, h);
    }
}

void main() {
    int n, i;
    printf("enter no. of elements: ");
    scanf("%d", &n);
    int* a = (int *) malloc(n * sizeof(int));
    printf("enter elements:\n");
    for(i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    printf("sorted array: ");
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}