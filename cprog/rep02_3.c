#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);

int main(void)
{
  int a = 1, b = 2;
  printf("%d\n", max(a, b));
  return EXIT_SUCCESS;
}

int max(int a, int b)
{
  return a > b ? a: b;
}
