#include<stdio.h>

int main(void)
{
  int i,no;
  printf("何個表示しますか:");
  scanf("%d",&no);
  for(i=0;i<=no-1;i++)printf("温故知新");
  putchar('\n');
  return 0;
}
