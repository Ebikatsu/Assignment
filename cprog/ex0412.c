/*
  読み込んだ正の整数値以下の2のべき乗の値を昇順に表示
*/

#include<stdio.h>

int main(void)
{
  int i,no;

  printf("整数を入力してください。:");
  scanf("%d",&no);

  i=2;//2から始める
  while(i<=no)
    {
      printf("%d",i);
      i*=2;//2を掛ける
    }
  putchar('\n');

  return 0;
}
