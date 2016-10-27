#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  char str[1024]="Ito Taisei";
  int i=0;
  while(str[i]!='\0')i++;
  printf("%d\n",i);
  return EXIT_SUCCESS;
}
