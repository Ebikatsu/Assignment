#include<stdio.h>

int main(void)
{
  double x1,x2,diff;
  puts("二つの実数を入力してください。");
  printf("実数x1:");
  scanf("%lf",&x1);
  printf("実数x2:");
  scanf("%lf",&x2);
  diff=(x1>x2)?x1-x2:x2-x1;
  if(diff<1.0)puts("それらの差は1.0未満です。");
  else puts("それらの差は1.0以上です。");
  return 0;
}
