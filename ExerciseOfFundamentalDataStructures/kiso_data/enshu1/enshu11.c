#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int a;
	printf("0以上の整数を入力してください。");
	scanf("%d",&a);
	if(a%2)printf("入力された0以上の整数は奇数です。\n");
	else printf("入力された0以上の整数は偶数です。\n");
	return EXIT_SUCCESS;
}
