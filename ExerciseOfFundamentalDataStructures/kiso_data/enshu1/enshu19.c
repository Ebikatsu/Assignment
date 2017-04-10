#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int a;
	printf("1以上の整数を1つ入力して下さい>>>");
	scanf("%d",&a);
	while(a > 0)
	{
		int b = 1;
		printf("%d\n",a);
		while(b < a)b *= 10;
		b /= 10;
		a %= b;
	}
	return EXIT_SUCCESS;
}

