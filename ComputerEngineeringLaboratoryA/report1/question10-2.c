#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

const unsigned int a = 0xcafe;
const unsigned int b = 0xbabe;

unsigned int getBit(unsigned int data, unsigned int digit);
unsigned int getDigit16(unsigned int data);

int main(void)
{
	unsigned int i,j;
	char stra[getDigit16(a) + 1], strb[getDigit16(b) + 1];
	printf(" ");
	for(i = 0; i < getDigit16(b); i++)printf(" ");
	printf("%x\n", a);
	printf("x");
	for(i = 0; i < getDigit16(a); i++)printf(" ");
	printf("%x\n", b);
	for(i = 0; i < 1 + getDigit16(a) + getDigit16(b); i++)printf("-");
	printf("\n");
	sprintf(stra, "%x", a);
	sprintf(strb, "%x", b);
	for(i = 0; i < getDigit16(b); i++)
	{
		unsigned int bOneDigit;
		char strBOneDigit[2];
		strBOneDigit[1] = '\0';
		strBOneDigit[0] = strb[getDigit16(b) - i - 1];
		sscanf(strBOneDigit, "%x", &bOneDigit);
		if(i == getDigit16(b) - 1)printf("+");
		else printf(" ");
		for(j = 0; j < getDigit16(a) + getDigit16(b) - getDigit16(a * bOneDigit) - i; j++)printf(" ");
		printf("%x", a * bOneDigit);
		for(j = 0; j < i; j++)printf(" ");
		printf("...%s x %s\n", stra, strBOneDigit);
	}
	for(i = 0; i < 1 + getDigit16(a) + getDigit16(b); i++)printf("-");
	printf("\n");
	printf(" %x\n", a * b);
	return EXIT_SUCCESS;
}

unsigned int getBit(unsigned int data, unsigned int digit)
{
	return data >> digit & 1;
}

unsigned int getDigit16(unsigned int data)
{
	unsigned int i;
	for(i = sizeof(unsigned int) * CHAR_BIT - 1; i < sizeof(unsigned int) * CHAR_BIT; i--)if(getBit(data, i))break;
	return (i + 3) / 4;
}
