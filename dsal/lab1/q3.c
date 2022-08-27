#include<stdio.h>
#include<stdlib.h>

void Product(int **a, int *s1, int **b, int *s2, int **c)
{
	for(int i=0; i<s2[0]; i++)
	{
		for(int j=0; i<s1[1]; j++)
		{
			c[i][j]=0;
			for(int k=0; k<s2[0]; k++)
				c[i][j] = c[i][j] + a[i][k]*b[k][j];
		}
	}
}
void inpMat(int **arr, int *size)
{
	for(int i=0; i<size[0]; i++)
		{
			for(int j=0; j<size[1]; j++)
				scanf("%d ", &arr[i][j]);
		}
}
void main()
{
	int s1[2], s2[2];
	printf("enter dimensions of first matrix\n");
	scanf("%d %d", &s1[0], &s1[1]);
	printf("enter dimensions of second matrix\n");
	scanf("%d %d", &s2[0], &s2[1]);
	if(s1[1]==s2[0])
	{
		int **a = (int **)malloc(s1[0] * sizeof(int *));
		for(int x = 0; x < s1[0]; x++)
			a[x] = (int *)malloc(s1[1] * sizeof(int));
		printf("enter elements of first matrix\n");
		inpMat(a, s1);

		int **b = (int **)malloc(s2[0] * sizeof(int *));
		for(int x = 0; x < s2[0]; x++)
			b[x] = (int *)malloc(s2[1] * sizeof(int));
		printf("enter elements of second matrix\n");
		inpMat(b, s2);

		int **c = (int **)malloc(s2[0] * sizeof(int *));
		for(int x = 0; x < s2[0]; x++)
			c[x] = (int *)malloc(s1[1] * sizeof(int));

		Product(a, s1, b, s2, c);
		for(int i = 0; i<s2[0]; i++)
		{
			for(int j = 0; j<s1[1]; j++)
				printf("%d ", c[i][j]);
			printf("\n");
		}
		
	}
	else
		printf("cant multiply");
}