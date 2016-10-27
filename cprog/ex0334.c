#include<stdio.h>

int main(void)
{
  int c1,c2,c3,min;
  puts("三つの整数を入力してください。");
  printf("整数c1:");
  scanf("%d",&c1);
  printf("整数c2:");
  scanf("%d",&c2);
  printf("整数c3:");
  scanf("%d",&c3);
  min=c3;
  if(min>c2)min=c2;
  if(min>c1)min=c1;
  printf("最小値は%dです。\n",min);
  return 0;
}
