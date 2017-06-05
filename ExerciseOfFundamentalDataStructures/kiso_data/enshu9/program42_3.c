#include<stdio.h>
#include<stdlib.h>

/*
void select_sort(int *x, int n)
{
	int i, j, index, tmp;
	for(i = 0; i < n - 1; i++)
	{
		index = i;
		for(j = i + 1; j < n; j++)if(x[index] > x[j])index = j;
		tmp = x[i];
		x[i] = x[index];
		x[index] = tmp;
	}
}
*/

int cmp, swp;

void select_sort_process(int *x, int n,  int i)
{
	int k;
	printf("i = %d; \n", i);
	for(k = 0; k < n; k++)printf("%d ", x[k]);
	printf("\n");
}

void select_sort(int *x, int n)
{
	int i, j, low_index, low_data, tmp;
	for(i = 0; i < n - 1; i++)
	{
		low_data = x[i];
		low_index = i;
		for(j = i + 1; j < n; j++)
		{
			cmp++;
			if(low_data > x[j])
			{
				low_data = x[j];
				low_index = j;
			}
		}
		swp++;
		tmp = x[i];
		x[i] = x[low_index];
		x[low_index] = tmp;
		select_sort_process(x, n, i);
	}
}

int main(int argc, char *argv[])
{
	int i, x[100], n;
	cmp = 0;
	swp = 0;
	n = atoi(argv[1]);
	for(i = 0; i < n; i++)scanf("%d", x+i);
	select_sort(x, n);
	printf("sort\n");
	for(i = 0; i < n; i++)printf("%d\n",x[i]);
	printf("cmp:%d\n", cmp);
	printf("swp:%d\n", swp);
	return EXIT_SUCCESS;	
}
