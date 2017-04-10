#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int m,n,r;
	printf("整数を2つ入力してください>>>");
	scanf("%d %d", &m, &n);
	r = m % n;
	while(r)
	{
		m = n;
		n = r;
		r = m % n;
	}
	printf("GCD = %d です。\n",n);
	return EXIT_SUCCESS;
}

