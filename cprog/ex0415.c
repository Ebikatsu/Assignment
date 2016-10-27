/*
  読み込んだ正の整数値までカウントアップ
*/

#include<stdio.h>

int main(void)
{
  int no;

  printf("正の整数を入力してください。:");
  scanf("%d", &no);

  if (no > 0) {
    int i;
    for(i = 1; i <= no; i++) /*iを1からnoまで一つずつ増やしながら*/
      printf("%d ", i);       /*iの値を表示*/
    putchar('\n');           /*最後に改行*/
  }

  return 0;
}
