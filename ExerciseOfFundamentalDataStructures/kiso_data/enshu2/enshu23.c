#include<stdio.h>
#include<stdlib.h>

void sum2(double a, double b, double *sum);

int main(void)
{
	double a,b,sum;
	printf("double型の値を2つ入力してください>>>");
	scanf("%lf %lf", &a, &b);
	sum2(a,b,&sum);
	printf("2つの値の和は;%fです\n",sum);
	return EXIT_SUCCESS;
}

void sum2(double a, double b, double *sum)
{
	*sum = a + b;
	return;
}

