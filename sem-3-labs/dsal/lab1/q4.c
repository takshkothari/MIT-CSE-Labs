#include <stdio.h>

int sec(int arr[], int n)
{
	int a, b;
	a = b = arr[0];
	for(int i = 0; i<n; i++)
	{
	    if(a<=arr[i])
	    {
	        b = a;
	        a = arr[i];
	    }
	}
	return b;
}
void main()
{
	int n, i;
	printf("enter the size of array \n");
	scanf("%d", &n);
	int arr[n];
	printf("enter the elements \n");
	for(i=0; i<n; i++)
	    scanf("%d", &arr[i]);

	int x = sec(arr, n);
	printf("the second largest element is %d", x);
}
