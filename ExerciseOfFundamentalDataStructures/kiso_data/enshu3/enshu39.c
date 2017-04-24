#include<stdio.h>
#include<stdlib.h>

int fib(int n);

int main(void)
{
	int n;
	printf("0以上の整数を入力してください: ");
	scanf("%d", &n);
	printf("fib(%d) = %d\n", n, fib(n));
	return EXIT_SUCCESS;
}

int fib(int n)
{
	return (n == 0) ? 0 : ((n == 1) ? 1 : (fib(n-1) + fib(n - 2)));
}

