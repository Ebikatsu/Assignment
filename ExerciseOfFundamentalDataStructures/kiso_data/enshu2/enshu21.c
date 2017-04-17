#include<stdio.h>
#include<stdlib.h>

double sum(double a, double b);

int main(void)
{
	double a,b;
	printf("double型の値を2つ入力してください>>>");
	scanf("%lf %lf", &a, &b);
	printf("2つの値の和は;%fです\n",sum(a,b));
	return EXIT_SUCCESS;
}

double sum(double a, double b)
{
	return a + b;
}

