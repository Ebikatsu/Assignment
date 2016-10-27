/*
  cmの単位で読み込んだ長さをインチに変換して表示
*/

#include<stdio.h>

int main(void)
{
  double cm;
  printf("長さをcmで入力して下さい:");
  scanf("%lf",&cm);
  printf("それは%fインチです。\n",cm/2.54);
  return 0;
}
