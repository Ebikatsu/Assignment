/*
  長方形を横に並べて表示
*/

#include<stdio.h>

int main(void)
{
  int i,j,n;
  int num;
  int width,height;
  puts("長方形を作りましょう。");
  printf("横幅:");scanf("%d",&width);
  printf("高さ:");scanf("%d",&height);
  printf("個数:");scanf("%d",&num);
  for(i=1;i<=height;i++){
    for(n=1;n<=num;n++){
      for(j=1;j<=width;j++)
	putchar('*');
      if(n<num)
	putchar(' ');
    }
    putchar('\n');
  }
  return 0;
}
