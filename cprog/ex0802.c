/*
  二つの値の差を求める関数形式マクロ
*/

#include <stdio.h>

#define diff(x, y) ((x) > (y) ? ((x) - (y)) : ((y) - (x)))

int main(void)
{
  int n1,n2;

  puts("二つの値を入力してください。");
  printf("整数1:"); scanf("%d", &n1);
  printf("整数2:"); scanf("%d", &n2);

  printf("それらの値は%dです。\n", diff(n1, n2));

  return (0);
}
