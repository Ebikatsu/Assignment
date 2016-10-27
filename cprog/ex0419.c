/*
  1から50までの整数を各行に5個ずつ表示
*/

#include<stdio.h>

int main(void)
{
  int i,j;

  for(i=0;i<10;i++)
    {
      for(j=1;j<=5;j++)printf("%3d",i*5+j);
      putchar('\n');
    }
  return 0;
}
