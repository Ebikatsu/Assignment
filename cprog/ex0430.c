#include<stdio.h>

int main(void)
{
  int no,dig;
  printf("正の整数を入力してください。:");
  scanf("%d",&no);
  dig=0;
  do
  {
    no/=10;
    dig++;
  }while(no>0);
  printf("それは%d桁です。\n",dig);
  return 0;
}
