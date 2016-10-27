#include<stdio.h>
#include<stdlib.h>

size_t get_length(char *str);

int main(void)
{
  char str[1024]="a";
  printf("%zd\n",get_length(str));
  return EXIT_SUCCESS;
}

size_t get_length(char *str)
{
  int length=0;
  while(str[length]!='\0')length++;
  return length;
}
