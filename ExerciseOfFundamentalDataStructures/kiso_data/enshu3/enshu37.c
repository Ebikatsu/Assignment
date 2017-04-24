#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	struct grade
	{
		char name[15];
		int subject1;
		int subject2;
		int subject3;
	} student[4];
	
	int i;
	int total1, total2, total3;
	double average1, average2, average3;
	double ndata = 4;

	//配列の初期化
	strcpy(student[0].name, "John Smith");
	student[0].subject1 = 90;
	student[0].subject2 = 80;
	student[0].subject3 = 35;

	strcpy(student[1].name, "Thomas Henry");
	student[1].subject1 = 70;
	student[1].subject2 = 50;
	student[1].subject3 = 65;

	strcpy(student[2].name, "Mike Bush");
	student[2].subject1 = 35;
	student[2].subject2 = 90;
	student[2].subject3 = 65;

	strcpy(student[3].name, "Merry White");
	student[3].subject1 = 70;
	student[3].subject2 = 65;
	student[3].subject3 = 80;

	//科目毎に4名の学生の点数の平均点を計算
	total1 = 0;
	total2 = 0;
	total3 = 0;
	for(i = 0; i < ndata; i++)
	{
		total1 += student[i].subject1;
		total2 += student[i].subject2;
		total3 += student[i].subject3;
	}

	average1 = total1 / ndata;
	average2 = total2 / ndata;
	average3 = total3 / ndata;

	printf("科目の平均点:\n");
	printf("科目1:%7.2lf, 科目2:%7.2lf, 科目3:%7.2lf\n", average1, average2, average3);



	return EXIT_SUCCESS;
}

