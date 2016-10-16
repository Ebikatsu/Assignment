#include<stdio.h>
#include<stdlib.h>

int fact(int n);

int main(void)
{
	int i;
	for(i = 10; i >= 0; i--)printf("%d!=%d\n", i, fact(i));
	return EXIT_SUCCESS;
}

int fact(int n)
{
	if(n == 0)return 1;
	else return n * fact(n -1);
}
