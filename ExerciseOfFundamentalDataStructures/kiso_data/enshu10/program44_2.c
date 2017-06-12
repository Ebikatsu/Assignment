#include<stdio.h>
#include<stdlib.h>

void insert_sort_process(int x[], int n)
{
	int i, j, tmp;

	for(i = 1; i < n; i++){
		printf("i = %d;", i);
		for(j = i; j > 0; j--){
			if(x[j] < x[j - 1]){
				tmp = x[j];
				x[j] = x[j - 1];
				x[j - 1] = tmp;
			}
			else{
				break;
			}
		}
		for(j = 0; j < n; j++)printf("%2d", x[j]);
		printf("\n");
	}
}

main(int argc, char *argv[])
{
	int i, x[100], n;

	n = atoi(argv[1]);
	for(i = 0; i < n; i++)scanf("%d", &x[i]);

	insert_sort_process(x, n);

	printf("sort\n");
	for(i = 0; i < n; i++){
		printf("%d\n", x[i]);
	}

	return 0;
}
