/*
  二つの整数値を読み込んでそれらの平均値の符号を反転した値を表示
*/

#include<stdio.h>

int main(void)
{
  int na,nb;
  int ave;
  puts("二つの整数を入力してください。");
  printf("整数A:"); scanf("%d",&na);
  printf("整数B:"); scanf("%d",&nb);
  ave=(na+nb)/2;
  printf("平均値の符号を反転した値は%dです。\n",-ave);
  return 0;
}
