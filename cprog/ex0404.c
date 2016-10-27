/*
  1から読み込んだ値までの整数を加えた値を表示
*/

#include<stdio.h>

int main(void)
{
  int no = 1;
  int sum = 0;
  int upr;

  printf("正の整数を入力してください:");
  scanf("%d",&upr);

  do {
    sum = sum + no;
    no = no + 1;
  } while(no <= upr);

  printf("1から%dまでを足した値は%dです。\n",upr,sum);

  return (0);
}
