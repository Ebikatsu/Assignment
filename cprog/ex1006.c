/*
  三つの整数を昇順に並べかえる
*/

#include <stdio.h>

/*--- nx・nyが指すオブジェクトの値を交換 ---*/
void swap(int *nx, int *ny)
{
  int temp = *nx;
  *nx = *ny;
  *ny = temp;
}

/*--- *n1≦*n2≦*n3となるように並べ替える ---*/
void sort3(int *n1, int *n2, int *n3)
{
  if(*n1 > *n2) swap(n1, n2);
  if(*n2 > *n3) swap(n2, n3);
  if(*n1 > *n2) swap(n1, n2);
}

int main(void)
{
  int na, nb,nc;

  puts("三つの整数を入力して下さい。");
  printf("整数A:"); scanf("%d", &na);
  printf("整数B:"); scanf("%d", &nb);
  printf("整数C:"); scanf("%d", &nc);

  sort3(&na, &nb, &nc);

  printf("整数Aは%dです。\n", na);
  printf("整数Bは%dです。\n", nb);
  printf("整数Cは%dです。\n", nc);

  return (0);
}
