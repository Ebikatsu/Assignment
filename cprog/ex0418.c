/*
  身長と標準体重の対応を表示
*/

#include <stdio.h>

int main(void)
{
  int    height; /* 身長 */
  int    lower;  /* 身長の下限(開始値) */
  int    upper;  /* 身長の上限(終了値) */
  int    step;   /* きざみ幅(増分) */
  double weight; /* 体重 */

  printf("何cmから:"); scanf("%d",&lower);
  printf("何cmまで:"); scanf("%d",&upper);
  printf("何cmごと:"); scanf("%d",&step);

  for (height = lower; height <= upper; height += step) {
    weight = (height - 100) * 0.9;           /* 標準体重を計算 */
    printf("%dcm %.2fkg\n", height, weight); /* 標準体重を表示 */
  }

  return (0);
}
