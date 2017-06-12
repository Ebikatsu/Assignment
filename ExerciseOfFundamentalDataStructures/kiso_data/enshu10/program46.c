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

void quick_sort(int a[], int start, int end)
{
	int s;

	if(start >= end)return;

	s = divide_array(a, start, end);

	quick_sort(a, start, s - 1);
	quick_sort(a, s + 1, end);
}

main(int argc, char *argv[])
{
	int i, x[100], n;

	n = atoi(argv[1]);
	for(i = 0; i < n; i++)scanf("%d", &x[i]);

	quick_sort(x, 0, n - 1);

	printf("sort\n");
	for(i = 0; i < n; i++){
		printf("%d\n", x[i]);
	}

	return 0;
}
