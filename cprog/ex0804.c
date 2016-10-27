/*
  二つの値を交換する関数形式マクロ
*/

#include <stdio.h>

#define swap(type, x, y)  {type temp = x; x = y; y = temp;} 

int main(void)
{
  int na, nb;

  puts("二つの整数を入力せよ。");
  printf("整数A:"); scanf("%d", &na);
  printf("整数B:"); scanf("%d", &nb);

  swap(int, na, nb); /*整数値を交換*/
  puts("\nAとBの値を交換。");
  printf("整数A=%d\n", na);
  printf("整数B=%d\n",nb);

  return (0);
}
