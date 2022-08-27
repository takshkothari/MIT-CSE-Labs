#include<stdio.h>
double Add(double a[], int n)
{
	double sum = 0;
	int i;
	for(i=0; i<n; i++)
	    sum = sum + a[i];
	return sum;
}
void main()
{
	double arr[10], s;
	int i, n;
	printf("enter the value of n \n");
	scanf("%d", &n);
	printf("enter the elements \n");
	for(i=0; i<n; i++)
	    scanf("%lf", &arr[i]);
	s = Add(arr, n);
	printf("sum of all the elements of the array is %lf \n", s);
}