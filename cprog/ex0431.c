#include<stdio.h>

int main(void)
{
  int no;
  do
  {
    printf("正の整数を入力せよ:");
    scanf("%d",&no);
  }while(no<=0);
  printf("入力された値は%dです。\n",no);
  return 0;
}
