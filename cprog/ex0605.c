/*
  読み込んだ整数値の四乗値を求める関数
*/

#include<stdio.h>

/*--- 二乗値を返す ---*/
int sqr(int x)
{
  return(x*x);
}

/*--- 四乗値を返す ---*/
int pow4(int x)
{
  return(sqr(sqr(x)));
}

int main(void)
{
  int no;
  printf("整数を入力してください:");
  scanf("%d",&no);
  printf("その数の四乗値は%dです。\n",pow4(no));
  return(0);
}
