/*
  配列の各要素に先頭から順に0,1,2,3,4を代入して表示
*/

#include <stdio.h>

int main(void)
{
  int vc[5];

  vc[0] = 0;
  vc[1] = 1;
  vc[2] = 2;
  vc[3] = 3;
  vc[4] = 4;

  printf("vc[0] = %d\n",vc[0]);
  printf("vc[1] = %d\n",vc[1]);
  printf("vc[2] = %d\n",vc[2]);
  printf("vc[3] = %d\n",vc[3]);
  printf("vc[4] = %d\n",vc[4]);

  return (0);
}
