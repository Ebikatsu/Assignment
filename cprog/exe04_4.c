#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y);

int main(void){
  int x = 10;
  int y = 20;

  printf("main : x=%d, y=%d\n", x, y);
  swap(&x, &y);
  printf("main : x=%d, y=%d\n", x, y);

  /* (A) swap関数によって,変数xと変数yの入れ替えが実現しない理由を述べよ. */
  //main関数のxとyのアドレスと、swap関数内で処理される時のxとyは、アドレスが異なるから。

  return EXIT_SUCCESS;
}

void swap(int *x, int *y){
  int tmp;

  printf("func : x=%d, y=%d\n", *x, *y);
  tmp = *x;
  *x = *y;
  *y = tmp;
  printf("func : x=%d, y=%d\n", *x, *y);
}
