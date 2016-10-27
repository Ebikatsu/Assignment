/*
  入力に出現する数字をカウントして表示
*/

#include<stdio.h>

int main(void)
{
  int i,ch;
  int cnt[10]={0};/*数字文字の出現回数(全ての要素を0で初期化)*/

  while(1){/*無限ループ*/
    ch=getchar();
    if(ch==EOF)break;

    if(ch>='0'&&ch<='9')
      cnt[ch-'0']++;
  }

  puts("数字文字の出現回数");
  for(i=0;i<10;i++)
    printf("'%d':%d\n",i,cnt[i]);
  return(0);
}
