#include<stdio.h>
#include<stdlib.h>

int main(void){
  int i;

  // (1) double型配列aryを宣言し、{1.1, 2.2, 3.3, 4.4}で初期化
  double ary[]={1.1, 2.2, 3.3, 4.4};

  // (2) ポインタ変数pを宣言し、配列aryの先頭アドレスを代入(複数の文になってもよい)
  double *p;
  p=ary;

  // (3) for文と配列aryを用いて、配列aryの各要素のアドレスと値を出力
  for(i=0;i<4;i++)printf("%p\n%lf\n",&ary[i],ary[i]);

  // (4) for文とポインタ変数pを用いて、配列aryの各要素のアドレスと値を出力
  for(i=0;i<4;i++)printf("%p\n%lf\n",p+i,*(p+i));

  /*
    (A) なぜ(3)と(4)の結果が同じになるか、理由を記述せよ
ポインタ変数pに配列aryの先頭アドレスが格納されているため、&ary[i]とp+i、ary[i]と*(p+i)が同じ値を指しているため。
   */

  // (5) 変数i、for文,ポインタ変数pを用いて、配列aryの各要素の値を1加算する
  //     (for文の中で配列aryは用いない)
  for(i=0;i<4;i++)(*(p+i))++;

  // (6) for文の中でポインタ変数pをインクリメントしながら、配列aryの各要素の値を1.5倍にする
  //     (for文の中で配列aryは用いない)
  for(i=0;i<4;i++)*(p++)*=1.5;

  // (7) for文の中でポインタ変数pをインクリメントしながら、配列aryの各要素の値を出力する
  //     (for文の中で配列aryは用いない)
  p=ary;
  for(i=0;i<4;i++)printf("%lf\n",*(p++));

  return EXIT_SUCCESS;
}
