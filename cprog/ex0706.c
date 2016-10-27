/*
  符号無し整数のビットを左右に回転する
*/

#include <stdio.h>

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

/*--- xを右にnビット回転した値を返す ---*/
unsigned rrotate(unsigned x, int n)
{
  int bits = int_bits();
  n %= bits;
  return (n ? (x >> n) | (x << (bits - n)) : x);
}

/*--- xを左にnビット回転した値を返す ---*/
unsigned lrotate(unsigned x, int n)
{
  int bits = int_bits();
  n %= bits;
  return (n ? (x << n) | (x >> (bits - n)) : x);
}

int main(void)
{
  unsigned nx,no;

  printf("非負の整数を入力してください:"); scanf("%u", &nx);
  printf("何ビット回転しますか:");         scanf("%u", &no);

  printf("\n回転前="); print_bits(nx);
  printf("\n右回転="); print_bits(rrotate(nx, no));
  printf("\n左回転="); print_bits(lrotate(nx, no));
  putchar('\n');

  return (0);
}
