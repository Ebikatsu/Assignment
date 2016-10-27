/*
  読み込んだ整数値を0までカウントダウン
*/

#include<stdio.h>

int main(void)
{
  int no;

  printf("整数を入力してください。:");
  scanf("%d",&no);

  if(no>=0)
    {
      while(no>=0)
	{
	  printf("%d",no);
	  no--;//noの値をデクリメントする(一つ減らす)
	}
      putchar('\n');//改行
    }
  return 0;
}
