#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ASCIIMAX (0x7f)

int main(void)
{
	int numbers[ASCIIMAX + 1];	//�܂��o�͂���Ă��Ȃ����̈ꗗ
	int i,j;	//���[�v�p
	srand((unsigned int)time(NULL));
	for(i = 0; i <= ASCIIMAX; i++)numbers[i] = i;//�z��̏�����
	for(i = 0; i <= ASCIIMAX; i++)
	{
		int number = rand() % (ASCIIMAX + 1 - i);//�o�͂��鐔���̔z���̈ʒu�𗐐��Ō��߂�B
		printf("%d\n",numbers[number]);//�������o�͂���
		for(j = number; j < ASCIIMAX - i; j++)numbers[j] = numbers[j + 1];//�o�͂��ꂽ��������̗v�f��S�ĂЂƂO�Ɉړ�������B
		numbers[ASCIIMAX - i] = 0;
	}
	return EXIT_SUCCESS;
}
