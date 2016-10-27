/*
  二つの整数値を読み込んで前者が後者の何%であるかを表示
*/

#include<stdio.h>

int main(void)
{
  int na,nb;
  puts("二つの整数を入力してください。");
  printf("整数A:"); scanf("%d",&na);
  printf("整数B:"); scanf("%d",&nb);
  printf("Aの値はBの%d%%です。\n",100*na/nb);
  return 0;
}
