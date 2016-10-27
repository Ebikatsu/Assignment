/*
  二つの整数を昇順に並べる
*/

#include <stdio.h>

/*--- nx・nyが指すオブジェクトの値を交換 ---*/
void swap(int *nx, int *ny)
{
  int temp = *nx;
  *nx = *ny;
  *ny = temp;
}

/*--- *n1≦*n2となるように並べる ---*/
void sort2(int *n1, int *n2)
{
  if(*n1>*n2)swap(n1,n2);
}

int main(void)
{
  int na, nb;

  puts("二つの整数を入力してください。");
  printf("整数A:"); scanf("%d", &na);
  printf("整数B:"); scanf("%d", &nb);

  sort2(&na, &nb);

  puts("これらの値を昇順に並べました。");
  printf("整数Aは%dです。\n", na);
  printf("整数Bは%dです。\n", nb);

  return (0);
}
