#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int na,nb;
  printf("二つの整数を入力してください。");

  printf("整数A:");
  scanf("%d",&na);
  printf("整数B;");
  scanf("%d",&nb);

  if(na==nb)
    printf("AとBは等しいです。");
  else if(na>nb)
    printf("AはBより大きいです。");
  else
    printf("AはBより小さいです。");
  return EXIT_SUCCESS;
}
