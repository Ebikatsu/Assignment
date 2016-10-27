/*
  直角三角形(右上が直角)を表示
*/

#include<stdio.h>

int main(void)
{
  int i,j,ln;
  printf("何段ですか:");
  scanf("%d",&ln);
  for(i=ln;i>=1;i--){
    for(j=1;j<=ln-i;j++)
      putchar(' ');
    for(j=1;j<=i;j++)
      putchar('*');
    putchar('\n');
  }
  return 0;
}
