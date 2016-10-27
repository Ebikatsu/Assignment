/*
  整数を次々と読み込んで合計と平均を表示
*/

#include<stdio.h>

int main(void)
{
  int i = 0;
  int sum = 0; /*合計*/
  int no;

  puts("整数を入力してください。");
  do {
    printf("No.%d:",i++); /*インクリメントしてから表示*/
    scanf("%d",&no);
    if (no != 9999) /*9999は加算しない*/
      sum += no;
  } while(no != 9999); /*9999を読み込むと終了*/

  if (i > 1)
    printf("合計は%dで平均は%.2fです。\n", sum, (double)sum / (i - 1));

  return (0);
}
