/*
  入力に出現する数字をカウントして縦向きの棒グラフで表示
*/

#include<stdio.h>

int main(void)
{
  int i,j,ch;
  int cnt_max=0;/*出現回数の最大値*/
  int cnt[10]={0};/*数字文字の出現回数*/

  while(1){
    ch=getchar();
    if(ch==EOF)break;

    if(ch>='0'&&ch<='9')
      cnt[ch-'0']++;
  }

  for(i=0;i<10;i++)
    if(cnt[i]>cnt_max)
      cnt_max=cnt[i];

  puts("数字文字の出現回数\n");
  for(i=cnt_max;i>=1;i--){
    for(j=0;j<10;j++)
      if(cnt[j]>=i)
	printf(" * ");
      else
	printf("   ");
    putchar('\n');
  }
  for(j=0;j<10;j++)
    printf(" %d ",j);
  putchar('\n');
  return(0);
}
