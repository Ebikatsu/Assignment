/*
  符号無し整数のシフトが2のべき乗での除乗算と等しいことを確認
*/

#include <stdio.h>

/*--- 2のno乗を返す ---*/
unsigned pow2(unsigned no)
{
  unsigned pw =1;

  while (no--)
    pw *= 2;
  return (pw);
}

int main(void)
{
  unsigned m_pow, d_pow, l_sht, r_sht;
  unsigned a, n;

  printf("整数Aを入力して下さい:");  scanf("%u",&a);
  printf("何ビットシフトしますか:"); scanf("%u",&n);

  m_pow = a * pow2(n); /* 2のn乗を掛けた値 */
  d_pow = a / pow2(n); /* 2のn乗で割った値 */

  l_sht = a << n;
  r_sht = a >> n;

  printf("A * (2の%u乗) = %u\n", n, m_pow);
  printf("A / (2の%u乗) = %u\n", n, d_pow);
  printf("A << %u = %u\n", n, l_sht);
  printf("A >> %u = %u\n", n, r_sht);

  if (r_sht == d_pow && l_sht == m_pow)
    printf("符号無し整数%uの左右%uビットシフトは、\n2の%u乗での乗算や除算と等しいです。\n", a, n, n);

  return (0);
}
