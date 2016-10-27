/*
  読み込んだ二つの整数値の積を求めて表示
*/

#include<stdio.h>

int main(void)
{
  int n1,n2;
  int seki; /*積*/
  puts("二つの整数値を値を入力して下さい。");
  printf("整数1:"); scanf("%d",&n1);
  printf("整数2:"); scanf("%d",&n2);
  seki=n1*n2; /*n1とn2の積をsekiに代入*/
  printf("それらの積は%dです。\n",seki); /*積を表示*/
  return 0;
}
