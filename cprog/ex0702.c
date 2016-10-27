/*
  型の大きさを表示する
*/

#include <stdio.h>

int main(void)
{
  printf("sixeof(char)          = %u\n", (unsigned)sizeof(char));
  printf("sizeof(signed char)   = %u\n", (unsigned)sizeof(signed char));
  printf("sizeof(unsigned char) = %u\n", (unsigned)sizeof(unsigned char));
  printf("sizeof(short int)     = %u\n", (unsigned)sizeof(short int));
  printf("sizeof(unsigned short)= %u\n", (unsigned)sizeof(unsigned short));
  printf("sizeof(int)           = %u\n", (unsigned)sizeof(int));
  printf("sizeof(unsigned)      = %u\n", (unsigned)sizeof(unsigned));
  printf("sizeof(long int)      = %u\n", (unsigned)sizeof(long int));
  printf("sizeof(unsigned long) = %u\n", (unsigned)sizeof(unsigned long));

  return (0);
}
