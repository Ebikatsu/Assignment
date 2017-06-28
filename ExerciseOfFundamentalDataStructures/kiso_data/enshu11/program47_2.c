#include<stdio.h>
#include<stdlib.h>

//#define DEBUG

int b[100];

void merge_array_process(int x[], int start, int mid, int end, int n)
{
	int k;

	printf("merge_array_pro\n");
	printf("start = %d, mid = %d, end = %d\n", start, mid, end);
	for(k = 0; k < n; k++)printf("%d ", x[k]);
	printf("\n");
}

void merge_sort_process(int x[], int start, int mid, int end, int n)
{
	int k;

	printf("merge_sort_pro\n");
	printf("start = %d, mid = %d, end = %d\n", start, mid, end);
	for(k = 0; k < n; k++)printf("%d ", x[k]);
	printf("\n");
}

void merge_array(int x[], int start, int end, int n)
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

	merge_array_process(x, start, mid, end, n);
}

void merge_sort(int a[], int start, int end, int n)
{
	int mid;

	if(start >= end)return;

	mid = (start + end) / 2;

	merge_sort(a, start, mid, n);
	merge_sort(a, mid + 1, end, n);

	merge_array(a, start, end, n);

	merge_sort_process(a, start, mid, end, n);
}

main(int argc, char *argv[])
{
	int i, x[100], n;

	n = atoi(argv[1]);
	for(i = 0; i < n; i++)scanf("%d", &x[i]);

	merge_sort(x, 0, n - 1, n);

	printf("sort\n");
	for(i = 0; i < n; i++){
		printf("%d\n", x[i]);
	}

	return 0;
}
