#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int a[5] = {21,22,23,24,25};
	int *a_p;
	a_p = &a[0];
	printf("%d\n", *a_p);
	a_p += 1;
	printf("%d\n", *a_p);
	a_p += 1;
	printf("%d\n", *a_p);
	a_p += 1;
	printf("%d\n", *a_p);
	a_p += 1;
	printf("%d\n", *a_p);
	return EXIT_SUCCESS;
}

