#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int a,b,c,min;
	printf("3つの整数を入力してください:");
	scanf("%d %d %d",&a,&b,&c);
	min = a;
	if(min > b)min = b;
	if(min > c)min = c;
	printf("最小値は:%d",min);
	return EXIT_SUCCESS;
}

