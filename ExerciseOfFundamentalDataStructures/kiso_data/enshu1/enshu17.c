#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int a,answer = 1;
	printf("0以上の整数nを入力してください>>>");
	scanf("%d",&a);
	if(a == 0)
	{
		printf("1\n");
		return EXIT_SUCCESS;
	}
	else do
	{
		answer *= a--;
	}while(a > 0);
	printf("%d\n",answer);
	return EXIT_SUCCESS;
} 
