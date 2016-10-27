/*
  配列とポインタを用いて各要素を表示
*/

#include <stdio.h>

int main(void)
{
  int i;
  int vc[5] = {10, 20, 30, 40, 50};
  int *ptr = &vc[0];

  for(i = 0; i < 5; i++) {
    printf("vc[%d]=%d %d[vc]=%d", i, vc[i], i, i[vc]);
    printf("*(vc+%d)=%d *(%d+vc)=%d\n", i, *(vc+i), i, *(i+vc));
  }
  putchar('\n');

  for(i = 0; i < 5; i++) {
    printf("*(ptr+%d)=%d *(%d+ptr)=%d", i, *(ptr+i), i, *(i+ptr));
    printf("ptr[%d]=%d %d[ptr]=%d\n", i, ptr[i], i, i[ptr]);
  }

  return (0);
}
