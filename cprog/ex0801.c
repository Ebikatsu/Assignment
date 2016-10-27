/*
  二乗を求める関数形式マクロと三乗を求める関数形式マクロ
*/

#include <stdio.h>

#define sqr(x) ((x)*(x))
#define cub(x) ((x)*(x)*(x))

int main(void)
{
  int nx;
  double dx;

  printf("整数を入力してください:");
  scanf("%d", &nx);
  printf("その数の二乗は%dで三乗は%dです。\n", sqr(nx), cub(nx));

  printf("実数を入力してください。:");
  scanf("%lf", &dx);
  printf("その数の二乗は%fで\n三乗は%fです。\n", sqr(dx), cub(dx));

  return(0);
}
