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
  int min;

  if(x<y)
    min = x;
  else
    min = y;
  return (min);
}
