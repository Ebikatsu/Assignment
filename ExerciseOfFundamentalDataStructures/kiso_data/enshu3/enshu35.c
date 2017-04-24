#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

void max(int *ary, size_t size, int *ans);
void min(int *ary, size_t size, int *ans);

int main(void)
{
	int ary[6];
	int Max = 0,Min = 0;
	int i;
	for(i = 0; i < sizeof(ary) / sizeof(int); i++)
	{
		printf("? ");
		scanf("%d", ary + i);
	}
	max(ary, sizeof(ary) / sizeof(int), &Max);
	min(ary, sizeof(ary) / sizeof(int), &Min);
	printf("最大値 ==> %d\n", Max);
	printf("最小値 ==> %d\n", Min);
	return EXIT_SUCCESS;
}

void max(int *ary, size_t size, int *ans)
{
	size_t i;
	*ans = INT_MIN;
	for(i = 0; i < size; i++)if(ary[i] > *ans)*ans = ary[i];
	return;
}

void min(int *ary, size_t size, int *ans)
{
	size_t i;
	*ans = INT_MAX;
	for(i = 0; i < size; i++)if(ary[i] < *ans)*ans = ary[i];
	return;
}
