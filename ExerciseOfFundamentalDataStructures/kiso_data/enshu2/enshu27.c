#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int data[10] = {60, 80, 40, 90, 100, 80, 70, 30, 50, 20};
	int min = INT_MAX;
	int i;
	for(i = 0; i < sizeof(data)/sizeof(int); i++)if(min > data[i])min = data[i];
	printf("最小値は、%d点です\n", min);
	return EXIT_SUCCESS;
}

