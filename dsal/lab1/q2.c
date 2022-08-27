#include<stdio.h>
int LSearch(int arr[], int n, int k)
{
	int x=0, i;
	for(i = 0; i<n; i++)
	{
		if(arr[i]==k)
		{
			x=1;
			break;
		}
	}
	return x;
}
void main()
{
	int a[10], n, k, i;
	printf("enter the value of n \n");
	scanf("%d", &n);
	printf("enter the elements \n");
	for(i=0; i<n; i++)
	    scanf("%d", &a[i]);
	printf("enter element to be searched ");
	scanf("%d", &k);
	int x = LSearch(a, n, k);
	if(x==1)
		printf("\nnumber is found\n");
	else
		printf("\nnumber not found\n");
}