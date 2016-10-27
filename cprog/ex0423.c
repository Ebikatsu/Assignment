/*
  直角三角形(左下が直角)を表示
*/

#include<stdio.h>

int main(void)
{
  int i,j,ln;
  printf("何段ですか:");
  scanf("%d",&ln);
  for(i=1;i<=ln;i++){
    for(j=1;j<=i;j++)
      putchar('*');
    putchar('\n');
  }
  return 0;
}
