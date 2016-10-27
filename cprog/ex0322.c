#include<stdio.h>

int main(void)
{
  int a;
  printf("整数を入力してください。:");
  scanf("%d",&a);
  if((a>0)&&(a<10)&&(a%2))puts("その数は正の1桁の奇数です。");
  return 0;
}
