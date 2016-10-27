#include<stdio.h>

int main(void)
{
  int no;
  printf("整数を入力してください。:");
  scanf("%d",&no);
  if(no*no<=13)puts("その値は13の平方根以下です。");
  return 0;
}
