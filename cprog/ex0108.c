/*
  読み込んだ整数値に10を加えた値を表示
*/

#include<stdio.h>

int main(void)
{
  int no;
  printf("整数を入力してください:");
  scanf("%d",&no);
  printf("その数に10を加えると%dです。\n",no+10);
  return 0;
}
