/*
  読み込んだ点数の成績評価を行う。
*/

#include<stdio.h>

int main(void)
{
  int ten;

  printf("点数を入力してください。:");
  scanf("%d",&ten);

  if(ten>=0&&ten<60)puts("評価は不可です。");
  else if(ten>=60&&ten<70)puts("評価は可です。");
  else if(ten>=70&&ten<80)puts("評価は良です。");
  else if(ten>=80&&ten<100)puts("評価は優です。");
  else puts("評価できません。");

  return 0;
}
