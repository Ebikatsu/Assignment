#include<stdio.h>
#include<stdlib.h>

// (4) twice関数のプロトタイプ宣言
void twice(double* d);

// (8) twice_pointer関数のプロトタイプ宣言
void twice_pointer(double* d);

int main(void){
  int i;

  // (1) double型配列aryを宣言し、{1.1, 2.2, 3.3, 4.4}で初期化
  double ary[]={1.1, 2.2, 3.3, 4.4};

  // (2) twice関数に配列aryを渡す(teice関数に配列aryの先頭アドレスを渡す)
  twice(ary);

  // (5) for文を用いて、配列aryの各要素の値を出力
  for(i=0;i<4;i++)printf("%lf\n",ary[i]);

  /*
    配列aryの各要素の値が、初期値と比べて変化した理由を考える。

    aryの先頭アドレスがtwice関数に渡されたことで、*ary~*(ary+3)までの値が2倍されたため。
   */

  // (6) twice_pointer関数に配列aryを渡す(teice_pointer関数に配列aryの先頭アドレスを渡す)
  twice_pointer(ary);

  // (9) for文を用いて、配列aryの各要素を出力
  for(i=0;i<4;i++)printf("%lf\n",ary[i]);

  /*
    配列aryの各要素の値が、(5)と比べて変化した理由を考える。

    aryの先頭アドレスがtwice_pointer関数に渡され、twice_pointer関数内でポインタ変数pを用いて*ary~*(ary+3)までの値が2倍されたため。
   */

  return EXIT_SUCCESS;
}

// (3) twice関数定義.仮引数として配列を用いる。
//     関数内では、for文と配列を用いて、配列の各要素の値を2倍にする。
void twice(double* d){
  int i;
  for(i=0;i<4;i++)d[i]*=2;
}

// (7) twice_pointer関数定義.仮引数としてポインタ変数を用いる。
//     関数内では、for文とポインタ変数を用いて、配列の各要素の値を2倍にする。
void twice_pointer(double* d){
  double* p=d;
  int i;
  for(i=0;i<4;i++)(*(p++))*=2;
}
