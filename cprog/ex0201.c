/*
  読み込んだ整数値と10との和・差・積・商・剰余を表示
*/

#include<stdio.h>

int main(void)
{
  int num;
  printf("整数を入力してください:");
  scanf("%d",&num);
  printf("10を加えると%dです。\n",num+10);     /*和*/
  printf("10を減じると%dです。\n",num-10);     /*差*/
  printf("10を乗じると%dです。\n",num*10);     /*積*/
  printf("10で除した商は%dです。\n",num/10);   /*商*/
  printf("10で除した剰余は%dです。\n",num%10); /*剰余*/
  return 0;
}
