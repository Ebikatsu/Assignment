#include<stdio.h>
#include<stdlib.h>

main(int argc, char *argv[])
{
	int a[100], max, n, i;

	n = atoi(argv[1]);
	for(i = 0; i < n; i++)scanf("%d", &a[i]);

	max = a[0];
	for(i = 1; i < n; i++){
		if(max < a[i])max = a[i];
	}

	printf("MAX = %d\n", max);

	return 0;
}
