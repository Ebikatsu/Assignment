#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
  char str[1024]="abc";
  printf("%zd\n",strlen(str));
  return EXIT_SUCCESS;
}
