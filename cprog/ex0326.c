#include<stdio.h>

int main(void)
{
  int a,b;
  printf("整数A:");scanf("%d",&a);
  printf("整数B:");scanf("%d",&b);
  if(a%b)printf("AをBで割ると%dあまり%dです。\n",a/b,a%b);
  else printf("AをBで割ると%dです。\n",a/b);
  return 0;
}
