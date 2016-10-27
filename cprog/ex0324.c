#include<stdio.h>

int main(void)
{
  int a,c;
  printf("整数を入力してください。:");
  scanf("%d",&a);
  c=a%10;
  if(c==3||c==7)puts("その数の一番下の桁の値は3あるいは7です。");
  return 0;
}
