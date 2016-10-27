/*
  階乗を求める関数(再帰版)
*/

#include<stdio.h>

/*--- 階乗値を返す(再帰版) ---*/
int factorial(int n)
{
  return(n>0?n*factorial(n-1):1);
}

int main(void)
{
  int num;

  printf("整数を入力してください:");
  scanf("%d",&num);

  printf("その数の階乗は%dです。\n",factorial(num));

  return(0);
}
