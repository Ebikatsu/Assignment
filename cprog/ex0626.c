#include<stdio.h>
#include<stdlib.h>

int scan_pint(void);

int main(void)
{
  printf("%d\n",scan_pint());
  return EXIT_SUCCESS;
}

int scan_pint(void)
{
  int temp;
  do {
    scanf("%d", &temp);
  } while (temp <= 0);
  return (temp);
}
