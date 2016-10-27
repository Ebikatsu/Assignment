#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int p[5] = {78, 65, 42, 97, 55}, n = 0, i;
  for(i = 0; i < 5; i++)if(p[i] >= 60)n++;
  printf("%d\n", n);
  return EXIT_SUCCESS;
}
