/*
  二つの整数の小さい方の値を返す関数
*/

#include<stdio.h>

/*--- 小さい方の値を返す ---*/
int minof(int x,int y)
{
  if (x<y)
    return (x);
  else
    return (y);
}

int main(void)
{
  int na,nb;
  puts("二つの整数を入力してください。");
  printf("整数1:"); scanf("%d",&na);
  printf("整数2:"); scanf("%d",&nb);
  printf("小さい方の値は%dです。\n",minof(na,nb));
  return (0);
}
