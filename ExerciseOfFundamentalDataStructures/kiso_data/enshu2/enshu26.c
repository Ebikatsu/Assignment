#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int data[10] = {60, 80, 40, 90, 100, 80, 70, 30, 50, 20};
	int max = 0;
	int i;
	for(i = 0; i < sizeof(data)/sizeof(int); i++)if(max < data[i])max = data[i];
	printf("最大値は、%d点です\n", max);
	return EXIT_SUCCESS;
}

