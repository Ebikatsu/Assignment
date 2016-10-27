/*
  等価演算子及び関係演算子が生成する値を表示
*/

#include<stdio.h>

int main(void)
{
  int na,nb;

  puts("二つの整数を入力してください。");
  printf("整数A:");scanf("%d",&na);
  printf("整数B:");scanf("%d",&nb);

  printf("A==B=%d\n",na==nb);
  printf("A!=B=%d\n",na!=nb);
  printf("A<B=%d\n",na<nb);
  printf("A>B=%d\n",na>nb);
  printf("A<=B=%d\n",na<=nb);
  printf("A>=B=%d\n",na>=nb);

  return 0;
}
