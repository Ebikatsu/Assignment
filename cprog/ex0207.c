/*
  読み込んだ実数値と0.1との和・差・積・商を表示
*/

#include<stdio.h>

int main(void)
{
  double num;
  printf("実数を入力してください:");
  scanf("%lf",&num);
  printf("0.1を加えると%fです。\n",num+0.1); /*和*/
  printf("0.1を減じると%fです。\n",num-0.1); /*差*/
  printf("0.1を乗じると%fです。\n",num*0.1); /*積*/
  printf("0.1で除すと%fです。\n",num/0.1);   /*商*/
  return 0;
}
