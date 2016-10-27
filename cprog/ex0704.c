/*
  0~UNIT_MAXを2進・8進・10進・16進で表示
*/

#include <stdio.h>
#include <limits.h>

/*--- 整数xのセットされたビット数を返す ---*/
int count_bits(unsigned x)
{
  int count = 0;
  while (x) {
    if(x & 1U) count++;
    x >>= 1;
  }
  return (count);
}

/*--- unsigned型のビット数を返す ---*/
int int_bits(void)
{
  return (count_bits(~0U));
}

/*--- unsigned型のビット内容を表示 ---*/
void print_bits(unsigned x)
{
  int i;
  for(i = int_bits() - 1; i >= 0; i--)
    putchar(((x >> i) & 1U) ? '1' : '0');
}

int main(void)
{
  unsigned i; /*int型は不可*/

  for(i = 0; i < UINT_MAX; i++){
    print_bits(i);
    printf(" %6o %5u %4x\n", i, i, i);
  }
  return (0);
}
