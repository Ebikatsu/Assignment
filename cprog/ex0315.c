/*
  読み込んだ二つの整数値の差が11以上であるかどうか
*/

#include<stdio.h>

int main(void)
{
  int na,nb,diff;

  puts("二つの整数を入力してください。");
  printf("整数A:");scanf("%d",&na);
  printf("整数B:");scanf("%d",&nb);

  diff=na-nb;

  if(diff>10||diff<-10)puts("それらの値は11以上です。");
  else puts("それらの値は11以下です。");

  return 0;
}
