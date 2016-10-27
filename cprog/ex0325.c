#include<stdio.h>

int main(void)
{
  int num;

  printf("整数を入力してください。:");
  scanf("%d",&num);

  if(num>0)puts("その数は正です。");
  else if(num==0)puts("その数は0です。");
  else puts("その数は負です。");
  return 0;
}
