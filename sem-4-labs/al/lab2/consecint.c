#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m, n, t, opc = 0;
	printf("enter 2 numbers ");
	scanf("%d %d", &m, &n);
	t = (m < n)? m : n;
	while(t!=1){
		opc++;
		if(m % t == 0){
			if(n % t == 0){
				printf("gcd is %d\nopcount is %d\n", t, opc);
				break;
			}
		}
		t--;
	}
	if(t==1)
		printf("gcd is 1\nopcount is %d\n", opc);
	return 0;
}