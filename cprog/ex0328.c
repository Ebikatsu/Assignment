#include<stdio.h>

int main(void)
{
  int a,b,mod;
  printf("整数A:");scanf("%d",&a);
  printf("整数B:");scanf("%d",&b);
  mod=a%b;
  printf("AをBで割ると%d",a/b);
  if(mod)printf("あまり%d",mod);
  printf("です。\n");
  return 0;
}
