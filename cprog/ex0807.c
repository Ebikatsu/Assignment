/*
  階乗を求める関数(非再帰版)
*/

#include<stdio.h>

/*--- 階乗値を返す(非再帰版) ---*/
int fact(int n)
{
  int f=1;
  while(n>0)
    f*=n--;
  return(f);
}

int main(void)
{
  int num;

  printf("整数を入力してください。:");
  scanf("%d",&num);

  printf("その数の階乗は%dです。\n",fact(num));

  return(0);
}
