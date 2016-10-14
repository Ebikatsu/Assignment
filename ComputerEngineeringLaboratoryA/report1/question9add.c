#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	unsigned int a,b;
	printf("  ");
	for(b = 0x1; b < 0x10; b++)printf("%3x", b);
	printf("\n");
	for(a = 0x1; a < 0x10; a++)
	{
		printf("%1x ", a);
		for(b = 0x1; b < 0x10; b++)printf("%3x", a+b);
		printf("\n");
	}
	return EXIT_SUCCESS;
}

