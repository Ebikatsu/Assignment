#include<stdio.h>

int main(void)
{
  int no;
  printf("整数を入力してください。:");
  scanf("%d",&no);
  switch(no)
    {
    case 3:printf("A");
    case 2:printf("B");break;
    default:printf("C");break;
    }
  printf("\n");
  return 0;
}
