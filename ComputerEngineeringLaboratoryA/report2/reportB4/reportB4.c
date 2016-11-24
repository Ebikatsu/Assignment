#include<stdio.h>
#include<stdlib.h>

const int arraylength = 10;
int array[10] = {0,0,0,0,0,0,0,0,0,0};

int main(void)
{
	int c,i;
	do
	{
		printf(">");
		scanf("%d", &c);
		if(0 <= c && c < arraylength)array[c]++;
		printf("%d\n", c);
	}while(c >= 0);
	for(i = 0; i < arraylength; i++)printf("%d:%d\n", i, array[i]);
	return EXIT_SUCCESS;
}
