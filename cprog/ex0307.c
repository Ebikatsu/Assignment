/*
  読み込んだ二つの整数値を比較して大小関係を表示
*/

#include<stdio.h>

int main(void)
{
  int na,nb;

  puts("二つの整数を入力してください。");
  printf("整数A:");scanf("%d",&na);
  printf("整数B:");scanf("%d",&nb);

  if(na==nb)puts("AとBは等しいです。");
  else if(na>nb)puts("AはBより大きいです。");
  else puts("AはBより小さいです。");

  return 0;
}
