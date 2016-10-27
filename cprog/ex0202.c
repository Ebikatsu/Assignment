/*
  読み込んだ整数を5で割った商と剰余を表示
*/

#include<stdio.h>

int main(void)
{
  int no;
  printf("noの値を入力してください:"); /*整数値の入力を促す*/
  scanf("%d",&no);                   /*整数値を読み込む*/
  printf("no/5は%dです。\n",no/5);    /*5で割った商を表示*/
  printf("no%%5は%dです。\n",no%5);  /*5で割った剰余を表示*/
  return 0;
}
