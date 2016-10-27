/*
  読み込んだ値を1までカウントダウン
*/

#include<stdio.h>

int main(void)
{
  int no;

  printf("正の整数を入力してください。:");
  scanf("%d",&no);

  if(no>=1)
    {
      while(no>0)printf("%d",no--);//noの値を表示した後にデクリメント
      putchar('\n');
    }
  return 0;
}
