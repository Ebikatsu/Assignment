#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

int min(int *data, size_t length);

int main(int argc, char **argv)
{
	int *data = (int*)malloc((size_t)argc * sizeof(int));
	int i;
	for(i = 0; i < argc; i++)data[i] = atoi(argv[i]);
	printf("%d\n", min(data, (size_t)argc));
	free(data);
	return EXIT_SUCCESS;
}

int min(int *data, size_t length)
{
	int result = INT_MAX;
	size_t i;
	for(i = 0; i < length; i ++)if(result > data[i])result = data[i];
	return result;
}
