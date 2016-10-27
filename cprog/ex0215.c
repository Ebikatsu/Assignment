#include<stdio.h>

int main(void)
{
  int no;
  printf("整数を入力してください:"); /*整数値の入力を促す。*/
  scanf("%d",&no);                 /*整数値を読み込む。*/
  printf("最も下の桁は%dです。\n",no%10);
  return 0;
}
