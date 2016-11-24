#include<stdio.h>
#include<stdlib.h>

#ifdef B5
int array[15] = {0,0,0,0,0,1,2,3,4,5,6,7,8,9,10};
#elif defined B6
int array[15] = {1,2,3,4,5,6,7,8,9,10,0,0,0,0,0};
#endif

int main(void)
{
	#ifdef B5
	int * const from = array + 5;
	int * const to = array;
	#elif defined B6
	int * const from = array;
	int * const to = array + 5;
	#endif
	int * i;
	if(from > to)for(i = array; i < array + 10; i++)*i = i[from - to];
	else for(i = array + 9; i >= array; i--)i[to - from] = *i;
	for(i = array; i < array + 15; i++)printf("%u:%d\n", i, *i);
	return EXIT_SUCCESS;
}
