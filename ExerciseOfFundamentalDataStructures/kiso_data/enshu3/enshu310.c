#include<stdio.h>
#include<stdlib.h>

int factorial(int n);

int main(void)
{
	int n;
	printf("0以上の整数を入力してください: ");
	scanf("%d", &n);
	printf("%dの階乗: %d\n", n, factorial(n));
	return EXIT_SUCCESS;
}

int factorial(int n)
{
	return (n == 0) ? 1 : (n * factorial(n - 1));
}
