/*
  読み込んだ整数値はゼロか否か
*/

#include<stdio.h>

int main(void)
{
  int no;

  printf("整数を入力してください:");
  scanf("%d",&no);

  if(no)puts("ゼロ以外の数を入力しましたね。");
  else puts("ゼロを入力しましたね。");

  return 0;
}
