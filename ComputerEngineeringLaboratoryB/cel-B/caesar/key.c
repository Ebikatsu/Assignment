#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ASCIIMAX (0x7f)

int main(void)
{
	int numbers[ASCIIMAX + 1];	//まだ出力されていない数の一覧
	int i,j;	//ループ用
	srand((unsigned int)time(NULL));
	for(i = 0; i <= ASCIIMAX; i++)numbers[i] = i;//配列の初期化
	for(i = 0; i <= ASCIIMAX; i++)
	{
		int number = rand() % (ASCIIMAX + 1 - i);//出力する数字の配列上の位置を乱数で決める。
		printf("%d\n",numbers[number]);//数字を出力する
		for(j = number; j < ASCIIMAX - i; j++)numbers[j] = numbers[j + 1];//出力された数字より後の要素を全てひとつ前に移動させる。
		numbers[ASCIIMAX - i] = 0;
	}
	return EXIT_SUCCESS;
}
