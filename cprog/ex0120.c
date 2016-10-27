#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int c1,c2,c3;

  printf("三つの整数を入力してください。\n");
  printf("一番目:");
  scanf("%d",&c1);
  printf("二番目:");
  scanf("%d",&c2);
  printf("三番目:");
  scanf("%d",&c3);
  printf("それらを掛け合わせた値は、%dです。\n",c1*c2*c3);
  return EXIT_SUCCESS;
}
