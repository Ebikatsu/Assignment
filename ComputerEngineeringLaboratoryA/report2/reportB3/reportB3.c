#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int x;
	do
	{
		printf(">");
		scanf("%d", &x);
		printf("%d\n", x);
	}while(x >= 0);
	return EXIT_SUCCESS;
}

