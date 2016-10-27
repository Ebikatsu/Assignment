/*
  読み込んだ整数の個数だけ*を縦に表示
*/

#include<stdio.h>

int main(void)
{
  int no;

  printf("正の整数を入力してください。:");
  scanf("%d",&no);

  while(no-->0) /*繰り返しはno回*/
    puts("*");  /**を表示して改行*/

  return 0;
}
