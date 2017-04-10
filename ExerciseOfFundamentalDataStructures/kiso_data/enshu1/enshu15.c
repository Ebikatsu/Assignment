#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int a,answer = 1;
	printf("0以上の整数nを入力してください>>>");
	scanf("%d",&a);
	while(a > 0)answer *= a--;
	printf("%d\n",answer);
	return EXIT_SUCCESS;
}

