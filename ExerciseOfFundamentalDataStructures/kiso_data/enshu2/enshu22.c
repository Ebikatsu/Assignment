#include<stdio.h>
#include<stdlib.h>

double diff(double a, double b);

int main(void)
{
	double a,b;
	printf("double型の値を2つ入力してください>>>");
	scanf("%lf %lf", &a, &b);
	printf("2つの値の差は;%fです\n",diff(a,b));
	return EXIT_SUCCESS;
}

double diff(double a, double b)
{
	return a - b;
}

