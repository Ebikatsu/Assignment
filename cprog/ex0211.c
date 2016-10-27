/*
  二つの整数値を読み込んで前者が後者の何%であるかを実数で表示
*/

#include<stdio.h>

int main(void)
{
  int na,nb;

  puts("二つの整数を入力してください。");
  printf("整数A:"); scanf("%d",&na);
  printf("整数B:"); scanf("%d",&nb);

  printf("Aの値はBの%f%%です。\n",100*(double)na/nb);

  return 0;
}
