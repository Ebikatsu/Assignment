/*
  二つの整数の和を求める関数と差を求める関数
*/

#include<stdio.h>

/*--- 二つの整数を和を返す ---*/
int sum(int x,int y)
{
  return(x+y);
}

/*--- 二つの整数の差を返す ---*/
int diff(int x,int y)
{
  if(x>y)
    return(x-y);
  else
    return(y-x);
}

int main(void)
{
  int na,nb;
  puts("二つの整数を入力してください。");
  printf("整数A:");scanf("%d",&na);
  printf("整数B:");scanf("%d",&nb);
  printf("二つの整数の和は%dです。\n",sum(na,nb));
  printf("二つの整数の差は%dです。\n",diff(na,nb));
  return(0);
}
