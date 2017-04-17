#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int i,j;//ループ
	int min_element;
	double data[10];
	double min;
	printf("データを10個入力してください>>>");
	scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", data, data + 1, data + 2, data + 3, data + 4, data + 5, data + 6, data + 7, data + 8, data + 9);
	for(i = 0; i < sizeof(data)/sizeof(double); i++)
	{
		min = data[i];
		min_element = i;
		for(j = i; j < sizeof(data)/sizeof(double); j++)if(min > data[j])
			{
				min = data[j];
				min_element = j;
			}
		data[min_element] = data[i];
		data[i] = min;
	}
	printf("ソート結果です。");
	for(i = 0; i < sizeof(data)/sizeof(double); i++)printf(" %f",data[i]);
	printf("\n");
	return EXIT_SUCCESS;
}

