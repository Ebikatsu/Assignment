#include<stdlib.h>
#include<stdio.h>
int intcmp(int x, int y);
int main(void)
{
  int a,b;
  scanf("%d",&a);
  scanf("%d",&b);
  printf("%d\n",intcmp(a,b));
  return EXIT_SUCCESS;
}
int intcmp(int x, int y)
{
  return (x==y ? 0 : x>y ? 1: -1);
}
