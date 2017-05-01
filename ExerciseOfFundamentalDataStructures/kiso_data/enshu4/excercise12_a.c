//1桁の自然数の素数判定プログラム
#include<stdio.h>
#include<stdlib.h>

int isprime(int n);

int main(int argc, char **argv)
{
	int n;
	if(argc == 1)return EXIT_FAILURE;
	n = atoi(argv[1]);
	if(n <= 0 || 10 <= n)return EXIT_FAILURE;
	if(isprime(n))printf("素数です\n");
	else printf("素数ではありません。\n");
	return EXIT_SUCCESS;
}

int isprime(int n)
{
	int a[4] = {2,3,5,7};
	int i;
	for(i = 0; i < sizeof(a) / sizeof(int); i++)if(n == a[i])return 1;
	return 0;
}
