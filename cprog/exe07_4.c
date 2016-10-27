#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
  char a[]="mississippi",b[]="sis";
  if(strstr(a,b)!=NULL)printf("aはbを含む。\n");
  else printf("aはbを含まない。\n");
  return EXIT_SUCCESS;
}
