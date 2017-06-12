#include<stdio.h>
#include<stdlib.h>

int divide_array(int x[], int start, int end)
{
	int i, j, tmp;

	i = start;
	j = end - 1;
	while(1){
		while(x[i] < x[end])i++;
		while(x[j] > x[end] && j > i)j--;
		if(i >= j)break;

		tmp = x[i];
		x[i] = x[j];
		x[j] = tmp;
		i++;
		j--;
	}
	tmp = x[i];
	x[i] = x[end];
	x[end] = tmp;

	return i;
}

void quick_sort_process(int a[], int start, int end, int n)
{
	int s, i;

	if(start >= end)return;

	for(i = 0; i < n; i++)printf("%2d", a[i]);
	printf("\n");

	s = divide_array(a, start, end);

	printf("s = %d\n", s);

	quick_sort_process(a, start, s - 1, n);
	quick_sort_process(a, s + 1, end, n);
}

main(int argc, char *argv[])
{
	int i, x[100], n;

	n = atoi(argv[1]);
	for(i = 0; i < n; i++)scanf("%d", &x[i]);

	printf("quick_sort\n");

	quick_sort_process(x, 0, n - 1, n);

	printf("sort\n");
	for(i = 0; i < n; i++){
		printf("%d\n", x[i]);
	}

	return 0;
}
