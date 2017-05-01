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
	int b[10] = {1,1,0,0,1,0,1,0,1,1};
	return !b[n];
}
