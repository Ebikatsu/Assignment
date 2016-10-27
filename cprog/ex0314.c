/*
  読み込んだ三つの整数値に同じ値がいくつあるかを表示
*/

#include<stdio.h>

int main(void)
{
  int na,nb,nc;

  puts("三つの整数を入力してください。");
  printf("整数A:");scanf("%d",&na);
  printf("整数B:");scanf("%d",&nb);
  printf("整数C:");scanf("%d",&nc);

  if(na==nb&&nb==nc)puts("三つの値は等しいです。");
  else if(na==nb||nb==nc||na==nc)puts("二つの値が等しいです。");
  else puts("三つの値は異なります。");

  return 0;
}
