#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int x[MAX],head = 0, tail = 0, size = 0;

void enqueue(int y)
{
	if(size < MAX){
		x[tail] = y;
		tail++;
		if(tail == MAX) tail = 0;
		size++;
	}
}

int dequeue(void)
{
	int data;

	if(size == 0) return -1;

	data = x[head];
	head++;
	if(head == MAX) head = 0;

	return data;
}

main(int argc, char *argv[])
{
	int i, val, n;

	n = atoi(argv[1]);
	for(i = 0; i < n; i++){
		scanf("%d", &val);
		enqueue(val);
	}

	printf("queue\n");
	for(i = 0; i < n; i++){
		val = dequeue();
		printf("%d\n", val);
	}

	return 0;
}

