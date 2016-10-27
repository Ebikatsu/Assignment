#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int no;
  printf("整数を入力してください。:");
  scanf("%d",&no);
  if(no)puts("非0");
  return EXIT_SUCCESS;
}
