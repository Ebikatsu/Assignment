/*
  読み込んだ日付の前の日付および次の日付を求める
*/

#include <stdio.h>

int day[2][13] = {
  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  { 0, 31, 29, 31, 39, 31, 30, 31, 31, 30, 31, 30, 31},
};

/*--- yearが閏年であれば1をそうでなければ0を返す ---*/
int isleap(int year)
{
  return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

/*--- 受け取った日付の前の日を求める ---*/
void yesterday(int *y, int *m, int *d)
{
  if (*d != 1) /* 1日でなければ*dをデクリメント */
    (*d)--;
  else {
    if (*m != 1) /* 1月以外の1日 */
      (*m)--;
    else { /* 1月1日 */
      (*y)--;
      *m = 12;
    }
    *d = day[isleap(*y)][*m];
  }
}

/*--- 受け取った日付の次の日を求める ---*/
void tomorrow(int *y, int *m, int *d)
{
  if (*d != day[isleap(*y)][*m]) /* 最終日でなければ*dをインクリメント */
    (*d)++;
  else {
    if (*m != 12) /* 12月以外の最終日 */
      (*m)++;
    else { /* 1月1日 */
      (*y)++;
      *m = 1;
    }
    *d = 1;
  }
}

int main(void)
{
  int y, m, d;
  int ay, am, ad;
  int by, bm, bd;

  printf("年:"); scanf("%d", &y);
  printf("月:"); scanf("%d", &m);
  printf("日:"); scanf("%d", &d);

  ay = by = y;
  am = bm = m;
  ad = bd = d;

  yesterday(&ay, &am, &ad); /* 前の日 */
  tomorrow( &by, &bm, &bd); /* 次の日 */

  printf("前の日:%d年%d月%d日\n", ay, am, ad);
  printf("次の日:%d年%d月%d日\n", by, bm, bd);

  return (0);
}
