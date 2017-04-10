#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int a;
	printf("1以上の整数を1つ入力して下さい>>>");
	scanf("%d",&a);
	while(a > 0)
	{
		printf("%d\n",a);
		a /= 10;
	}
	return EXIT_SUCCESS;
}

