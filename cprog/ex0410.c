/*
  読み込んだ正の整数値まで1からカウントアップ
*/

#include<stdio.h>

int main(void)
{
  int no;

  printf("正の整数を入力してください:");
  scanf("%d",&no);

  if(no>0)
    {
      int i=1;
      while(i<=no)printf("%d",i++);//iの値を表示した後にインクリメント
      putchar('\n');
    }
  return 0;
}
