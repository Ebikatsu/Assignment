/*
  二つの整数値を読み込んで小さい数から大きい数までの整数を加えた値を表示
*/

#include<stdio.h>

int main(void)
{
  int n1,n2,no;
  int upper,lower;
  int sum = 0;

  puts("二つの整数を入力してください。");
  printf("整数1:"); scanf("%d",&n1);
  printf("整数2:"); scanf("%d",&n2);

  if (n1 > n2) { /*n1～n2の合計を求める準備*/
    upper = n1;
    lower = n2;
  } else {       /*n2～n1の合計を求める準備*/
    upper = n2;
    lower = n1;
  }

  no = lower; /*lowerから*/
  do {
    sum = sum + no;
    no = no + 1;
  } while(no <= upper); /*upperまでの合計を求める。*/

  printf("%d以上%d以下の全整数の和は%dです。\n",lower,upper,sum);

  return (0);
}
