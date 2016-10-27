/*
  選ばれた季節の趣を表示
*/

#include <stdio.h>

enum season { Spring, Summer, Fall, Winter, Invalid };

/*--- 春 ---*/
void spring(void)
{
  puts("春はあけぼの");
}

/*--- 夏 ---*/
void summer(void)
{
  puts("夏は夜");
}

/*--- 秋 ---*/
void fall(void)
{
  puts("秋は夕暮れ");
}

/*--- 冬 ---*/
void winter(void)
{
  puts("冬はつとめて");
}

/*--- 季節を選ぶ ---*/
enum season select(void)
{
  int tmp;

  do {
    printf("0…春 1… 2…秋 3…冬 4…終了");
	   scanf("%d", &tmp);
  } while (tmp < Spring || tmp > Invalid);
  return (tmp);
}

int main(void)
{
  enum season selected;

  do {
    switch (selected = select()) {
    case Spring : spring(); break;
    case Summer : summer(); break;
    case Fall : fall(); break;
    case Winter : winter(); break;
    case Invalid: break;
    }
  } while (selected != Invalid);

  return (0);
}
