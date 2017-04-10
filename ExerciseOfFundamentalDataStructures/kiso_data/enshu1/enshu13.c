#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
	double a,b,c;
	double d;
	printf("ax^2+bx+c=0のabcを入力してください>>>");
	scanf("%lf %lf %lf", &a, &b, &c);
	d = b * b - 4 * a * c;
	printf("%f\n",d);
	if(d > 0.0)printf("解は%fと%fです。\n",(-b+sqrt(d))/(2*a),(-b-sqrt(d))/(2*a));
	if(d == 0.0)printf("解は重解となり%fです。\n",-b/(2*a));
	if(d < 0.0)printf("虚数解となるため、実数解はありません。\n");
	return EXIT_SUCCESS;
}

