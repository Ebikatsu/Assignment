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

void select_sort(int *x, int n)
{
	int i, j, low_index, low_data, tmp;
	for(i = 0; i < n - 1; i++)
	{
		low_data = x[i];
		low_index = i;
		for(j = i + 1; j < n; j++)if(low_data > x[j])
		{
			low_data = x[j];
			low_index = j;
		}
		tmp = x[i];
		x[i] = x[low_index];
		x[low_index] = tmp;
	}
}

int main(int argc, char *argv[])
{
	int i, x[100], n;
	n = atoi(argv[1]);
	for(i = 0; i < n; i++)scanf("%d", x+i);
	select_sort(x, n);
	printf("sort\n");
	for(i = 0; i < n; i++)printf("%d\n",x[i]);
	return EXIT_SUCCESS;	
}
