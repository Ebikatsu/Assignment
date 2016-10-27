/*
  読み込んだ実数値をそのまま表示
*/

#include<stdio.h>

int main(void)
{
  double no;
  printf("実数を入力してください:");
  scanf("%lf",&no);
  printf("あなたは%fと入力しましたね。\n",no);
  return 0;
}
