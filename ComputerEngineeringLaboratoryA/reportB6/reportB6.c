#include<stdio.h>
#include<stdlib.h>

int array[15] = {1,2,3,4,5,6,7,8,9,10,0,0,0,0,0};

int main(void)
{
	int * const from = array;
	int * const to = array + 5;
	int * i;
	for(i = array + 9; i >= array; i--)i[to - from] = *i;
	for(i = array; i < array + 15; i++)printf("%d\n", *i);
	return EXIT_SUCCESS;
}

