#include<stdio.h>
#include<stdlib.h>

int x[100], size = 0;

void push(int y)
{
	x[size] = y;
	size++;
}

int pop(void)
{
	int data;

	if(size == 0) return -1;

	data = x[size-1];
	size--;

	return data;
}

main(int argc, char *argv[])
{
	int i, val, n;

	n = atoi(argv[1]);
	for(i = 0; i < n; i++){
		scanf("%d", &val);
		push(val);
	}

	printf("stack\n");
	for(i = 0; i < n; i++){
		val = pop();
		printf("%d\n", val);
	}

	return 0;
}
