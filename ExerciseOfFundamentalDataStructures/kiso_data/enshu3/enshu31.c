#include<stdio.h>
#include<stdlib.h>

void swap(int *p, int *q);

int main(void)
{
	int x,y;
	printf("x = ? ");
	scanf("%d", &x);
	printf("y = ? ");
	scanf("%d", &y);
	swap(&x,&y);
	printf("変数xとyの内容を入れ替えた結果を出力します\n");
	printf("x = %d, y = %d です\n", x, y);
	return EXIT_SUCCESS;
}

void swap(int *p, int *q)
{
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}
