#include<stdio.h>

main()
{
	int a,b,c;
	int max;
	scanf("%d %d %d", &a, &b, &c);
	max = a;
	if(max < b) max = b;
	if(max < c) max = c;

	printf("MAX = %d\n",max);

	return 0;
}

