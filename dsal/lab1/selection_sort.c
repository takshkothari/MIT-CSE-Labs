#include<stdio.h>
#include "selection_sort_fun.h"
void main()
{
	int array[10];
	int i, j, n, t;
	printf("enter the value of n \n");
	scanf("%d", &n);
	printf("enter the elements \n");
	for(i=0; i<n; i++)
	    scanf("%d", &array[i]);
	SelectionSort(array, n);
	printf("the sorted list using selection sort is: \n");
	for(i=0; i<n; i++)
	    printf("%d\n", array[i]);
}