#include<stdio.h>
#include<stdlib.h>

// (1) string.hを使用するためのinclude文
#include<string.h>

int main(void){
  int i;

  // (2) 128文字の要素を持つ文字列を"ABCDE"で初期化する。
  char str1[128]="ABCDE";

  // (3) 128文字の要素を持つ別の文字列を宣言する。
  char str2[128];

  // (4) (3)の文字列に"xyz"を代入する。
  strcpy(str2,"xyz");

  // (5) (2)と(3)の文字列を出力する。
  printf("%s\n%s\n",str1,str2);

  // (6) for文もしくはwhile文を用いて、(2)の文字列を1文字ずつ改行して表示する。
  //     ただし、不必要な文字を出力してはならず、
  //     (2)の文字列は127文字以内のアルファベットであれば、どのような文字列でも正しく出力されること。
  i=0;
  while(str1[i]!='\0')printf("%c\n",str1[i++]);

  // (7) (2)の文字列を"abc"に変更する。
  strcpy(str1,"abc");

  // (8) (2)の文字列を出力する。
  printf("%s\n",str1);

  return EXIT_SUCCESS;
}
