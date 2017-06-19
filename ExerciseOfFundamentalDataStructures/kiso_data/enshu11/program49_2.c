//未完成
#include<stdio.h>
#include<stdlib.h>

//#define DEBUG

void down_heap_process(int x[], int m)
{
	int i;
	for(i = 1; i <= m; i++)printf(" %d", x[i]);
	printf("\n");
}

void heap_sort_process(int x[], int m)
{
	int i;
	for(i = 1; i <= m; i++)printf(" %d", x[i]);
	printf("\n");
	printf("heap_sort\n");
}

void down_heap(int x[], int start, int end, int m)
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

			printf("return文でdown_heap終了\n");
			down_heap_process(x, m);

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

	printf("down_heap\n");
	down_heap_process(x, m);
}

void heap_sort(int x[], int n, int m)
{
	int i, tmp;
	#ifdef DEBUG
	int j;
	#endif

	for(i = n / 2; i > 0; i--){
		down_heap(x, i, n, m);
	}

	#ifdef DEBUG
	printf("heap1\n");
	for(j = 1; j < n + 1; j++)
	{
		printf("%d\n", x[j]);
	}
	#endif

	for(i = n; i >= 2; i--){
		printf("i = %d\n", i);
		tmp = x[i];
		x[i] = x[1];
		x[1] = tmp;
		printf("x[1]とx[%d]の入れ替え完了\n", i);
		#ifdef DEBUG
		printf("heap2\n");
		for(j = 1; j < n + 1; j++)
		{
			printf("%d\n", x[j]);
		}
		#endif
		down_heap(x, 1, i - 1, m);
		printf("down_heap終了\n");
		#ifdef DEBUG
		printf("heap3(i == %d)\n", i);
		for(j = 1; j < n + 1; j++)
		{
			printf("%d\n", x[j]);
		}
		#endif
	}
	heap_sort_process(x, m);
}

main(int argc, char *argv[])
{
	int i, x[100], n;

	n = atoi(argv[1]);
	for(i = 1; i < n + 1; i++)scanf("%d", &x[i]);

	heap_sort(x, n, n);

	printf("sort\n");
	for(i = 1; i < n + 1; i++)
	{
		printf("%d\n", x[i]);
	}

	return 0;
}
