//未完成
#include<stdio.h>
#include<stdlib.h>

//#define DEBUG

void down_heap(int x[], int start, int end)
{
	int pivot, tmp;
	#ifdef DEBUG
	int i,saved_start;
	saved_start = start;
	#endif

	#ifdef DEBUG
	printf("down_before\n");
	for(i = saved_start; i <= end; i++)
	{
		printf("%d\n", x[i]);
	}
	#endif

	while(2 * start <= end){
		if(2 * start + 1 > end){
			pivot = 2 * start;
		}
		else{
			if(x[2 * start] > x[2 * start + 1]){
				pivot = 2 * start;
			}
			else{
				pivot = 2 * start + 1;
			}
		}
		if(x[pivot] > x[start]){
			tmp = x[pivot];
			x[pivot] = x[start];
			x[start] = tmp;
			#ifdef DEBUG
			printf("down_changed\n");
			for(i = saved_start; i <= end; i++)
			{
				printf("%d\n", x[i]);
			}
			#endif
		}
		else{

			#ifdef DEBUG
			printf("down_after\n");
			for(i = saved_start; i <= end; i++)
			{
				printf("%d\n", x[i]);
			}
			#endif

			return;
		}
		start = pivot;
	}

	#ifdef DEBUG
	printf("down_after\n");
	for(i = saved_start; i <= end; i++)
	{
		printf("%d\n", x[i]);
	}
	#endif
}

void heap_sort(int x[], int n)
{
	int i, tmp;
	#ifdef DEBUG
	int j;
	#endif

	for(i = n / 2; i > 0; i--){
		down_heap(x, i, n);
	}

	#ifdef DEBUG
	printf("heap1\n");
	for(j = 1; j < n + 1; j++)
	{
		printf("%d\n", x[j]);
	}
	#endif

	for(i = n; i >= 2; i--){
		tmp = x[i];
		x[i] = x[1];
		x[1] = tmp;
		#ifdef DEBUG
		printf("heap2\n");
		for(j = 1; j < n + 1; j++)
		{
			printf("%d\n", x[j]);
		}
		#endif
			down_heap(x, 1, i - 1);
		#ifdef DEBUG
		printf("heap3(i == %d)\n", i);
		for(j = 1; j < n + 1; j++)
		{
			printf("%d\n", x[j]);
		}
		#endif
	}
}

main(int argc, char *argv[])
{
	int i, x[100], n;

	n = atoi(argv[1]);
	for(i = 1; i < n + 1; i++)scanf("%d", &x[i]);

	heap_sort(x, n);

	printf("sort\n");
	for(i = 1; i < n + 1; i++)
	{
		printf("%d\n", x[i]);
	}

	return 0;
}
