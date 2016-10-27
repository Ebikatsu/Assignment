#include<stdlib.h>
#include<stdio.h>
int abs(int x);
int main(void)
{
  int a;
  scanf("%d",&a);
  printf("%d\n",abs(a));
  return EXIT_SUCCESS;
}
int abs(int x)
{
  return (x>0 ? x: -x);
}
