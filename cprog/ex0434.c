#include<stdio.h>

int main(void)
{
  int i,no;
  printf("+を何個表示させますか。:");
  scanf("%d",&no);
  i=0;
  do
  {
    putchar('+');
    ++i;
  }while(i<no);
  putchar('\n');
  return 0;
}
