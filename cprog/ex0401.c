/*
  読み込んだ整数値は10で割りきれるか(好きなだけ繰り返す)
*/

#include<stdio.h>

int main(void)
{
  int cont;//処理を続けるか
  do
    {
      int no;
      printf("整数を入力してください。:");
      scanf("%d",&no);
      if(no%10)puts("その数は10で割り切れません。");
      else puts("その数は10で割り切れます。");
      printf("もう一度?【Yes…0/no…9】:");
      scanf("%d",&cont);
    }while(cont==0);
  return 0;
}
