#include<stdio.h>
#include<stdlib.h>

int array[15] = {0,0,0,0,0,1,2,3,4,5,6,7,8,9,10};

int main(void)
{
	int * const from = array + 5;
	int * const to = array;
	int * i;
	for(i = array; i < array + 10; i++)*i = i[from - to];
	for(i = array; i < array + 15; i++)printf("%u:%d\n", i, *i);
	return EXIT_SUCCESS;
}

