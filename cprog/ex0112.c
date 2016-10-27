/*
  読み込んだ三つの整数値の和を求めて表示
*/

#include<stdio.h>

int main(void)
{
  int n1,n2,n3;
  puts("三つの整数を入力してください。");
  printf("整数1:"); scanf("%d",&n1);
  printf("整数2:"); scanf("%d",&n2);
  printf("整数3:"); scanf("%d",&n3);
  printf("それらの和は%dです。\n",n1+n2+n3); /*和を表示*/
  return 0;
}
