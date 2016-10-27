/*
  読み込んだ二つの整数値の差を求めて表示(if文)
*/

#include<stdio.h>

int main(void)
{
  int n1,n2,diff;

  puts("二つの整数を入力してください。");
  printf("整数1:");scanf("%d",&n1);
  printf("整数2:");scanf("%d",&n2);

  if(n1>n2)diff=n1-n2;/*差を求める*/
  else diff=n2-n1;

  printf("それらの差は%dです。\n",diff);

  return 0;
}
