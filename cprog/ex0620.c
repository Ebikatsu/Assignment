#include<stdio.h>
#include<stdlib.h>

void f(int x)
{
  x = 5;
}

int main(void)
{
  int no=10;
  f(no);
  printf("%d\n",no);
  return EXIT_SUCCESS;
}
