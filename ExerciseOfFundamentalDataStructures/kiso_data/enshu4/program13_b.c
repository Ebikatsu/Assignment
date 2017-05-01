#include<stdio.h>

int gcd(int a, int b);

main()
{
	int a, b, t;

	scanf("%d %d", &a, &b);
	printf("GCD = %d\n", gcd(a,b));

	return 0;
}

int gcd(int a, int b)
{
	if(a % b == 0)return b;
	else return gcd(b, a % b);
}
