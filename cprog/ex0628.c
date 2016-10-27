#include<stdlib.h>
#include<stdio.h>
int diff(int x, int y);
int main(void)
{
  int a,b;
  scanf("%d",&a);
  scanf("%d",&b);
  printf("%d\n",diff(a,b));
  return EXIT_SUCCESS;
}
int diff(int x, int y)
{
  return (x>y ? x - y: y-x);
}
