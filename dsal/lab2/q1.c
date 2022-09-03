#include <stdio.h>
#include <stdlib.h>
void Reverse(int *a, int l)
{
	int *x = a;
	int *y = a + (l - 1);
	while (x < y)
	{
		int t = *x;
		*x = *y;
		*y = t;
		x++;
		y--;
	}
}

void main()
{
	int l;
	printf("enter length of array ");
	scanf("%d", &l);
	int *arr = (int *)malloc(l * sizeof(int));
	printf("enter numbers\n");
	for (int i = 0; i < l; i++)
		scanf("%d", &arr[i]);
	Reverse(arr, l);
	printf("the reversed array is:\n");
	for (int i = 0; i < l; i++)
	{
		printf("%d", arr[i]);
		printf("\n");
	}
}