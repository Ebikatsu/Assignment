/*
  入力に現れた改行の数を表示する
*/

#include<stdio.h>

int main(void)
{
  int ch;
  int n_count=0;/*改行文字の数*/

  while((ch=getchar())!=EOF)
    if(ch=='\n')
      n_count++;

  printf("行数:%d\n",n_count);

  return(0);
}
