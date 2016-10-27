#include<stdio.h>

int main(void)
{
  double fa,fb;
  puts("二つの実数を入力してください。");
  printf("実数A:");scanf("%lf",&fa);
  printf("実数B:");scanf("%lf",&fb);
  printf("それらの平均は%.1fです。\n",(fa+fb)/2);
  return 0;
}
