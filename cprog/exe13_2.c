#include<stdio.h>
#include<stdlib.h>
struct AD{
  int year;
  // 西暦
  int heisei; // 和暦
};
void add_year(struct AD *a,struct AD y, int x);
int main(void){
  // ある年の西暦と和暦を保存するための構造体変数 y1 の宣言と初期化.とりあえず今年としておく.
  struct AD y1 = {2016, 28};
  // x 年後の西暦と和暦を保存するための構造体変数 y2 の宣言
  struct AD y2;
  // x 年後を表す int 型変数.代入する整数は適当でよい.
  int x = 5;
  add_year(&y2,y1,x);
  // ある年と x 年後の出力
  printf("%d 年 - 平成%d 年\n", y1.year, y1.heisei);
  printf("%d 年 - 平成%d 年\n", y2.year, y2.heisei);
  return EXIT_SUCCESS;
}
void add_year(struct AD *a,struct AD y, int x)
{
  //*a = {y.year+x,y.heisei+x};
  a->year=y.year+x;
  a->heisei=y.heisei+x;
  return;
}
