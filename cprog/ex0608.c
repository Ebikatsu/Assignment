/*
 *を連続表示する関数を利用して長方形を表示
*/

#include<stdio.h>

/*--- *をno個連続表示 ---*/
void put_stars(int no)
{
  while(no-->0)
    putchar('*');
}

int main(void)
{
  int i;
  int width,height;
  puts("長方形を作りましょう。");
  printf("横幅:");scanf("%d",&width);
  printf("高さ:");scanf("%d",&height);
  for(i=1;i<=height;i++){
    put_stars(width);
    putchar('\n');
  }
  return(0);
}
