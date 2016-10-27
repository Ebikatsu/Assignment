/*
  長方形を描画
*/

#include<stdio.h>

int main(void)
{
  int i,j;
  int width,height;

  puts("長方形を作りましょう。");
  printf("横幅:");scanf("%d",&width);
  printf("高さ:");scanf("%d",&height);

  for(i=1;i<=height;i++){
    for(j=1;j<=width;j++)
      putchar('*');
    putchar('\n');
  }
  return 0;
}
