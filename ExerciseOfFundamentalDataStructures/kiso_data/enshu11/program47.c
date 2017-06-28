#include<stdio.h>
#include<stdlib.h>

//#define DEBUG

int b[100];

void merge_array(int x[], int start, int end)
{
	int mid, i, j, k;

	mid = (start + end) / 2;

	i = start;
	j = mid + 1;
	for(k = start; k <= end; k++){
		if(x[i] > x[j] && j <= end || i > mid){
			b[k] = x[j];
			j++;
		}
		else{
			b[k] = x[i];
			i++;
		}
	}
	for(k = start; k <= end; k++){
		x[k] = b[k];
	}
}

void merge_sort(int a[], int start, int end)
{
	int mid;
	#ifdef DEBUG
	int i;
	#endif

	#ifdef DEBUG
	printf("before merge\n");
	for(i = start; i < end; i++){
		printf("%d\n", a[i]);
	}
	printf("\n");
	#endif

	#ifdef DEBUG
	if(start >= end){
		printf("start + 1>= end\n");
		return;
	}
	#else
	if(start >= end)return;
	#endif

	mid = (start + end) / 2;

	merge_sort(a, start, mid);
	merge_sort(a, mid + 1, end);

	merge_array(a, start, end);

	#ifdef DEBUG
	printf("after merge\n");
	for(i = start; i < end; i++){
		printf("%d\n", a[i]);
	}
	printf("\n");
	#endif
}

main(int argc, char *argv[])
{
	int i, x[100], n;

	n = atoi(argv[1]);
	for(i = 0; i < n; i++)scanf("%d", &x[i]);
	#ifdef DEBUG
	printf("\n");
	#endif

	merge_sort(x, 0, n - 1);

	printf("sort\n");
	for(i = 0; i < n; i++){
		printf("%d\n", x[i]);
	}

	return 0;
}
