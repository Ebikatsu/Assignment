#include<stdio.h>
#include<stdlib.h>

int minof(int x, int y);

int main(void)
{
  int a,b;
  scanf("%d",&a);
  scanf("%d",&b);
  printf("%d\n",minof(a,b));
  return EXIT_SUCCESS;
}

int minof(int x, int y)
{
  return ((x<y) ? x : y);
}
