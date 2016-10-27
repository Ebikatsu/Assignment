#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  int a,b;
  a=100;
  b=20+3;
  printf("a=%3d,b=%3d\n",a,b);
  a=50;
  b=a+b+150;
  printf("a=%3d,b=%3d\n",a,b);
  return EXIT_SUCCESS;
}
