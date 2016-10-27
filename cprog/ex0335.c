#include<stdio.h>

int main(void)
{
  int no;
  printf("整数を入力してください。:");
  scanf("%d",&no);
  if(no>49)printf("★★★");
  else if(no>=20)printf("★★");
  else if(no>=0)printf("★");
  printf("\n");
  return 0;
}
