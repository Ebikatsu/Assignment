#include<stdio.h>

int main(void)
{
  int a,b;
  printf("整数A:");scanf("%d",&a);
  printf("整数B:");scanf("%d",&b);
  printf("AをBで割ると%d",a/b);
  if(a%b!=0)printf("あまり%d",a%b);
  printf("です。\n");
  return 0;
}
