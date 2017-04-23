#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ASCIIMAX (0x7f)

int main(void)
{
	int numbers[ASCIIMAX + 1];	//まだ出力されていない数の一覧
	int i,j;	//ループ用
	srand((unsigned int)time(NULL));
	for(i = 0; i <= ASCIIMAX; i++)numbers[i] = i;
	for(i = 0; i <= ASCIIMAX; i++)
	{
		int number = rand() % (ASCIIMAX + 1 - i);//出力する数字
		printf("%d\n",numbers[number]);
		for(j = number; j < ASCIIMAX - i; j++)numbers[j] = numbers[j + 1];
		numbers[ASCIIMAX - i] = 0;
	}
	return EXIT_SUCCESS;
}
