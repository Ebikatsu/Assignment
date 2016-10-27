/*
  二つの整数の和・差・積を求める関数
*/

#include <stdio.h>

/*--- n1とn2の和・差・積をsum,diff,mulが指す変数に格納 ---*/
void sum_diff_mul(int n1, int n2, int *sum, int *diff, int *mul)
{
  *sum  = n1 + n2;
  *diff = (n1 > n2) ? n1 - n2 : n2 - n1;
  *mul  = n1 * n2;
}

int main(void)
{
  int na, nb;
  int wa, sa, seki;

  puts("二つの整数を入力してください。");
  printf("整数A:"); scanf("%d", &na);
  printf("整数B:"); scanf("%d", &nb);

  sum_diff_mul(na, nb, &wa, &sa, &seki);

  printf("和は%dです。\n差は%dです。\n積は%dです。\n", wa, sa, seki);

  return (0);
}
