/*
  1から5までの和を求めて表示
*/

#include<stdio.h>

int main(void)
{
  int i;
  int sum = 0; /* 合計値 */

  for (i = 1; i <= 5; i++) /* iを1から5まで一つずつ増やしながら */
    sum += i;              /* sumにiを加える */

  printf("1から5までを足した値は%dです。\n",sum);

  return (0);
}
