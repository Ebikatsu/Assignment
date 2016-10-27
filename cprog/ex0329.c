#include<stdio.h>

int main(void)
{
  int n1,n2;
  puts("二つの整数を入力してください。");
  printf("整数n1:");
  scanf("%d",&n1);
  printf("整数n2:");
  scanf("%d",&n2);
  if(n2%n1)puts("n1はn2の約数ではありません。");
  else puts("n1はn2の約数です。");
  return 0;
}
