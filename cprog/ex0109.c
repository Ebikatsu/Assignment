/*
  読み込んだ整数値から10を減じた値を表示
*/

#include<stdio.h>

int main(void)
{
  int no;
  printf("整数を入力してください:");
  scanf("%d",&no);
  printf("その数から10を減じると%dです。\n",no-10);
  return 0;
}
