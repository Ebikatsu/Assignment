#include<stdio.h>
#include<stdlib.h>

void diff2(double a, double b, double *diff);

int main(void)
{
	double a,b,diff;
	printf("double型の値を2つ入力してください>>>");
	scanf("%lf %lf", &a, &b);
	diff2(a,b,&diff);
	printf("2つの値の差は;%fです\n",diff);
	return EXIT_SUCCESS;
}

void diff2(double a, double b, double *diff)
{
	*diff = a - b;
	return;
}

