/*
  任意の文字を連続表示する関数を利用して平行四辺形を表示
*/

#include<stdio.h>

/*--- 文字chをno個連続表示 ---*/
void put_nchar(int ch,int no)
{
  while(no-->0)
    putchar(ch);
}

int main(void)
{
  int i;
  int width,height;

  puts("平行四辺形を作りましょう。");
  printf("横幅:");scanf("%d",&width);
  printf("高さ:");scanf("%d",&height);
  for(i=1;i<=height;i++){
    put_nchar(' ',height-i);
    put_nchar('+',width);
    putchar('\n');
  }
  return(0);
}
