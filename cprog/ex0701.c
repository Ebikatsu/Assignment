/*
  文字列と整数型の表現範囲を表示する
*/

#include <stdio.h>
#include <limits.h>

int main(void)
{
  printf("char               : %d~%d\n",CHAR_MIN,CHAR_MAX);
  printf("signed char        : %d~%d\n",SCHAR_MIN,SCHAR_MAX);
  printf("unsigned char      : %d~%d\n",0,UCHAR_MAX);
  printf("short int          : %d~%d\n",SHRT_MIN,SHRT_MAX);
  printf("unsigned short int : %u~%u\n",0,USHRT_MAX);
  printf("int                : %d~%d\n",INT_MIN,INT_MAX);
  printf("unsigned int       : %u~%u\n",0,UINT_MAX);
  printf("long int           : %ld~%ld\n",LONG_MIN,LONG_MAX);
  printf("unsigned long int  : %lu~%lu\n",(unsigned long int)0,ULONG_MAX);

  return (0);
}
