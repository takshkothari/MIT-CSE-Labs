#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int l, int m, int h) {
    if (l >= h || a == NULL)
        return;
    int * finalArr = (int *) malloc((h - l + 1) * sizeof(int));
    int i = l;
    int j = m + 1;
    int ind = 0;
    while (i <= m && j <= h) {
        if (a[i] < a[j]) {
            finalArr[ind++] = a[i];
            i++;
        } else {
            finalArr[ind++] = a[j];
            j++;
        }
    }
    while (i <= m) {
        finalArr[ind++] = a[i];
        i++;
    }
    while (j <= h) {
        finalArr[ind++] = a[j];
        j++;
    }
    ind = 0;
    for (i = l; i <= h; i++)
        a[i] = finalArr[ind++];
    free(finalArr);
}
void mergeSort(int a[], int l, int r) {
    if (a == NULL || l >= r)
        return;
    int m = (l + r) / 2;
    if (l < m)
        mergeSort(a, l, m);
    if (m + 1 < r)
        mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}
void main() {
    int n, i;
    printf("enter no. of elements: ");
    scanf("%d", &n);
    int * arr = (int *) malloc(n * sizeof(int));
    printf("enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("sorted array: ");
    mergeSort(arr, 0, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}