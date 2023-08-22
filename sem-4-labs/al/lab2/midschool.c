#include<stdio.h>
#include<stdlib.h>

int main()
{
	int gcd = 1, m, n, i = 2, opc = 0;
	printf("enter 2 numbers ");
	scanf("%d %d", &m, &n);
	while(gcdiv(m,n, &opc) != 1){
		opc++;
		if(prime(i, &opc)){
			if(m%i == 0 && n % i == 0){
				gcd = gcd * i;
				m = m/i;
				n = n/i;
			}
			else
				i++;
		}
		else
			i++;
	}
	printf("gcd is %d\nopcount is %d\n", gcd, opc);
	return 0;
}
int gcdiv(int m, int n, int *opc){
	int r;
	if(n>m){
		r = m;
		m = n;
		n = r;
	}
	while(n!=0){
		(*opc)++;
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}
int prime(int x, int* opc){
	int c = 0, i;
	for(i = 2; i < x; i++){
		(*opc)++;
		if(x % i == 0)
			return 0;
	}
		return 1;
}