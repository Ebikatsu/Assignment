/*
  指定された回数だけ警告を発する関数
*/

#include<stdio.h>

/*--- 警告をno回発する ---*/
void alert(int no)
{
  while(no-->0)
    putchar('\a');
}

int main(void)
{
  int x;
  printf("整数を入力してください:");
  scanf("%d",&x);
  alert(x);
  return(0);
}
