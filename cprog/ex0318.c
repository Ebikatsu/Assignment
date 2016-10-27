/*
  読み込んだ月の季節を表示
*/

#include<stdio.h>

int main(void)
{
  int month;

  printf("何月ですか:");
  scanf("%d",&month);

  if(month>=3&&month<=5)puts("春です。");
  else if(month>=6&&month<=8)puts("夏です。");
  else if(month>=9&&month<=11)puts("秋です。");
  else if(month==1||month==2||month==12)puts("冬です。");
  else puts("そんな月はありませんよ!!\a");

  return 0;
}
