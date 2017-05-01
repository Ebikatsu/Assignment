#include<stdio.h>

main()
{
	int a, b, t = 1;

	scanf("%d %d", &a, &b);

	if(a < b){
		t=a;
		a=b;
		b=t;
	}

	while(t != 0){
		t = a % b;
		a = b;
		b = t;
	}
	printf("GCD = %d\n", a);

	return 0;
}
