#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  float a[10] = {1.1, 1.1};
  int i;
  for(i = 2; i < 10; i++)a[i] = a[i - 1] + a[i - 2];
  for(i = 0; i < 10; i++)printf("%f\n", a[i]);
  return EXIT_SUCCESS;
}
