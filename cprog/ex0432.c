#include<stdio.h>

int main(void)
{
  int i=0;
  int sum=0;
  int no;
  puts("整数を入力してください。");
  do
  {
    printf("No.%d:",++i);
    scanf("%d",&no);
    if(no>=0)sum+=no*no;
  }while(no>=0);
  printf("二乗値の合計は%dです。\n",sum);
  return 0;
}
