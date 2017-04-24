#include<stdio.h>
#include<stdlib.h>

typedef struct grade
{
	char *name;
	int subject1;
	int subject2;
	int subject3;
	double average;
} SMITH; //構造体の新しい型名

//プロトタイプ宣言
void average_of_score(SMITH *h_p);

int main(void)
{
	SMITH Smith;
	Smith.name = "John Smith";
	Smith.subject1 = 90;
	Smith.subject2 = 80;
	Smith.subject3 = 35;

	average_of_score(&Smith);//関数呼び出し
	//構造体変数のポインタのアドレスを求めるには、構造体変数名に&を作用させればよい。

	printf("name: %s\n", Smith.name);
	printf("科目1: %d, 科目2: %d, 科目3: %d\n", Smith.subject1, Smith.subject2, Smith.subject3);
	printf("平均: %lf\n", Smith.average);
	return EXIT_SUCCESS;
}

void average_of_score(SMITH *h_p)
{
	h_p->average = (h_p->subject1 + h_p->subject2 + h_p->subject3) / 3.0;
	//ポインタを使用してメンバを指定するには、アロー演算子(->)を使う
}
