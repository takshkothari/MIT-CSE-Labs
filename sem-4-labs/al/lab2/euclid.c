#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m, n, r, opc = 0;
	printf("enter 2 numbers ");
	scanf("%d %d", &m, &n);
	if(n>m){
		r = m;
		m = n;
		n = r;
	}
	while(n!=0){
		opc++;
		r = m % n;
		m = n;
		n = r;
	}
	printf("gcd is %d\nopcount is %d\n", m, opc);
	return 0;
}