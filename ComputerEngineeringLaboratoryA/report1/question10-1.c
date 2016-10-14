#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char * const stra = "1100101011111110";
const char * const strb = "1011101010111110";

int main(void)
{
	unsigned int a,b;
	unsigned int i,j;
	a = 0;
	b = 0;
	for(i = 0; i < strlen(stra); i++)
	{
		a <<= 1;
		if(stra[i] == '1')a++;
	}
	for(i = 0; i < strlen(strb); i++)
	{
		b <<= 1;
		if(strb[i] == '1')b++;
	}
	printf(" ");
	for(i = 0; i < strlen(strb); i++)printf(" ");
	printf("%s\n", stra);
	printf("x");
	for(i = 0; i < strlen(stra); i++)printf(" ");
	printf("%s\n", strb);
	for(i = 0; i < 1 + strlen(stra) + strlen(strb); i++)printf("-");
	printf("\n");
	for(i = 0; i < strlen(strb); i++)
	{
		if(i == strlen(strb) - 1)printf("+");
		else printf(" ");
		for(j = 0; j < strlen(strb) - i; j++)printf(" ");
		if(b >> i & 1)printf("%s", stra);
		else for(j = 0; j < strlen(stra); j++)printf("0");
		for(j = 0; j < i; j++)printf(" ");
		printf("...%s x %c\n", stra, b >> i & 1 ? '1' : '0');
	}
	for(i = 0; i < 1 + strlen(stra) + strlen(strb); i++)printf("-");
	printf("\n ");
	for(i = 0; i < strlen(stra) + strlen(strb); i++)printf("%c", (a * b) >> (strlen(stra) + strlen(strb) - i - 1) & 1 ? '1' : '0');
	printf("\n");
	return EXIT_SUCCESS;
}
