#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n;//人数
	int i;//ループ
	double height[10];//身長
	double average = 0;//身長の平均
	printf("人数を入力してください>>>");
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		printf("身長を入力してください>>>");
		scanf("%lf",height+i);
		average += height[i];
	}
	average /= n;
	printf("身長の平均は%f[cm]です\n",average);
	return EXIT_SUCCESS;
}

