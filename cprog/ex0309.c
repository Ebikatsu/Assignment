/*
  読み込んだ四つの整数値の最大値を求めて表示
*/

#include<stdio.h>

int main(void)
{
  int n1,n2,n3,n4,max;

  puts("四つの整数値を入力してください。");
  printf("整数1:");scanf("%d",&n1);
  printf("整数2:");scanf("%d",&n2);
  printf("整数3:");scanf("%d",&n3);
  printf("整数4:");scanf("%d",&n4);

  max=n1;/*四つの整数値の最大値を求める*/
  if(n2>max)max=n2;
  if(n3>max)max=n3;
  if(n4>max)max=n4;

  printf("最大値は%dです。\n",max);

  return 0;
}
