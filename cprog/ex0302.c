/*
  二つの整数値AとBを読み込んでBがAの約数かどうかを調べる
*/

#include<stdio.h>

int main(void)
{
  int na,nb;
 
  puts("二つの整数を入力してください。");
  printf("整数A:");scanf("%d",&na);
  printf("整数B:");scanf("%d",&nb);

  if(na%nb)puts("BはAの約数ではありません。");
  else puts("BはAの約数です。");
  return 0;
}
