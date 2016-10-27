#include<stdio.h>

int main(void)
{
  int i,no;
  printf("+を何個表示させますか。:");
  scanf("%d",&no);
  i=1;
  while(i<=no)
  {
    i++;
    putchar('+');
  }
  putchar('\n');
  return 0;
}
