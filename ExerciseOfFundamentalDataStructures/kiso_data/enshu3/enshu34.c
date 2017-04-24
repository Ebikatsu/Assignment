#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int a[5] = {21,22,23,24,25};
	int *a_p;
	int i;
	a_p = a;
	for(i = 0; i < sizeof(a) / sizeof(int); i++)printf("%d\n",*(a_p++));
	return EXIT_SUCCESS;
}

