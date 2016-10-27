/*
  読み込んだ二つの整数値の大小関係を表示
*/

#include<stdio.h>

int main(void)
{
  int n1,n2;

  puts("二つの整数を入力してください。");
  printf("整数1:");scanf("%d",&n1);
  printf("整数2:");scanf("%d",&n2);

  if(n1==n2)
    {
      puts("二つの値は同じです。");
      printf("両方とも%dです。\n",n1);
    }
  else if(n1>n2)
    {
      printf("大きいほうの値は%dです。\n",n1);
      printf("小さいほうの値は%dです。\n",n2);
    }
  else
    {
      printf("大きいほうの値は%dです。\n",n2);
      printf("小さいほうの値は%dです。\n",n1);
    }

  return 0;
}
